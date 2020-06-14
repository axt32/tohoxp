#include "GameState_ScoreBoard.h"

std::vector<Record *> vRecord;			//extern이 아님.
std::vector<Record *>::iterator Iter;	//extern이 아님.
int iHiScore = 0;
bool bOnceExtended;
int iExtendAppearRemainTime = 0;

std::vector<Record *>::iterator PlayerRecordIter;	//extern이 아님.

bool bInputScore = false;		//extern이 아님.

int iScoreBoard_Score_PosCol = 0;
int iScoreBoard_Score_PosRow = 0;

bool LoadRecord()
{
	printf ("Loading Score ... ");
	CSVManager CSVReader;
	if (CSVReader.OpenFile("config/score.csv", IOTYPE_READ) == true)
	{
		printf ("OK\n");
	}
	else
	{
		printf ("Failed\n");
		return false;
	}

	std::string sName;
	std::string sChara;
	std::string sScore;
	std::string sDate;
	std::string sStage;

	bool bLoadResult = false;
	
	//첫째줄은 버림
	CSVReader.ReadLine(5, &sName, &sChara, &sScore, &sDate, &sStage);

	while(CSVReader.ReadLine(5, &sName, &sChara, &sScore, &sDate, &sStage) == true)
	{
		Record * pRecord = new Record;
		pRecord->sName = sName;
		pRecord->sChara = sChara;
		pRecord->iScore = atoi(sScore.c_str());
		pRecord->sDate = sDate;
		pRecord->iStage = atoi(sStage.c_str());
		vRecord.push_back(pRecord);

		bLoadResult = true;
	}

	if (bLoadResult == true)
	{
		Iter = vRecord.begin();
		iHiScore = (*(vRecord.begin()))->iScore;
		return true;
	}

	return false;
}

bool CheckRecord()
{
	bool bRanked = false;

	for ( 	std::vector<Record *>::iterator Iter = vRecord.begin(); Iter != vRecord.end(); Iter++)
	{
		auto InsertScore = [&] (bool bSameScore)
		{
			Record * pRecord = new Record;
			pRecord->sName = "";
			pRecord->iScore = Player.iScore;
			pRecord->sDate = "";
			switch (Player.iPlayerCharaType)
			{
			case PLAYERCHARA_REIMU:
				pRecord->sChara = "Reimu";
				break;
			case PLAYERCHARA_MARISA:
				pRecord->sChara = "Marisa";
				break;
			case PLAYERCHARA_REISEN:
				pRecord->sChara = "Sakuya";
				break;
			}
			pRecord->iStage = iCurrentStage;
			if (bSameScore == true)
			{
				PlayerRecordIter = vRecord.insert(Iter + 1, pRecord);
			}
			else
			{
				PlayerRecordIter = vRecord.insert(Iter, pRecord);
			}
			delete (*(vRecord.end() - 1));
			vRecord.erase(vRecord.end() - 1);
			bRanked = true;
		};


		if ( Player.iScore > (*Iter)->iScore)
		{
			InsertScore(false);
			break;
		}
		else if (Player.iScore == (*Iter)->iScore)
		{
			//동점인데 동점자의 등위가 10위면 제한다.
			if ( Iter - vRecord.begin() == 9)
			{
				break;
			}
			else
			{
				InsertScore(true);
				break;
			}
		}
	}

	return bRanked;
}

bool GoToFirst()
{
	if (vRecord.size() > 0)
	{
		Iter = vRecord.begin();

		return true;
	}

	return false;

}

bool GetRecord(std::string * OUT_sName, std::string * OUT_sChara, int * OUT_iScore, std::string * OUT_sDate, int * OUT_iStage, bool * OUT_isPlayer)
{
	if (vRecord.size() > 0)
	{
		if (Iter == vRecord.end())
		{
			return false;
		}

		if (OUT_sName != NULL)
		{
			*OUT_sName = (*Iter)->sName;
		}
		if (OUT_sChara != NULL)
		{
			*OUT_sChara = (*Iter)->sChara;
		}
		if (OUT_iScore != NULL)
		{
			*OUT_iScore = (*Iter)->iScore;
		}
		if (OUT_sDate != NULL)
		{
			*OUT_sDate = (*Iter)->sDate;
		}
		if (OUT_iStage != NULL)
		{
			*OUT_iStage = (*Iter)->iStage;
		}

		if (OUT_isPlayer != NULL)
		{
			if ( Iter == PlayerRecordIter)
			{
				*OUT_isPlayer = true;
			}
			else
			{
				*OUT_isPlayer = false;
			}
		}

		Iter++;

		return true;
	}

	return false;
}



bool ClearRecord()
{
	if (vRecord.size() > 0)
	{
		for (std::vector<Record *>::iterator Iter = vRecord.begin(); Iter != vRecord.end(); Iter++)
		{
			if (*Iter != NULL)
			{
				delete (*Iter);
			}
		}
		vRecord.clear();
		
		return true;
	}

	return false;
}

bool InsertChar(int IN_Order)
{
	if ((*PlayerRecordIter) == NULL || (*PlayerRecordIter)->sName.length() == 8)
	{
		return false;
	}

	int iAscii = OrderToAscii(IN_Order);
	if (iAscii == -1 || *PlayerRecordIter == NULL)
	{
		return false;
	}

	char charascii[2];

	charascii[0] = iAscii;
	charascii[1] = NULL;
	
	(*PlayerRecordIter)->sName += (std::string)(charascii);

	if ((*PlayerRecordIter)->sName.length() == 8)
	{
		iScoreBoard_Score_PosRow = SCOREBOARD_STATUS_CHARTABLE_ROWS - 1;
		iScoreBoard_Score_PosCol = SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 1;
	}

	return true;
}

bool DeleteOneChar()
{
	if ((*PlayerRecordIter) == NULL || (*PlayerRecordIter)->sName.length() == 0)
	{
		return false;
	}

	(*PlayerRecordIter)->sName.erase((*PlayerRecordIter)->sName.end() - 1);
	return true;

}
bool InsertBlank()
{
	if ((*PlayerRecordIter) == NULL || (*PlayerRecordIter)->sName.length() == 8)
	{
		return false;
	}	

	(*PlayerRecordIter)->sName += " ";
	return true;

}

bool isNameFull()
{
	if (*PlayerRecordIter == NULL)
	{
		return false;
	}

	if ( (*PlayerRecordIter)->sName.length() == 8)
	{
		return true;
	}

	return false;
}

int OrderToAscii(int IN_Order)
{
	//A~Z, a~z
	if (IN_Order < 26)
	{
		return 65 + IN_Order;
	}
	else if (IN_Order < 52)		//a~z
	{
		return 97 + IN_Order - 26;
	}
	else if (IN_Order < 62)		//0~9
	{
		return 48 + IN_Order - 52;
	}
	else if (IN_Order < 77)		//!~/
	{
		return 33 + IN_Order - 62;
	}
	else if ( IN_Order < 83)	//:~?
	{
		return 58 + IN_Order - 77;
	}
	else if (IN_Order == 83)	//@
	{
		return 64;
	}
	else if (IN_Order < 89)		//[~_
	{
		return 91 + IN_Order - 84;
	}
	else if (IN_Order < 94)		//{~'~'
	{
		return 123 + IN_Order - 89;
	}

	return -1;
}

bool SaveRecord()
{
	CSVManager CSVWriter;

	if (CSVWriter.OpenFile("config/score.csv", IOTYPE_WRITE) == false)
	{
		printf ("Score Save Failed.\n");
	}

	CSVWriter.WriteLine(5, (std::string)"Name", (std::string)"Chara", (std::string)"Score", (std::string)"DTime", (std::string)"Stage");

	if (vRecord.size() > 0)
	{
		for (std::vector<Record *>::iterator Iter = vRecord.begin(); Iter != vRecord.end(); Iter++)
		{
			CSVWriter.WriteLine(5, (*Iter)->sName, (*Iter)->sChara, std::to_string((_Longlong)((*Iter)->iScore)), (*Iter)->sDate, (std::to_string)((_Longlong)((*Iter)->iStage)));
		}

		return true;
	}

	return false;

}

void ScoreBoard_Left()
{
	Sound_Select.Play(false, NULL, fVolume_SE);
	if (iScoreBoard_Score_PosCol > 0)
	{
		if ( iScoreBoard_Score_PosCol == SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 3 
			&& iScoreBoard_Score_PosRow == SCOREBOARD_STATUS_CHARTABLE_ROWS - 1 )
		{
			iScoreBoard_Score_PosCol = 1;
		}
		else
		{
			iScoreBoard_Score_PosCol--;
		}
	}
}

void ScoreBoard_Right()
{
	Sound_Select.Play(false, NULL, fVolume_SE);
	if (iScoreBoard_Score_PosCol < SCOREBOARD_STATUS_CHARTABLE_COLUMNS  - 1)
	{
		if (iScoreBoard_Score_PosCol == 1 && iScoreBoard_Score_PosRow == SCOREBOARD_STATUS_CHARTABLE_ROWS - 1)
		{
			iScoreBoard_Score_PosCol = SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 3;
		}
		else
		{
			iScoreBoard_Score_PosCol++;
		}
	}
}

void ScoreBoard_Up()
{
	Sound_Select.Play(false, NULL, fVolume_SE);
	if (iScoreBoard_Score_PosRow > 0)
	{
		iScoreBoard_Score_PosRow--;
	}
}

void ScoreBoard_Down()
{
	Sound_Select.Play(false, NULL, fVolume_SE);
	if (iScoreBoard_Score_PosRow < SCOREBOARD_STATUS_CHARTABLE_ROWS - 1)
	{
		if ( !(iScoreBoard_Score_PosRow == SCOREBOARD_STATUS_CHARTABLE_ROWS - 2
			&& (iScoreBoard_Score_PosCol > 1 && iScoreBoard_Score_PosCol < SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 3)))
		{
			iScoreBoard_Score_PosRow++;
		}
	}
}


bool Input_ScoreBoard()
{
	Sound_Okay.Play(false, NULL, fVolume_SE);
	if (iScoreBoard_Score_PosRow == SCOREBOARD_STATUS_CHARTABLE_ROWS - 1 &&				//終
		iScoreBoard_Score_PosCol == SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 1)
	{
		SaveRecord();
		ClearRecord();
		//컨티뉴할지 물어보는 창(GAMEOVERMENU)으로..
		return true;
	}
	else if (iScoreBoard_Score_PosRow == SCOREBOARD_STATUS_CHARTABLE_ROWS - 1 &&		//백스페이스
		iScoreBoard_Score_PosCol == SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 2)
	{
		DeleteOneChar();
	}
	else if (iScoreBoard_Score_PosRow == SCOREBOARD_STATUS_CHARTABLE_ROWS - 1 &&		//공백
		iScoreBoard_Score_PosCol == SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 3)
	{
		if (isNameFull() == false)
		{
			InsertBlank();
		}
		else
		{
			iScoreBoard_Score_PosRow = SCOREBOARD_STATUS_CHARTABLE_ROWS - 1;
			iScoreBoard_Score_PosCol = SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 1;
		}
	}
	else
	{	
		if (isNameFull() == false)
		{
			InsertChar(iScoreBoard_Score_PosRow * SCOREBOARD_STATUS_CHARTABLE_COLUMNS + iScoreBoard_Score_PosCol);
		}
		else
		{
			iScoreBoard_Score_PosRow = SCOREBOARD_STATUS_CHARTABLE_ROWS - 1;
			iScoreBoard_Score_PosCol = SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 1;
		}
	}

	return false;
}

void ScoreBoard_Cancel()
{
	Sound_Cancel.Play(false, NULL, fVolume_SE);
	DeleteOneChar();
}

void Init_ScoreBoard_State(bool IN_InputScore)
{
	bInputScore = IN_InputScore;
	ClearRecord();

	if (LoadRecord() == true)
	{
		if (bInputScore == true)
		{
			bool bRanked = CheckRecord();
			if (bRanked == true)
			{
				iScoreBoard_Score_PosCol = 0;
				iScoreBoard_Score_PosRow = 0;
				iGameState = RECORDSTATUS;
			}
			else
			{
				Init_MainMenu();
			}
		}
		else
		{
			iGameState = RECORDSTATUS;
		}
	}
	else
	{
		printf ("Record Load Failed !!\n");
		ClearRecord();
		Init_MainMenu();
	}

}
void Draw_ScoreBoard_State()
{
	Spr_UI_MainMenu_Background.DrawSprite(0, 0, 0);
//	Spr_UI_Record_Background.DrawSprite(0, 0, 0);

	Spr_UI_Record_Title.DrawSprite(SCOREBOARD_TITLE_X, SCOREBOARD_TITLE_Y, 0);

	DarkScreen_Record.DrawSprite(SCOREBOARD_STATUS_TABLE_COLUMN0_X, SCOREBOARD_STATUS_TABLE_COLUMN0_Y, 0);

	std::string sName;
	std::string sChara;
	int iScore;
	std::string sDTime;
	int iStage;

	int iRow = 0;
	GoToFirst();

	Shooter_DrawText(&Spr_NormalFont, "No", SCOREBOARD_STATUS_TABLE_COLUMN0_X, SCOREBOARD_STATUS_TABLE_COLUMN0_Y + iRow * 17);
	Shooter_DrawText(&Spr_NormalFont, "Chara", SCOREBOARD_STATUS_TABLE_COLUMN1_X, SCOREBOARD_STATUS_TABLE_COLUMN1_Y + iRow * 17);
	Shooter_DrawText(&Spr_NormalFont, "Name", SCOREBOARD_STATUS_TABLE_COLUMN2_X, SCOREBOARD_STATUS_TABLE_COLUMN2_Y + iRow * 17);
	Shooter_DrawText(&Spr_NormalFont, "Score" , SCOREBOARD_STATUS_TABLE_COLUMN3_X, SCOREBOARD_STATUS_TABLE_COLUMN3_Y + iRow * 17);
	Shooter_DrawText(&Spr_NormalFont, "Stage", SCOREBOARD_STATUS_TABLE_COLUMN4_X, SCOREBOARD_STATUS_TABLE_COLUMN4_Y + iRow * 17);

	iRow++;

	bool bIsPlayer;
	ShooterSprite * pFont;

	auto DrawOneLine = [&]
	{
		Shooter_DrawText(pFont, std::to_string((_Longlong)(iRow)), SCOREBOARD_STATUS_TABLE_COLUMN0_X, SCOREBOARD_STATUS_TABLE_COLUMN0_Y + iRow * 20);
		Shooter_DrawText(pFont, sChara, SCOREBOARD_STATUS_TABLE_COLUMN1_X, SCOREBOARD_STATUS_TABLE_COLUMN1_Y + iRow * 20);
		Shooter_DrawText(pFont, sName, SCOREBOARD_STATUS_TABLE_COLUMN2_X, SCOREBOARD_STATUS_TABLE_COLUMN2_Y + iRow * 20);
		Shooter_DrawText(pFont, std::to_string((_Longlong)(iScore)), SCOREBOARD_STATUS_TABLE_COLUMN3_X, SCOREBOARD_STATUS_TABLE_COLUMN3_Y + iRow * 20, 9);
		if (iStage < 3)
		{
			Shooter_DrawText(pFont, "Stage" + std::to_string((_Longlong)(iStage)), SCOREBOARD_STATUS_TABLE_COLUMN4_X, SCOREBOARD_STATUS_TABLE_COLUMN4_Y + iRow * 20);
		}
		else
		{
			Shooter_DrawText(pFont, "Clear", SCOREBOARD_STATUS_TABLE_COLUMN4_X, SCOREBOARD_STATUS_TABLE_COLUMN4_Y + iRow * 20);
		}
		iRow++;
	};

	if (bInputScore == true)
	{
		while (GetRecord(&sName, &sChara, &iScore, &sDTime, &iStage, &bIsPlayer) == true)
		{
			if (bIsPlayer == true)
			{
				pFont = &Spr_NormalFont_Selected;
			}
			else
			{
				pFont = &Spr_NormalFont;
			}

			DrawOneLine();
		}
	}
	else
	{
		pFont = &Spr_NormalFont;
		while (GetRecord(&sName, &sChara, &iScore, &sDTime, &iStage, NULL) == true)
		{
			DrawOneLine();
		}
	}

	if (bInputScore == true)
	{
		DrawCharTable(SCOREBOARD_STATUS_CHARTABLE_X, SCOREBOARD_STATUS_CHARTABLE_Y + SCOREBOARD_STATUS_CHARTABLE_Y_ADD);
	}
}

void Input_RecordStatus()
{
	if (GameInput.GetInput(QUIT))
	{
		//'QUIT' 명령시 ->  강제종료.
		bRunning = false;
		return;
	}

	if (GameInput.GetPreviousInput(iKey_Attack) == false && GameInput.GetInput(iKey_Attack))
	{
		if (bInputScore == true)
		{
			if (Input_ScoreBoard() == true)
			{
				Init_MainMenu();
			}
		}
	}

	if ( GameInput.GetPreviousInput(iKey_Bomber) == false && GameInput.GetInput(iKey_Bomber))
	{
		if (bInputScore == true)
		{
			ScoreBoard_Cancel();
		}
		else
		{
			Sound_Cancel.Play(false, NULL, fVolume_SE);
			Init_MainMenu(false);
		}
	}

	if ( GameInput.GetPreviousInput(KEY_ESCAPE) == false && GameInput.GetInput(KEY_ESCAPE) )
	{
		if (bInputScore == false)
		{
			Sound_Cancel.Play(false, NULL, fVolume_SE);
			Init_MainMenu(false);
		}
	}

	if (bInputScore == true)
	{
		if (GameInput.GetPreviousInput(iKey_Left) == false && GameInput.GetInput(iKey_Left))
		{
			ScoreBoard_Left();
		}
		if (GameInput.GetPreviousInput(iKey_Right) == false && GameInput.GetInput(iKey_Right))
		{
			ScoreBoard_Right();
		}
		if (GameInput.GetPreviousInput(iKey_Up) == false && GameInput.GetInput(iKey_Up))
		{
			ScoreBoard_Up();
		}
		if (GameInput.GetPreviousInput(iKey_Down) == false && GameInput.GetInput(iKey_Down))
		{
			ScoreBoard_Down();
		}
	}
}

void DrawCharTable(int IN_x, int IN_y)
{
	for (int i = 0; i < SCOREBOARD_STATUS_CHARTABLE_ROWS; i++)
	{
		for (int j = 0; j < SCOREBOARD_STATUS_CHARTABLE_COLUMNS; j++)
		{
			if (i == SCOREBOARD_STATUS_CHARTABLE_ROWS - 1)
			{
				if (j > 1 && j < SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 3)
				{
					continue;
				}
				else if (j >= SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 3)
				{
					ShooterSprite * pFont;
					if (j == iScoreBoard_Score_PosCol && i == iScoreBoard_Score_PosRow)
					{
						pFont = &Spr_NormalFont_Others_Selected;
					}
					else
					{
						pFont = &Spr_NormalFont_Others_Gray;
					}

					pFont->DrawSprite(IN_x + (j * 17), IN_y + (i * 17), j - (SCOREBOARD_STATUS_CHARTABLE_COLUMNS - 3));

					continue;
				}
			}

			//글자가 출력되는 순서는 폰트 비트맵과 다름.
			//폰트 비트맵 => 숫자, 대문자, 소문자, 특수문자 순
			//게임오버 화면 => 대문자, 소문자, 숫자, 특수문자 순

			ShooterSprite * pFont;

			if (j == iScoreBoard_Score_PosCol && i == iScoreBoard_Score_PosRow)
			{
				pFont = &Spr_NormalFont_Selected;
			}
			else
			{
				pFont = &Spr_NormalFont_Gray;
			}

			int iOrder = i * SCOREBOARD_STATUS_CHARTABLE_COLUMNS + j;

			if (iOrder < 52)
			{
				pFont->DrawSprite(IN_x + (j * 17), IN_y + (i * 17), iOrder + 10);
			}
			else if (iOrder < 62)
			{
				pFont->DrawSprite(IN_x + (j * 17), IN_y + (i * 17), iOrder - 52);
			}
			else
			{
				pFont->DrawSprite(IN_x + (j * 17), IN_y + (i * 17), iOrder);
			}
		}
	}
}
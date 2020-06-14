#include "GameState_Game.h"

bool bPause;
bool bPause_Query;
bool bPause_Query_YesNo;

bool bNowDisplayBGMName = false;
int iCurrentBGMDisplayTime = 0;

int iCurrentPauseMenuStatus;
int iCurrentGameOverMenuStatus;

ShooterSprite PrintedBossName;
ShooterSprite PrintedSpellName;
ShooterSprite PrintedBGMName;

void InitGame(PlayerCharaType IN_CharaType)
{

	Player.SetAngle(90.0);

	Player.iPlayerCharaType = IN_CharaType;

	//캐릭터 모양
	switch ( Player.iPlayerCharaType)
	{
	case PLAYERCHARA_REIMU:
		Player.SetSprite(&Spr_Reimu_Front, &Spr_Reimu_Left, &Spr_Reimu_Right);
		break;
	case PLAYERCHARA_MARISA:
		Player.SetSprite(&Spr_Marisa_Front, &Spr_Marisa_Left, &Spr_Marisa_Right);
		break;
	case PLAYERCHARA_REISEN:
		Player.SetSprite(&Spr_Reisen_Front, &Spr_Reisen_Left, &Spr_Reisen_Right);
		break;
	}
	
	Player.ChangeState(PLAYERSTATUS_SHIELD);
	MovePlayerToPrimaryLocation(&Player);

	Player.ClearPlayerShot();

	//파워
	Player.SetPower(0);
	switch (Player.iPlayerCharaType)
	{
	case PLAYERCHARA_REIMU:
		Player.SetPlayerShot(0, 0, &PlayerShot_Reimu_0);
		Player.SetPlayerShot(1, 0, &PlayerShot_Reimu_Sub_0);
		Player.SetPlayerShot(2, 0, &PlayerShot_Reimu_Rapier_0);
		Player.iPlayerShotSubCoolTime = 3;
		Player.pPlayerBomberInit = (PlayerBomberInit)(&Bomber_Reimu_Init);
		Player.pPlayerBomber = (PlayerBomber)(&Bomber_Reimu);
		Player.pBomberPortrait = &Spr_CutIn_Reimu;
		Player.fConstNormalSpeed = 3.0;
		Player.fConstSlowSpeed = 2.0;
		PlayerShot_Reimu_Rapier_0.fCurrentSelfRotateAngle = 90.0;
		PlayerShot_Reimu_Rapier_0.fSelfRotateAddAngle = 1.0;
		break;
	case PLAYERCHARA_MARISA:
		Player.SetPlayerShot(0, 0, &PlayerShot_Marisa_0);
		Player.SetPlayerShot(1, 0, &PlayerShot_Marisa_Rapier_0);
		Player.iPlayerShotSubCoolTime = 3;
		Player.pPlayerBomberInit = (PlayerBomberInit)(&Bomber_Marisa_Init);
		Player.pPlayerBomber = (PlayerBomber)(&Bomber_Marisa);
		Player.pBomberPortrait = &Spr_CutIn_Marisa;	
		Player.fConstNormalSpeed = 2.25;
		Player.fConstSlowSpeed = 1.75;
		PlayerShot_Marisa_Rapier_0.fCurrentSelfRotateAngle = 90.0;
		PlayerShot_Marisa_Rapier_0.fSelfRotateAddAngle = 1.0;
		break;
	case PLAYERCHARA_REISEN:
		Player.SetPlayerShot(0, 0, &PlayerShot_Reisen_0);
// 		Player.SetPlayerShot(0, 1, &PlayerShot_Reisen_1);
// 		Player.SetPlayerShot(0, 2, &PlayerShot_Reisen_1);
		Player.iPlayerShotSubCoolTime = 3;
		Player.pPlayerBomberInit = (PlayerBomberInit)(&Bomber_Reisen_Init);
		Player.pPlayerBomber = (PlayerBomber)(&Bomber_Reisen);
		Player.pBomberPortrait = &Spr_CutIn_Reisen;
		Player.fConstNormalSpeed = 2.5;
		Player.fConstSlowSpeed = 2.0;
		break;
	}

	InitPlayerBomber();

	Player.life = 2;	//테스트용
	Player.iScore = 0;

	Player.AddCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, 4.0);
	Player.AddGrazeCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, 12.0);
// 	Player.AddGrazeCollision(0.0, -10.0, COLLISIONMODEL_CIRCLE, 5.0);
// 	Player.AddGrazeCollision(0.0, 22.0, COLLISIONMODEL_CIRCLE, 10.0);

	Player.bNowBomber = false;

	Player.bNowBomberPortrait = false;
	
	bPause = false;
	bPause_Query = false;
	bPause_Query_YesNo = false;
	iCurrentPauseMenuStatus = PAUSEMENU_RETURN;

	iCurrentStage = 1;	//1부터.

	Player.iGravity = 0;
	Player.iOldGravity = 0;
	Player.iCurrentGravityFrameTime = 0;

	bNowDisplayBGMName = false;
	iCurrentBGMDisplayTime = 0;

	pBoss = NULL;
	StartCurrentStage();
	bOnceExtended = false;

	//하이스코어 불러옴.
	LoadRecord();
	ClearRecord();
}

void InitPlayerBomber()
{
	switch (Player.iPlayerCharaType)
	{
	case PLAYERCHARA_REIMU:
		Player.bomber = 2;
		break;
	case PLAYERCHARA_MARISA:
		Player.bomber = 2;
		break;
	case PLAYERCHARA_REISEN:
		Player.bomber = 2;
		break;
	}
}

void PreTreat_Game()
{
	Player.bShift = false;
	Player.speed = Player.fConstNormalSpeed;
}

void Input_Game()
{
	if (GameInput.GetInput(QUIT))
	{
		//'QUIT' 명령시 -> 오브젝트 다 소멸시키고 강제종료.
		DeleteAllObjects();
		DeleteAllBarrage();
		DeleteAllChara();
		DeleteAllScripts();
		bRunning = false;
		return;
	}

	if (GameInput.GetPreviousInput(KEY_ESCAPE) == false && GameInput.GetInput(KEY_ESCAPE))
	{
		if (bPause == true && iGameState_Game_PauseType == PAUSE_GAMEOVERSCORE)
		{
			
		}
		else if (bPause == true && iGameState_Game_PauseType == PAUSE_GAMEOVERMENU)
		{
			if (bPause_Query == true)
			{

			}
			else
			{

			}
		}
		else
		{
			if (bPause == true)
			{
				if (bPause_Query == true)
				{
					bPause_Query = false;
					bPause_Query_YesNo = false;
					Sound_Cancel.Play(false, NULL, fVolume_SE);
				}
				else
				{
					bPause = false;
					Sound_Cancel.Play(false, NULL, fVolume_SE);
					ResumeMusicAllInOne();
				}
			}
			else
			{
				PauseMusicAllInOne();
				Sound_Pause.Play(false, NULL, fVolume_SE);
				bPause = true;
				iGameState_Game_PauseType = PAUSE_PAUSEMENU;
				iCurrentPauseMenuStatus = PAUSEMENU_RETURN;
			}

		}
	}

	auto MovePlayer = [&] (double IN_add_x, double IN_add_y)
	{
		if (Player.iCurrentStatus != PLAYERSTATUS_EXPLOSION)
		{
			Player.x = Player.x + IN_add_x * fTimeFactor;
			Player.y = Player.y + IN_add_y * fTimeFactor;

			if (GamePlayerShotVector.size() > 0)
			{
				std::vector<GamePlayerShot *>::iterator ShotIter = GamePlayerShotVector.begin();
				while ( true )
				{
					if (ShotIter == GamePlayerShotVector.end())
					{
						break;
					}

					if ( IN_add_y == 0.0)
					{
						if ( (*ShotIter)->bFollowToPlayerMoving == true && 
							(*ShotIter)->bUsingHomingTargetIter == false)
						{
							(*ShotIter)->x += (IN_add_x * fTimeFactor);
							(*ShotIter)->y += (IN_add_y * fTimeFactor);
						}
						else
						{
							int x;
							x = 1;
						}
					}


					ShotIter++;
				}
			}
			

			if (IN_add_x > 0.0)
			{
				Player.iOldGravity = Player.iGravity;
				if (Player.iOldGravity < 0)
				{
					Player.iGravity = 0;
					Player.iCurrentGravityFrameTime = 0;
				}
					
					if (Player.iGravity < PLAYER_MAX_GRAVITY)
					{
						if (Player.iCurrentGravityFrameTime >= PLAYER_GRAVITY_FRAMECHANGE_INTERVAL - 1)
						{
							Player.iGravity++;
							Player.iCurrentGravityFrameTime = 0;
						}
						else
						{
							Player.iCurrentGravityFrameTime++;
						}
					}
			}
			else if ( IN_add_x < 0.0)
			{
				Player.iOldGravity = Player.iGravity;
				if (Player.iOldGravity > 0)
				{
					Player.iGravity = 0;
					Player.iCurrentGravityFrameTime = 0;
				}

				if (Player.iGravity > -PLAYER_MAX_GRAVITY)
				{
					if (Player.iCurrentGravityFrameTime >= PLAYER_GRAVITY_FRAMECHANGE_INTERVAL - 1)
					{
						Player.iGravity--;
						Player.iCurrentGravityFrameTime = 0;
					}
					else
					{
						Player.iCurrentGravityFrameTime++;
					}
				}
			}


			if ( Player.x <= (double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH)
			{
				Player.x = (double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + 1.0;
			}
			else if (Player.x + (double)(Player.GetSprite()->GetWidth()) >= (double)UI_WINDOW_RIGHT_X)
			{
				Player.x = (double)UI_WINDOW_RIGHT_X - (double)(Player.GetSprite()->GetWidth()) - 1.0;
			}
			else if (Player.y <= (double)UI_WINDOW_TOP_Y + (double)UI_WINDOW_TOP_HEIGHT)
			{
				Player.y = (double)UI_WINDOW_TOP_Y + (double)UI_WINDOW_TOP_HEIGHT + 1.0;
			}
			else if (Player.y + (double)(Player.GetSprite()->GetHeight()) >= (double)UI_WINDOW_BOTTOM_Y)
			{
				Player.y = (double)UI_WINDOW_BOTTOM_Y - (double)(Player.GetSprite()->GetHeight()) - 1.0;
			}
		}
	};

	auto ExitGame = [&] ()
	{
		if ( (PAUSEMENU_STATUS)iCurrentPauseMenuStatus == PAUSEMENU_EXIT)
		{
			bPause_Query = false;
			bPause_Query_YesNo = false;
			GoToMainMenu();
		}
		else if ( (PAUSEMENU_STATUS)iCurrentPauseMenuStatus == PAUSEMENU_RETRY)
		{
			bPause_Query = false;
			bPause_Query_YesNo = false;
			GiveUpAndRetry();
		}
	};
	
	if (GameInput.GetInput(iKey_Slow))
	{
		if (bPause == false)
		{
			Player.bShift = true;
			Player.speed = Player.fConstSlowSpeed;
		}

	}

	bool bLeftOrRight = false;
	if (GameInput.GetInput(iKey_Left))
	{
		if (bPause == false)
		{
			MovePlayer(-Player.speed, 0);
			bLeftOrRight = true;
		}
		else		//bPause == true;
		{
			if (iGameState_Game_PauseType == PAUSE_GAMEOVERSCORE)
			{
				if (GameInput.GetPreviousInput(iKey_Left) == false)
				{
					ScoreBoard_Left();
				}
			}
		}
	}

	if (GameInput.GetInput(iKey_Right))
	{
		if (bPause == false)
		{
			MovePlayer(Player.speed, 0);
			bLeftOrRight = true;
		}
		else		//bPause == true;
		{
			if (iGameState_Game_PauseType == PAUSE_GAMEOVERSCORE)
			{
				if (GameInput.GetPreviousInput(iKey_Right) == false)
				{
					ScoreBoard_Right();
				}
			}
		}
	}

	if (bPause == false && bLeftOrRight == false)
	{
		Player.iOldGravity = Player.iGravity;
		Player.iGravity = 0;
		Player.iCurrentGravityFrameTime = 0;
	}

	if (GameInput.GetInput(iKey_Up))
	{
		if (bPause == false)
		{
			MovePlayer(0, -Player.speed);
		}
		else		//bPause == true;
		{
			if (iGameState_Game_PauseType == PAUSE_GAMEOVERSCORE)
			{
				if (GameInput.GetPreviousInput(iKey_Up) == false)
				{
					ScoreBoard_Up();
				}
			}
			else
			{
				if (bPause_Query == true)
				{
					if (GameInput.GetPreviousInput(iKey_Up) == false)
					{
						bPause_Query_YesNo = !bPause_Query_YesNo;
						Sound_Select.Play(false, NULL, fVolume_SE);
					}
				}
				else
				{
					if (iGameState_Game_PauseType == PAUSE_GAMEOVERMENU)
					{
						if (GameInput.GetPreviousInput(iKey_Up) == false)
						{
							if (iCurrentGameOverMenuStatus == GAMEOVERMENU_CONTINUE)
							{
								iCurrentGameOverMenuStatus = GAMEOVERMENU_RETRY;
							}
							else
							{
								iCurrentGameOverMenuStatus--;
							}
							Sound_Select.Play(false, NULL, fVolume_SE);
						}						
					}
					else if (iGameState_Game_PauseType == PAUSE_PAUSEMENU)		//pause-menu
					{
						if (GameInput.GetPreviousInput(iKey_Up) == false)
						{
							if (iCurrentPauseMenuStatus == PAUSEMENU_RETURN)
							{
								iCurrentPauseMenuStatus = PAUSEMENU_RETRY;
							}
							else
							{
								iCurrentPauseMenuStatus--;
							}
							Sound_Select.Play(false, NULL, fVolume_SE);
						}
					}
				}
			}

		}
	}
	if (GameInput.GetInput(iKey_Down))
	{
		if (bPause == false)
		{
			MovePlayer(0, Player.speed);
		}
		else		//bPause == true;
		{
			if (iGameState_Game_PauseType == PAUSE_GAMEOVERSCORE)
			{
				if (GameInput.GetPreviousInput(iKey_Down) == false)
				{
					ScoreBoard_Down();
				}
			}
			else
			{
				if (bPause_Query == true)
				{
					if (GameInput.GetPreviousInput(iKey_Down) == false)
					{
						bPause_Query_YesNo = !bPause_Query_YesNo;
						Sound_Select.Play(false, NULL, fVolume_SE);
					}
				}
				else
				{
					if (iGameState_Game_PauseType == PAUSE_GAMEOVERMENU)
					{
						if (GameInput.GetPreviousInput(iKey_Down) == false)
						{
							if (iCurrentGameOverMenuStatus == GAMEOVERMENU_RETRY)
							{
								iCurrentGameOverMenuStatus = GAMEOVERMENU_CONTINUE;
							}
							else
							{
								iCurrentGameOverMenuStatus++;
							}
							Sound_Select.Play(false, NULL, fVolume_SE);
						}
					}
					else if (iGameState_Game_PauseType == PAUSE_PAUSEMENU)		//pause-menu
					{
						if (GameInput.GetPreviousInput(iKey_Down) == false)
						{
							if (iCurrentPauseMenuStatus == PAUSEMENU_RETRY)
							{
								iCurrentPauseMenuStatus = PAUSEMENU_RETURN;
							}
							else
							{
								iCurrentPauseMenuStatus++;
							}
							Sound_Select.Play(false, NULL, fVolume_SE);
						}
					}
				}
			}
		}
	}

	auto Action_KeyZ = [&] (bool isKeyZ, bool isKeyReturn)
	{
		if (bPause == false)
		{
			if (iGameState_Game_Status == GAMESTATE_GAME_FIELD || iGameState_Game_Status == GAMESTATE_GAME_BOSS)
			{
				if (isKeyZ == true)
				{
					if (bOnceDescreteInput == false)
					{
						PlayerShotStart(&Player);
					}
					else
					{
						if (GameInput.GetPreviousInput(iKey_Attack) == false)
						{
							bOnceDescreteInput = false;
							PlayerShotStart(&Player);
						}
					}
					
				}
			}
			else if (iGameState_Game_Status == GAMESTATE_GAME_EVENT)
			{
				if ( (isKeyZ == false && isKeyReturn == false) || GameInput.GetPreviousInput(iKey_Attack) == false)
				{
					if (pBoss->bMovable == false)
					{
						if (NextScript() == false)
						{
							bOnceDescreteInput = true;
							StartSpell();

							iGameState_Game_Status = GAMESTATE_GAME_BOSS;
						}
					}
				}
			}
			else if (iGameState_Game_Status == GAMESTATE_GAME_EVENT_AFTER_BOSS)
			{
				if ((isKeyZ == false && isKeyReturn == false) || GameInput.GetPreviousInput(iKey_Attack) == false)
				{
					if (pBoss->bMovable == false)
					{
						if (NextScript() == false)
						{
							//어차피 이 상황에서의 적군이라곤 보스 하나뿐이다.
							MakeExplosion(pBoss, true);
							DeleteObject(pBoss);
							pBoss = NULL;
							GameEnemyVector.clear();
							InitResult();
						}
					}
				}
			}
			else if (iGameState_Game_Status == GAMESTATE_GAME_RESULT)
			{
				if (GameInput.GetPreviousInput(iKey_Attack) == false)
				{
					//next stage..
					NextStage();
				}
			}
		}
		else		//bPause == true;
		{
			if (iGameState_Game_PauseType == PAUSE_GAMEOVERSCORE)
			{
				if (GameInput.GetPreviousInput(iKey_Attack) == false)
				{	
					if (Input_ScoreBoard() == true)
					{
						iGameState_Game_PauseType = PAUSE_GAMEOVERMENU;
						iCurrentGameOverMenuStatus = GAMEOVERMENU_CONTINUE;
					}
				}
			}
			else
			{
				if (bPause_Query == false)
				{
					if (GameInput.GetPreviousInput(iKey_Attack) == false)
					{
						if (iGameState_Game_PauseType == PAUSE_GAMEOVERMENU)
						{
							//게임오버 메뉴에서의 명령은 YesNo를 물어보지 않습니다.
							if (iCurrentGameOverMenuStatus == GAMEOVERMENU_CONTINUE)
							{
								//컨티뉴
								Player.life = 2;
								InitPlayerBomber();
								Player.iScore = 0;
								Player.iSmallScoreItemCount = 0;
								Player.iBigScoreItemCount = 0;
								Player.bNoMiss = false;
								Player.ChangeState(PLAYERSTATUS_SHIELD);
								MovePlayerToPrimaryLocation(&Player);
								Music_GameOver.Stop();
								Music_GameOver.FreeSound();
								//StopMusicAllinOne();
								//FreeMusicAllInOne();
								if (bBGM_Use == true)
								{
									if (iCurrentStage == 1)
									{
										if (iGameState_Game_Status == GAMESTATE_GAME_FIELD)
										{
											//Music_Stage1Field.LoadSound("data.rom", "music/stage1_field.ogg", &MySoundManager);
											Music_Stage1Field.Resume();
											//ShowBGMName("동방요요몽 - Ancient Temple");
										}
										else if (iGameState_Game_Status == GAMESTATE_GAME_BOSS)
										{
											//Music_Stage1Boss.LoadSound("data.rom", "music/stage1_boss.ogg", &MySoundManager);
											Music_Stage1Boss.Resume();
											//ShowBGMName("히로아리 괴조를 쏘다 - Till When");
										}
									}
									else if (iCurrentStage == 2)
									{
										if (iGameState_Game_Status == GAMESTATE_GAME_FIELD)
										{
											//Music_Stage2Field.LoadSound("data.rom", "music/stage2_field.ogg", &MySoundManager);
											Music_Stage2Field.Resume();
											//ShowBGMName("Ultimate Truth");
										}
										else if (iGameState_Game_Status == GAMESTATE_GAME_BOSS)
										{
											if (pBoss->iCurrentSpell <= 4)
											{
												//Music_Stage2Boss.LoadSound("data.rom", "music/stage2_boss.ogg", &MySoundManager);
												Music_Stage2Boss.Resume();
												//ShowBGMName("Border of Life ～ The Black Cherry Blossom");
											}
											else
											{
												//Music_Stage2Boss_Final.LoadSound("data.rom", "music/stage2_boss_final.ogg", &MySoundManager);
												Music_Stage2Boss_Final.Resume();
												//ShowBGMName("Bordersense");
											}
										}
									}
								}

								bPause = false;
							}
							else if (iCurrentGameOverMenuStatus == GAMEOVERMENU_EXIT)
							{
								GoToMainMenu();
							}
							else if (iCurrentGameOverMenuStatus == GAMEOVERMENU_RETRY)
							{
								GiveUpAndRetry();
							}
							Sound_Okay.Play(false, NULL, fVolume_SE);
						}
						else if (iGameState_Game_PauseType == PAUSE_PAUSEMENU)
						{
							if ( (PAUSEMENU_STATUS)iCurrentPauseMenuStatus == PAUSEMENU_RETURN)
							{
								Sound_Cancel.Play(false, NULL, fVolume_SE);
								ResumeMusicAllInOne();
								bPause = false;
							}
							else
							{
								bPause_Query = true;
								bPause_Query_YesNo = false;
								Sound_Okay.Play(false, NULL, fVolume_SE);
							}
							
						}
					}
				}
				else		//bPause_Query == true;
				{
					if (iGameState_Game_PauseType == PAUSE_GAMEOVERSCORE)
					{

					}
					else if (iGameState_Game_PauseType == PAUSE_GAMEOVERMENU)
					{
						//처리
					}
					else if (iGameState_Game_PauseType == PAUSE_PAUSEMENU)
					{
						if (GameInput.GetPreviousInput(iKey_Attack) == false)
						{
							if (bPause_Query_YesNo == true)
							{
								Sound_Okay.Play(false, NULL, fVolume_SE);
								ExitGame();
							}
							else
							{
								Sound_Cancel.Play(false, NULL, fVolume_SE);
								bPause_Query_YesNo = false;
								bPause_Query = false;
							}
						}
					}
				}
			}
		}
	};

	if (GameInput.GetInput(iKey_Attack))
	{
		Action_KeyZ(true, false);
	}

	if (GameInput.GetInput(iKey_Bomber))
	{
		if (bPause == false)
		{
			if (iGameState_Game_Status == GAMESTATE_GAME_FIELD || iGameState_Game_Status == GAMESTATE_GAME_BOSS)
			{
				if (GameInput.GetPreviousInput(iKey_Bomber) == false)
				{
					PlayerBomberStart(&Player);
				}
			}
		}
		else	//bPause == true
		{
			if (iGameState_Game_PauseType == PAUSE_GAMEOVERSCORE)
			{
				if (GameInput.GetPreviousInput(iKey_Bomber) == false)
				{
					ScoreBoard_Cancel();
				}
			}
			else
			{
				if (bPause_Query == true)
				{
					bPause_Query_YesNo = false;
					bPause_Query = false;
					Sound_Cancel.Play(false, NULL, fVolume_SE);
				}
				else
				{
					if (GameInput.GetPreviousInput(iKey_Bomber) == false)
					{
						if (iGameState_Game_PauseType == PAUSE_GAMEOVERMENU)
						{

						}
						else if (iGameState_Game_PauseType == PAUSE_PAUSEMENU)
						{
							Sound_Cancel.Play(false, NULL, fVolume_SE);
							ResumeMusicAllInOne();
							bPause = false;
						}
					}
				}
			}
		}
	}
	
	if (GameInput.GetPreviousInput(KEY_RETURN) == false && GameInput.GetInput(KEY_RETURN))
	{
// 		if (bPause == false)
// 		{
// 
// 		}
// 		else
// 		{
// 			if (bPause_Query == true)
// 			{
// 				if (bPause_Query_YesNo == true)
// 				{
// 					if (iGameState_Game_PauseType == PAUSE_GAMEOVERMENU)
// 					{
// 
// 					}
// 					else if (iGameState_Game_PauseType == PAUSE_PAUSEMENU)
// 					{
// 						Sound_Okay.Play();
// 						ExitGame();
// 					}
// 				}
// 				else
// 				{
// 					bPause_Query = false;
// 					bPause_Query_YesNo = false;
// 				}
// 			}
// 		}

		Action_KeyZ(false, true);

	}

	if (GameInput.GetInput(iKey_Skip) == true)
	{
		if (iGameState_Game_Status == GAMESTATE_GAME_EVENT ||
			iGameState_Game_Status == GAMESTATE_GAME_EVENT_AFTER_BOSS)
		{
			Action_KeyZ(false, false);
		}
	}

}

void GameState_Game()
{
	if (iGameState_Game_Status == GAMESTATE_GAME_RESULT)
	{
		//리절트 출력
		DrawResult();
	}
	else
	{
		//예비 목록
		MakeEnemyFromPreVector();

		//스테이지 출력
		Stage.Draw();
		if (bPause == false)
		{
			Stage.Roll(fTimeFactor);
		}

		//위치계산, 충돌판정, 출력
		auto DestroyAll = [&]
		{
			DestroyAllEnemy();
			DestroyAllBullet();
			Player.bNowBomber = false;
			Player.bNowBomberPortrait = false;
			Player.bNowShooting = false;
		};

		if (iGameState_Game_Status == GAMESTATE_GAME_FIELD || iGameState_Game_Status == GAMESTATE_GAME_BOSS)
		{
			if (iGameState_Game_Status == GAMESTATE_GAME_FIELD)
			{
				if (bPause == false)
				{
					if (iCurrentStage == 1)
					{
						if (iGameFrame == 7500)
							//if (iGameFrame == 0)		//테스트
						{
							DestroyAll();
							InitStage1Boss();
							InitStage1Event();
						}
					}
					else if (iCurrentStage == 2)
					{
						if (iGameFrame == 5000)
						{
							DestroyAll();
							InitStage2Boss();
							InitStage2Event();
						}
					}
				}

			}
			else if (iGameState_Game_Status == GAMESTATE_GAME_BOSS)
			{
				//보스전 연산
				ProcessSpell();
			}

			//보스전 및 필드전 공통
			//플레이어 출력
			DrawBossEffect();
			ProcessEnemy();
			ProcessPlayer();
			ProcessPlayerShot();	
			ProcessBullet();
			ProcessExplosion();		
			ProcessItem();

			if (iGameState_Game_Status == GAMESTATE_GAME_BOSS)
			{
				DrawBossHP();

				if (pBoss->bMuteki == true)
				{
					DrawPortrait(pBoss->pSpellPortrait, UI_WINDOW_RIGHT_X - pBoss->pSpellPortrait->GetWidth() - 6, 
						UI_WINDOW_TOP_Y + (int)(UI_WINDOW_TOP_HEIGHT - 50.0), 
						&(pBoss->iCurrentMutekiTime), MUTEKITIME);

					double fX = UI_SPELL_SPELLNAME_X_RIGHT - PrintedSpellName.GetWidth();
					double fY = UI_SPELL_SPELLNAME_Y + 
						300.0 - (double)(pBoss->iCurrentMutekiTime) / (double)MUTEKITIME * 300.0;

					Spr_UI_EnemySpell.DrawSprite(UI_SPELL_SPELLNAME_X_RIGHT + 15 - Spr_UI_EnemySpell.GetWidth(), fY-10, 0);
					PrintedSpellName.DrawSprite( fX, fY, 0);
				}
				else
				{
					double fX = UI_SPELL_SPELLNAME_X_RIGHT - PrintedSpellName.GetWidth();
					double fY = UI_SPELL_SPELLNAME_Y;

					Spr_UI_EnemySpell.DrawSprite(UI_SPELL_SPELLNAME_X_RIGHT + 15 - Spr_UI_EnemySpell.GetWidth(), fY-10, 0);
					PrintedSpellName.DrawSprite(fX, fY, 0);
				}

				PrintedBossName.DrawSprite(UI_SPELL_CHARANAME_X, UI_SPELL_CHARANAME_Y, 0);

				Shooter_DrawText(&Spr_NumbersFont, std::to_string((_Longlong)(pBoss->iRemainTime)), UI_SPELL_COUNTDOWN_X, UI_SPELL_COUNTDOWN_Y);

			}

			if (Player.bNowBomberPortrait == true)
			{
				if (Player.iCurrentBomberPortraitTime >= BOMBERPORTRAITTIME)
				{
					Player.bNowBomberPortrait = false;
				}
				else
				{
					DrawPortrait(Player.pBomberPortrait, UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + 6, 
						UI_WINDOW_TOP_Y + (int)(UI_WINDOW_TOP_HEIGHT - 50.0), 
						&(Player.iCurrentBomberPortraitTime), BOMBERPORTRAITTIME);

					if (bPause == false)
					{
						Player.iCurrentBomberPortraitTime++;
					}
				}
			}
		}
		else if (iGameState_Game_Status == GAMESTATE_GAME_EVENT || iGameState_Game_Status == GAMESTATE_GAME_EVENT_AFTER_BOSS)
		{
			DrawBossEffect();
			ProcessEnemy();
			ProcessPlayer();
			ProcessPlayerShot();
			ProcessBullet();
			ProcessExplosion();
			ProcessItem();

			if (pBoss->bMovable == false)
			{
				DrawScript();
			}
		}
	}

	if (iGameState_Game_Status != GAMESTATE_GAME_RESULT)
	{
		if (iExtendAppearRemainTime > 0)
		{
			Spr_UI_Extend.DrawSpriteCenter( (UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + UI_WINDOW_RIGHT_X) / 2, UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT + 50, 0);
			iExtendAppearRemainTime--;
		}
	}

	Spr_UI_Window_Left.DrawSprite(UI_WINDOW_LEFT_X, UI_WINDOW_LEFT_Y, 0);
	Spr_UI_Window_Right.DrawSprite(UI_WINDOW_RIGHT_X, UI_WINDOW_RIGHT_Y, 0);
	Spr_UI_Window_Top.DrawSprite(UI_WINDOW_TOP_X, UI_WINDOW_TOP_Y, 0);
	Spr_UI_Window_Bottom.DrawSprite(UI_WINDOW_BOTTOM_X, UI_WINDOW_BOTTOM_Y, 0);
	
	if (iGameState_Game_Status == GAMESTATE_GAME_BOSS)
	{
		Spr_BossCursor.DrawSprite( (double)(pBoss->GetCenterX()) - (double)Spr_BossCursor.GetWidth() / 2.0 ,UI_WINDOW_BOTTOM_Y, 0);
	}

	Shooter_DrawText(&Spr_NumbersFont,
		std::to_string((_Longlong)(iHiScore)), UI_HISCORE_X, UI_HISCORE_Y, 9);

	Shooter_DrawText(&Spr_NumbersFont, std::to_string((_ULonglong)Player.iScore),
		UI_PLAYERSCORE_X, UI_PLAYERSCORE_Y, 9);

	Shooter_DrawText(&Spr_NumbersFont, std::to_string((_ULonglong)Player.iGrazeCount),
		UI_PLAYERGRAZE_X, UI_PLAYERGRAZE_Y, 9);

	for (int i = 0; i < Player.life; i++)
	{
		Spr_PlayerLife.DrawSprite(UI_PLAYERLIFE_X + (Spr_PlayerLife.GetWidth()) * i, UI_PLAYERLIFE_Y, 0);
	}

	for (int i = 0; i < Player.bomber; i++)
	{
		Spr_PlayerBomber.DrawSprite(UI_PLAYERBOMBER_X + (Spr_PlayerBomber.GetWidth()) * i, UI_PLAYERBOMBER_Y, 0);
	}

	if (bPause == true)
	{
		DarkScreen.DrawSprite(UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH, UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT, 0);
		
		if (bPause_Query == true)
		{
			Spr_UI_PauseMenu_New_Question.DrawSprite(UI_PAUSEMENU_QUESTION_X, UI_PAUSEMENU_QUESTION_Y, 0);
			
			ShooterSprite * pMenuYes = &Spr_UI_PauseMenu_New_Yes;
			ShooterSprite * pMenuNo = &Spr_UI_PauseMenu_New_No;

			if (bPause_Query_YesNo == true)
			{
				pMenuYes = &Spr_UI_PauseMenu_New_Yes_Selected;
			}
			else
			{
				pMenuNo = &Spr_UI_PauseMenu_New_No_Selected;
			}

			pMenuYes->DrawSprite(UI_PAUSEMENU_YES_X, UI_PAUSEMENU_YES_Y, 0);
			pMenuNo->DrawSprite(UI_PAUSEMENU_YES_X, UI_PAUSEMENU_YES_Y + pMenuYes->GetHeight() + 10, 0);
		}
		else
		{
			if (iGameState_Game_PauseType == PAUSE_PAUSEMENU)
			{
				Spr_UI_PauseMenu_New_Title.DrawSprite(UI_PAUSEMENU_TITLE_X, UI_PAUSEMENU_TITLE_Y, 0);

				ShooterSprite * pMenuReturn = &Spr_UI_PauseMenu_New_Return;
				ShooterSprite * pMenuExit = &Spr_UI_PauseMenu_New_Exit;
				ShooterSprite * pMenuRetry = &Spr_UI_PauseMenu_New_Retry;
				if (iCurrentPauseMenuStatus == PAUSEMENU_RETURN)
				{
					pMenuReturn = &Spr_UI_PauseMenu_New_Return_Selected;
				}
				else if (iCurrentPauseMenuStatus == PAUSEMENU_EXIT)
				{
					pMenuExit = &Spr_UI_PauseMenu_New_Exit_Selected;
				}
				else if (iCurrentPauseMenuStatus == PAUSEMENU_RETRY)
				{
					pMenuRetry = &Spr_UI_PauseMenu_New_Retry_Selected;
				}

				pMenuReturn->DrawSprite(UI_PAUSEMENU_ITEMS_X, UI_PAUSEMENU_ITEMS_Y, 0);
				pMenuExit->DrawSprite(UI_PAUSEMENU_ITEMS_X, UI_PAUSEMENU_ITEMS_Y + pMenuReturn->GetHeight() + 10, 0);
				pMenuRetry->DrawSprite(UI_PAUSEMENU_ITEMS_X, UI_PAUSEMENU_ITEMS_Y+ pMenuReturn->GetHeight() + 10 + pMenuExit->GetHeight() + 10, 0);


			}
			else if (iGameState_Game_PauseType == PAUSE_GAMEOVERSCORE)
			{
				DrawGameOver_Score();
			}
			else if (iGameState_Game_PauseType == PAUSE_GAMEOVERMENU)
			{
				//게임오버 메뉴화면도 포즈메뉴랑 구성이 거의 같기에 스프라이트나 상수 등을 포즈메뉴와 공유합니다.
				Spr_UI_GameOverMenu_New_Title.DrawSprite(UI_PAUSEMENU_TITLE_X, UI_PAUSEMENU_TITLE_Y, 0);
				
				ShooterSprite * pMenuContinue = &Spr_UI_GameOverMenu_New_Continue;
				ShooterSprite * pMenuExit = &Spr_UI_PauseMenu_New_Exit;
				ShooterSprite * pMenuRetry = &Spr_UI_PauseMenu_New_Retry;

				if (iCurrentGameOverMenuStatus == GAMEOVERMENU_CONTINUE)
				{
					pMenuContinue = &Spr_UI_GameOverMenu_New_Continue_Selected;
				}
				else if (iCurrentGameOverMenuStatus == GAMEOVERMENU_EXIT)
				{
					pMenuExit = &Spr_UI_PauseMenu_New_Exit_Selected;
				}
				else if (iCurrentGameOverMenuStatus == GAMEOVERMENU_RETRY)
				{
					pMenuRetry = &Spr_UI_PauseMenu_New_Retry_Selected;
				}

				pMenuContinue->DrawSprite(UI_PAUSEMENU_ITEMS_X, UI_PAUSEMENU_ITEMS_Y, 0);
				pMenuExit->DrawSprite(UI_PAUSEMENU_ITEMS_X, UI_PAUSEMENU_ITEMS_Y + pMenuContinue->GetHeight() + 10, 0);
				pMenuRetry->DrawSprite(UI_PAUSEMENU_ITEMS_X, UI_PAUSEMENU_ITEMS_Y+ pMenuRetry->GetHeight() + 10 + pMenuExit->GetHeight() + 10, 0);
				
			}
		}

	}

	//BGM 이름
	if (bNowDisplayBGMName == true)
	{
		if (iCurrentBGMDisplayTime >= DISPLAY_BGM_NAME_DURATION)
		{
			bNowDisplayBGMName = false;
			iCurrentBGMDisplayTime = 0;
		}
		else
		{
			double fX = UI_WINDOW_RIGHT_X - DISPLAY_BGM_NAME_SPAN_X - PrintedBGMName.GetWidth();
			double fY = UI_WINDOW_BOTTOM_Y - DISPLAY_BGM_NAME_SPAN_Y - PrintedBGMName.GetHeight();

			PrintedBGMName.DrawSprite( fX, fY, 0);

			iCurrentBGMDisplayTime++;
		}
	}

	if (bPause == false)
	{
		iGameFrame++;
	}
}

void GoToMainMenu()
{
	DeleteAllObjects();
	DeleteAllBarrage();
	DeleteAllChara();
	DeleteAllScripts();
	StopMusicAllinOne();
	FreeMusicAllInOne();
	Init_MainMenu();
}

void GiveUpAndRetry()
{
	DeleteAllObjects();
	DeleteAllBarrage();
	DeleteAllChara();
	DeleteAllScripts();
	InitGame(Player.iPlayerCharaType);
	bPause = false;
}

void DrawPortrait(ShooterSprite * IN_Sprite, double IN_x, double IN_y, int * IN_CurrentFrame, int IN_DesiredFrame)
{
	if (*IN_CurrentFrame < (int)((double)(IN_DesiredFrame) / 3.0))
	{
		IN_Sprite->SetAlpha(SDL_ALPHA_TRANSPARENT + (int)((double)(*IN_CurrentFrame) / (double)((IN_DesiredFrame) / 3.0) * 255.0));
	}
	else if (*IN_CurrentFrame > (int)((double)(IN_DesiredFrame) / 3.0 * 2.0))
	{
		IN_Sprite->SetAlpha(SDL_ALPHA_OPAQUE - (int)((double)( (*IN_CurrentFrame) - (int)((double) (IN_DesiredFrame) / 3.0 * 2.0)) * 255.0) / (double)( (IN_DesiredFrame) / 3.0));
	}

	IN_Sprite->DrawSprite
		(IN_x, IN_y + (double)(*IN_CurrentFrame)  / ((double)(IN_DesiredFrame) / 2.0) * 100.0,
		0);


//아래는 원본
// 	if (pBoss->iCurrentMutekiTime < (int)((double)MUTEKITIME / 3.0))
// 	{
// 		pBoss->pSpellPortrait->SetAlpha(SDL_ALPHA_TRANSPARENT + (int)((double)(pBoss->iCurrentMutekiTime) / (double)(MUTEKITIME / 3.0) * 255.0));
// 	}
// 	else if (pBoss->iCurrentMutekiTime > (int)((double)MUTEKITIME / 3.0 * 2.0))
// 	{
// 		pBoss->pSpellPortrait->SetAlpha(SDL_ALPHA_OPAQUE - (int)((double)(pBoss->iCurrentMutekiTime - (int)((double)MUTEKITIME / 3.0 * 2.0)) * 255.0) / (double)(MUTEKITIME / 3.0));
// 	}
// 
// 	pBoss->pSpellPortrait->DrawSprite
// 		(UI_WINDOW_RIGHT_X - pBoss->pSpellPortrait->GetWidth() - 6.0, 
// 		UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT - 50.0 + (double)(pBoss->iCurrentMutekiTime)  / ((double)MUTEKITIME / 2.0) * 100.0,
// 		0, &GameScreen);


}

void DrawBossHP()
{
	int iCount = 0;
	bool bCountStart = false;
	if (pBoss->SpellVector.size() > 0)
	{
		std::vector<BossSpell *>::iterator Iter = pBoss->SpellVector.begin();
		while ( true )
		{
			if (Iter == pBoss->SpellVector.end())
			{
				break;
			}

			if (bCountStart == false)
			{
				if ( (*Iter) == pBoss->SpellVector[pBoss->iCurrentSpell])
				{
					bCountStart = true;
				}
			}

			if (bCountStart == true && (*Iter)->bCountable == true)
			{
				iCount++;
			}

			Iter++;
		}
	}

	if (iCount > 0)
	{
		iCount--;
		for (int i = 0; i < iCount; i++)
		{
			Spr_SpellIndex.DrawSprite(UI_SPELLCOUNT_X + i * (Spr_SpellIndex.GetWidth() + 3), UI_SPELLCOUNT_Y, 0);
		}
	}
	

	int iWidth = (int)((double)(pBoss->iHP) / (double)(pBoss->iMaxHP) * (double)(Sur_BossHP.GetSurfaceWidth()));

	ShooterRect SrcRect(0,0,iWidth, Sur_BossHP.GetSurfaceHeight());
	ShooterRect DestRect(UI_BOSSHP_X, UI_BOSSHP_Y, iWidth, Sur_BossHP.GetSurfaceHeight());

	Sur_BossHP.DrawSurface(&SrcRect, &DestRect);
}

void NextStage()
{
	printf ("Next Stage..\n");
	iCurrentStage++;

	if (iCurrentStage > 2)
	{
		//게임 엔딩으로.....
		DeleteAllObjects();
		DeleteAllBarrage();
		DeleteAllChara();
		DeleteAllScripts();
		StopMusicAllinOne();
		InitGameCredits();
	}
	else
	{
		Sound_StageClear.Play(false, NULL, fVolume_SE);
		StartCurrentStage();
	}
}
void StartCurrentStage()
{
	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;
	Player.bShift = false;
	Player.bNowShooting = false;
	Player.iShotCurrentWaitTime = DEFAULT_PLAYER_SHOT_COOLTIME - 1;
	Player.iShotCurrentWaitSubTime = DEFAULT_PLAYER_SHOT_COOLTIME - 1;
	Player.bCoupleShot = false;
	Player.iShotCount = 0;

	Player.iSmallScoreItemCount = 0;
	Player.iBigScoreItemCount = 0;
	Player.bNoMiss = true;
	Player.InitGravity();

	DeleteAllObjects();

	Stage.x = UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH;
	Stage.y = UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT;
	Stage.speed = 0.5;

	switch (iCurrentStage)
	{
	case 1:
		Stage.SetSprite(&Spr_Stage1);
		Stage.iScrollType = SCROLLTYPE_DIAGONAL;
		Stage.fSpeedX = 0.0;
		Stage.fPosX = UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + 1;
		Stage.fPosY = UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT + 1;
		InitGameStage1();
		break;
	case 2:
		Stage.SetSprite(&Spr_Stage2);
		Stage.iScrollType = SCROLLTYPE_DIAGONAL;
		Stage.fSpeedX = 0.0;
		Stage.fPosX = UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + 1;
		Stage.fPosY = UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT + 1;
		InitGameStage2();	
		break;
	case 3:
		Stage.SetSprite(&Spr_Stage3);
		Stage.iScrollType = SCROLLTYPE_VERTICAL;
		break;
	case 4:
		Stage.SetSprite(&Spr_Stage4);
		Stage.iScrollType = SCROLLTYPE_VERTICAL;
		break;
	case 5:
		Stage.SetSprite(&Spr_Stage5);
		Stage.iScrollType = SCROLLTYPE_VERTICAL;
		break;
	case 6:
		Stage.SetSprite(&Spr_Stage6);
		Stage.iScrollType = SCROLLTYPE_VERTICAL;
		break;
	default:
		break;
	}

	iExtendAppearRemainTime = 0;

	iGameState_Game_Status = GAMESTATE_GAME_FIELD;

}

void StopMusicAllinOne()
{
	Music_MainMenu.Stop();
	Music_GameOver.Stop();
	Music_Stage1Field.Stop();
	Music_Stage1Boss.Stop();
	Music_Stage2Field.Stop();
	Music_Stage2Boss.Stop();
	Music_Stage2Boss_Final.Stop();
	Music_Credits.Stop();
}

void FreeMusicAllInOne()
{
	Music_MainMenu.FreeSound();
	Music_GameOver.FreeSound();
	Music_Stage1Field.FreeSound();
	Music_Stage1Boss.FreeSound();
	Music_Stage2Field.FreeSound();
	Music_Stage2Boss.FreeSound();
	Music_Stage2Boss_Final.FreeSound();
	Music_Credits.FreeSound();
}

void PauseMusicAllInOne()
{
	Music_MainMenu.Pause();
	Music_GameOver.Pause();
	Music_Stage1Field.Pause();
	Music_Stage1Boss.Pause();
	Music_Stage2Field.Pause();
	Music_Stage2Boss.Pause();
	Music_Stage2Boss_Final.Pause();
	Music_Credits.Pause();
}
void ResumeMusicAllInOne()
{
	Music_MainMenu.Resume();
	Music_GameOver.Resume();
	Music_Stage1Field.Resume();
	Music_Stage1Boss.Resume();
	Music_Stage2Field.Resume();
	Music_Stage2Boss.Resume();
	Music_Stage2Boss_Final.Resume();
	Music_Credits.Resume();
}

void ShowBGMName(std::string IN_BGMName)
{

	GameNormalSizeFont.PrintFont(&PrintedBGMName, std::string("BGM : " ) + IN_BGMName, 255, 255, 0, FONT_BLENDED);
	bNowDisplayBGMName = true;
	iCurrentBGMDisplayTime = 0;
}
#include "GameState_GameUtil.h"

bool FindCommand(GameEnemy * IN_Enemy, std::string IN_TypeString, int IN_Frame, std::vector<EnemyCommand *>::iterator * OUT_Iter)
{
	if (IN_Enemy->EnemyCommandVector.size() > 0)
	{
		for (std::vector<EnemyCommand *>::iterator Iter = IN_Enemy->EnemyCommandVector.begin(); Iter != IN_Enemy->EnemyCommandVector.end(); Iter++)
		{
			if ( (*Iter)->type == IN_TypeString && (*Iter)->Frame == IN_Frame)
			{
				*OUT_Iter = Iter;
				return true;
			}
		}
	} 

	return false;
}

void AddEnemy(std::string IN_Protocol)
{
	GameEnemy * pEnemy = new GameEnemy();
	//프로토콜 파싱
	ParseProtocol(pEnemy, IN_Protocol);

	//파싱이 끝나면 적군에 대한 세팅을 하고 예비 명단으로 넘긴다.
	std::vector<EnemyCommand *>::iterator OUT_Iter;
	
	//여기서 "Type"이란 프로토콜 안의 적군 유형을 나타내는 '타입'을 의미한다.
	if (FindCommand(pEnemy, "Type", 0, &OUT_Iter) == true)
	{
		pEnemy->iEnemyBulletType = (*OUT_Iter)->param0 + ENEMY_TYPE0;

		switch (pEnemy->iEnemyBulletType)
		{
		case ENEMY_TYPE0:
			pEnemy->SetSprite(&Spr_EnemyType0);
			pEnemy->bAutoNextFrame = true;
			pEnemy->bRotate = false;
			pEnemy->iFrameChangeInterval = DEFAULT_FRAMECHANGE_INTERVAL;
			//pEnemy->SetExtraSurface(&Spr_EnemyType0_A, &Spr_EnemyType0_B);
			pEnemy->AddCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType0.GetWidth() / 2));
			pEnemy->AddGrazeCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType0.GetWidth() / 2));
			break;
		case ENEMY_TYPE1:
			pEnemy->SetSprite(&Spr_EnemyType1);
			pEnemy->bAutoNextFrame = true;
			pEnemy->bRotate = false;
			pEnemy->iFrameChangeInterval = DEFAULT_FRAMECHANGE_INTERVAL;
			//pEnemy->SetExtraSurface(&Spr_EnemyType1_A, &Spr_EnemyType1_B);
			pEnemy->AddCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType1.GetWidth() / 2));
			pEnemy->AddGrazeCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType1.GetWidth() / 2));
			break;
		case ENEMY_TYPE2:
			pEnemy->SetSprite(&Spr_EnemyType2);
			pEnemy->bAutoNextFrame = true;
			pEnemy->bRotate = false;
			pEnemy->iFrameChangeInterval = DEFAULT_FRAMECHANGE_INTERVAL;
			//pEnemy->SetExtraSurface(&Spr_EnemyType2_A, &Spr_EnemyType2_B);
			pEnemy->AddCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType2.GetWidth() / 2));
			pEnemy->AddGrazeCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType2.GetWidth() / 2));
			break;
		case ENEMY_TYPE3:
			pEnemy->SetSprite(&Spr_EnemyType3);
			pEnemy->bAutoNextFrame = true;
			pEnemy->bRotate = false;
			pEnemy->iFrameChangeInterval = DEFAULT_FRAMECHANGE_INTERVAL;
			//pEnemy->SetExtraSurface(&Spr_EnemyType3_A, &Spr_EnemyType3_B);
			pEnemy->AddCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType3.GetWidth() / 2));
			pEnemy->AddGrazeCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType3.GetWidth() / 2));
			break;
		case ENEMY_TYPE4:
			pEnemy->SetSprite(&Spr_EnemyType4);
			pEnemy->bAutoNextFrame = true;
			pEnemy->bRotate = false;
			pEnemy->iFrameChangeInterval = DEFAULT_FRAMECHANGE_INTERVAL;
			//pEnemy->SetExtraSurface(&Spr_EnemyType4_A, &Spr_EnemyType4_B);
			pEnemy->AddCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType4.GetWidth() / 2));
			pEnemy->AddGrazeCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType4.GetWidth() / 2));
			break;
		case ENEMY_TYPE5:
			pEnemy->SetSprite(&Spr_EnemyType5);
			pEnemy->bAutoNextFrame = true;
			pEnemy->bRotate = false;
			pEnemy->iFrameChangeInterval = DEFAULT_FRAMECHANGE_INTERVAL;
			//pEnemy->SetExtraSurface(&Spr_EnemyType5_A, &Spr_EnemyType5_B);
			pEnemy->AddCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType5.GetWidth() / 2));
			pEnemy->AddGrazeCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_EnemyType5.GetWidth() / 2));
			break;
		}
	}
	
	PreEnemyBulletVector.push_back(pEnemy);
}

void ParseProtocol(GameEnemy * IN_Enemy, std::string IN_Protocol)
{	
	//Split 중 예외처리가 안되어있다.

	auto SplitString = [] (std::string * IN_SrcString, std::string IN_TokenString, std::string * IN_StrResult)
	{
		std::size_t FoundPosition = 0;
		FoundPosition = IN_SrcString->find(IN_TokenString);

		if (FoundPosition == std::string::npos)
		{
			*IN_StrResult = *IN_SrcString;
			*IN_SrcString = "";
		}
		else
		{
			*IN_StrResult = IN_SrcString->substr(0, FoundPosition);
			*IN_SrcString = IN_SrcString->substr(FoundPosition+1);
		}
	};
	
	std::string Protocol = IN_Protocol;
	std::string StrResult = "";
	while ( 1 )
	{
		SplitString(&Protocol, "@", &StrResult);
		
		if (StrResult == std::string(""))
		{

			break;
		}

		std::string StrSubResult;
		int iCount = 0;
		EnemyCommand * pNewEnemyCommand = new EnemyCommand;
		pNewEnemyCommand->Frame = 0;
		pNewEnemyCommand->type = "";
		pNewEnemyCommand->param0 = 0;
		pNewEnemyCommand->param1 = 0;
		pNewEnemyCommand->param2 = 0;
		pNewEnemyCommand->param3 = 0;
		pNewEnemyCommand->param4 = 0;
		pNewEnemyCommand->param5 = "";
		while ( 1 )
		{
			SplitString(&StrResult, ":", &StrSubResult);
			if (StrSubResult == std::string (""))
			{
				break;
			}

			if (iCount == 0)
			{
				pNewEnemyCommand->Frame = atoi(StrSubResult.c_str());
			}
			else if (iCount == 1)
			{
				pNewEnemyCommand->type = StrSubResult;
			}
			else if (iCount == 2)
			{
				pNewEnemyCommand->param0 = atoi(StrSubResult.c_str());
			}
			else if (iCount == 3)
			{
				pNewEnemyCommand->param1 = atoi(StrSubResult.c_str());
			}
			else if (iCount == 4)
			{
				pNewEnemyCommand->param2 = atoi(StrSubResult.c_str());
			}
			else if (iCount == 5)
			{
				pNewEnemyCommand->param3 = atoi(StrSubResult.c_str());
			}
			else if (iCount == 6)
			{
				pNewEnemyCommand->param4 = atoi(StrSubResult.c_str());
			}
			else if (iCount == 7)
			{
				pNewEnemyCommand->param5 = StrSubResult;
			}
			iCount++;
		}
		IN_Enemy->EnemyCommandVector.push_back(pNewEnemyCommand);
	}

}

void DeleteCommand(GameEnemy * IN_Enemy, std::vector<EnemyCommand *>::iterator IN_Iter)
{
	delete (*IN_Iter);
	IN_Enemy->EnemyCommandVector.erase(IN_Iter);
}

void MakeEnemyFromPreVector()
{
	if (PreEnemyBulletVector.size() > 0)
	{
		bool bEraseIter = false;
		std::vector<GameEnemy*>::iterator Iter = PreEnemyBulletVector.begin();
		while ( 1 )
		{

			if ((*Iter)->EnemyCommandVector.size() > 0)
			{
				std::vector<EnemyCommand*>::iterator SubIter = (*Iter)->EnemyCommandVector.begin();
				while ( 1 )
				{
					if ((*SubIter)->Frame == iGameFrame)
					{
						if ((*SubIter)->type == std::string("HP"))
						{
							(*Iter)->iMaxHP = (*SubIter)->param0;
							(*Iter)->iHP = (*Iter)->iMaxHP;
						}

						if ((*SubIter)->type == std::string("DropPowerupItem"))
						{
							(*Iter)->bDropPowerupItem = true;
						}

						if ((*SubIter)->type == std::string("Locate"))
						{
							(*Iter)->x = (double)((*SubIter)->param0) - (double)((*Iter)->GetSprite()->GetWidth()) / 2.0 + (double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH;
							(*Iter)->y = (double)((*SubIter)->param1) - (double)((*Iter)->GetSprite()->GetHeight()) / 2.0 + (double)UI_WINDOW_TOP_Y + (double)UI_WINDOW_TOP_HEIGHT;

							if (OutsideCheck(*Iter) == true)
							{
								(*Iter)->bPermitOutside = true;
							}
							
							//SubIter를 지운다.
							DeleteCommand(((GameEnemy*)(*Iter)), SubIter);

							//현재 자료를 EnemyBulletVector에 넣고.
							GameEnemyVector.push_back((*Iter));

							bEraseIter = true;	//후보 벡터에서의 자료는 지우도록 한다.

							//지운 이후는 무조건 break. 왜냐하면 현 SubIter의 자료를 EnemyBulletVector에 넣었으니깐.
							break;
							//
						}
					}
					if (SubIter == (*Iter)->EnemyCommandVector.end() - 1)
					{
						break;
					}
					else
					{
						SubIter++;
					}
				}
			}
			if (bEraseIter == true)
			{
				if (Iter == PreEnemyBulletVector.end() - 1)
				{
					PreEnemyBulletVector.erase(Iter);
					break;
				}
				else
				{
					Iter = PreEnemyBulletVector.erase(Iter);			//지우고 난 뒤, 지웠던 자료 그 다음으로 이동함.
					bEraseIter = false;
				}
			}
			else
			{
				if (Iter == PreEnemyBulletVector.end() - 1)
				{
					break;
				}
				else
				{
					Iter++;
				}
			}

		}
	}
}

bool ProcessPos(GameObject * IN_Object)
{

	auto move = [&]
	{
		double Radian = GetRadian( (IN_Object)->GetAngle());
		(IN_Object)->x = (IN_Object)->x + GetXbyCos(Radian, (IN_Object)->speed) * fTimeFactor;
		(IN_Object)->y = (IN_Object)->y + GetYbySin(Radian, (IN_Object)->speed) * fTimeFactor;
		(IN_Object)->speed = (IN_Object)->speed + (IN_Object)->acc;
		(IN_Object)->SetAngle((IN_Object)->GetAngle() + (IN_Object)->addangle);

		//printf ("%f, %d, %d\n", (IN_Object)->x, (int)((IN_Object)->x) << 8, ((int)((IN_Object)->x) << 8) >> 8);

// 
// 		double Radian = GetRadian( (IN_Object)->GetAngle());
// 
// 		int screen_x, screen_y;
// 		int scaled_x, scaled_y;
// 		int scaled_velocity_x, scaled_velocity_y;
// 		screen_x = IN_Object->x;
// 		scaled_x = (screen_x << 8);
// 		scaled_velocity_x = (int)(GetXbyCos(Radian, (IN_Object)->speed)) << 8;
// 
// 		scaled_x += scaled_velocity_x;
// 		screen_x = scaled_x >> 8;
// 		(IN_Object)->x = screen_x;
// 
// 		screen_y = (IN_Object->y);
// 		scaled_y = (screen_y << 8);
// 		scaled_velocity_y = (int)(GetYbySin(Radian, (IN_Object)->speed)) << 8;
// 
// 		scaled_y += scaled_velocity_y;
// 		screen_y = scaled_y >> 8;
// 		(IN_Object)->y = screen_y;
// 
// 		printf ("%d, %d\n", screen_x, screen_y);
// 
// 		(IN_Object)->speed = (IN_Object)->speed + (IN_Object)->acc;
// 		(IN_Object)->SetAngle((IN_Object)->GetAngle() + (IN_Object)->addangle);


	};

	if ((IN_Object)->bMovable == true)
	{
		//원래 GameEnemyBullet에서만 지원하는 기능을 전 GameObject로 확대시킴. 130126
//		if ((IN_Object)->iType == TYPE_ENEMY || (IN_Object)->iType == TYPE_BULLET || (IN_Object)->iType == TYPE_BOSS) 
		{
			if ( (IN_Object)->bFollow == true)
			{
				(IN_Object)->SetAngle(GetAngle( (IN_Object), &Player));
			}

			//GoTo 연산
// 			if ( ((IN_Object))->bGoTo == true
// 				&& GetDistance((IN_Object)->x, (IN_Object)->y, 
// 				((IN_Object))->fDest_X, ((IN_Object))->fDest_Y) 
// 				<= ((IN_Object)->speed) * fTimeFactor)
			
			//130216
			double fDestDist = ( sqrt( pow(GetXbyCos( IN_Object->GetAngle(), IN_Object->speed), 2.0) + 
				pow(GetYbySin( IN_Object->GetAngle(), IN_Object->speed), 2.0)));

			if (fDestDist < 1.0)
			{
				fDestDist = 1.0;
			}
			
			if ( ((IN_Object))->bGoTo == true
				&& GetDistance((IN_Object)->x, (IN_Object)->y, 
				((IN_Object))->fDest_X, ((IN_Object))->fDest_Y) 
				<= fDestDist)
			{
				(IN_Object)->x = ((IN_Object))->fDest_X;
				(IN_Object)->y = ((IN_Object))->fDest_Y;

				((IN_Object))->bGoTo = false;
				((IN_Object))->bMovable = false;
			}
			else if ( ((IN_Object))->bBezier == true )	//Bezier 연산
			{
				if ( ((IN_Object))->iCurrentBezierTime > ((IN_Object))->iBezierTime )
				{
					((IN_Object))->bBezier = false;
				}
				else
				{
					double fMu = (double)(((IN_Object))->iCurrentBezierTime) / (double)(((IN_Object))->iBezierTime);

					Bezier3(((IN_Object))->fBezier3_DeptX, ((IN_Object))->fBezier3_DeptY,
						((IN_Object))->fBezier3_PointX, ((IN_Object))->fBezier3_PointY,
						((IN_Object))->fBezier3_DestX, ((IN_Object))->fBezier3_DestY,
						fMu,
						&(((IN_Object))->x), &(((IN_Object))->y));

					(((IN_Object))->iCurrentBezierTime)++;

				}
			}
			else
			{
				move();
			}
		}
// 		else
// 		{
// 			move();
// 		}

		//오브젝트 이동 전 현재의 값을 기준으로 로테이트.
		if (IN_Object->iType == TYPE_BULLET)
		{
			if (  ((GameBullet*)(IN_Object))->iEnemyBulletType == BULLET_TYPE0 ||
				((GameBullet*)(IN_Object))->iEnemyBulletType == BULLET_TYPE1 ||
				((GameBullet*)(IN_Object))->iEnemyBulletType == BULLET_TYPE6 ||
				((GameBullet*)(IN_Object))->iEnemyBulletType == BULLET_TYPE9 ||
				((GameBullet*)(IN_Object))->iEnemyBulletType == BULLET_TYPE10 || 
				((GameBullet*)(IN_Object))->iEnemyBulletType == BULLET_TYPE11 || 
				((GameBullet*)(IN_Object))->iEnemyBulletType == BULLET_TYPE18 ) 
			{
				IN_Object->Rotate(true, 90.0, 1.0);
			}
			else
			{
				IN_Object->Rotate();
			}
		}
		else
		{
			(IN_Object)->Rotate();		//회전을 하든 안하든 일단 이 함수를 실행해야 한다.
		}
	}

	//범위를 벗어난 오브젝트는 지워버린다.
	if ( (IN_Object)->bPermitOutside == false)
	{
		if (OutsideCheck(IN_Object) == true)
		{
			//조건별로 제거
			if (IN_Object->iType == TYPE_ITEM)
			{
				if (IN_Object->y + IN_Object->GetSprite()->GetHeight() >= UI_WINDOW_BOTTOM_Y)
				{
					return false;
				}
			}
			else if (IN_Object->iType == TYPE_PLAYERSHOT)
			{
				if (((GamePlayerShot*)IN_Object)->iPlayerShotType == (PLAYERSHOT_TYPE)PLAYERSHOT_TYPE_REIMU_SUB_0)
				{
					if (IN_Object->y <= UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT - IN_Object->GetSprite()->GetHeight())
					{
						return false;
					}
				}
				else if (((GamePlayerShot*)IN_Object)->iPlayerShotType == (PLAYERSHOT_TYPE)PLAYERSHOT_TYPE_REIMU_BOMBER)
				{
					int * iInited = &(((GamePlayerShot*)IN_Object)->iPlayerShotParameters[0]);
					if ( *iInited == 1 && ((GamePlayerShot*)IN_Object)->bUsingHomingTargetIter == false)
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if (OutsideCheck(IN_Object) == false)
		{
			(IN_Object)->bPermitOutside = false;	
		}
	}

	return true;
}

void DrawBossEffect()
{
	//2스테이지일 경우
	if (iCurrentStage == 2)
	{
		if (iGameState_Game_Status == GAMESTATE_GAME_EVENT || iGameState_Game_Status == GAMESTATE_GAME_BOSS)
		{
			if (pBoss != NULL)
			{

				if (pBoss->iCurrentSpell < 2)
				{
					if (bPause == false)
					{
						Obj_Boss_Stage2_Border.Rotate();
					}
					Obj_Boss_Stage2_Border.x = pBoss->GetCenterX() - (double)(Obj_Boss_Stage2_Border.GetSprite()->GetWidth()) / 2.0;
					Obj_Boss_Stage2_Border.y = pBoss->GetCenterY() - (double)(Obj_Boss_Stage2_Border.GetSprite()->GetHeight()) / 2.0;
					Obj_Boss_Stage2_Border.Draw();					
				}
				else if (pBoss->iCurrentSpell <= 4)
				{
					Spr_Boss_Stage2_Hangonchou.DrawSpriteCenter( pBoss->GetCenterX(), pBoss->GetCenterY(), 0);
				}
			}
		}
	}
}

void ProcessPlayer()
{
	Player.Rotate();
	if (Player.iCurrentStatus == PLAYERSTATUS_SHIELD)
	{
		if (bPause == false)
		{
			if (Player.iCurrentShieldTime > PLAYER_SHIELD_DURATION)
			{
				Player.SetAlphaAll(SDL_ALPHA_OPAQUE);
				Player.ChangeState(PLAYERSTATUS_NONE);
			}
			else
			{
// 				Player.bShield = !Player.bShield;
// 				if (Player.bShield == true)
// 				{
// 					Player.GetSprite()->SetAlpha(SDL_ALPHA_TRANSPARENT );
// 				}
// 				else
// 				{
// 					Player.GetSprite()->SetAlpha(SDL_ALPHA_OPAQUE);
// 				}
				Player.SetAlphaAll(180);
				Player.iCurrentShieldTime++;
			}
		}

		Player.Draw(!bPause);
	}
	else if (Player.iCurrentStatus == PLAYERSTATUS_NONE)
	{
		static bool bOldBomberStatus = Player.bNowBomber;

		if (bOldBomberStatus != Player.bNowBomber)
		{
			if (Player.bNowBomber == true)
			{
				Player.SetAlphaAll(180);
			}
			else
			{
				Player.SetAlphaAll(SDL_ALPHA_OPAQUE);
			}
		}

		Player.Draw(!bPause);

		bOldBomberStatus = Player.bNowBomber;

	}
	else if (Player.iCurrentStatus == PLAYERSTATUS_EXPLOSION)
	{

	}

	if (Player.bShift == true && Player.iCurrentStatus != PLAYERSTATUS_EXPLOSION)
	{
		Player.pPlayerHeatBox->x = Player.GetCenterX() - (Player.pPlayerHeatBox->GetSprite()->GetWidth()) / 2.0;		
		Player.pPlayerHeatBox->y = Player.GetCenterY() - (Player.pPlayerHeatBox->GetSprite()->GetHeight()) / 2.0;
		//pPlayerHeatBox->SetAngle(pPlayerHeatBox->GetAngle() - 1.0);
		Player.pPlayerHeatBox->Rotate();
		Player.pPlayerHeatBox->Draw();
	}
}

void ProcessEnemy()
{
	if (GameEnemyVector.size() > 0)
	{
		std::vector<GameEnemy *>::iterator Iter = GameEnemyVector.begin();
		while ( 1 )
		{
			if (Iter == GameEnemyVector.end())
			{
				break;
			}

			if (bPause == false)
			{
				auto DeleteCurrentIter = [&] ()
				{
					if ( (*Iter)->bUsingHomingTargetIter == true)
					{
						(*((*Iter)->HomingTargetIter))->bEnemyAlive = false;
						(*Iter)->bUsingHomingTargetIter = false;
						CheckGarbageHomingTarget( & ((*Iter)->HomingTargetIter) );
					}
					delete (*Iter);
					Iter = GameEnemyVector.erase(Iter);
				};

				if (ProcessPos(*Iter) == false)
				{
					DeleteCurrentIter();
					continue;
				}

				/* TODO */

				//프로토콜
				bool bResult = false;
				std::vector<EnemyCommand*>::iterator Found_Iter;

				auto Find = [&] (std::string IN_TypeString)
				{
					bResult = FindCommand( (*Iter), IN_TypeString, iGameFrame, &Found_Iter);
				};

				Find("Angle");
				if (bResult == true)
				{
					(*Iter)->SetAngle((*Found_Iter)->param0);
					DeleteCommand((*Iter), Found_Iter);
				}	

				Find ("Follow");
				if (bResult == true)
				{
					(*Iter)->bGoTo = false;
					if ( (*Found_Iter)->param0 == 1)
					{
						(*Iter)->bFollow = true;
					}
					else if ( (*Found_Iter)->param0 == 0)
					{
						(*Iter)->bFollow = false;
					}
					DeleteCommand((*Iter), Found_Iter);

				}

				Find ("GoTo");
				if (bResult == true)
				{
					(*Iter)->bFollow = false;
					(*Iter)->bGoTo = true;
					(*Iter)->bMovable = true;			
					(*Iter)->fDest_X = (double)((*Found_Iter)->param0) - (double)((*Iter)->GetSprite()->GetWidth()) / 2.0 + (double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH;
					(*Iter)->fDest_Y = (double)((*Found_Iter)->param1) - (double)((*Iter)->GetSprite()->GetHeight()) / 2.0 + (double)UI_WINDOW_TOP_Y + (double)UI_WINDOW_TOP_HEIGHT;
					(*Iter)->SetAngle( GetAngle((*Iter)->x, (*Iter)->y, ((GameEnemy*)(*Iter))->fDest_X, ((GameEnemy*)(*Iter))->fDest_Y));
					DeleteCommand((*Iter), Found_Iter);
				}

				Find ("Bezier");
				if (bResult == true)
				{
					(*Iter)->bBezier = true;
					(*Iter)->iBezierTime = (*Found_Iter)->param0;
					(*Iter)->iCurrentBezierTime = 0;
					(*Iter)->fBezier3_DeptX = (*Iter)->x;
					(*Iter)->fBezier3_DeptY = (*Iter)->y;
					(*Iter)->fBezier3_PointX = (double)((*Found_Iter)->param1) - (double)((*Iter)->GetSprite()->GetWidth()) / 2.0 + (double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH;
					(*Iter)->fBezier3_PointY = (double)((*Found_Iter)->param2) - (double)((*Iter)->GetSprite()->GetHeight()) / 2.0 + (double)UI_WINDOW_TOP_Y + (double)UI_WINDOW_TOP_HEIGHT;
					(*Iter)->fBezier3_DestX = (double)((*Found_Iter)->param3) - (double)((*Iter)->GetSprite()->GetWidth()) / 2.0 + (double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH;
					(*Iter)->fBezier3_DestY = (double)((*Found_Iter)->param4) - (double)((*Iter)->GetSprite()->GetHeight()) / 2.0 + (double)UI_WINDOW_TOP_Y + (double)UI_WINDOW_TOP_HEIGHT;

				}

				Find("Speed");
				if (bResult == true)
				{
					(*Iter)->speed = (double)(*Found_Iter)->param0 / 10.0;
					DeleteCommand((*Iter), Found_Iter);
				}

				bResult = true;
				while (bResult == true)
				{
					Find("BarrageName");
					if (bResult == true)
					{
						std::vector<GameBarrage*>::iterator Found_Barrage;
						if (FindBarrage((*Found_Iter)->param5, &Found_Barrage) == true)
						{
							(*Iter)->pvBarrage.push_back(new GameBarrage( *Found_Barrage ) );

							(*(((*Iter))->pvBarrage.end() - 1))->pInit((*Iter), 
								(*Found_Iter)->param0, (*Found_Iter)->param1, (*Found_Iter)->param2, (*Found_Iter)->param3, 
								(*Found_Iter)->param4, (*((*Iter)->pvBarrage.end() - 1))->iBarrageParameters );
							DeleteCommand((*Iter), Found_Iter);
						}
						else
						{
							printf("Barrage Not Found : %s\n", (*Found_Iter)->param5.c_str());
							bResult = false;
						}
					}
				}

				Find("DetachBarrage");
				if (bResult == true)
				{
					(*Iter)->pvBarrage.clear();
					DeleteCommand((*Iter), Found_Iter);
				}
				//프로토콜 끝
				if ( (*Iter)->iType == TYPE_BOSS)		//←이걸 안넣었다고 오류가 나다니 말도 안돼.....
																	//안넣은 상태로 컴파일이 되는건 이해를 하겠는데 오류없이 돌아가는건 또 뭐야.
																	//계속 잘못된 메모리주소를 참조하다가 프로그램이 튕기는것같다.
																	//Win7에서는 메모리 찐빠가 나더라도 알아서 해결해주고 XP에서는 뱉어내는듯.
				{
					if ( ((GameBoss*)(*Iter))->iCurrentMutekiTime >= MUTEKITIME)
					{
						((GameBoss*)(*Iter))->iCurrentMutekiTime = 0;
						((GameBoss*)(*Iter))->bMuteki = false;
					}

					if (iGameState_Game_Status == GAMESTATE_GAME_BOSS)
					{
						if ( ((GameBoss*)(*Iter))->iCurrentSpell < ((GameBoss*)(*Iter))->SpellVector.size() )
						{
							if (( ((GameBoss*)(*Iter))->iRemainTime_FrameTime ) == 59)		//TOUHOU_FRAMERATE
							{
								( ((GameBoss*)(*Iter))->iRemainTime_FrameTime ) = 0;

								( ((GameBoss*)(*Iter))->iRemainTime) --;

								if (((GameBoss*)(*Iter))->iRemainTime <= 10)
								{
									Sound_Timeout.Play(false, NULL, fVolume_SE);
								}

								if (  ((GameBoss*)(*Iter))->iRemainTime == 0)
								{
									//if (SpellClear( ((GameBoss*)(*Iter)) ) == true)
									SpellClear( ((GameBoss*)(*Iter)) );
									{
										Iter = GameEnemyVector.begin();		//이상황에선 에너미 벡터에 보스만 남아있음.
										//break;
									}
								}
							}
							else
							{
								( ((GameBoss*)(*Iter))->iRemainTime_FrameTime ) ++;
							}
						}
					}

				}

				//탄막
				ProcessBarrage(*Iter);

				//구현중..
				if ( (*Iter)->bDecele == true && (*Iter)->bGoTo == true)
				{
					if (GetDistance((*Iter)->x, (*Iter)->y, (*Iter)->fDest_X, (*Iter)->fDest_Y) <= (*Iter)->fDeceleDist)
					{

					}
				}

				if ( (*Iter)->iCurrentState == ENEMYSTATE_HIT)
				{
					if ((*Iter)->iHitState_CurrentTime > ENEMYSTATE_HIT_DURATION)
					{
						//원상복귀
						(*Iter)->ChangeState(ENEMYSTATE_NONE);
					}
					else
					{
						((*Iter)->iHitState_CurrentTime)++;
						(*Iter)->GetSprite()->SetAlpha(100);
					}
				}
				else if ( (*Iter)->iCurrentState == ENEMYSTATE_NONE)
				{
					(*Iter)->GetSprite()->SetAlpha(SDL_ALPHA_OPAQUE);
				} 

				bool bNeedCheck = true;
				if ((*Iter)->iType == (GameObjectType)TYPE_BOSS)
				{
					if ( ((GameBoss*)(*Iter))->SpellVector.size() > 0)
					{
						if (((GameBoss*)(*Iter))->iCurrentSpell < ((GameBoss*)(*Iter))->SpellVector.size())
						{
							if ( ((GameBoss*)(*Iter))->SpellVector[((GameBoss*)(*Iter))->iCurrentSpell]->bInvincible == true)
							{
								bNeedCheck = false;
							}
						}
					}
				}

				if (bNeedCheck == true)
				{
					if (Player.iCurrentStatus == PLAYERSTATUS_NONE && CollisionCheck((*Iter), &Player) == true)
					{
						if ( (*Iter)->iType == TYPE_ENEMY
							|| !(iGameState_Game_Status == GAMESTATE_GAME_EVENT || iGameState_Game_Status == GAMESTATE_GAME_EVENT_AFTER_BOSS))
						{
							if (Player.bNowBomber == false)
							{
								KillPlayer();

								if ((*Iter)->iType != TYPE_BOSS)
								{
									MakeExplosion(*Iter, true);
									DeleteCurrentIter();
									continue;
								}
							}
							else
							{
								if ((*Iter)->iType == TYPE_ENEMY)
								{
									AddScore(BOMBER_CRASH_SCORE);
									MakeExplosion(*Iter, true);
									DeleteCurrentIter();
									continue;
								}
							}
						}
					}

					if ( (*Iter)->iCurrentGrazeTime >= GRAZECOOLTIME && Player.iCurrentStatus != PLAYERSTATUS_EXPLOSION)
					{
						if (GrazeCheck((*Iter), &Player) == true)
						{
							//						Sound_Graze.Play();						
							//						AddScore(GRAZESCORE);
							//						Player.iGrazeCount++;
							//Enemy는 그레이즈가 없다.
							//대신, 그레이즈 기능을 활용하여 폭탄 실행 중에 적군이 파괴되도록 하는 효과를 실행한다.

							if (Player.bNowBomber == true)
							{
								(*Iter)->iCurrentGrazeTime = 0;

								if ((*Iter)->iType == TYPE_ENEMY)
								{
									AddScore(BOMBER_CRASH_SCORE);
									MakeExplosion(*Iter, true);
									DeleteCurrentIter();
									continue;
								}
								else if ( (*Iter)->iType == TYPE_BOSS)
								{
									//TODO
									if ( (*Iter)->bMuteki == false)
									{
										PlayEnemyDamagedSound();
										(*Iter)->iHP = (*Iter)->iHP - 5;

										if ((*Iter)->iHP <= 0)
										{
											//if (SpellClear((GameBoss*)(*Iter)) == true)
											SpellClear((GameBoss*)(*Iter));
											{
												Iter = GameEnemyVector.begin();		//이상황에선 에너미 벡터에 보스만 남아있음.
												//break;
											}
										}
										else
										{
											(*Iter)->ChangeState(ENEMYSTATE_HIT);
											if ( (((GameBoss*)(*Iter))->iHP) / (((GameBoss*)(*Iter))->iMaxHP) < 0.1)
											{
												Sound_BossFatal.Play(false, NULL, fVolume_SE);
											}
											else
											{
												PlayEnemyDamagedSound();
											}
										}
									}
								}

							}
						}
					}
					else
					{
						((*Iter)->iCurrentGrazeTime)++;
					}
				}

				//적군 보스의 무적처리
				if ((*Iter)->iType == (GameObjectType)TYPE_BOSS)
				{
					(((GameBoss*)(*Iter))->iCurrentMutekiTime)++;
				}

				//자신의 위치를 호밍 타겟으로 찍어준다.
				if ( (*Iter)->bUsingHomingTargetIter == true)
				{
// 					(*((*Iter)->HomingTargetIter))->Target_X = (*Iter)->x + (double)((*Iter)->GetSprite()->GetWidth()) / 2.0;
// 					(*((*Iter)->HomingTargetIter))->Target_Y = (*Iter)->y + (double)((*Iter)->GetSprite()->GetHeight()) / 2.0;
					(*((*Iter)->HomingTargetIter))->Target_X = (*Iter)->x + 5.0;
					(*((*Iter)->HomingTargetIter))->Target_Y = (*Iter)->y + 5.0;
				}

			}

			//if (bPause == true)
			{
				(*Iter)->Rotate();
			}
			(*Iter)->Draw(!bPause);
			Iter++;

		}
	}
}

void ProcessBullet()
{
	if (GameBulletVector.size() > 0)
	{
		//Item Get Border line에 없을때
		std::vector<GameBullet *>::iterator Iter = GameBulletVector.begin();
		while ( 1 )
		{
			if (Iter == GameBulletVector.end())
			{
				break;
			}

			if (bPause == false)
			{
				auto DeleteCurrentIter = [&] ()
				{
					delete (*Iter);
					Iter = GameBulletVector.erase(Iter);
				};

				if (ProcessPos(*Iter) == false)
				{
					DeleteCurrentIter();
					continue;
				}

				ProcessBarrage(*Iter);

				if (Player.iCurrentStatus == PLAYERSTATUS_NONE && CollisionCheck((*Iter), &Player) == true)
				{
					if (Player.bNowBomber == false)
					{
						KillPlayer();
					}
					if ((*Iter)->bMuteki == false)
					{
						MakeExplosion(*Iter, false);
						DeleteCurrentIter();
						continue;			
					}
				}
				if ( (*Iter)->iCurrentGrazeTime >= GRAZECOOLTIME && Player.iCurrentStatus != PLAYERSTATUS_EXPLOSION)
				{
					if (GrazeCheck((*Iter), &Player) == true)
					{
						if (Player.bNowBomber == true && (*Iter)->bMuteki == false)
						{
							MakeExplosion(*Iter, false);
							DeleteCurrentIter();
							continue;			
						}
						else
						{
							Sound_Graze.Play(false, NULL, fVolume_SE);
							AddScore(GRAZESCORE);
							Player.iGrazeCount++;
						}
						(*Iter)->iCurrentGrazeTime = 0;
					}
				}
				else
				{
					((*Iter)->iCurrentGrazeTime)++;
				}

			}

			//if (bPause == true)
			{
				(*Iter)->Rotate();
			}
			(*Iter)->Draw(!bPause);
			Iter++;

		}
	}

}

void ProcessExplosion()
{
	if (GameExplosionVector.size() > 0)
	{
		std::vector<GameExplosion *>::iterator Iter = GameExplosionVector.begin();
		while ( 1 )
		{
			if (Iter == GameExplosionVector.end())
			{
				break;
			}

			if (bPause == false)
			{
				auto DeleteCurrentIter = [&] ()
				{
					delete (*Iter);
					Iter = GameExplosionVector.erase(Iter);
				};

				if (ProcessPos(*Iter) == false)
				{
					DeleteCurrentIter();
					continue;
				}

				/* TODO */
				if ((*Iter)->bStarted == false && (*Iter)->iCurrentFrame == 1)
				{
					(*Iter)->bStarted = true;
				}
				else if ( (*Iter)->bStarted == true && 
					((*Iter))->iCurrentFrame == (*Iter)->GetSprite()->GetMaxFrame() -1 &&
					((*Iter))->iCurrentFrameTime >= (*Iter)->iFrameChangeInterval - 1)
				{
					if (((GameExplosion*)(*Iter))->bPlayerExplosion == true)
					{
						if (Player.life < 0)
						{
							InitGameOver_Score();
						}
						else
						{
							Player.ChangeState(PLAYERSTATUS_SHIELD);
							MovePlayerToPrimaryLocation(&Player);
							Player.iGravity = 0;
							Player.iOldGravity = 0;
							Player.iCurrentGravityFrameTime = 0;
						}
					}

					DeleteCurrentIter();
					continue;		
				}
			}

			//if (bPause == true)
			{
				(*Iter)->Rotate();
			}
			(*Iter)->Draw(!bPause);
			Iter++;
		}
	}
}

void ProcessPlayerShot()
{

// 	std::vector<int> ScoreAdditionVector;
// 	ScoreAdditionVector.clear();


	auto Shooting = [&]
	{
		//AddPlayerShot => 함수, AddNewPlayerShot => 람다 함수.
		auto AddNewPlayerShot = [&] (double IN_Far_X, double IN_Far_Y, double IN_angle)
		{
			AddPlayerShot(Player.GetPlayerShot(0), IN_Far_X, IN_Far_Y, IN_angle);
		};

		auto Reimu_InitSubShot = [&] (double IN_Far_X, double IN_Angle)
		{
			AddPlayerShot(Player.GetPlayerShot(1), IN_Far_X, 0.0, IN_Angle, (int) (IN_Angle * 10.0), 50, 1, 300, 1);		//중복타겟 허용, 감지각도 30도 이내
		};

		auto Reimu_RapierShot = [&] (double IN_Far_X, double IN_Angle)
		{
			AddPlayerShot(Player.GetPlayerShot(2), IN_Far_X, 0.0, IN_Angle, (int) (IN_Angle * 10.0), 50, 1, 300, 1);		//중복타겟 허용, 감지각도 30도 이내
		};

		auto Marisa_RapierShot = [&] (double IN_Far_X)
		{
			AddPlayerShot(Player.GetPlayerShot(1), IN_Far_X, 0.0, 90.0);
		};

		switch (Player.iPlayerCharaType)
		{
		case PLAYERCHARA_REIMU:
			if (Player.bCoupleShot == true)
			{
				if (Player.iShotCount == 0)
				{
					Reimu_RapierShot(0.0, 90.0);
				}
			}
			else
			{
				AddNewPlayerShot(0.0, 0.0, 90.0);
				//if (Player.iShotCount == 0)
				{
					Reimu_InitSubShot(-5.0, 160.0);
					Reimu_InitSubShot(5.0, 20.0);
				}
			}
			break;
		case PLAYERCHARA_MARISA:
			if (Player.bCoupleShot == true)
			{
				Marisa_RapierShot(0.0);
			}
			else
			{
				AddNewPlayerShot(-10.0, 0.0, 95.0);
				AddNewPlayerShot(-5.0, 0.0, 92.5);
				AddNewPlayerShot(0.0, 0.0, 90.0);
				AddNewPlayerShot(+5.0, 0.0, 87.5);
				AddNewPlayerShot(+10.0, 0.0, 85.0);
			}
			break;
		case PLAYERCHARA_REISEN:
			if (Player.bCoupleShot == true)
			{
				AddNewPlayerShot(+5, (Player.GetSprite()->GetHeight() / 4), 90.0);		
				AddNewPlayerShot(0.0, 0.0, 90.0);
				AddNewPlayerShot(-5, (Player.GetSprite()->GetHeight() / 4), 90.0);

				AddNewPlayerShot(+2.5, (Player.GetSprite()->GetHeight() / 4), 90.0);		
				AddNewPlayerShot(-2.5, (Player.GetSprite()->GetHeight() / 4), 90.0);
			}
			else
			{
				AddNewPlayerShot(0.0, 0.0, 90.0);
				AddNewPlayerShot(+5.0, (Player.GetSprite()->GetHeight() / 4), 86.0);	
				AddNewPlayerShot(-5.0, (Player.GetSprite()->GetHeight() / 4), 94.0);

 				AddNewPlayerShot(+2.5, (Player.GetSprite()->GetHeight() / 4), 88.0);	
 				AddNewPlayerShot(-2.5, (Player.GetSprite()->GetHeight() / 4), 92.0);
			}
			break;
		}

	};

	if (bPause == false)
	{
		if (Player.bNowBomber == true)
		{
			Player.pPlayerBomber(&Player);
		}
		else
		{
			if (Player.bNowShooting == true)
			{
//				if (Player.iShotCurrentWaitSubTime >= (double)(Player.GetPlayerShot()->GetSprite()->GetHeight()) / ((Player.GetPlayerShot()->speed)) )
				if (Player.iShotCurrentWaitSubTime >= Player.iPlayerShotSubCoolTime)
				{
					Sound_PlayerShot.Play(false, NULL, fVolume_SE);
					Shooting();

					Player.iShotCount++;
					Player.iShotCurrentWaitSubTime = 0;

					//5발을 다 쐈을 경우 종료.
					if (Player.iShotCount >= Player.iPlayerShotQuantity)
					{
						Player.iShotCount = 0;
						Player.iShotCurrentWaitTime = 0;
						Player.bNowShooting = false;
					}

				}
				else
				{
					Player.iShotCurrentWaitSubTime++;
				}
			}
			else
			{
				Player.iShotCurrentWaitTime++;
			}
		}
	}


	if (GamePlayerShotVector.size() > 0)
	{
		bool bBossBattleEnd = false;

		std::vector<GamePlayerShot *>::iterator Iter = GamePlayerShotVector.begin();
		while ( 1 )
		{

			if (Iter == GamePlayerShotVector.end())
			{
				break;
			}

			if (bPause == false)
			{
				auto DeleteCurrentIter = [&] ()
				{
					if ( ((*Iter)->bUsingHomingTargetIter) == true)
					{
						((*((*Iter)->HomingTargetIter))->iPlayerShotReferenceCount)--;
						(*Iter)->bUsingHomingTargetIter = false;
						CheckGarbageHomingTarget( & ((*Iter)->HomingTargetIter) );
					}
					delete (*Iter);
					Iter = GamePlayerShotVector.erase(Iter);
				};

				if (ProcessPos(*Iter) == false)
				{
					DeleteCurrentIter();
					continue;
				}

				/* TODO */

				if ( (*Iter)->pPlayerShotFunc != NULL)
				{ 
					(*Iter)->pPlayerShotFunc(*Iter);
					if ( (*Iter)->bSuicide == true)
					{
						DeleteCurrentIter();
						continue;
					}
				}

				bool bDeleteShot = false;
				if (GameEnemyVector.size() > 0)
				{
					std::vector<GameEnemy *>::iterator EnemyIter = GameEnemyVector.begin(); 
					while ( 1 )
					{

						if (EnemyIter == GameEnemyVector.end())
						{
							break;
						}

						bool bEnemyDeleted = false;
						bool bNeedCheck = true;

						if ((*EnemyIter)->iType == (GameObjectType)TYPE_BOSS)
						{
							if ( ((GameBoss*)(*EnemyIter))->SpellVector.size() > 0)
							{
								if (((GameBoss*)(*EnemyIter))->iCurrentSpell < ((GameBoss*)(*EnemyIter))->SpellVector.size())
								{
									if ( ((GameBoss*)(*EnemyIter))->SpellVector[((GameBoss*)(*EnemyIter))->iCurrentSpell]->bInvincible == true)
									{
										bNeedCheck = false;
									}
								}
							}
						}

						if (bNeedCheck == true && OutsideCheck(*EnemyIter) == false && CollisionCheck((*Iter), (*EnemyIter)) == true)
						{
							//필드전 및 보스전에서만 데미지 및 적군제거 처리를 한다.
							//그 외 모드에서는 플레이어 샷 제거만 함.
							PlayEnemyDamagedSound();
							//ScoreAdditionVector.push_back(10);		//10점 추가
							if (iGameState_Game_Status == GAMESTATE_GAME_FIELD || iGameState_Game_Status == GAMESTATE_GAME_BOSS)
							{	
								if ( (*EnemyIter)->iType == (GameObjectType)TYPE_BOSS)
								{
									if ( ((GameBoss*)(*EnemyIter))->bMuteki == false
										&& iGameState_Game_Status == GAMESTATE_GAME_BOSS)
									{
										if ( (*Iter)->bIsBomber == true)
										{
											(*EnemyIter)->iHP = (*EnemyIter)->iHP - ((*Iter)->iDamageToBoss);
										}
										else
										{
											(*EnemyIter)->iHP = ((*EnemyIter)->iHP) - ((*Iter)->iDamage);
										}
									}
								}
								else
								{
									if ( (*EnemyIter)->bMuteki == false)
									{
										(*EnemyIter)->iHP = ((*EnemyIter)->iHP) - ((*Iter)->iDamage);
									}
								}
							
			
								//HP고갈인경우 적군 제거
								if ((*EnemyIter)->iHP <= 0)
								{
									AddScore(((*EnemyIter)->iMaxHP) * 100);

									//파워업 아이템 생성
									if ((*EnemyIter)->bDropPowerupItem == true)
									{
										GameItem * pItem = new GameItem(&Spr_PowerupItem_Big, ITEM_POWERUP_BIG, DEFAULT_FRAMECHANGE_INTERVAL);
										pItem->x = (*EnemyIter)->GetCenterX() - (double)Spr_PowerupItem_Big.GetWidth() / (double)2.0;
										pItem->y = (*EnemyIter)->GetCenterY() - (double)Spr_PowerupItem_Big.GetHeight() / (double)2.0;
										pItem->SetAngle(270.0);
										pItem->speed = 1.5;
										//pItem->acc = 0.5;
										pItem->FastSpeed = 7.0;
										GameItemVector.push_back(pItem);
									}

									//점수 아이템 생성
									int iItemQuantity = 4;

									int iScore = ((*EnemyIter)->iMaxHP) * 10;
									if ( (*EnemyIter)->iEnemyBulletType == ENEMY_BOSS)
									{
										iItemQuantity = 20;

										int iRandRange = 70;
										int iRandX = (*EnemyIter)->GetRect()->Get_W() + (iRandRange * 2) - Spr_ScoreItem_Small.GetWidth();
										int iRandY = (*EnemyIter)->GetRect()->Get_H() + (iRandRange * 2) - Spr_ScoreItem_Small.GetHeight();

										for (int i = 0; i < iItemQuantity; i++)
										{
											GameItem * pItem =
												new GameItem(&Spr_ScoreItem_Big, ITEM_SCORE_BIG, DEFAULT_FRAMECHANGE_INTERVAL);
												
											pItem->x = (*EnemyIter)->GetCenterX() - (pItem->GetSprite()->GetWidth()) / 2.0;
											pItem->y = (*EnemyIter)->GetCenterY() - (pItem->GetSprite()->GetHeight()) / 2.0;
											pItem->fDest_X = pItem->x - (double)(iRandRange) + (double)(rand()%iRandX);
											pItem->fDest_Y = pItem->y - (double)(iRandRange) + (double)(rand()%iRandY);
											pItem->SetAngle(GetAngle(pItem->x, pItem->y, pItem->fDest_X, pItem->fDest_Y));
											pItem->speed = 1.5 + ((double)(rand()%15))/(double)15.0;
											//pItem->acc = 0.5;
											pItem->FastSpeed = 7.0;											
											pItem->bGoTo = true;
											GameItemVector.push_back(pItem);
										}

									}
									else
									{
										for (int i = 0; i < iItemQuantity; i++)
										{
											GameItem * pItem =
												new GameItem(&Spr_ScoreItem_Small, ITEM_SCORE_SMALL, DEFAULT_FRAMECHANGE_INTERVAL);

											pItem->x = (*EnemyIter)->GetCenterX() - (pItem->GetSprite()->GetWidth()) / 2.0;
											pItem->y = (*EnemyIter)->GetCenterY() - (pItem->GetSprite()->GetHeight()) / 2.0;
											pItem->SetAngle(90.0);
											pItem->speed = 1.5 + ((double)(rand()%15))/(double)15.0;
											//pItem->acc = 0.5;
											pItem->FastSpeed = 7.0;
											pItem->fDest_X = pItem->x;
											pItem->fDest_Y = pItem->y - 50.0 - (double)(rand() % 100);
											pItem->bGoTo = true;
											pItem->bPermitOutside = true;
											GameItemVector.push_back(pItem);
										}
									}

									if ( !((*EnemyIter)->iEnemyBulletType == ENEMY_BOSS) )
									{
										if ( (*Iter)->bIsBomber == false)
										{
											PlayEnemyDeadSound();
										}
										MakeExplosion(*EnemyIter, true);
										DeleteObject(*EnemyIter);		//정적 캐스팅은 잘 해야된다..... 안하면 엉뚱한데서 힙 어쩌고 오류가 나온다. 그러면 버그고치기 힘들어진다		
										//ScoreAdditionVector.push_back(100);
										EnemyIter = GameEnemyVector.erase(EnemyIter);
										bEnemyDeleted = true;
									}
									else
									{
										bBossBattleEnd = SpellClear((GameBoss*)(*EnemyIter));
										break;		//SpellClear 함수 내에서 모든 오브젝트들이 소멸되었으므로 이터레이터가 무효화되었다.
									}

								}
								else
								{
									(*EnemyIter)->ChangeState(ENEMYSTATE_HIT);
								}
							}

							if ( (*Iter)->bMuteki == false)
							{
								bDeleteShot = true;
							}
						}

						//if (EnemyIter == GameEnemyVector.end() - 1)
						//{
						//	break;
						//}

						//if (bEnemyDeleted == false)
						//{
						//	EnemyIter++;
						//}
						//else
						//{
						//	
						//}

						if (bBossBattleEnd == false)
						{
							if (bEnemyDeleted == false)
							{
								EnemyIter++;
							}
						}
						else
						{
							break;
						}
					
					}
				}

				//보스전 종료 시 이미 모든 오브젝트들이 소멸되어 이터레이터도 무효화되었으므로 루프 종료
				if (bBossBattleEnd == true)
				{
					break;
				}

				//폭탄일 경우 적 총알도 지움.
				if ( (*Iter)->bIsBomber == true)
				{

					if (GameBulletVector.size() > 0)
					{
						
						std::vector<GameBullet *>::iterator BulletIter = GameBulletVector.begin(); 
						while ( 1 )
						{

							if (BulletIter == GameBulletVector.end())
							{
								break;
							}

							bool bBulletDeleted = false;

							if ( OutsideCheck(*BulletIter) == false && CollisionCheck((*Iter), (*BulletIter)) == true)
							{
								if ( (*BulletIter)->bMuteki == false)
								{
									//PlayEnemyDeadSound();
									//ScoreAdditionVector.push_back(10);
									MakeExplosion(*BulletIter, false);
									DeleteObject(*BulletIter);		
									BulletIter = GameBulletVector.erase(BulletIter);
									bBulletDeleted = true;
								}

								//사운드 필요!!
								if ( (*Iter)->bMuteki == false && (*Iter)->bPassBullet == false)
								{
									bDeleteShot = true;
								}
							}


							if (bBulletDeleted == false)
							{
								BulletIter++;
							}

						}
					}
				}
				
			
				//마무리
				if (bDeleteShot == false)
				{
			
				}
				else
				{
					
// 					//플레이어 점수 추가
// 					for ( std::vector<int>::iterator ScoreIter = ScoreAdditionVector.begin(); ScoreIter != ScoreAdditionVector.end(); ScoreIter++)
// 					{
// 						Player.iScore += *ScoreIter;
// 					}
					
					//플레이어 샷 제거
					MakeExplosion(*Iter, false);
					DeleteCurrentIter();
					continue;				
				}
			}

			if (bPause == false)
			{
				(*Iter)->Rotate(false, 0, 0);
			}

			(*Iter)->Draw(!bPause);
			Iter++;
		}
	}
}

void ProcessItem()
{
	if (GameItemVector.size() > 0)
	{
		std::vector<GameItem *>::iterator Iter = GameItemVector.begin();
		while ( 1 )
		{
			if (Iter == GameItemVector.end())
			{
				break;
			}

			if (bPause == false)
			{
				auto DeleteCurrentIter = [&] ()
				{
					delete (*Iter);
					Iter = GameItemVector.erase(Iter);
				};

				if ( (*Iter)->bMovable == false)
				{
					 (*Iter)->bMovable = true;
					 (*Iter)->SetAngle(270.0);
				}

				if ( (*Iter)->bGoTo == false)
				{
					if ( (*Iter)->bAutoFollow == true)
					{
						(*Iter)->bMovable = true;
						(*Iter)->bFollow = true;
					}
					else if ( (Player.iCurrentStatus != PLAYERSTATUS_EXPLOSION && Player.y <= ITEM_GET_BORDER_LINE_Y) || Player.bNowBomber == true )
					{
						(*Iter)->bMovable = true;
						(*Iter)->bFollow = true;
 						if ( (*Iter)->speed < (*Iter)->FastSpeed)
 						{
 							(*Iter)->OldSpeed = (*Iter)->speed;
 							(*Iter)->speed = (*Iter)->FastSpeed;
 						}
					}
					else
					{
						if  (Player.iCurrentStatus == PLAYERSTATUS_EXPLOSION)
						{
							(*Iter)->bFollow = false;
							(*Iter)->SetAngle(270.0);
							if ( (*Iter)->OldSpeed != 0.0)
							{
								(*Iter)->speed = (*Iter)->OldSpeed;
							}
						}						
					}
				}

				if (ProcessPos(*Iter) == false)
				{
					DeleteCurrentIter();
					continue;
				}

				/* TODO */
				//아이템<->플레이어간 충돌체크는 피탄판정체크가 아닌 전 범위 체크이다.
				if (Player.iCurrentStatus != PLAYERSTATUS_EXPLOSION &&
					CollisionCheck(*Iter, &Player) == true)
				{
					switch ( (*Iter)->iItemType)
					{
					case ITEM_BOMBER:
						Sound_Item.Play(false, NULL, fVolume_SE);
						Player.bomber++;
						break;
					case ITEM_EXTEND:
						Sound_Extend.Play(false, NULL, fVolume_SE);
						Player.life++;
						break;
					case ITEM_POWERUP_BIG:
						//일단 보류
						break;
					case ITEM_POWERUP_SMALL:
						//일단 보류
						break;
					case ITEM_SCORE_BIG:
						Sound_Item.Play(false, NULL, fVolume_SE);
						Player.iScore += 1000;
						Player.iBigScoreItemCount++;
						break;
					case ITEM_SCORE_SMALL:
						Sound_Item.Play(false, NULL, fVolume_SE);
						Player.iScore += 100;	
						Player.iSmallScoreItemCount++;
						break;
					}
					DeleteCurrentIter();
					continue;
				}
			}

// 			if (bPause == true)
// 			{
// 				(*Iter)->Rotate();
// 			}
			(*Iter)->Draw(!bPause);
			Iter++;
		}
	}

}

//이렇게 쓰시오.
//if (GameEnemyVector.size() > 0)
//{
//	std::vector<GameEnemy *>::iterator Iter = GameEnemyVector.begin();
//	while ( 1 )
//	{
//		auto DeleteCurrentIter = [&] ()
//		{
//			delete (*Iter);
//			Iter = GameEnemyVector.erase(Iter);
//		};

//		if (Iter == GameEnemyVector.end())
//		{
//			break;
//		}

//		if (ProcessPos(*Iter) == false)
//		{
//			DeleteCurrentIter();
//			continue;
//		}

//		/* TODO */

//		(*Iter)->Draw(&GameScreen);
//		Iter++;
//	}
//}

void ProcessBarrage(GameEnemyBullet * IN_Object)
{

	if ( IN_Object->pvBarrage.size() > 0)
	{
		for (std::vector<GameBarrage*>::iterator BrIter = IN_Object->pvBarrage.begin(); BrIter != IN_Object->pvBarrage.end(); BrIter++)
		{

			(*BrIter)->pFunction (IN_Object, (*BrIter)->iBarrageParameters);	
		}
	}

}

void StartSpell()
{
	Sound_SpellCard.Play(false, NULL, fVolume_SE);

	if (iCurrentStage == 2 && pBoss->iCurrentSpell == 5)
	{
		StopMusicAllinOne();
		FreeMusicAllInOne();
		if (bBGM_Use == true)
		{
			Music_Stage2Boss_Final.LoadSound("data.rom", "music/stage2_boss_final.ogg", &MySoundManager);
			Music_Stage2Boss_Final.Play(true, NULL, fVolume_BGM);
			ShowBGMName("Bordersense");
		}
	}

	DestroyAllBullet();
//	DestroyAllEnemy();
	
	DeleteAllBarrage(pBoss);

	pBoss->iMaxHP = pBoss->SpellVector[pBoss->iCurrentSpell]->iHP;
	pBoss->iHP = pBoss->iMaxHP;
	pBoss->SpellVector[pBoss->iCurrentSpell]->pSpellInit();
	pBoss->iRemainTime = pBoss->SpellVector[pBoss->iCurrentSpell]->iLimitTime;
	pBoss->iRemainTime_FrameTime = 0;

	pBoss->iCurrentMutekiTime = 0;
	pBoss->bMuteki = true;

	GameNormalSizeFont.PrintFont(&PrintedSpellName, pBoss->SpellVector[pBoss->iCurrentSpell]->Name, 238, 187, 197, FONT_BLENDED);

}

void ProcessSpell()
{

	if (bPause == false)
	{
		if (pBoss->bMuteki == false)
		{
			pBoss->SpellVector[pBoss->iCurrentSpell]->pSpellFunction();	
		}

	}

}

bool SpellClear(GameBoss * IN_Boss)
{
	DestroyAllBullet();
	DestroyAllEnemy();		//이 작업 이후 EnemyIter의 무효화가 일어난다.

	(IN_Boss->iCurrentSpell)++;

	if ((IN_Boss->iCurrentSpell) == (IN_Boss->SpellVector.size()))
	{
		//보스전 종료.
		if (GameItemVector.size() > 0)
		{
			std::vector <GameItem *>::iterator Iter = GameItemVector.begin();
			while ( true )
			{
				if (Iter == GameItemVector.end())
				{
					break;
				}

				(*Iter)->bAutoFollow = true;
				(*Iter)->speed = 5.0;
				(*Iter)->acc = 0.5;
				(*Iter)->OldSpeed = 0.0;

				Iter++;
			}
		}


		MoveBossToPrimaryLocation();
		Sound_BossDead.Play(false, NULL, fVolume_SE);
		//ScoreAdditionVector.push_back(10000);
		DeleteAllPlayerShot();
		DeleteAllBarrage(pBoss);
		Player.bNowBomber = false;
		Player.bNowBomberPortrait = false;
		Player.bNowShooting = false;
		printf ("보스전 종료.\n");
		if (iCurrentStage == 1)
		{
			InitStage1Event_After_Boss();
		}
		else if (iCurrentStage == 2)
		{
			InitStage2Event_After_Boss();
		}
		iGameState_Game_Status = GAMESTATE_GAME_EVENT_AFTER_BOSS;
		return true;
	}
	else
	{
		//다음 스펠
		StartSpell();
	}

	return false;
}

bool AddBullet(ENEMYBULLET_TYPE IN_Type, int IN_SubType, double IN_x, double IN_y, double IN_angle, double IN_addangle, double IN_speed, double IN_acc, bool IN_IgnorePlayerSpell)
{
	//플레이어 스펠카드 발동중에는 false를 반환
	//if ( IN_IgnorePlayerSpell == false && Player.bNowBomber == true)
	//{
	//	return false;
	//}


	if (iGameFrame != iOldGameFrame)
	{
		Sound_Bullet.Play(false, NULL, fVolume_SE);
		iOldGameFrame = iGameFrame;
	}

	bool bRotate = true;		//

	ShooterSprite * pSprite;
	CollisionModel iCollisionModel;
	double fCollisionRadius;
	double fGrazeCollisionRadius;

	bool bSelfRotate = false;
	double fSelfRotateAddAngle = IN_angle;
	double fCurrentSelfRotateAngle = 0.1;

	switch (IN_Type)
	{
	case BULLET_TYPE0:
		pSprite = &Spr_BulletType0;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 3.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		bRotate = false;
		break;
	case BULLET_TYPE1:
		pSprite = &Spr_BulletType1;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 3.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		bRotate = false;
		break;
	case BULLET_TYPE2:
		pSprite = &Spr_BulletType2;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 2.0;	
//		fGrazeCollisionRadius = fCollisionRadius;
		break;
	case BULLET_TYPE3:
		pSprite = &Spr_BulletType3;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 2.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		break;
	case BULLET_TYPE4:
		pSprite = &Spr_BulletType4;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 2.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		break;
	case BULLET_TYPE5:
		pSprite = &Spr_BulletType5;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 4.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		break;
	case BULLET_TYPE6:
		pSprite = &Spr_BulletType6;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 14.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		bRotate = false;
		break;
	case BULLET_TYPE7:
		pSprite = &Spr_BulletType7;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 2.5;
//		fGrazeCollisionRadius = fCollisionRadius;
		break;
	case BULLET_TYPE8:
		pSprite = &Spr_BulletType8;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 6.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		break;
	case BULLET_TYPE9:
		pSprite = &Spr_BulletType9;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 12.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		bRotate = false;
		break;
	case BULLET_TYPE10:
		pSprite = &Spr_BulletType10;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 3.5;
//		fGrazeCollisionRadius = fCollisionRadius;
		bRotate = false;
		break;
	case BULLET_TYPE11:
		pSprite = &Spr_BulletType11;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 5.5;
//		fGrazeCollisionRadius = fCollisionRadius;
		bRotate = false;
		break;
	case BULLET_TYPE12:
		pSprite = &Spr_BulletType12;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 5.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		//bSelfRotate = true;
		break;
	case BULLET_TYPE13:
		pSprite = &Spr_BulletType13;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 3.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		//bSelfRotate = true;
		break;
	case BULLET_TYPE14:
		pSprite = &Spr_BulletType14;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 3.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		break;
	case BULLET_TYPE15:
		pSprite = &Spr_BulletType15;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 2.5;
//		fGrazeCollisionRadius = fCollisionRadius;
		break;
	case BULLET_TYPE16:
		pSprite = &Spr_BulletType16;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 6.5;
//		fGrazeCollisionRadius = fCollisionRadius;
		break;
	case BULLET_TYPE17:
		pSprite = &Spr_BulletType17;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 5.0;
//		fGrazeCollisionRadius = fCollisionRadius;
		break;
	case BULLET_TYPE18:
		pSprite = &Spr_BulletType18;
		iCollisionModel = COLLISIONMODEL_CIRCLE;
		fCollisionRadius = 16.0;
//		fGrazeCollisionRadius = 30.0;
		bRotate = false;
		break;
	default:
		return false;
	};

	GameBullet * pBullet = new GameBullet(IN_Type, pSprite, bRotate);

	pBullet->x = IN_x - (pSprite->GetWidth() / 2);
	pBullet->y = IN_y - (pSprite->GetHeight() / 2);
	pBullet->SetAngle(IN_angle);
	pBullet->addangle = IN_addangle;
	pBullet->speed = IN_speed;
//	pBullet->acc = 0.0;		//테스트
	//가속기능에 문제가 있어서 임시로 꺼뒀다.
	pBullet->acc = IN_acc;
	pBullet->AddCollision(0.0, 0.0, iCollisionModel, fCollisionRadius);
	fGrazeCollisionRadius = (double)(pBullet->GetSprite()->GetWidth()) / 2.0;
	pBullet->AddGrazeCollision(0.0, 0.0, iCollisionModel, fGrazeCollisionRadius);
	pBullet->iCurrentFrame = IN_SubType;

	pBullet->bSelfRotate = bSelfRotate;
	pBullet->fCurrentSelfRotateAngle = fCurrentSelfRotateAngle;
	pBullet->fSelfRotateAddAngle = fSelfRotateAddAngle;

//	pEnemyBullet->angle = GetAngle(pEnemyBullet, &Player);

	GameBulletVector.push_back(pBullet);	

	return true;
}

GameBullet * GetLastBullet()
{
	if (GameBulletVector.size() == 0)
	{
		return NULL;
	}

	return *(GameBulletVector.end() - 1);
}

bool AddPlayerShot(GamePlayerShot * IN_PlayerShot, double IN_Far_X, double IN_Far_Y, double IN_angle, bool IN_Muteki)
{
	GamePlayerShot * NewPlayerShot = new GamePlayerShot( *(IN_PlayerShot) );
	NewPlayerShot->x = IN_Far_X + Player.GetCenterX() - ( (NewPlayerShot->GetSprite()->GetWidth() ) / 2);
	NewPlayerShot->y = IN_Far_Y + Player.y - ( NewPlayerShot->GetSprite()->GetHeight() );
	NewPlayerShot->SetAngle(IN_angle);
	NewPlayerShot->bMuteki = IN_Muteki;

	GamePlayerShotVector.push_back(NewPlayerShot);

	return true;
}

bool AddPlayerShot(GamePlayerShot * IN_PlayerShot, double IN_Far_X, double IN_Far_Y, double IN_angle, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4, bool IN_Muteki)
{
	if (AddPlayerShot(IN_PlayerShot, IN_Far_X, IN_Far_Y, IN_angle, IN_Muteki) == true)
	{
		GamePlayerShot * pPlayerShot = (*(GamePlayerShotVector.end() - 1));
		if (pPlayerShot->pPlayerShotInit != NULL)
		{
			pPlayerShot->pPlayerShotInit(pPlayerShot, IN_iParam0, IN_iParam1, IN_iParam2, IN_iParam3, IN_iParam4);
		}
		return true;

	}

	return false;
}

bool MakeBossBarrage(std::string IN_TypeString, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4)
{

	if (BarrageVector.size() > 0)
	{
		std::vector<GameBarrage*>::iterator Found_Barrage;
		if (FindBarrage(IN_TypeString, &Found_Barrage) == true)
		{
			pBoss->pvBarrage.push_back(new GameBarrage(*Found_Barrage));
			(*(pBoss->pvBarrage.end() -1))->pInit( pBoss, IN_iParam0, IN_iParam1, IN_iParam2, IN_iParam3, IN_iParam4, (*(pBoss->pvBarrage.end() -1))->iBarrageParameters);
		}
		else
		{
			printf ("Can't Find Barrage : %s", IN_TypeString.c_str());
			return false;
		}

		return true;
	}
	
	return false;
}


bool MakeMicroThread(std::string IN_TypeString, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4)
{
	if (GameBulletVector.size() > 0)
	{
		std::vector<GameBullet * >::iterator Iter = GameBulletVector.end() - 1;
		
		std::vector<GameBarrage * >::iterator Found_Iter;
		if (FindBarrage(IN_TypeString, &Found_Iter) == true)
		{
			(*Iter)->pvBarrage.push_back( new GameBarrage( *Found_Iter ));
			std::vector<GameBarrage *>::iterator BarrageIter = (*Iter)->pvBarrage.end() - 1;
			(*BarrageIter)->pInit( *Iter, IN_iParam0, IN_iParam1, IN_iParam2, IN_iParam3, IN_iParam4, (*BarrageIter)->iBarrageParameters);
		}
		else
		{
			printf ("Can't Find Micro Thread : %s\n", IN_TypeString.c_str());
			return false;
		}

		
		return true;
	}

	return false;
}

bool MakeMicroThread(GameBullet * IN_Bullet, std::string IN_TypeString, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4)
{
	std::vector<GameBarrage * >::iterator Found_Iter;
	if (FindBarrage(IN_TypeString, &Found_Iter) == true)
	{
		IN_Bullet->pvBarrage.push_back( new GameBarrage( *Found_Iter ));
		std::vector<GameBarrage *>::iterator BarrageIter = IN_Bullet->pvBarrage.end() - 1;
		(*BarrageIter)->pInit( IN_Bullet, IN_iParam0, IN_iParam1, IN_iParam2, IN_iParam3, IN_iParam4, (*BarrageIter)->iBarrageParameters);
	}
	else
	{
		printf ("Can't Find Micro Thread : %s\n", IN_TypeString.c_str());
		return false;
	}

	return true;

}

void DeleteObject(GameObject * IN_Object)
{

	if (IN_Object->iType == (GameObjectType)TYPE_BASE)
	{
		delete IN_Object; 
	}
	else if (IN_Object->iType == (GameObjectType)TYPE_ENEMY)
	{
		if ( ((GameEnemy*)IN_Object)->bUsingHomingTargetIter == true)
		{
			(*(((GameEnemy*)IN_Object)->HomingTargetIter))->bEnemyAlive = false;
			((GameEnemy*)IN_Object)->bUsingHomingTargetIter = false;
			CheckGarbageHomingTarget( & (((GameEnemy*)IN_Object)->HomingTargetIter) );
		}
		delete (GameEnemy*)IN_Object;
	}
	else if (IN_Object->iType == (GameObjectType)TYPE_BOSS)
	{
		delete (GameBoss*)IN_Object;
	}
	else if ( IN_Object->iType == (GameObjectType)TYPE_BULLET)
	{
		delete (GameBullet*)IN_Object;
	}
	else if ( IN_Object->iType == (GameObjectType)TYPE_ENEMYBULLET)
	{
		delete (GameEnemyBullet*)IN_Object;
	}
	else if (IN_Object->iType == (GameObjectType)TYPE_PLAYERSHOT)
	{
		if ( ((GamePlayerShot*)IN_Object)->bUsingHomingTargetIter == true)
		{
			((*(((GamePlayerShot*)IN_Object)->HomingTargetIter))->iPlayerShotReferenceCount)--;
			((GamePlayerShot*)IN_Object)->bUsingHomingTargetIter = false;
			CheckGarbageHomingTarget( & (((GamePlayerShot*)IN_Object)->HomingTargetIter) );
		}
		delete (GamePlayerShot*)IN_Object;
	}
	else if (IN_Object->iType == (GameObjectType)TYPE_EXPLOSION)
	{
		delete (GameExplosion*)IN_Object;
	}
	else if (IN_Object->iType == (GameObjectType)TYPE_ITEM)
	{
		delete (GameItem*)IN_Object;
	}

}

void DeleteAllObjects()
{

	if (GameEnemyVector.size() > 0)
	{
		for (std::vector<GameEnemy*>::iterator Iter = GameEnemyVector.begin(); Iter != GameEnemyVector.end(); Iter++)
		{
			//동적으로 선언했던 모든 적군, 총알 객체를 지운다.
			if (*Iter != NULL)
			{
				DeleteObject(*Iter);
			}
		}
	}
	GameEnemyVector.clear();

	if (GameBulletVector.size() > 0)
	{
		for (std::vector<GameBullet*>::iterator Iter = GameBulletVector.begin(); Iter != GameBulletVector.end(); Iter++)
		{
			//동적으로 선언했던 모든 적군, 총알 객체를 지운다.
			if (*Iter != NULL)
			{
				DeleteObject(*Iter);
			}
		}
	}
	GameBulletVector.clear();

	if (GameExplosionVector.size() > 0)
	{
		for (std::vector<GameExplosion*>::iterator Iter = GameExplosionVector.begin(); Iter != GameExplosionVector.end(); Iter++)
		{
			//동적으로 선언했던 모든 적군, 총알 객체를 지운다.
			if (*Iter != NULL)
			{
				DeleteObject(*Iter);
			}
		}
	}
	GameExplosionVector.clear();

	DeleteAllPlayerShot();

	if (PreEnemyBulletVector.size() > 0)
	{
		for (std::vector<GameEnemy*>::iterator Iter = PreEnemyBulletVector.begin(); Iter != PreEnemyBulletVector.end(); Iter++)
		{
			//동적으로 선언했던 모든 적군, 총알 객체를 지운다.
			DeleteObject(*Iter);
		}
	}
	PreEnemyBulletVector.clear();

	if (GameItemVector.size() > 0)
	{
		for (std::vector<GameItem*>::iterator Iter = GameItemVector.begin(); Iter != GameItemVector.end(); Iter++)
		{
			//동적으로 선언했던 모든 적군, 총알 객체를 지운다.
			DeleteObject(*Iter);
		}
	}
	GameItemVector.clear();

	ClearHomingTargetList();

}

void DestroyAllEnemy()
{

	if (PreEnemyBulletVector.size() > 0)
	{
		for (std::vector<GameEnemy*>::iterator Iter = PreEnemyBulletVector.begin(); Iter != PreEnemyBulletVector.end(); Iter++)
		{		
			delete (*Iter);
		}
		PreEnemyBulletVector.clear();
	}

	GameBoss * pBoss_Backup = NULL;
	if (GameEnemyVector.size() > 0)
	{
		for (std::vector<GameEnemy*>::iterator Iter = GameEnemyVector.begin(); Iter != GameEnemyVector.end(); Iter++)
		{
			//동적으로 선언했던 모든 적군, 총알 객체를 지운다.
			if (*Iter != NULL)
			{
				//Enemy, Boss 관계없이 호밍타겟 다 지움.
				if ( (*Iter)->bUsingHomingTargetIter == true)
				{
					(*((*Iter)->HomingTargetIter))->bEnemyAlive = false;
					(*Iter)->bUsingHomingTargetIter = false;
					CheckGarbageHomingTarget( & ((*Iter)->HomingTargetIter) );
				}

				if ( (*Iter)->iType != TYPE_BOSS)
				{
					MakeExplosion(*Iter, true);
					DeleteObject(*Iter);
				}
				else
				{
					pBoss_Backup = (GameBoss*)(*Iter);
				}

			}
		}

		GameEnemyVector.clear();
		if (pBoss_Backup != NULL)
		{
			GameEnemyVector.push_back(pBoss_Backup);
		}
	}
}
void DestroyAllBullet(bool bDeleteAll)
{
	if (GameBulletVector.size() > 0)
	{
		std::vector<GameBullet*>::iterator Iter = GameBulletVector.begin();
		while ( 1 )
		{
			if (Iter == GameBulletVector.end())
			{
				break;
			}

			//동적으로 선언했던 모든 적군, 총알 객체를 지운다.
			bool bDeleted = false;
			if (*Iter != NULL)
			{
				if ( (*Iter)->bMuteki == false || bDeleteAll == true)
				{
					MakeExplosion(*Iter, false);
					DeleteObject(*Iter);
					Iter = GameBulletVector.erase(Iter);
					bDeleted = true;
				}
			}
			else
			{
				Iter = GameBulletVector.erase(Iter);
				bDeleted = true;
			}

			if (bDeleted == false)
			{
				Iter++;
			}

		}

	}
}

void DeleteAllPlayerShot()
{
	if (GamePlayerShotVector.size() > 0)
	{
		for (std::vector<GamePlayerShot*>::iterator Iter = GamePlayerShotVector.begin(); Iter != GamePlayerShotVector.end(); Iter++)
		{
			//동적으로 선언했던 모든 적군, 총알 객체를 지운다.
			if (*Iter != NULL)
			{
				if ( (*Iter)->bUsingHomingTargetIter == true)
				{
					((*((*Iter)->HomingTargetIter))->iPlayerShotReferenceCount)--;
					(*Iter)->bUsingHomingTargetIter = false;
					CheckGarbageHomingTarget( & ((*Iter)->HomingTargetIter) );
				}
				DeleteObject(*Iter);
			}
		}
	}
	GamePlayerShotVector.clear();
	
}

void RegisterBarrage(std::string IN_Name, BarrageFunctionInit IN_Init, BarrageFunction IN_Function)
{
	BarrageVector.push_back(new GameBarrage(IN_Name, IN_Init, IN_Function));
}

bool FindBarrage(std::string IN_TypeString, std::vector<GameBarrage *>::iterator * OUT_Iter)
{
	if (BarrageVector.size() > 0)
	{
		for (std::vector<GameBarrage *>::iterator Iter = BarrageVector.begin(); Iter != BarrageVector.end(); Iter++)
		{
			if ( (*Iter)->Name == IN_TypeString)
			{
				*OUT_Iter = Iter;
				return true;
			}
		}
	} 

	return false;
}

void DeleteAllBarrage()
{
	if (BarrageVector.size() > 0)
	{
		for (std::vector<GameBarrage*>::iterator Iter = BarrageVector.begin(); Iter != BarrageVector.end(); Iter++)
		{
			//동적으로 선언했던 모든 적군, 총알 객체를 지운다.
			delete (*Iter);
		}		
		BarrageVector.clear();
	}
}

void DeleteAllBarrage(GameEnemy * IN_Object)
{
	if (IN_Object->pvBarrage.size() > 0)
	{
		for (std::vector<GameBarrage*>::iterator Iter = IN_Object->pvBarrage.begin(); Iter != IN_Object->pvBarrage.end(); Iter++)
		{
			//동적으로 선언했던 모든 적군, 총알 객체를 지운다.
			delete (*Iter);
		}		
		IN_Object->pvBarrage.clear();
	}
}

void RegisterSpell(GameBoss * IN_Boss, std::string IN_Name, int IN_HP, SpellInit IN_SpellInit, SpellFunction IN_SpellFunction, int IN_LimitTime, bool IN_Invincible, bool IN_Countable)
{
	
	BossSpell * pBossSpell = new BossSpell;
	pBossSpell->Name = IN_Name;
	pBossSpell->iHP = IN_HP;
	pBossSpell->pSpellInit = IN_SpellInit;
	pBossSpell->pSpellFunction = IN_SpellFunction;
	pBossSpell->iLimitTime = IN_LimitTime;
	pBossSpell->bInvincible = IN_Invincible;
	pBossSpell->bCountable = IN_Countable;
	IN_Boss->SpellVector.push_back(pBossSpell);

}

void MovePlayerToPrimaryLocation(GamePlayer * IN_Player)
{
	IN_Player->x = (double)(UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + UI_WINDOW_RIGHT_X) / 2.0 - (double)(IN_Player->GetSprite()->GetWidth()) / 2.0;
	IN_Player->y = 414.0;
}

bool PlayerShotStart(GamePlayer * IN_Player)
{
	if (Player.iCurrentStatus == PLAYERSTATUS_EXPLOSION)
	{
		return false;
	}

// 	if (IN_Player->GetPlayerShot() == NULL)
// 	{
// 		return false;
// 	}

	if (IN_Player->bNowShooting == false)
	{
		if ( IN_Player->iShotCurrentWaitTime >= IN_Player->iPlayerShotCoolTime - 1)
		{
			IN_Player->bCoupleShot = IN_Player->bShift;
			IN_Player->iShotCount = 0;
			IN_Player->iShotCurrentWaitSubTime = IN_Player->iPlayerShotQuantity - 1;
			IN_Player->bNowShooting = true;
		}
	}
	else
	{
		return false;
	}
	
	return true;
}

bool PlayerBomberStart(GamePlayer * IN_Player)
{
	if (IN_Player->bomber >= 1 && IN_Player->bNowBomber == false)
	{
		if (IN_Player->iCurrentStatus != PLAYERSTATUS_EXPLOSION)
		{
			Sound_SpellCard.Play(false, NULL, fVolume_SE);
			//DestroyAllBullet(false);

			IN_Player->iShotCount = 0;
			IN_Player->iShotCurrentWaitSubTime = 0;
			IN_Player->bNowShooting = false;
			IN_Player->bNowBomber = true;
			
			switch (IN_Player->iPlayerCharaType)
			{
			case PLAYERCHARA_REIMU:
				IN_Player->pPlayerBomberInit(&Player, 1, 50, 60, 1, 80);
				break;
			case PLAYERCHARA_MARISA:
				IN_Player->pPlayerBomberInit(&Player, -100, 2, 0, 0, 0);
				break;
			case PLAYERCHARA_REISEN:
				IN_Player->pPlayerBomberInit(&Player, 0, 5, 27, 0, 0);
				break;
			}
			IN_Player->iCurrentBomberPortraitTime = 0;
			IN_Player->bNowBomberPortrait = true;
			IN_Player->bomber--;
		}

		return true;
	}
	
	return false;
}

void KillPlayer()
{

	Sound_PlayerDead.Play(false, NULL, fVolume_SE);
	Player.ChangeState(PLAYERSTATUS_EXPLOSION);
	MakeExplosion(&Player, true);

	Player.life--;
	if (Player.life >= 0)
	{
		InitPlayerBomber();
	}
	Player.iSmallScoreItemCount = 0;
	Player.iBigScoreItemCount = 0;
	Player.bNoMiss = false;
	Player.InitGravity();
}

void MakeExplosion(GameObject * IN_Object, bool IN_Type, double IN_Far_X, double IN_Far_Y)
{
	
	GameExplosion * NewExplosion;

	if (IN_Type == true)
	{
		NewExplosion = new GameExplosion(&Spr_Explosion_Big, 5);
	}
	else
	{
		NewExplosion = new GameExplosion(&Spr_Explosion_Small, 5);
	}

	if (IN_Object->iType == TYPE_PLAYER)
	{
		NewExplosion->bPlayerExplosion = true;
	}
	
	double cx = IN_Object->GetCenterX();
	double cy = IN_Object->GetCenterY();

	NewExplosion->x = (double)(IN_Object->GetCenterX()) - (double)(NewExplosion->GetSprite()->GetWidth()) / (double)2.0 + IN_Far_X;
	NewExplosion->y = (double)(IN_Object->GetCenterY()) - (double)(NewExplosion->GetSprite()->GetHeight()) / (double)2.0 + IN_Far_Y;
	NewExplosion->bStarted = false;

	GameExplosionVector.push_back(NewExplosion);

}

bool CollisionCheck(GameObject * Obj1, GameObject * Obj2)
{
	auto CircleCheck = [&] (double IN_x1, double IN_y1, double IN_radius1, double IN_x2, double IN_y2, double IN_radius2) -> bool
	{
		if (pow(abs(IN_x1 - IN_x2), 2) + 
			pow(abs(IN_y1 - IN_y2), 2)
			<= pow((IN_radius1 + IN_radius2), 2) )
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	auto WholeCheck = [&] (double IN_x1, double IN_y1, double IN_w1, double IN_h1, double IN_x2, double IN_y2, double IN_w2, double IN_h2) -> bool
	{
		if (IN_x1 <= IN_x2 + IN_w2)
			if (IN_x1 + IN_w1 >= IN_x2)
				if (IN_y1 <= IN_y2 + IN_h2)
					if (IN_y1 + IN_h1 >= IN_y2)
						return true;

		return false;
	};

	for (std::vector<Collision *>::iterator Obj1Iter = Obj1->CollisionVector.begin(); Obj1Iter != Obj1->CollisionVector.end(); Obj1Iter++)
	{
		for (std::vector<Collision *>::iterator Obj2Iter = Obj2->CollisionVector.begin(); Obj2Iter != Obj2->CollisionVector.end(); Obj2Iter++)
		{
			if ( ( (*Obj1Iter)->iCollisionModel == COLLISIONMODEL_CIRCLE) && ((*Obj2Iter)->iCollisionModel == COLLISIONMODEL_CIRCLE) )
			{
				return CircleCheck(Obj1->GetCenterX() + (*Obj1Iter)->FarFromCenterX, Obj1->GetCenterY() + (*Obj1Iter)->FarFromCenterY, (*Obj1Iter)->fCollisionRadius, 
					Obj2->GetCenterX() + (*Obj2Iter)->FarFromCenterX, Obj2->GetCenterY() + (*Obj2Iter)->FarFromCenterY, (*Obj2Iter)->fCollisionRadius);
			}
			//충돌 모델중에 COLLISIONMODEL_WHOLE를 하나라도 포함하고 있으면 WholeCheck를 실행한다.
			else if ( ((*Obj1Iter)->iCollisionModel == COLLISIONMODEL_WHOLE) || ((*Obj2Iter)->iCollisionModel == COLLISIONMODEL_WHOLE) )
			{
				return WholeCheck( Obj1->x, Obj1->y, (double)(Obj1->GetRect()->Get_W()), (double)(Obj1->GetRect()->Get_H()),
					Obj2->x, Obj2->y, (double)(Obj2->GetRect()->Get_W()), (double)(Obj2->GetRect()->Get_H()));
			}
		}
	}

	//만들다 만거...... Elipsoid Check
	//double fAbovePoint1_x, fAbovePoint1_y, fBelowPoint1_x, fBelowPoint1_y, 
	//	fAbovePoint2_x, fAbovePoint2_y, fBelowPoint2_x, fBelowPoint2_y;
	//
	
	//auto GetEllipsoid = [&] (int IN_ObjNo) 
	//{
	//	GameObject * pObj;
	//	double * pAbovePoint_x;
	//	double * pAbovePoint_y;
	//	double * pBelowPoint_x;
	//	double * pBelowPoint_y;

	//	if (IN_ObjNo == 1)
	//	{
	//		pAbovePoint_x = &fAbovePoint1_x;
	//		pAbovePoint_y = &fAbovePoint1_y;
	//		pBelowPoint_x = &fBelowPoint1_x;
	//		pBelowPoint_y = &fBelowPoint1_y;
	//		pObj = Obj1;
	//	}
	//	else if (IN_ObjNo == 2)
	//	{
	//		pAbovePoint_x = &fAbovePoint2_x;
	//		pAbovePoint_y = &fAbovePoint2_y;
	//		pBelowPoint_x = &fBelowPoint2_x;
	//		pBelowPoint_y = &fBelowPoint2_y;
	//		pObj = Obj2;
	//	}

	//	double fRadian;
	//	fRadian = GetRadian(pObj->GetAngle());
	//	*pAbovePoint_x = pObj->GetCenterX() + GetXbyCos(fRadian, pObj->fCollisionRadius);
	//	*pAbovePoint_y = pObj->GetCenterY() + GetYbySin(fRadian, pObj->fCollisionRadius);

	//	fRadian = GetRadian(pObj->GetAngle() + 180);	
	//	*pBelowPoint_x = pObj->GetCenterX() + GetXbyCos(fRadian, pObj->fCollisionRadius);
	//	*pBelowPoint_y = pObj->GetCenterY() + GetYbySin(fRadian, pObj->fCollisionRadius);

	//};

	//double bLineToCircleResult;
	//auto LineToCircleCheck = [&] (double IN_above_x, double IN_above_y, double IN_below_x, double IN_below_y, double IN_radius, double IN_target_x, double IN_target_y, double IN_target_radius)
	//{

	//};

	//if (Obj1->iCollisionModel == COLLISIONMODEL_ELLIPSOID && Obj2->iCollisionModel == COLLISIONMODEL_CIRCLE)
	//{
	//	double fInnerLength1 = Obj1->fCollisionLength - ((Obj1->fCollisionRadius) * 2.0);
	//	double fInnerLength2 = Obj2->fCollisionLength - ((Obj2->fCollisionRadius) * 2.0);

	//	GetEllipsoid(1);

	//	//위쪽 원 -> 위쪽 원
	//	CircleCheck(fAbovePoint1_x, fAbovePoint1_y, Obj1->fCollisionRadius, Obj2->GetCenterX(), Obj2->GetCenterY(), Obj2->fCollisionRadius);
	//	if (bCircleResult == true)
	//	{
	//		return true;
	//	}

	//	//위쪽 원 -> 아랫쪽 원
	//	CircleCheck(fAbovePoint1_x, fAbovePoint1_y, Obj1->fCollisionRadius, Obj2->GetCenterX(), Obj2->GetCenterY(), Obj2->fCollisionRadius);
	//	if (bCircleResult == true)
	//	{
	//		return true;
	//	}

	//	//왼쪽 직선 -> 원


	//	//오른쪽 직선 -> 원

	//}

	//타원과 타원의 충돌 -> 아직 지원되지 않음. (필요가 없음..)

	return false;
}

bool GrazeCheck(GameObject * Obj1, GameObject * Obj2)
{
	bool bCircleResult = false;
	auto CircleCheck = [&] (double IN_x1, double IN_y1, double IN_radius1, double IN_x2, double IN_y2, double IN_radius2)
	{
		if (pow(abs(IN_x1 - IN_x2), 2) + 
			pow(abs(IN_y1 - IN_y2), 2)
			<= pow((IN_radius1 + IN_radius2), 2) )
		{
			bCircleResult = true;
		}
		else
		{
			bCircleResult = false;
		}
	};

	for (std::vector<Collision *>::iterator Obj1Iter = Obj1->GrazeCollisionVector.begin(); Obj1Iter != Obj1->GrazeCollisionVector.end(); Obj1Iter++)
	{
		for (std::vector<Collision *>::iterator Obj2Iter = Obj2->GrazeCollisionVector.begin(); Obj2Iter != Obj2->GrazeCollisionVector.end(); Obj2Iter++)
		{
			if ( ( (*Obj1Iter)->iCollisionModel == COLLISIONMODEL_CIRCLE) && ((*Obj2Iter)->iCollisionModel == COLLISIONMODEL_CIRCLE) )
			{
				CircleCheck(Obj1->GetCenterX() + (*Obj1Iter)->FarFromCenterX, Obj1->GetCenterY() + (*Obj1Iter)->FarFromCenterY, (*Obj1Iter)->fCollisionRadius, 
					Obj2->GetCenterX() + (*Obj2Iter)->FarFromCenterX, Obj2->GetCenterY() + (*Obj2Iter)->FarFromCenterY, (*Obj2Iter)->fCollisionRadius);

				if (bCircleResult == true)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool OutsideCheck(GameObject * IN_Object)
{
	if ( IN_Object->x + (double)(IN_Object->GetRect()->Get_W()) < (double)(UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH) || IN_Object->x > (double)(UI_WINDOW_RIGHT_X)
		|| IN_Object->y + (double)(IN_Object->GetRect()->Get_H()) < (double)(UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT) || IN_Object->y > (double)(UI_WINDOW_BOTTOM_Y))
	{
		return true;
	}

	return false;
}

bool InsideCheck(GameObject * IN_Object)
{
	if ( ( IN_Object->x >= (double)(UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH) ))
		if ( IN_Object->x + (double)(IN_Object->GetRect()->Get_W()) <= (double)(UI_WINDOW_RIGHT_X) )
		if ( IN_Object->y >= (double)(UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT) )
		if ( IN_Object->y + (double)(IN_Object->GetRect()->Get_H()) <= (double)(UI_WINDOW_BOTTOM_Y) )
	{
		return true;
	}

	return false;
}

void AddScore(int IN_Score)
{
	Player.iScore += IN_Score;

	if (Player.iScore > iHiScore)
	{
		iHiScore = Player.iScore;
	}

	if (Player.iScore > 1000000)
	{
		if (bOnceExtended == false)
		{
			iExtendAppearRemainTime = UI_EXTEND_APPEAR_REMAIN_TIME;
			Sound_Extend.Play(false, NULL, fVolume_SE);
			Player.life++;
			bOnceExtended = true;
		}

	}

}

void PlayEnemyDamagedSound()
{
	if (iGameFrame >= iOldGameFrame_EnemyDamaged)
	{
		Sound_EnemyDamaged.Play(false, NULL, fVolume_SE);
		iOldGameFrame_EnemyDamaged = iGameFrame;
	}
}

void PlayEnemyDeadSound()
{
	if (iGameFrame >= iOldGameFrame_EnemyDead)
	{
		Sound_EnemyDead.Play(false, NULL, fVolume_SE);
		iOldGameFrame_EnemyDead = iGameFrame;
	}
}
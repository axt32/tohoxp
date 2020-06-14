#include "GameObject.h"

GameObject :: GameObject()
{
	//130127. 생성자 내에서 또다른 생성자를 호출하면, 그것은 메모리 공간에 새로운 지역변수를 만들고 그것에 대한 생성자를 만드는것이다.
	//현재의 클래스 변수에 대한 생성자를 호출하는 것이 아님.
	InitGameObject(TYPE_BASE, NULL, 0, false, 0, true, true);
}

GameObject :: GameObject(GameObjectType IN_Type)
{
	InitGameObject(IN_Type, NULL, 0, false, 0, true, true);
}

GameObject :: GameObject(GameObjectType IN_Type, ShooterSprite * IN_Sprite, bool IN_Rotate, bool IN_Movable)
{
	InitGameObject(IN_Type, IN_Sprite, 0, false, 0, IN_Rotate, IN_Movable);
}

GameObject :: GameObject(GameObjectType IN_Type, ShooterSprite * IN_Sprite, int IN_FrameChangeInterval, bool IN_AutoNextFrame, int IN_CurrentFrame, bool IN_Rotate, bool IN_Movable)
{
	InitGameObject(IN_Type, IN_Sprite, IN_FrameChangeInterval, IN_AutoNextFrame, IN_CurrentFrame, IN_Rotate, IN_Movable);
}

GameObject :: GameObject(GameObject& IN_GameObject)
{
	pSprite = IN_GameObject.pSprite;
	ShooterRect * pRect;

	IN_GameObject.RotatedRect.Duplicate(&RotatedRect);
	angle = IN_GameObject.angle;
	for (std::vector<Collision *>::iterator Iter = IN_GameObject.CollisionVector.begin(); Iter != IN_GameObject.CollisionVector.end(); Iter++)
	{
		Collision * pCollision = new Collision;
		pCollision->FarFromCenterX = (*Iter)->FarFromCenterX;
		pCollision->FarFromCenterY = (*Iter)->FarFromCenterY;
		pCollision->iCollisionModel = (*Iter)->iCollisionModel;
		pCollision->fCollisionRadius = (*Iter)->fCollisionRadius;
		pCollision->fCollisionLength = (*Iter)->fCollisionLength;
		CollisionVector.push_back(pCollision);
	}
//	CollisionVector
	iType = IN_GameObject.iType;
	iFrameChangeInterval = IN_GameObject.iFrameChangeInterval;		//단위 : 프레임
	iCurrentFrameTime = 0;			//단위 : 프레임
	iCurrentFrame = 0;
	bAutoNextFrame = IN_GameObject.bAutoNextFrame;
	bRotate = IN_GameObject.bRotate;
	bMovable = IN_GameObject.bMovable;

	//

	bPermitOutside = IN_GameObject.bPermitOutside;

	bSuicide = IN_GameObject.bSuicide;

	x = IN_GameObject.x;
	y = IN_GameObject.y;
	addangle = IN_GameObject.addangle;
	speed = IN_GameObject.speed;
	acc = IN_GameObject.acc;
	for (int i = 0; i < MAXPARAMETER; i++)
	{
		Parameter[i] = IN_GameObject.Parameter[i];
	}

	bGoTo = IN_GameObject.bGoTo;
	bFollow = IN_GameObject.bFollow;
	fDest_X = IN_GameObject.fDest_X;
	fDest_Y = IN_GameObject.fDest_Y;
	bDropPowerupItem = IN_GameObject.bDropPowerupItem;

	bBezier = IN_GameObject.bBezier;
	iBezierTime = IN_GameObject.iBezierTime;
	iCurrentBezierTime = IN_GameObject.iCurrentBezierTime;
	fBezier3_DeptX = IN_GameObject.fBezier3_DeptX;
	fBezier3_DeptY = IN_GameObject.fBezier3_DeptY;
	fBezier3_PointX = IN_GameObject.fBezier3_PointX;		//Corner 값
	fBezier3_PointY = IN_GameObject.fBezier3_PointY;		//Corner 값
	fBezier3_DestX = IN_GameObject.fBezier3_DestX;		//Corner 값
	fBezier3_DestY = IN_GameObject.fBezier3_DestY;		//Corner 값

	bSelfRotate = IN_GameObject.bSelfRotate;
	fSelfRotateAddAngle = IN_GameObject.fSelfRotateAddAngle;
	fCurrentSelfRotateAngle = IN_GameObject.fCurrentSelfRotateAngle;

}

GameObject :: ~GameObject()
{
	if (CollisionVector.size() > 0)
	{
		for (std::vector<Collision * >::iterator Iter = CollisionVector.begin(); Iter != CollisionVector.end(); Iter++)
		{
			delete (*Iter);
		}

		CollisionVector.clear();
	}

	if (GrazeCollisionVector.size() > 0)
	{
		for (std::vector<Collision * >::iterator Iter = GrazeCollisionVector.begin(); Iter != GrazeCollisionVector.end(); Iter++)
		{
			delete (*Iter);
		}

		GrazeCollisionVector.clear();
	}
}

void GameObject::InitGameObject(GameObjectType IN_Type, ShooterSprite * IN_Sprite, int IN_FrameChangeInterval, bool IN_AutoNextFrame, int IN_CurrentFrame, bool IN_Rotate, bool IN_Movable)
{
	pSprite = IN_Sprite;
	iFrameChangeInterval = IN_FrameChangeInterval;
	iCurrentFrame = IN_CurrentFrame;
	iCurrentFrameTime = 0;
	bAutoNextFrame = IN_AutoNextFrame;
	bRotate = IN_Rotate;
	bMovable = IN_Movable;
	
	bPermitOutside = false;
	CollisionVector.clear();
	GrazeCollisionVector.clear();
	iCurrentGrazeTime = GRAZECOOLTIME;
	x = 0.0;
	y = 0.0;
	angle = 90.0;
	speed = 0.0;
	acc = 0.0;
	addangle = 0.0;
	int i;
	for (i = 0; i < MAXPARAMETER; i++)
	{
		Parameter[i] = 0;
	}
	iType = IN_Type;

	bGoTo = false;
	bFollow = false;
	fDest_X = 0;
	fDest_Y = 0;
	bDropPowerupItem = false;

	bBezier = false;
	iBezierTime = 0;
	iCurrentBezierTime = 0;
	fBezier3_DeptX = 0.0;
	fBezier3_DeptY = 0.0;
	fBezier3_PointX = 0.0;		//Corner 값
	fBezier3_PointY = 0.0;		//Corner 값
	fBezier3_DestX = 0.0;		//Corner 값
	fBezier3_DestY = 0.0;		//Corner 값

	bMuteki = false;

	bSelfRotate = false;
	fSelfRotateAddAngle = 0.0;
	fCurrentSelfRotateAngle = 90.0;

}


bool GameObject :: SetSprite(ShooterSprite * IN_Sprite)
{
	return SetSprite(IN_Sprite, 0);
}

bool GameObject :: SetSprite(ShooterSprite * IN_Sprite, int IN_FrameChangeInterval)
{
	if (IN_Sprite == NULL || IN_Sprite->GetLoaded() == false)
	{
		return false;
	}

	pSprite = IN_Sprite;

	iCurrentFrame = 0;
	iCurrentFrameTime = 0;

	iFrameChangeInterval = IN_FrameChangeInterval;

	if (iFrameChangeInterval <= 0)
	{
		bAutoNextFrame = false;
	}
	else
	{
		bAutoNextFrame = true;
	}

	SetAngle(90.0);
	RotatedRect.Set_X(x);
	RotatedRect.Set_Y(y);
	RotatedRect.Set_W(GetSprite()->GetWidth());
	RotatedRect.Set_H(GetSprite()->GetHeight());

	return true;
}

ShooterSprite * GameObject :: GetSprite()
{
	return pSprite;
}
/*
bool GameObject :: SetFrame(int IN_Frame)
{

	if (pSprite == NULL)
	{
		return false;
	}

	if (pSprite->GetMaxFrame() >= 1)
	{
		if (IN_Frame >= 0 && IN_Frame < pSprite->GetMaxFrame())
		{
			iCurrentFrame = IN_Frame;
		}
	}
	else
	{
		return false;
	}

	return true;

}	*/
bool GameObject :: NextFrame()
{

	if (pSprite == NULL)
	{
		return false;
	}

	if (pSprite->GetMaxFrame() >= 1)
	{
		iCurrentFrame++;

		if (iCurrentFrame == pSprite->GetMaxFrame())
		{
			iCurrentFrame = 0;
		}
	}
	else
	{
		return false;
	}

	return true;
}
/*
bool GameObject :: GetCurrentFrame(int * OUT_CurrentFrame)
{
	if (pSprite == NULL)
	{
		return false;
	}
	*OUT_CurrentFrame = iCurrentFrame;
	return true;
}
bool GameObject :: SetFrameChangeInterval(int IN_FrameChangeInveral)
{
	if (pSprite == NULL)
	{
		return false;
	}
	iFrameChangeInterval = IN_FrameChangeInveral;
	iCurrentFrameTime = 0;

	return true;
}
bool GameObject :: GetFrameChangeInterval(int * OUT_FrameChangeInterval)
{
	if (pSprite == NULL)
	{
		return false;
	}
	*OUT_FrameChangeInterval = iFrameChangeInterval;
	
	return true;
}

bool GameObject :: SetAutoNextFrame(bool IN_AutoNextFrame)
{
	if (pSprite == NULL)
	{
		return false;
	}

	bAutoNextFrame = IN_AutoNextFrame;
	return true;
}
bool GameObject :: GetAutoNextFrame(bool * OUT_AutoNextFrame)
{
	if (pSprite == NULL)
	{
		return false;
	}

	*OUT_AutoNextFrame = bAutoNextFrame;
	return true;
}
*/

ShooterRect * GameObject :: GetRect()
{
	if (RotatedRect.Get_W() == 0 && RotatedRect.Get_H() == 0)
	{
		RotatedRect.Set_W(GetSprite()->GetWidth());
		RotatedRect.Set_H(GetSprite()->GetHeight());
		RotatedRect.Set_X((int)x);
		RotatedRect.Set_Y((int)y);
	}

	return &RotatedRect;
}

bool GameObject :: Draw(bool IN_AutoNextFrame)
{
	if (pSprite == NULL)
	{
		return false;
	}

	double DrawAngle;
	
	if (bRotate == false)
	{
		DrawAngle = 0.0;	
	}
	else
	{
		if (bSelfRotate == true)
		{
			DrawAngle = Angle360(- ( (fCurrentSelfRotateAngle - 90.0) )); 
		}
		else
		{
			DrawAngle = Angle360(- ( (angle - 90.0) )); 
		}
	}

	pSprite->DrawSprite( (int)(x), (int)(y),  iCurrentFrame, DrawAngle, 1.0);

	if (IN_AutoNextFrame & bAutoNextFrame == true)
	{
		if (iCurrentFrameTime >= iFrameChangeInterval - 1)
		{
			NextFrame();
			iCurrentFrameTime = 0;
		}
		else
		{
			iCurrentFrameTime++;
		}
	}

	return true;
}
bool GameObject :: Rotate(bool IN_CustomRotate, double IN_angle, double IN_zoom, bool IN_DisableSelfRotate)
{
	if (pSprite == NULL)
	{
		return false;
	}

	double fZoom = 1.0;
	if (bRotate == true)
	{
		if (bSelfRotate == true && IN_DisableSelfRotate == false)
		{
			fCurrentSelfRotateAngle = Angle360(fCurrentSelfRotateAngle + fSelfRotateAddAngle);

			RotatedRect.Set_W (pSprite->GetWidth() * fZoom);
			RotatedRect.Set_H (pSprite->GetHeight() * fZoom);
		}
		else
		{
			if (IN_CustomRotate == true)
			{
				angle = IN_angle;
				fZoom = IN_zoom;
			}
			else
			{
// 				if (bSelfRotate == true && IN_DisableSelfRotate == true)
// 				{
// 					angle = fCurrentSelfRotateAngle;
// 					fZoom = 1.0;
// 				}
// 				else
				{
					
					fZoom = IN_zoom;
				}
			}

			RotatedRect.Set_W (pSprite->GetWidth() * fZoom);
			RotatedRect.Set_H (pSprite->GetHeight() * fZoom);
		}
	}

	return true;
}

double GameObject :: GetAngle()
{
	return angle;
}
void GameObject :: SetAngle(double IN_angle)
{
	angle = Angle360(IN_angle);
}

double GameObject :: GetCenterX()
{
	if (pSprite == NULL)
	{
		return -1.0;
	}
//	return x + (double)((GetSprite()->GetWidth()) / 2.0);
	return x + (double)(GetRect()->Get_W()) / 2.0; 
}

double GameObject :: GetCenterY()
{
	if (pSprite == NULL)
	{
		return -1.0;
	}
//	return y + (double)((GetSprite()->GetHeight()) / 2.0);
	return y + (double)((GetRect()->Get_H()) / 2.0);
}

void GameObject :: AddCollision(double IN_FarFromCenterX, double IN_FarFromCenterY, CollisionModel IN_CollisionModel, double IN_CollisionRadius, double IN_CollisionLength)
{
	Collision * pCollision = new Collision;
	pCollision->FarFromCenterX = IN_FarFromCenterX;
	pCollision->FarFromCenterY = IN_FarFromCenterY;
	pCollision->iCollisionModel = IN_CollisionModel;
	pCollision->fCollisionRadius = IN_CollisionRadius;

	CollisionVector.push_back(pCollision);
}

void GameObject :: AddGrazeCollision(double IN_FarFromCenterX, double IN_FarFromCenterY, CollisionModel IN_CollisionModel, double IN_CollisionRadius, double IN_CollisionLength)
{
	Collision * pCollision = new Collision;
	pCollision->FarFromCenterX = IN_FarFromCenterX;
	pCollision->FarFromCenterY = IN_FarFromCenterY;
	pCollision->iCollisionModel = IN_CollisionModel;
	pCollision->fCollisionRadius = IN_CollisionRadius;

	GrazeCollisionVector.push_back(pCollision);
}
#pragma once
#include "../MemoryLeakChecker.h"
#include "../SDLEngine/ShooterSprite.h"
#include "../SDLEngine/ShooterSurface.h"
#include "../GameCore/Angle360.h"
#include <math.h>
#include <vector>

#define MAXPARAMETER 8
#define GRAZECOOLTIME 30
#define BOMBER_CRASH_SCORE 10
#define GRAZESCORE 100

//Object���� Ÿ���� ������, Enemy, Bullet �ȿ��� �� ���� Ÿ���� ������.
typedef enum GameObjectType
{
	TYPE_BASE = 0,
	TYPE_PLAYER,
	TYPE_PLAYERSHOT,
	TYPE_PLAYERHEATBOX,
	TYPE_ENEMYBULLET,
	TYPE_ENEMY,
	TYPE_BOSS,
	TYPE_BULLET,
	TYPE_EXPLOSION,
	TYPE_ITEM,
	TYPE_STAGE,
} GameObjectType;

typedef enum CollisionModel
{
	COLLISIONMODEL_NONE = 0,
	COLLISIONMODEL_CIRCLE,
	COLLISIONMODEL_ELLIPSOID,
	COLLISIONMODEL_WHOLE
};

typedef struct Collision
{
	double FarFromCenterX;
	double FarFromCenterY;
	CollisionModel iCollisionModel;
	double fCollisionRadius;
	double fCollisionLength;
} Collision;

class GameObject
{
private:
	ShooterSprite * pSprite;
	ShooterRect RotatedRect;
	double angle;
	void InitGameObject(GameObjectType IN_Type, ShooterSprite * IN_Sprite, int IN_FrameChangeInterval, bool IN_AutoNextFrame, int IN_CurrentFrame, bool IN_Rotate, bool IN_Movable);

public:

	std::vector<Collision * > CollisionVector;
	std::vector<Collision * > GrazeCollisionVector;

	int iCurrentGrazeTime;

	//CollisionModel iCollisionModel;
	//double fCollisionRadius;
	//double fCollisionLength;
	/* private->public���� �ű� */
	int iType;
	int iFrameChangeInterval;		//���� : ������
	int iCurrentFrameTime;			//���� : ������
	int iCurrentFrame;
	bool bAutoNextFrame;
	bool bRotate;
	bool bMovable;
	/* */

	double x;
	double y;
	double addangle;
	double speed;
	double acc;
	int Parameter[MAXPARAMETER];

	//130126 EnemyBullet���� GameObject�� ���� �ű�
	//���ǻ��� : ��ǥ�� �������� Corner ��(���� ��� 1�ȼ�)�� Center �� (�߾� 1�ȼ�)�� �ִµ�
	//Locate �� AddBullet�� ��� Center ������ �Է¹޾� Corner ������ ��ȯ�Ѵ�.
	//Dest ������ ��� Corner ������ �Է¹޴´�.
	//��, ���ο��� ��ǥ ������ �� ������ Corner ������ ó���Ѵٴ� ���̴�.
	//Center���� ���� ���Ǹ� ���� ������ ���̴�.
	bool bGoTo;
	bool bFollow;			//121113 Enemy���� EnemyBullet���� �ű�.
	double fDest_X;		//Corner ��
	double fDest_Y;		//Corner ��
	bool bDropPowerupItem;
	
	bool bBezier;		//Corner ��
	int iBezierTime;
	int iCurrentBezierTime;
	double fBezier3_DeptX;
	double fBezier3_DeptY;
	double fBezier3_PointX;		//Corner ��
	double fBezier3_PointY;		//Corner ��
	double fBezier3_DestX;		//Corner ��
	double fBezier3_DestY;		//Corner ��

	bool bMuteki;

	bool bSelfRotate;
	double fSelfRotateAddAngle;
	double fCurrentSelfRotateAngle;

	bool bPermitOutside;

	bool bSuicide;

	GameObject();
	GameObject(GameObjectType IN_Type);
	GameObject(GameObjectType IN_Type, ShooterSprite * IN_Sprite, bool IN_Rotate, bool IN_Movable);
	GameObject(GameObjectType IN_Type, ShooterSprite * IN_Sprite, int IN_FrameChangeInterval, bool IN_AutoNextFrame, int IN_CurrentFrame, bool IN_Rotate, bool IN_Movable);
	GameObject(GameObject& IN_GameObject);
	
	~GameObject();

	bool SetSprite(ShooterSprite * IN_Sprite);
	bool SetSprite(ShooterSprite * IN_Sprite, int IN_FrameChangeInterval);
	ShooterSprite * GetSprite();
	//bool SetFrame(int IN_Frame);
	bool NextFrame();
	//bool GetCurrentFrame(int * OUT_CurrentFrame);
	//bool SetFrameChangeInterval(int IN_FrameChangeInveral);
	//bool GetFrameChangeInterval(int * OUT_FrameChangeInterval);
	//bool SetAutoNextFrame(bool IN_AutoNextFrame);
	//bool GetAutoNextFrame(bool * OUT_AutoNextFrame);

	ShooterRect * GetRect();
	bool Draw(bool IN_AutoNextFrame = true);
	//ȸ�� ������ �ٲ���� ������ Rect�� �����ִ� �Լ��̴�.
	//�� �Լ��� ȣ���ϰ� �Ǹ� ��������Ʈ ȸ�� �۾����� �ϰԵȴ�.
	bool Rotate(bool IN_CustomRotate = false, double IN_angle = 90.0, double IN_zoom = 1.0, bool IN_DisableSelfRotate = false);

	double GetAngle();
	void SetAngle(double IN_angle);

	double GetCenterX();
	double GetCenterY();

	void AddCollision(double IN_FarFromCenterX, double IN_FarFromCenterY, CollisionModel IN_CollisionModel, double IN_CollisionRadius = 0.0, double IN_CollisionLength = 0.0);
	void AddGrazeCollision(double IN_FarFromCenterX, double IN_FarFromCenterY, CollisionModel IN_CollisionModel, double IN_CollisionRadius = 0.0, double IN_CollisionLength = 0.0);

};
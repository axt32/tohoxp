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

//Object에서 타입이 나뉘고, Enemy, Bullet 안에서 또 각각 타입이 나뉜다.
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
	/* private->public으로 옮김 */
	int iType;
	int iFrameChangeInterval;		//단위 : 프레임
	int iCurrentFrameTime;			//단위 : 프레임
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

	//130126 EnemyBullet에서 GameObject로 몽땅 옮김
	//유의사항 : 좌표의 종류에는 Corner 값(좌측 상단 1픽셀)과 Center 값 (중앙 1픽셀)이 있는데
	//Locate 및 AddBullet의 경우 Center 값으로 입력받아 Corner 값으로 변환한다.
	//Dest 설정의 경우 Corner 값으로 입력받는다.
	//즉, 내부에서 좌표 연산을 할 때에는 Corner 값으로 처리한다는 것이다.
	//Center값은 유저 편의를 위해 제공할 뿐이다.
	bool bGoTo;
	bool bFollow;			//121113 Enemy에서 EnemyBullet으로 옮김.
	double fDest_X;		//Corner 값
	double fDest_Y;		//Corner 값
	bool bDropPowerupItem;
	
	bool bBezier;		//Corner 값
	int iBezierTime;
	int iCurrentBezierTime;
	double fBezier3_DeptX;
	double fBezier3_DeptY;
	double fBezier3_PointX;		//Corner 값
	double fBezier3_PointY;		//Corner 값
	double fBezier3_DestX;		//Corner 값
	double fBezier3_DestY;		//Corner 값

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
	//회전 등으로 바뀌어진 현재의 Rect를 구해주는 함수이다.
	//이 함수를 호출하게 되면 스프라이트 회전 작업또한 하게된다.
	bool Rotate(bool IN_CustomRotate = false, double IN_angle = 90.0, double IN_zoom = 1.0, bool IN_DisableSelfRotate = false);

	double GetAngle();
	void SetAngle(double IN_angle);

	double GetCenterX();
	double GetCenterY();

	void AddCollision(double IN_FarFromCenterX, double IN_FarFromCenterY, CollisionModel IN_CollisionModel, double IN_CollisionRadius = 0.0, double IN_CollisionLength = 0.0);
	void AddGrazeCollision(double IN_FarFromCenterX, double IN_FarFromCenterY, CollisionModel IN_CollisionModel, double IN_CollisionRadius = 0.0, double IN_CollisionLength = 0.0);

};
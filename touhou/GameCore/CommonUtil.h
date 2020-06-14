#pragma once
#include "../MemoryLeakChecker.h"
#include "../SDLEngine/ShooterScreen.h"
#include "../SDLEngine/ShooterSprite.h"
#include "../GameEngine/GameObject.h"
#include <string>

#define PI 3.1415926535897932384626433832795

void Shooter_DrawText(ShooterSprite * IN_Font, std::string IN_Text, double IN_x, double IN_y, int IN_RightAlignment = 0);

//������ ���Ѵ�.
double GetRadian(double IN_angle);

//���ϴ� ������ Ʋ���� X�� ���Ѵ�.
double GetXbyCos(double IN_radian, double IN_x);

//���ϴ� ������ Ʋ���� Y�� ���Ѵ�.
double GetYbySin(double IN_radian, double IN_y);

//�ش� ������Ʈ�� �߾����� �������� �� ������Ʈ ������ ������ ���Ѵ�. (Center ��)
double GetAngle(GameObject * Obj1, GameObject * Obj2);

//�� �� ������ ������ ���Ѵ�. (Corner ��)
double GetAngle(double IN_x1, double IN_y1, double IN_x2, double IN_y2);

//�� �� ������ �Ÿ��� ���Ѵ�. (Corner ��)
double GetDistance(double IN_x1, double IN_y1, double IN_x2, double IN_y2);

double GetDistance(GameObject * Obj1, GameObject * Obj2);

//������ ��� �׸���.
bool Bezier3(double IN_x1, double IN_y1, 
	double IN_x2, double IN_y2, 
	double IN_x3, double IN_y3, 
	double mu,
	double * OUT_x, double * OUT_y);
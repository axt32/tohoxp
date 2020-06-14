#pragma once
#include "../MemoryLeakChecker.h"
#include "../SDLEngine/ShooterScreen.h"
#include "../SDLEngine/ShooterSprite.h"
#include "../GameEngine/GameObject.h"
#include <string>

#define PI 3.1415926535897932384626433832795

void Shooter_DrawText(ShooterSprite * IN_Font, std::string IN_Text, double IN_x, double IN_y, int IN_RightAlignment = 0);

//라디안을 구한다.
double GetRadian(double IN_angle);

//원하는 각도로 틀어진 X를 구한다.
double GetXbyCos(double IN_radian, double IN_x);

//원하는 각도로 틀어진 Y를 구한다.
double GetYbySin(double IN_radian, double IN_y);

//해당 오브젝트의 중앙점을 기준으로 두 오브젝트 사이의 각도를 구한다. (Center 값)
double GetAngle(GameObject * Obj1, GameObject * Obj2);

//두 점 사이의 각도를 구한다. (Corner 값)
double GetAngle(double IN_x1, double IN_y1, double IN_x2, double IN_y2);

//두 점 사이의 거리를 구한다. (Corner 값)
double GetDistance(double IN_x1, double IN_y1, double IN_x2, double IN_y2);

double GetDistance(GameObject * Obj1, GameObject * Obj2);

//베지어 곡선을 그린다.
bool Bezier3(double IN_x1, double IN_y1, 
	double IN_x2, double IN_y2, 
	double IN_x3, double IN_y3, 
	double mu,
	double * OUT_x, double * OUT_y);
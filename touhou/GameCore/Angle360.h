#pragma once
#include "../MemoryLeakChecker.h"
#include <stdio.h>

//입력된 값을 0~360 사이의 값으로 출력해준다.
double Angle360 (double IN_angle);
int Angle360(int IN_angle);

//반올림하여 정수로 변환.
int RoundInt(double IN_value);
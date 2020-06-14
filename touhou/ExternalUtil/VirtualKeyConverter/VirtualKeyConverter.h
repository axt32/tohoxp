#pragma once

#include <string>
#include "../../stdafx.h"
#include <windows.h>

std::string VKeyToKeyName(int IN_VKey);
int KeyNameToVKey(std::string IN_KeyName);

bool CheckValidKeyName(std::string IN_KeyName);
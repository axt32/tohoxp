 #pragma once
#include "../../stdafx.h"
#include <string>
#include <windows.h>

class INIManager
{
private:
	std::string sPath;
public:
	static std::string CombineModulePath(std::string IN_FileName);
	INIManager();
	INIManager(std::string IN_Path);
	void SetPath(std::string IN_Path);
	bool SaveToINI(std::string Group, std::string Category, std::string IN_value);
	std::string INIManager :: LoadFromINI(std::string Group, std::string Category);
};

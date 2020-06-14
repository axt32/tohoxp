 #include "INIManager.h"


std::string INIManager :: CombineModulePath(std::string IN_FileName)
{
	char path[256];
	GetModuleFileName(NULL, path, 256);
	std::string newpath = path;
	int index = newpath.rfind("\\");
	newpath = newpath.substr(0, index+1);
	newpath += IN_FileName.c_str();
	return newpath;

	return "";
}
INIManager :: INIManager()
{

}

INIManager :: INIManager(std::string IN_Path)
{
	SetPath(IN_Path);
}

void INIManager :: SetPath(std::string IN_Path)
{
	sPath = CombineModulePath(IN_Path.c_str());
}

bool INIManager :: SaveToINI(std::string Group, std::string Category, std::string IN_value)
{
	BOOL bResult = WritePrivateProfileString(Group.c_str(), Category.c_str(), IN_value.c_str(), sPath.c_str());
	if (bResult == TRUE)
	{
		return true;
	}
	return false;
}
std::string INIManager :: LoadFromINI(std::string Group, std::string Category)
{
	TCHAR sResult[255] = "";
	GetPrivateProfileString(Group.c_str(), Category.c_str(), "failed", sResult, 255, sPath.c_str());
	if (strcmp(sResult, "failed") == 0)
	{
		return (std::string)"";
	}
	else
	{
		return (std::string)sResult;
	}
}

#include "CSVManager.h"

CSVManager :: CSVManager()
{
	pFile = NULL;
	iIOTYPE = IOTYPE_NONE;
	iCurrentReadLine = 0;
}

CSVManager :: ~CSVManager()
{
	CloseFile();
}

bool CSVManager :: OpenFile(std::string IN_Path, IOTYPE IN_TYPE)
{
	errno_t err;

	std::string sMode;

	iIOTYPE = IN_TYPE;

	if (iIOTYPE == IOTYPE_READ)
	{
		sMode = "r";
	}
	else if (iIOTYPE == IOTYPE_WRITE)
	{
		sMode = "w";
	}


	err = fopen_s(&pFile, IN_Path.c_str(), sMode.c_str());

	if (err != 0)
	{
		//FAIL!
		pFile = NULL;
		iIOTYPE = IOTYPE_NONE;
		return false;
	}

	return true;
}
bool CSVManager :: CloseFile()
{
	if (pFile != NULL)
	{
		fclose(pFile);
		pFile = NULL;
		iIOTYPE = IOTYPE_NONE;
		iCurrentReadLine = 0;
		return true;
	}

	return false;
}

bool CSVManager :: ReadLine(int IN_Count, ...)
{
	if (pFile == NULL || iIOTYPE != IOTYPE_READ)
	{
		return false;
	}
	
	char Line[MAXLINELENGTH];
	if (fgets(Line, MAXLINELENGTH, pFile) != NULL)
	{
		iCurrentReadLine++;

		if (IN_Count <= 0)
		{
			return false;
		}

		_UtilSet::StringTokenizer MyTokenizer( (std::string)Line, ",");
		
		if (MyTokenizer.Split() == false)
		{
			return false;
		}

		int iCurrentColumn = 0;
		va_list argptr;
		va_start(argptr, IN_Count);

		while ( 1 )
		{
			std::string * pString = va_arg(argptr, std::string *);

			*pString = MyTokenizer.GetResultString(iCurrentColumn);

			iCurrentColumn++;

			if (iCurrentColumn == IN_Count)
			{
				break;
			}
		}

		return true;
	}

	return false;

}

bool CSVManager :: WriteLine(int IN_Count, ...)
{
	if (pFile == NULL || iIOTYPE != IOTYPE_WRITE)
	{
		return false;
	}

	va_list argptr;
	va_start(argptr, IN_Count);

	if (IN_Count <= 0)
	{
		return false;
	}

	int iCurrentColumn = 0;
	std::string OutputString = "";
	
	while ( 1 )
	{
		OutputString += va_arg(argptr, std::string);
		iCurrentColumn++;

		if (iCurrentColumn == IN_Count)
		{
			break;
		}
		else
		{
			OutputString += ",";
		}
	}

	errno_t err;
	err = fprintf_s(pFile, OutputString.c_str());
	if (err < 0)
	{
		return false;
	}
	err = fprintf_s(pFile, "\n");
	if (err < 0)
	{
		return false;
	}

	return true;
}
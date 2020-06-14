//////////////////////////////////////////////////////////////////////////
// CSV Manager
//////////////////////////////////////////////////////////////////////////

#pragma once
#include "../../MemoryLeakChecker.h"

#include <string>
#include <stdio.h>
#include <stdarg.h>

#include "../StringTokenizer/stringTokenizer.h"

#define MAXLINELENGTH 512

typedef enum IOTYPE
{
	IOTYPE_NONE,
	IOTYPE_READ,
	IOTYPE_WRITE
} IOTYPE;

class CSVManager
{
private:
	FILE * pFile;
	IOTYPE iIOTYPE;
	int iCurrentReadLine;

public:
	CSVManager();
	~CSVManager();
	bool OpenFile(std::string IN_Path, IOTYPE IN_TYPE);
	bool CloseFile();
	bool ReadLine(int IN_Count, ...);
	bool WriteLine(int IN_Count, ...);

};
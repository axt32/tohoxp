#include "ShooterObject.h"

ShooterObject :: ShooterObject()
{
	bLoaded = false;
}

bool ShooterObject :: SetObject(void * IN_Object)
{
	if (GetLoaded() == true)
	{
		return false;
	}

	pObject = IN_Object;
	SetLoaded(true);
	return true;
}

void * ShooterObject :: GetObject()
{
	return pObject;
}

void ShooterObject :: SetLoaded(bool IN_Flag)
{
	bLoaded = IN_Flag;
}
bool ShooterObject :: GetLoaded()
{
	return bLoaded;
}
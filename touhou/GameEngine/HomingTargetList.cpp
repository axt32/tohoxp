#include "HomingTargetList.h"

HomingTarget :: HomingTarget()
{
	Target_X = 0;
	Target_Y = 0;
	iPlayerShotReferenceCount = 1;
	bEnemyAlive = true;
}

HomingTarget :: HomingTarget (double IN_Target_X, double IN_Target_Y)
{
	Target_X = IN_Target_X;
	Target_Y = IN_Target_Y;
	iPlayerShotReferenceCount = 1;
	bEnemyAlive = true;
}

//list�� ����, ���� ���� �ص� ���ͷ������� ��ȿȭ�� �Ͼ�� �ʴ´�.
std::list <HomingTarget *> vHomingTarget;

bool CheckGarbageHomingTarget(std::list<HomingTarget *>::iterator * IN_pIter)
{
	if ( (**IN_pIter)->bEnemyAlive == false && (**IN_pIter)->iPlayerShotReferenceCount == 0)
	{
		delete (**IN_pIter);
		vHomingTarget.erase( *IN_pIter );
		return false;
	}

	return true;
}

void ClearHomingTargetList()
{
	if ( vHomingTarget.size() > 0)
	{
		std::list <HomingTarget *>::iterator Iter = vHomingTarget.begin();
		
		while ( true )
		{
			if (Iter == vHomingTarget.end())
			{
				break;
			}

			if (*Iter != NULL)
			{
				delete (*Iter);
			}

			Iter++;
		}
		vHomingTarget.clear();
	}
}
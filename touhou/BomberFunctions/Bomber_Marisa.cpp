#include "Bomber_Marisa.h"

void Bomber_Marisa_Init(GamePlayer * IN_GamePlayer, int IN_iParam0, int IN_iParam1, int IN_iParam2, int IN_iParam3, int IN_iParam4)
{
	//IN_iParam0 = FarY (X10)
	//IN_iParam1 = 보스에게 주는 Damage.
	AddPlayerShot(&PlayerShot_Marisa_Bomber, 0.0, 0.0, (double)IN_iParam0 / 10.0, IN_iParam0, IN_iParam1, IN_iParam2, IN_iParam3, IN_iParam4, true);
	Sound_MasterSpark.Play(false, NULL, fVolume_SE);
}
void Bomber_Marisa	(GamePlayer *IN_GamePlayer)
{
	std::vector<GamePlayerShot *>::iterator Iter = GamePlayerShotVector.begin();

	bool bBomberFound = false;
	if (GamePlayerShotVector.size() > 0)
	{
		while ( true )
		{
			if ( Iter == GamePlayerShotVector.end())
			{
				break;
			}

			if ( (*Iter)->iPlayerShotType == PLAYERSHOT_TYPE_MARISA_BOMBER)
			{
				bBomberFound = true;
				break;
			}

			Iter++;

		}
	}

	if (bBomberFound == false)
	{
		IN_GamePlayer->bNowBomber = false;
		return;
	}

}
#include "Game_Stage1.h"

bool bOldStatus = true;		//보스전용
bool bOnceLaunched = false;		//보스전용

void InitGameStage1()
{

	RegisterBarrage("Stage1ZakouAttack0", (BarrageFunctionInit)&InitStage1ZakouAttack0, (BarrageFunction)&Stage1ZakouAttack0);
	RegisterBarrage("Stage1ZakouAttack1", (BarrageFunctionInit)&InitStage1ZakouAttack1, (BarrageFunction)&Stage1ZakouAttack1);
	RegisterBarrage("ZakouAttack1", (BarrageFunctionInit)&InitZakouAttack1, (BarrageFunction)&ZakouAttack1);
	RegisterBarrage("ZakouAttack9", (BarrageFunctionInit)&InitZakouAttack9, (BarrageFunction)&ZakouAttack9);

	//패턴 1
	AddEnemy("0:Type:0@0:HP:20@60:Speed:15@60:Angle:270@60:Locate:30:-180@60:GoTo:30:999");
	AddEnemy("0:Type:0@0:HP:20@60:Speed:15@60:Angle:270@60:Locate:110:-120@60:GoTo:110:999");
	AddEnemy("0:Type:3@0:HP:20@60:Speed:15@60:Angle:270@60:Locate:190:-60@60:GoTo:190:999@60:BarrageName:30:5:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@60:Speed:15@60:Angle:270@60:Locate:270:-120@60:GoTo:270:999");
	AddEnemy("0:Type:0@0:HP:20@60:Speed:15@60:Angle:270@60:Locate:350:-180@60:GoTo:350:999");

	AddEnemy("0:Type:0@0:HP:20@180:Speed:15@180:Angle:270@180:Locate:30:-180@180:GoTo:30:999");
	AddEnemy("0:Type:0@0:HP:20@180:Speed:15@180:Angle:270@180:Locate:110:-120@180:GoTo:110:999");
	AddEnemy("0:Type:3@0:HP:20@180:Speed:15@180:Angle:270@180:Locate:190:-60@180:GoTo:190:999@180:BarrageName:30:5:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@180:Speed:15@180:Angle:270@180:Locate:270:-120@180:GoTo:270:999");
	AddEnemy("0:Type:0@0:HP:20@180:Speed:15@180:Angle:270@180:Locate:350:-180@180:GoTo:350:999");

	AddEnemy("0:Type:0@0:HP:20@300:Speed:15@300:Angle:270@300:Locate:30:-180@300:GoTo:30:999");
	AddEnemy("0:Type:0@0:HP:20@300:Speed:15@300:Angle:270@300:Locate:110:-120@300:GoTo:110:999");
	AddEnemy("0:Type:3@0:HP:20@300:Speed:15@300:Angle:270@300:Locate:190:-60@300:GoTo:190:999@300:BarrageName:30:5:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@300:Speed:15@300:Angle:270@300:Locate:270:-120@300:GoTo:270:999");
	AddEnemy("0:Type:0@0:HP:20@300:Speed:15@300:Angle:270@300:Locate:350:-180@300:GoTo:350:999");

	//패턴 2
	AddEnemy("0:Type:0@0:HP:20@460:Locate:400:50@460:Bezier:120:180:50:180:125@580:Bezier:120:180:205:-40:205@460:BarrageName:30:11:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@520:Locate:400:50@520:Bezier:120:180:50:180:125@640:Bezier:120:180:205:-40:205@520:BarrageName:30:11:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@580:Locate:400:50@580:Bezier:120:180:50:180:125@700:Bezier:120:180:205:-40:205@580:BarrageName:30:11:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@640:Locate:400:50@640:Bezier:120:180:50:180:125@760:Bezier:120:180:205:-40:205@640:BarrageName:30:11:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@700:Locate:400:50@700:Bezier:120:180:50:180:125@820:Bezier:120:180:205:-40:205@700:BarrageName:30:5:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@760:Locate:400:50@760:Bezier:120:180:50:180:125@880:Bezier:120:180:205:-40:205@760:BarrageName:30:11:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@820:Locate:400:50@820:Bezier:120:180:50:180:125@940:Bezier:120:180:205:-40:205@820:BarrageName:30:11:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@880:Locate:400:50@880:Bezier:120:180:50:180:125@1000:Bezier:120:180:205:-40:205@880:BarrageName:30:11:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@940:Locate:400:50@940:Bezier:120:180:50:180:125@1060:Bezier:120:180:205:-40:205@940:BarrageName:30:11:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@1000:Locate:400:50@1000:Bezier:120:180:50:180:125@1120:Bezier:120:180:205:-40:205@1000:BarrageName:30:11:25:0:0:Stage1ZakouAttack1");

	AddEnemy("0:Type:0@0:HP:20@460:Locate:-50:50@460:Bezier:120:205:50:205:125@580:Bezier:120:205:205:440:205@460:BarrageName:30:9:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@520:Locate:-50:50@520:Bezier:120:205:50:205:125@640:Bezier:120:205:205:440:205@520:BarrageName:30:9:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@580:Locate:-50:50@580:Bezier:120:205:50:205:125@700:Bezier:120:205:205:440:205@580:BarrageName:30:9:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@640:Locate:-50:50@640:Bezier:120:205:50:205:125@760:Bezier:120:205:205:440:205@640:BarrageName:30:9:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@700:Locate:-50:50@700:Bezier:120:205:50:205:125@820:Bezier:120:205:205:440:205@700:BarrageName:30:5:25:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@760:Locate:-50:50@760:Bezier:120:205:50:205:125@880:Bezier:120:205:205:440:205@760:BarrageName:30:9:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@820:Locate:-50:50@820:Bezier:120:205:50:205:125@940:Bezier:120:205:205:440:205@820:BarrageName:30:9:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@880:Locate:-50:50@880:Bezier:120:205:50:205:125@1000:Bezier:120:205:205:440:205@880:BarrageName:30:9:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@940:Locate:-50:50@940:Bezier:120:205:50:205:125@1060:Bezier:120:205:205:440:205@940:BarrageName:30:9:25:0:0:Stage1ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@1000:Locate:-50:50@1000:Bezier:120:205:50:205:125@1120:Bezier:120:205:205:440:205@1000:BarrageName:30:9:25:0:0:Stage1ZakouAttack1");



	//패턴 3		////
	AddEnemy("0:Type:0@0:HP:20@1200:Locate:-80:-80@1300:Speed:20@1300:GoTo:48:131@1800:GoTo:-40:182");
	AddEnemy("0:Type:0@0:HP:20@1200:Locate:-40:-80@1300:Speed:20@1300:GoTo:108:131@1800:GoTo:-40:222");
	AddEnemy("0:Type:0@0:HP:20@1200:Locate:0:-80@1300:Speed:20@1300:GoTo:168:131@1800:GoTo:-40:262@1300:BarrageName:30:2:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@1200:Locate:40:-80@1300:Speed:20@1300:GoTo:228:131@1800:GoTo:-40:302");

	//패턴 4
	AddEnemy("0:Type:0@0:HP:20@1800:Locate:-80:-80@1900:Speed:20@1900:GoTo:48:131@2200:GoTo:-40:182");
	AddEnemy("0:Type:0@0:HP:20@1800:Locate:-40:-80@1900:Speed:20@1900:GoTo:108:131@2200:GoTo:-40:222@1900:BarrageName:30:6:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@1800:Locate:0:-80@1900:Speed:20@1900:GoTo:168:131@2200:GoTo:-40:262@1900:BarrageName:30:6:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@1800:Locate:40:-80@1900:Speed:20@1900:GoTo:228:131@2200:GoTo:-40:302");	

	//패턴 5
	AddEnemy("0:Type:0@0:HP:20@2300:Locate:337:-50@2300:Bezier:300:337:395:-50:395");
	AddEnemy("0:Type:0@0:HP:20@2360:Locate:337:-50@2360:Bezier:300:337:395:-50:395");
	AddEnemy("0:Type:0@0:HP:20@2420:Locate:337:-50@2420:Bezier:300:337:395:-50:395@2420:BarrageName:30:-1:20:0:0:ZakouAttack9");
	AddEnemy("0:Type:0@0:HP:20@2480:Locate:337:-50@2480:Bezier:300:337:395:-50:395");
	AddEnemy("0:Type:0@0:HP:20@2540:Locate:337:-50@2540:Bezier:300:337:395:-50:395");
	AddEnemy("0:Type:0@0:HP:20@2600:Locate:337:-50@2600:Bezier:300:337:395:-50:395");
	AddEnemy("0:Type:0@0:HP:20@2660:Locate:337:-50@2660:Bezier:300:337:395:-50:395@2660:BarrageName:30:-1:20:0:0:ZakouAttack9");
	AddEnemy("0:Type:0@0:HP:20@2720:Locate:337:-50@2720:Bezier:300:337:395:-50:395");
	AddEnemy("0:Type:0@0:HP:20@2780:Locate:337:-50@2780:Bezier:300:337:395:-50:395");
	AddEnemy("0:Type:0@0:HP:20@2840:Locate:337:-50@2840:Bezier:300:337:395:-50:395@2840:BarrageName:30:-1:20:0:0:ZakouAttack9");


	AddEnemy("0:Type:0@0:HP:20@2300:Locate:48:-50@2300:Bezier:300:48:395:435:395");
	AddEnemy("0:Type:0@0:HP:20@2360:Locate:48:-50@2360:Bezier:300:48:395:435:395@2360:BarrageName:30:-1:20:0:0:ZakouAttack9");
	AddEnemy("0:Type:0@0:HP:20@2420:Locate:48:-50@2420:Bezier:300:48:395:435:395");
	AddEnemy("0:Type:0@0:HP:20@2480:Locate:48:-50@2480:Bezier:300:48:395:435:395");
	AddEnemy("0:Type:0@0:HP:20@2540:Locate:48:-50@2540:Bezier:300:48:395:435:395");
	AddEnemy("0:Type:0@0:HP:20@2600:Locate:48:-50@2600:Bezier:300:48:395:435:395@2600:BarrageName:30:-1:20:0:0:ZakouAttack9");
	AddEnemy("0:Type:0@0:HP:20@2660:Locate:48:-50@2660:Bezier:300:48:395:435:395");
	AddEnemy("0:Type:0@0:HP:20@2720:Locate:48:-50@2720:Bezier:300:48:395:435:395");
	AddEnemy("0:Type:0@0:HP:20@2780:Locate:48:-50@2780:Bezier:300:48:395:435:395");
	AddEnemy("0:Type:0@0:HP:20@2840:Locate:48:-50@2840:Bezier:300:48:395:435:395@2840:BarrageName:30:-1:20:0:0:ZakouAttack9");


	//패턴 6
	AddEnemy("0:Type:0@0:HP:20@3200:Speed:20@3200:Locate:-50:-50@3200:GoTo:300:202@3400:GoTo:-50:305@3200:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3320:Speed:20@3320:Locate:-50:-50@3320:GoTo:300:202@3520:GoTo:-50:305@3320:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3440:Speed:20@3440:Locate:-50:-50@3440:GoTo:300:202@3640:GoTo:-50:305@3440:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3560:Speed:20@3560:Locate:-50:-50@3560:GoTo:300:202@3760:GoTo:-50:305@3560:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3680:Speed:20@3680:Locate:-50:-50@3680:GoTo:300:202@3880:GoTo:-50:305@3680:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3800:Speed:20@3800:Locate:-50:-50@3800:GoTo:300:202@4000:GoTo:-50:305@3800:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3920:Speed:20@3920:Locate:-50:-50@3920:GoTo:300:202@4120:GoTo:-50:305@3920:BarrageName:30:-1:25:10:3:ZakouAttack1");


	AddEnemy("0:Type:0@0:HP:20@3200:Speed:20@3200:Locate:435:-50@3200:GoTo:100:202@3400:GoTo:435:305@3200:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3320:Speed:20@3320:Locate:435:-50@3320:GoTo:100:202@3520:GoTo:435:305@3320:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3440:Speed:20@3440:Locate:435:-50@3440:GoTo:100:202@3640:GoTo:435:305@3440:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3560:Speed:20@3560:Locate:435:-50@3560:GoTo:100:202@3760:GoTo:435:305@3560:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3680:Speed:20@3680:Locate:435:-50@3680:GoTo:100:202@3880:GoTo:435:305@3680:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3800:Speed:20@3800:Locate:435:-50@3800:GoTo:100:202@4000:GoTo:435:305@3800:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@3920:Speed:20@3920:Locate:435:-50@3920:GoTo:100:202@4120:GoTo:435:305@3920:BarrageName:30:-1:25:10:3:ZakouAttack1");

	//패턴 7
	AddEnemy("0:Type:0@0:HP:20@4200:Speed:25@4200:Locate:337:-50@4200:GoTo:-50:395@4200:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@4260:Speed:25@4260:Locate:337:-50@4260:GoTo:-50:395");
	AddEnemy("0:Type:0@0:HP:20@4320:Speed:25@4320:Locate:337:-50@4320:GoTo:-50:395@4320:BarrageName:30:0:15:60:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@4380:Speed:25@4380:Locate:337:-50@4380:GoTo:-50:395");
	AddEnemy("0:Type:0@0:HP:20@4440:Speed:25@4440:Locate:337:-50@4440:GoTo:-50:395");
	AddEnemy("0:Type:0@0:HP:20@4500:Speed:25@4500:Locate:337:-50@4500:GoTo:-50:395");
	AddEnemy("0:Type:0@0:HP:20@4560:Speed:25@4560:Locate:337:-50@4560:GoTo:-50:395");
	AddEnemy("0:Type:0@0:HP:20@4620:Speed:25@4620:Locate:337:-50@4620:GoTo:-50:395@4620:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@4680:Speed:25@4680:Locate:337:-50@4680:GoTo:-50:395");
	AddEnemy("0:Type:0@0:HP:20@4740:Speed:25@4740:Locate:337:-50@4740:GoTo:-50:395");
	AddEnemy("0:Type:0@0:HP:20@4800:Speed:25@4800:Locate:337:-50@4800:GoTo:-50:395@4800:BarrageName:30:-1:25:10:3:ZakouAttack1");

	AddEnemy("0:Type:0@0:HP:20@4200:Speed:25@4200:Locate:48:-50@4200:GoTo:435:395@4200:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@4260:Speed:25@4260:Locate:48:-50@4260:GoTo:435:395");
	AddEnemy("0:Type:0@0:HP:20@4320:Speed:25@4320:Locate:48:-50@4320:GoTo:435:395");
	AddEnemy("0:Type:0@0:HP:20@4380:Speed:25@4380:Locate:48:-50@4380:GoTo:435:395");
	AddEnemy("0:Type:0@0:HP:20@4440:Speed:25@4440:Locate:48:-50@4440:GoTo:435:395");
	AddEnemy("0:Type:0@0:HP:20@4500:Speed:25@4500:Locate:48:-50@4500:GoTo:435:395@4500:BarrageName:30:0:15:60:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@4560:Speed:25@4560:Locate:48:-50@4560:GoTo:435:395");
	AddEnemy("0:Type:0@0:HP:20@4620:Speed:25@4620:Locate:48:-50@4620:GoTo:435:395");
	AddEnemy("0:Type:0@0:HP:20@4680:Speed:25@4680:Locate:48:-50@4680:GoTo:435:395");
	AddEnemy("0:Type:0@0:HP:20@4740:Speed:25@4740:Locate:48:-50@4740:GoTo:435:395");
	AddEnemy("0:Type:0@0:HP:20@4800:Speed:25@4800:Locate:48:-50@4800:GoTo:435:395@4800:BarrageName:30:-1:25:10:3:ZakouAttack1");
	
	//패턴 8
	AddEnemy("0:Type:0@0:HP:20@5000:Speed:20@5000:Angle:270@5000:Locate:30:-180@5000:GoTo:30:999");
	AddEnemy("0:Type:0@0:HP:20@5000:Speed:20@5000:Angle:270@5000:Locate:110:-120@5000:GoTo:110:999");
	AddEnemy("0:Type:3@0:HP:20@5000:Speed:20@5000:Angle:270@5000:Locate:190:-60@5000:GoTo:190:999@5000:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@5000:Speed:20@5000:Angle:270@5000:Locate:270:-120@5000:GoTo:270:999");
	AddEnemy("0:Type:0@0:HP:20@5000:Speed:20@5000:Angle:270@5000:Locate:350:-180@5000:GoTo:350:999");

	//패턴 9
	AddEnemy("0:Type:0@0:HP:20@5200:Locate:400:100@5200:Bezier:120:180:100:180:175@5320:Bezier:120:180:255:-40:255@5200:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@5260:Locate:400:100@5260:Bezier:120:180:100:180:175@5380:Bezier:120:180:255:-40:255");
	AddEnemy("0:Type:0@0:HP:20@5320:Locate:400:100@5320:Bezier:120:180:100:180:175@5440:Bezier:120:180:255:-40:255");
	AddEnemy("0:Type:0@0:HP:20@5380:Locate:400:100@5380:Bezier:120:180:100:180:175@5500:Bezier:120:180:255:-40:255");
	AddEnemy("0:Type:0@0:HP:20@5440:Locate:400:100@5440:Bezier:120:180:100:180:175@5560:Bezier:120:180:255:-40:255");
	AddEnemy("0:Type:0@0:HP:20@5500:Locate:400:100@5500:Bezier:120:180:100:180:175@5620:Bezier:120:180:255:-40:255@5500:BarrageName:30:5:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:0@0:HP:20@5560:Locate:400:100@5560:Bezier:120:180:100:180:175@5680:Bezier:120:180:255:-40:255");
	AddEnemy("0:Type:0@0:HP:20@5620:Locate:400:100@5620:Bezier:120:180:100:180:175@5740:Bezier:120:180:255:-40:255");
	AddEnemy("0:Type:0@0:HP:20@5680:Locate:400:100@5680:Bezier:120:180:100:180:175@5800:Bezier:120:180:255:-40:255");
	AddEnemy("0:Type:0@0:HP:20@5740:Locate:400:100@5740:Bezier:120:180:100:180:175@5860:Bezier:120:180:255:-40:255");
	AddEnemy("0:Type:0@0:HP:20@5800:Locate:400:100@5800:Bezier:120:180:100:180:175@5920:Bezier:120:180:255:-40:255@5800:BarrageName:30:-1:25:10:3:ZakouAttack1");

	AddEnemy("0:Type:0@0:HP:20@5200:Locate:-50:100@5200:Bezier:120:205:100:205:175@5320:Bezier:120:205:255:440:255@5200:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@5260:Locate:-50:100@5260:Bezier:120:205:100:205:175@5380:Bezier:120:205:255:440:255");
	AddEnemy("0:Type:0@0:HP:20@5320:Locate:-50:100@5320:Bezier:120:205:100:205:175@5440:Bezier:120:205:255:440:255");
	AddEnemy("0:Type:0@0:HP:20@5380:Locate:-50:100@5380:Bezier:120:205:100:205:175@5500:Bezier:120:205:255:440:255");
	AddEnemy("0:Type:0@0:HP:20@5440:Locate:-50:100@5440:Bezier:120:205:100:205:175@5560:Bezier:120:205:255:440:255@5440:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@5500:Locate:-50:100@5500:Bezier:120:205:100:205:175@5620:Bezier:120:205:255:440:255@5500:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@5560:Locate:-50:100@5560:Bezier:120:205:100:205:175@5680:Bezier:120:205:255:440:255@5560:BarrageName:30:-1:25:10:3:ZakouAttack1");
	AddEnemy("0:Type:0@0:HP:20@5620:Locate:-50:100@5620:Bezier:120:205:100:205:175@5740:Bezier:120:205:255:440:255");
	AddEnemy("0:Type:0@0:HP:20@5680:Locate:-50:100@5680:Bezier:120:205:100:205:175@5800:Bezier:120:205:255:440:255");
	AddEnemy("0:Type:0@0:HP:20@5740:Locate:-50:100@5740:Bezier:120:205:100:205:175@5860:Bezier:120:205:255:440:255");
	AddEnemy("0:Type:0@0:HP:20@5800:Locate:-50:100@5800:Bezier:120:205:100:205:175@5920:Bezier:120:205:255:440:255@5800:BarrageName:30:-1:25:10:3:ZakouAttack1");

	
	AddEnemy("0:Type:1@0:HP:20@6000:Locate:-50:118@6000:Bezier:130:231:97:95:237@6300:GoTo:-50:327@6000:BarrageName:40:7:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:1@0:HP:20@6030:Locate:-50:110@6030:Bezier:130:251:87:65:247@6330:GoTo:-50:317@6030:BarrageName:40:7:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:1@0:HP:20@6060:Locate:-50:130@6060:Bezier:130:211:57:105:317@6360:GoTo:-50:327@6060:BarrageName:40:7:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:1@0:HP:20@6090:Locate:-50:120@6090:Bezier:130:251:87:65:217@6390:GoTo:-50:317@6090:BarrageName:40:7:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:1@0:HP:20@6120:Locate:-50:110@6120:Bezier:130:221:107:135:237@6420:GoTo:-50:327@6120:BarrageName:40:7:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:1@0:HP:20@6150:Locate:-50:115@6150:Bezier:130:301:87:105:277@6450:GoTo:-50:317@6150:BarrageName:40:7:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:1@0:HP:20@6180:Locate:-50:113@6180:Bezier:130:251:78:77:247@6480:GoTo:-50:337@6180:BarrageName:40:7:20:0:1:Stage1ZakouAttack0");

	AddEnemy("0:Type:2@0:HP:20@6600:Locate:450:152@6600:Bezier:130:222:70:301:194@6900:GoTo:450:327@6600:BarrageName:40:8:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:2@0:HP:20@6630:Locate:450:132@6630:Bezier:130:220:70:301:174@6930:GoTo:450:317@6630:BarrageName:40:8:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:2@0:HP:20@6660:Locate:450:152@6660:Bezier:130:222:88:301:224@6960:GoTo:450:337@6660:BarrageName:40:8:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:2@0:HP:20@6690:Locate:450:112@6690:Bezier:130:211:70:301:296@6990:GoTo:450:317@6690:BarrageName:40:8:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:2@0:HP:20@6720:Locate:450:152@6720:Bezier:130:222:99:301:184@7020:GoTo:450:327@6720:BarrageName:40:8:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:2@0:HP:20@6750:Locate:450:202@6750:Bezier:130:233:70:301:174@7050:GoTo:450:347@6750:BarrageName:40:8:20:0:1:Stage1ZakouAttack0");
	AddEnemy("0:Type:2@0:HP:20@6780:Locate:450:152@6780:Bezier:130:222:66:301:154@7080:GoTo:450:327@6780:BarrageName:40:8:20:0:1:Stage1ZakouAttack0");

	StopMusicAllinOne();
#ifndef TESTMODE
	FreeMusicAllInOne();
	if (bBGM_Use == true)
	{
		Music_Stage1Field.LoadSound("data.rom", "music/stage1_field.ogg", &MySoundManager);
		Music_Stage1Field.Play(true, NULL, fVolume_BGM);
		ShowBGMName("동방요요몽 - Ancient Temple");
	}
#endif

}

void InitStage1Boss()
{

	GameBoss * pNewBoss = new GameBoss();
	pBoss = pNewBoss;
	pNewBoss->SetSprite(&Spr_Boss_Stage1);
	pNewBoss->bAutoNextFrame = false;
	pNewBoss->bRotate = false;
	pNewBoss->iCurrentFrame = 0;
	//pEnemy->SetExtraSurface(&Spr_EnemyType0_A, &Spr_EnemyType0_B);

	//	pEnemy->iCollisionModel = COLLISIONMODEL_CIRCLE;
	//	pEnemy->fCollisionRadius = (double)(Spr_EnemyType0.GetWidth() / 2);

	pNewBoss->x = ((double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X) / 2.0 - ((double)(Spr_Boss_Stage1.GetWidth()) / (double)2.0);
	pNewBoss->y = -100;
	pNewBoss->fDest_X = pNewBoss->x;
	pNewBoss->fDest_Y = 123;
	pNewBoss->speed = 2.0;
	pNewBoss->SetAngle(270.0);
	pNewBoss->bGoTo = true;
	pNewBoss->bMovable = true;
	pNewBoss->bPermitOutside = true;

	pNewBoss->AddCollision(0.0, -12.0, COLLISIONMODEL_CIRCLE, 12.0);
	pNewBoss->AddCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, 12.0);
	pNewBoss->AddCollision(0.0, 12.0, COLLISIONMODEL_CIRCLE, 12.0);

	pNewBoss->AddGrazeCollision(0.0, -12.0, COLLISIONMODEL_CIRCLE, 12.0);
	pNewBoss->AddGrazeCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, 12.0);
	pNewBoss->AddGrazeCollision(0.0, 12.0, COLLISIONMODEL_CIRCLE, 12.0);
//	pNewBoss->AddGrazeCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, (double)(Spr_Boss_Stage1.GetWidth()) / 2.0);

	pNewBoss->iCurrentSpell = 0;	//0부터.

	pNewBoss->pSpellPortrait = &Spr_CutIn_Youmu;
	
	GameSmallSizeFont.PrintFont(&PrintedBossName, "콘파쿠 요우무", 119, 221, 153, FONT_BLENDED);

	RegisterSpell(pBoss, "유귀검 「요동아귀의 단식」", 800, (SpellInit)(&Stage1BossSpell0Init), (SpellInit)(&Stage1BossSpell0), 90);
	RegisterSpell(pBoss, "옥계검 「이백유순의 일섬」", 800, (SpellInit)(&Stage1BossSpell1Init), (SpellInit)(&Stage1BossSpell1), 90);
	RegisterSpell(pBoss, "축취검 「무위무책의 명벌」", 800, (SpellInit)(&Stage1BossSpell2Init), (SpellInit)(&Stage1BossSpell2), 90);

	GameEnemyVector.push_back(pBoss);

	Stage.SetSprite(&Spr_Stage1_Boss);
	Stage.iScrollType = SCROLLTYPE_DIAGONAL;
	Stage.fSpeedX = Stage.speed;
	Stage.fPosX = UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + 1;
	Stage.fPosY = UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT + 1;
}

void InitStage1Event()
{

	DeleteAllChara();
	DeleteAllScripts();

	iColor_Event_CharaName_R = 160;
	iColor_Event_CharaName_G = 0;
	iColor_Event_CharaName_B = 160;

	switch (Player.iPlayerCharaType)
	{
	case PLAYERCHARA_REIMU:

		RegisterChara("레이무", 1, &Spr_Portrait_Reimu0);
		RegisterChara("요우무", 1, &Spr_Portrait_Youmu0);

		AddScript("레이무", 0, "", 0, 0, "이 불길한 느낌. 그다지 탐탁하지 않은데.");
		AddScript("레이무", 0, "요우무", 0, 1, "모두가 소란스럽다 생각했더니 살아있는 인간이었구나.");
		AddScript("레이무", 0, "요우무", 0, 0, "...설마 했지만 여기는...");
		AddScript("레이무", 0, "요우무", 0, 1, "옛날엔 살아 있었던 자들이 머무르는 곳이야.");
		AddScript("레이무", 0, "요우무", 0, 0, "저 세상? 역시 부름을 받고 있었던 걸까.");
		AddScript("레이무", 0, "요우무", 0, 1, "당신은, 아직 부름받지 않았어.");
		AddScript("레이무", 0, "요우무", 0, 0, "그건 그렇다 치고");
		AddScript("레이무", 0, "요우무", 0, 0, "이렇게 쉽사리, 보통 사람이 저 세상에 들어오면 위험하지 않겠어.");
		AddScript("레이무", 0, "요우무", 0, 1, "당신이 멋대로 결계를 깨고 들어온 거겠지!");
		AddScript("레이무", 0, "요우무", 0, 0, "그런 결계, 간단하게 깨졌는걸.");
		AddScript("레이무", 0, "요우무", 0, 1, "들어오지 마시오, 라는 의사 표시로 결계가 쳐져 있었던 거잖아.");
		AddScript("레이무", 0, "요우무", 0, 1, "'위험하니 오르지 말 것' 이라 써진 전신주에 기어오르는 어린애도 아니고.");
		AddScript("레이무", 0, "요우무", 0, 1, "멋대로 결계 깨고 들어와서, 멋대로 위험하다던가 하고 궁시렁거리면 안되지.");
		AddScript("레이무", 0, "요우무", 0, 0, "말을 잘 하는 유령이네.");
		AddScript("레이무", 0, "요우무", 0, 1, "난 반은 유령이 아니라구!");
		AddScript("레이무", 0, "요우무", 0, 0, "그 부분을 정정하는 거야?");
		AddScript("레이무", 0, "요우무", 0, 1, "아무튼, 이제 아주 조금만 더 봄이 모이면 이 '사이교우 아야카시' 가 활짝 피게 돼.");
		AddScript("레이무", 0, "요우무", 0, 1, "당신이 가지고 있는 '얼마 없는 봄' 이, 활짝 피게 만드는 결정적 실마리가 되는 거야.");
		AddScript("레이무", 0, "요우무", 0, 0, "말을 잘 하는 반쪽짜리 유령.");
		AddScript("레이무", 0, "요우무", 0, 1, "얘기 듣고 있어?");
		AddScript("레이무", 0, "요우무", 0, 1, "당신은 여기서 검에 베여 끝장나는 거라니까.");
		AddScript("레이무", 0, "요우무", 0, 0, "저 세상에서 죽어도, 저 세상에 가는 걸까.");
		AddScript("레이무", 0, "요우무", 0, 1, "당신은 지옥행.");
		AddScript("레이무", 0, "요우무", 0, 0, "아, 여기 지옥 아니었어?");
		break;
	case PLAYERCHARA_MARISA:
		RegisterChara("마리사", 1, &Spr_Portrait_Marisa0);
		RegisterChara("요우무", 1, &Spr_Portrait_Youmu0);

		AddScript("마리사", 0, "", 0, 0, "꽤 따뜻해졌군.");
		AddScript("마리사", 0, "요우무", 0, 1, "모두가 소란스럽다 생각했더니 살아있는 인간이었구나.");
		AddScript("마리사", 0, "요우무", 0, 0, "내가 시체라면 소란스럽지 않는 거냐?");
		AddScript("마리사", 0, "요우무", 0, 1, "안 그래.");
		AddScript("마리사", 0, "요우무", 0, 1, "인간이 여기 백옥루에 온다는 건 그 자체가 죽음에 해당할 터인걸.");
		AddScript("마리사", 0, "요우무", 0, 0, "난 분명히 살아있다고. ");
		AddScript("마리사", 0, "요우무", 0, 1, "당신은, 그 결계를 스스로 넘어 들어왔어.");
		AddScript("마리사", 0, "요우무", 0, 1, "그 어리석음이라면 영혼들이 시끄러워질 만도 하겠지.");
		AddScript("마리사", 0, "요우무", 0, 0, "아무튼, 여긴 따뜻해서 좋은데.");
		AddScript("마리사", 0, "요우무", 0, 1, "그거야 뭐, 환상향 전체의 봄이 모여있으니까 말이야.");
		AddScript("마리사", 0, "요우무", 0, 1, "보통의 벚꽃이라면 활짝 핀 것 이상으로 피었어.");
		AddScript("마리사", 0, "요우무", 0, 0, "시체가 우아하게 꽃놀이라니 멋부리고 있군 그래.");
		AddScript("마리사", 0, "요우무", 0, 1, "그래도 '사이교우 아야카시' 가 만발하기엔 부족해...");
		AddScript("마리사", 0, "요우무", 0, 0, "사이교우 아야카시?");
		AddScript("마리사", 0, "요우무", 0, 1, "우리가 자랑하는 요괴 벚꽃이야.");
		AddScript("마리사", 0, "요우무", 0, 0, "그건 좀 보고 싶은 기분도 드는데.");
		AddScript("마리사", 0, "요우무", 0, 1, "아무튼, 이제 조금만 더 봄이 모이면 이 사이교우 아야카시도 활짝 피게 되겠지.");
		AddScript("마리사", 0, "요우무", 0, 1, "당신이 가지고 있는 '얼마 없는 봄' 이, 활짝 피게 만드는 결정적 실마리가 되는 거야.");
		AddScript("마리사", 0, "요우무", 0, 0, "하지만, 모처럼 모은 봄을 넘겨줄 생각따위 있을 리도 없어.");
		AddScript("마리사", 0, "요우무", 0, 1, "활짝 피게 되기까지 바로 금방 ! ");
		AddScript("마리사", 0, "요우무", 0, 0, "이렇게 된 거, 네가 모은 봄을 내가 전부 뺏어서 그 요괴 벚꽃을 피워 주지. ");
		AddScript("마리사", 0, "요우무", 0, 1, "내가 모은 봄을 넘길 수야 없지.");
		AddScript("마리사", 0, "요우무", 0, 0, "나도다.");
		AddScript("마리사", 0, "요우무", 0, 1, "...요괴가 제련한 이 누관검에 베이지 않는 것 따위, 거의 없다구!");
		break;
	case PLAYERCHARA_REISEN:
		RegisterChara("사쿠야", 1, &Spr_Portrait_Reisen0);
		RegisterChara("요우무", 1, &Spr_Portrait_Youmu0);

		AddScript("사쿠야", 0, "", 0, 0, "나와.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "모두가 소란스럽다 했더니 살아있는 인간이었구나.");
		AddScript("사쿠야", 0, "요우무", 0, 0, "겨우 원흉이 있는 곳에 도착한 것 같네.");
		AddScript("사쿠야", 0, "요우무", 0, 0, "꼬박 하루가 걸려 버렸어.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "이런 곳까지 와서는 여유가 많네.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "여기는 백옥루. 죽은 자들이 머무르는 곳이야.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "산 사람의 상식으로 생각하면 호된 꼴을 당할 걸.");
		AddScript("사쿠야", 0, "요우무", 0, 0, "'죽은 사람은 말이 없다'.");
		AddScript("사쿠야", 0, "요우무", 0, 0, "순순히 봄을 돌려주실까.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "이제 조금밖에 안 남았는걸.");
		AddScript("사쿠야", 0, "요우무", 0, 0, "조금이라도 안 돼.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "이제 곧 '사이교우 아야카시' 가 활짝 피게 돼.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "보통의 봄으로는 절대 만발하게 만들 수 없다구.");
		AddScript("사쿠야", 0, "요우무", 0, 0, "안된다니까.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "당신이 가지고 있는 '얼마 없는 봄' 으로 '사이교우 아야카시'도 분명 만발하게 되겠지.");
		AddScript("사쿠야", 0, "요우무", 0, 0, "말을 듣고 있는거야?");
		AddScript("사쿠야", 0, "요우무", 0, 0, "그런 것 때문에, 난 추위에 떨어 왔었다구.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "여긴 따뜻하잖아?");
		AddScript("사쿠야", 0, "요우무", 0, 0, "뭐 됐어.");
		AddScript("사쿠야", 0, "요우무", 0, 0, "'죽은 자는 말이 없다' 랬지.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "'죽은 자는 말이 없다'.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "그 봄을 모두 빼앗을 뿐이야.");
		AddScript("사쿠야", 0, "요우무", 0, 0, "내 나이프로, 유령도 벨 수 있을까?");
		AddScript("사쿠야", 0, "요우무", 0, 1, "요괴가 제련한 이 누관검에 베이지 않는 것 따위, 조금밖에 없다구!");
		break;
	}


	StartScript();

	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;
	iGameState_Game_Status = GAMESTATE_GAME_EVENT;
}

void Stage1BossSpell0Init()
{
	StopMusicAllinOne();
	FreeMusicAllInOne();
#ifndef TESTMODE
	if (bBGM_Use == true)
	{
		Music_Stage1Boss.LoadSound("data.rom", "music/stage1_boss.ogg", &MySoundManager);
		Music_Stage1Boss.Play(true, NULL, fVolume_BGM);
		ShowBGMName("히로아리 괴조를 쏘다 - Till When");
	}
#endif

	DeleteAllBarrage();
	RegisterBarrage("Stage1BossAttack0", (BarrageFunctionInit)&InitStage1BossAttack0, (BarrageFunction)&Stage1BossAttack0);
	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;

	bOldStatus = true;
}

void Stage1BossSpell0()
{
	//보스전에서 보스 캐릭터의 처리는 스크립트 엔진을 사용하지 않습니다.

	if (bOldStatus & (pBoss->bMovable) == false)	//수정 요망.
	{
		std::vector<GameBarrage*>::iterator Found_Barrage;
		if (FindBarrage("Stage1BossAttack0", &Found_Barrage) == true)
		{
			pBoss->pvBarrage.push_back(new GameBarrage(*Found_Barrage));
			(*(pBoss->pvBarrage.end() -1))->pInit( pBoss, 0,0,0,0,0, (*(pBoss->pvBarrage.end() -1))->iBarrageParameters);
		}
	}

	bOldStatus = pBoss->bMovable;

	if (pBoss->bMuteki == true)
	{
		iGameFrame = 199;		//200 - 1
	}
	else
	{
		if (iGameFrame == 600)
		{
			DeleteAllBarrage(pBoss);
			MoveBoss(70.0, 78.0);
		}
		else if (iGameFrame == 1200)
		{
			DeleteAllBarrage(pBoss);
			MoveBoss(292, 78.0);
		}
		else if (iGameFrame == 1800)
		{
			DeleteAllBarrage(pBoss);
			MoveBoss(((double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X) / 2.0 - ((double)(Spr_Boss_Stage1.GetWidth()) / (double)2.0), 123.0);
			iGameFrame = 0;		//테스트.
			iOldGameFrame = 0;
			iOldGameFrame_EnemyDamaged = 0;
			iOldGameFrame_EnemyDead = 0;
		}
	}
}

void Stage1BossSpell1Init()
{
	DeleteAllBarrage();
	RegisterBarrage("Stage1BossAttack1", (BarrageFunctionInit)&InitStage1BossAttack1, (BarrageFunction)&Stage1BossAttack1);
	RegisterBarrage("Stage1BossAttack1MicroThread0", (BarrageFunctionInit)&InitStage1BossAttack1MicroThread0, (BarrageFunction)&Stage1BossAttack1MicroThread0);
	RegisterBarrage("Stage1BossAttack1MicroThread1", (BarrageFunctionInit)&InitStage1BossAttack1MicroThread1, (BarrageFunction)&Stage1BossAttack1MicroThread1);
	RegisterBarrage("Stage1BossAttack1MicroThread2", (BarrageFunctionInit)&InitStage1BossAttack1MicroThread2, (BarrageFunction)&Stage1BossAttack1MicroThread2);
//	RegisterBarrage("SixWingsAst", (BarrageFunctionInit)&InitSixWingsAst, (BarrageFunction)&SixWingsAst);

	pBoss->fDest_X = ((double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X) / 2.0 - ((double)(Spr_Boss_Stage1.GetWidth()) / (double)2.0), 123.0;
	pBoss->fDest_Y = 100;
	pBoss->SetAngle(GetAngle(pBoss->x, pBoss->y, pBoss->fDest_X, pBoss->fDest_Y));
	pBoss->speed = 2.0;
	pBoss->bGoTo = true;
	pBoss->bMovable = true;
	
	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;

	bOldStatus = true;
	bOnceLaunched = false;
}
void Stage1BossSpell1()
{
	static int iAddAngle = 0;
	
	if (pBoss->bMuteki == true)
	{
		iGameFrame = 120;
	}

	if (pBoss->bMovable == false && iGameFrame >= 120)
	{
		if (pBoss->bMuteki == false)
		{
			DeleteAllBarrage(pBoss);
			MakeBossBarrage("Stage1BossAttack1", iAddAngle, 0, 0, 0, 0);
			iAddAngle = Angle360(iAddAngle + 30);

			if (bOnceLaunched == false)
			{
				double fLeftCircle_X = (pBoss->GetCenterX()) - 100 - Spr_BulletType18.GetWidth() / 2.0;
				double fLeftCircle_Y = (pBoss->GetCenterY()) - 10 - Spr_BulletType18.GetHeight() / 2.0;

				AddBullet(BULLET_TYPE18, 1, pBoss->GetCenterX(), pBoss->GetCenterY(), 0.0, 0.0, 2.0, 0.0, true);
				GetLastBullet()->fDest_X = fLeftCircle_X;
				GetLastBullet()->fDest_Y = fLeftCircle_Y;
				GetLastBullet()->speed = 2.0;
				GetLastBullet()->SetAngle(GetAngle(pBoss->x, pBoss->y, (*(GameBulletVector.end() - 1))->fDest_X, (*(GameBulletVector.end() - 1))->fDest_Y));
				GetLastBullet()->bGoTo = true;
				GetLastBullet()->bMuteki = true;
				
				int iDelay = 5;
				int iAngle = 2700;
				int iSpeed = 43;

				MakeMicroThread("Stage1BossAttack1MicroThread1", 0, iDelay, iAngle, iSpeed, 100);
				MakeMicroThread("Stage1BossAttack1MicroThread2", (int)((pBoss->x) * 10.0), (int)((pBoss->y) * 10.0), (int)((*(GameBulletVector.end() - 1))->GetAngle() * 10.0), 20, 0);
				
				double fRightCircle_X = (pBoss->GetCenterX()) + 100 - Spr_BulletType18.GetWidth() / 2.0;
				double fRightCircle_Y = (pBoss->GetCenterY()) - 10 - Spr_BulletType18.GetHeight() / 2.0;

				AddBullet(BULLET_TYPE18, 1, pBoss->GetCenterX(), pBoss->GetCenterY(), 0.0, 0.0, 2.0, 0.0, true);
				GetLastBullet()->fDest_X = fRightCircle_X;
				GetLastBullet()->fDest_Y = fRightCircle_Y;
				GetLastBullet()->speed = 2.0;
				GetLastBullet()->SetAngle(GetAngle(pBoss->x, pBoss->y, (*(GameBulletVector.end() - 1))->fDest_X, (*(GameBulletVector.end() - 1))->fDest_Y));
 				GetLastBullet()->bGoTo = true;
				GetLastBullet()->bMuteki = true;

				MakeMicroThread("Stage1BossAttack1MicroThread1", 0, iDelay, iAngle, iSpeed, -100);
				MakeMicroThread("Stage1BossAttack1MicroThread2", (int)((pBoss->x) * 10.0), (int)((pBoss->y) * 10.0), (int)((*(GameBulletVector.end() - 1))->GetAngle() * 10.0), 20, 0);

				bOnceLaunched = true;
			}

		}
	}

}

void Stage1BossSpell2Init()
{
	DeleteAllBarrage();
	RegisterBarrage("Stage1BossAttack2", (BarrageFunctionInit)&InitStage1BossAttack2, (BarrageFunction)&Stage1BossAttack2);
	RegisterBarrage("Stage1BossAttack2MicroThread0", (BarrageFunctionInit)&InitStage1BossAttack2MicroThread0, (BarrageFunction)&Stage1BossAttack2MicroThread0);
	RegisterBarrage("Stage1BossAttack2_1", (BarrageFunctionInit)&InitStage1BossAttack2_1, (BarrageFunction)&Stage1BossAttack2_1);

	MakeBossBarrage("Stage1BossAttack2", 0, 0, 0, 0, 0);
	MakeBossBarrage("Stage1BossAttack2_1", 0, 40, 0, 0, 0);

	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;

	bOldStatus = true;
}

void Stage1BossSpell2()
{

	if (pBoss->bMuteki == true)
	{
		iGameFrame = 199;		//200 - 1
	}
	else
	{
		if (iGameFrame == 600)
		{
			MoveBoss(70.0 - 30.0 + (double)(rand()%60), 78.0 - 30.0 + (double)(rand()%60));
		}
		else if (iGameFrame == 1200)
		{
			MoveBoss(292 - 30.0 + (double)(rand()%60), 78.0 - 30.0 + (double)(rand()%60));
		}
		else if (iGameFrame == 1800)
		{
			MoveBoss(((double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X) / 2.0 - ((double)(Spr_Boss_Stage1.GetWidth()) / (double)2.0),  78.0 - 30.0 + (double)(rand()%60));
			iGameFrame = 0;		//테스트.
			iOldGameFrame = 0;
			iOldGameFrame_EnemyDamaged = 0;
			iOldGameFrame_EnemyDead = 0;
		}
	}

}

void InitStage1Event_After_Boss()
{
	DeleteAllChara();
	DeleteAllScripts();

	iColor_Event_CharaName_R = 160;
	iColor_Event_CharaName_G = 0;
	iColor_Event_CharaName_B = 160;

	switch (Player.iPlayerCharaType)
	{
	case PLAYERCHARA_REIMU:
		RegisterChara("레이무", 1, &Spr_Portrait_Reimu0);
		RegisterChara("요우무", 1, &Spr_Portrait_Youmu0);

		AddScript("레이무", 0, "요우무", 0, 0, "여긴 이미 충분히 봄이잖아.");
		AddScript("레이무", 0, "요우무", 0, 0, "이 이상 뭘 하겠다는 거야?");
		AddScript("레이무", 0, "요우무", 0, 1, "아가씨께서 올해야말로 벚꽃을 활짝 피게 만드신다고......");
		AddScript("레이무", 0, "요우무", 0, 1, "'사이교우 아야카시' 가 만발하게 만들기 위해선 이 정도의 봄으로는...");
		AddScript("레이무", 0, "요우무", 0, 0, "활짝 피면 좋은일이 있는 걸까.");
		break;
	case PLAYERCHARA_MARISA:
		RegisterChara("마리사", 1, &Spr_Portrait_Marisa0);
		RegisterChara("요우무", 1, &Spr_Portrait_Youmu0);

		AddScript("마리사", 0, "요우무", 0, 0, "자, 그 요괴 벚꽃이 있는 곳까지 안내해 주실까.");
		AddScript("마리사", 0, "요우무", 0, 1, "어차피 '사이교우 아야카시'가 만발하게 된다면 그래도 좋겠지만.");
		AddScript("마리사", 0, "요우무", 0, 1, "뭔가 납득이 안가는데...");
		AddScript("마리사", 0, "요우무", 0, 0, "누가 만발하게 만든댔냐?");
		AddScript("마리사", 0, "요우무", 0, 0, "난 꽃구경을 하고 싶은것 뿐이라고. ");
		break;
	case PLAYERCHARA_REISEN:
		RegisterChara("사쿠야", 1, &Spr_Portrait_Reisen0);
		RegisterChara("요우무", 1, &Spr_Portrait_Youmu0);

		AddScript("사쿠야", 0, "요우무", 0, 0, "다행이다. 유령도 베어지는 모양이네.");
		AddScript("사쿠야", 0, "요우무", 0, 0, "은이라서 그런가?");
		AddScript("사쿠야", 0, "요우무", 0, 1, "난 반은 유령이 아니야.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "하지만 사이교우지 아가씨께서는 완벽한 영체.");
		AddScript("사쿠야", 0, "요우무", 0, 1, "그렇게 진부한 무기로 상대가 될까?");
		AddScript("사쿠야", 0, "요우무", 0, 0, "근데, 왜 그 아가씨와 싸우는 방향으로 얘길 이끄는 건데. ");
		break;
	}
	StartScript();

// 	pBoss->fDest_X = (double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X / 2.0 - ((double)(Spr_Boss_Stage1.GetWidth()) / (double)2.0), 123.0;
// 	pBoss->fDest_Y = 100;
// 	pBoss->SetAngle(GetAngle(pBoss->x, pBoss->y, pBoss->fDest_X, pBoss->fDest_Y));
// 	pBoss->speed = 2.0;
// 	pBoss->bGoTo = true;
// 	pBoss->bMovable = true;
// 
// 	iGameFrame = 0;
// 	iOldGameFrame = 0;
// 	iGameState_Game_Status = GAMESTATE_GAME_EVENT_AFTER_BOSS;
}

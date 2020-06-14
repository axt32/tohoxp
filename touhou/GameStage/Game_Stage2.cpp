#include "Game_Stage2.h"

bool bOldStatus2 = true;
bool bSpellMade2 = false;

int iHangonchou_CurrentAngle = 0;

void InitGameStage2()
{

	RegisterBarrage("ZakouAttack0", (BarrageFunctionInit)&InitZakouAttack0, (BarrageFunction)&ZakouAttack0);
	RegisterBarrage("ZakouAttack1", (BarrageFunctionInit)&InitZakouAttack1, (BarrageFunction)&ZakouAttack1);
	RegisterBarrage("ZakouAttack2", (BarrageFunctionInit)&InitZakouAttack2, (BarrageFunction)&ZakouAttack2);
	RegisterBarrage("ZakouAttack3", (BarrageFunctionInit)&InitZakouAttack3, (BarrageFunction)&ZakouAttack3);
	RegisterBarrage("ZakouAttack4", (BarrageFunctionInit)&InitZakouAttack4, (BarrageFunction)&ZakouAttack4);
	RegisterBarrage("ZakouAttack5", (BarrageFunctionInit)&InitZakouAttack5, (BarrageFunction)&ZakouAttack5);
	RegisterBarrage("ZakouAttack6", (BarrageFunctionInit)&InitZakouAttack6, (BarrageFunction)&ZakouAttack6);
	RegisterBarrage("ZakouAttack7", (BarrageFunctionInit)&InitZakouAttack7, (BarrageFunction)&ZakouAttack7);
	RegisterBarrage("ZakouAttack8", (BarrageFunctionInit)&InitZakouAttack8, (BarrageFunction)&ZakouAttack8);
	RegisterBarrage("ZakouAttack9", (BarrageFunctionInit)&InitZakouAttack9, (BarrageFunction)&ZakouAttack9);
	RegisterBarrage("ZakouAttack10", (BarrageFunctionInit)&InitZakouAttack10, (BarrageFunction)&ZakouAttack10);
	RegisterBarrage("ZakouAttack7MicroThread0", (BarrageFunctionInit)&InitZakouAttack7MicroThread0, (BarrageFunction)&ZakouAttack7MicroThread0);
	RegisterBarrage("ZakouAttack8MicroThread0", (BarrageFunctionInit)&InitZakouAttack8MicroThread0, (BarrageFunction)&ZakouAttack8MicroThread0);


	//패턴1
	AddEnemy("0:Type:0@0:HP:25@90:Locate:103:-117@90:Speed:30@90:GoTo:103:103@160:BarrageName:60:10:5:0:0:ZakouAttack0@600:GoTo:95:500");
	AddEnemy("0:Type:2@0:HP:25@90:Locate:222:-50@90:Speed:30@90:GoTo:208:170@160:BarrageName:60:10:5:0:0:ZakouAttack0@600:GoTo:198:500");
	AddEnemy("0:Type:0@0:HP:25@90:Locate:341:-117@90:Speed:30@90:GoTo:341:103@160:BarrageName:60:10:5:0:0:ZakouAttack0@600:GoTo:301:500");

	//패턴2
	AddEnemy("0:Type:2@0:HP:25@300:Locate:351:-50@300:Speed:30@300:GoTo:39:103@300:BarrageName:60:-1:30:5:4:ZakouAttack1@420:GoTo:504:356");
	AddEnemy("0:Type:0@0:HP:25@300:Locate:351:-50@330:Speed:30@330:GoTo:39:103@330:BarrageName:150:-1:10:30:4:ZakouAttack3@450:GoTo:504:356");
	AddEnemy("0:Type:0@0:HP:25@300:Locate:351:-50@360:Speed:30@360:GoTo:39:103@480:GoTo:504:356");
	AddEnemy("0:Type:0@0:HP:25@300:Locate:351:-50@390:Speed:30@390:GoTo:39:103@510:GoTo:504:356");
	AddEnemy("0:Type:0@0:HP:25@300:Locate:351:-50@420:Speed:30@420:GoTo:39:103@420:BarrageName:60:-1:30:5:4:ZakouAttack1@540:GoTo:504:356");
	AddEnemy("0:Type:0@0:HP:25@300:Locate:351:-50@450:Speed:30@450:GoTo:39:103@570:GoTo:504:356");
	AddEnemy("0:Type:0@0:HP:25@300:Locate:351:-50@480:Speed:30@480:GoTo:39:103@600:GoTo:504:356");
	AddEnemy("0:Type:0@0:HP:25@300:Locate:351:-50@510:Speed:30@510:GoTo:39:103@630:GoTo:504:356");
	AddEnemy("0:Type:0@0:HP:25@300:Locate:351:-50@540:Speed:30@540:GoTo:39:103@540:BarrageName:60:-1:30:5:4:ZakouAttack1@660:GoTo:504:356");
	AddEnemy("0:Type:0@0:HP:25@300:Locate:351:-50@570:Speed:30@570:GoTo:39:103@690:GoTo:504:356");
	AddEnemy("0:Type:0@0:HP:25@300:Locate:351:-50@600:Speed:30@600:GoTo:39:103@720:GoTo:504:356");

	// 	//패턴3

	AddEnemy("0:Type:1@0:HP:25@750:Locate:400:60@750:Bezier:300:169:60:-50:117@750:BarrageName:60:-1:30:5:4:ZakouAttack4");
	AddEnemy("0:Type:1@0:HP:25@750:Locate:400:60@780:Bezier:300:169:60:-50:117@780:BarrageName:150:-1:15:30:4:ZakouAttack3");
	AddEnemy("0:Type:1@0:HP:25@750:Locate:400:60@810:Bezier:300:169:60:-50:117@810:BarrageName:150:-1:15:30:4:ZakouAttack3");
	AddEnemy("0:Type:1@0:HP:25@750:Locate:400:60@840:Bezier:300:169:60:-50:117@840:BarrageName:60:-1:30:5:4:ZakouAttack4");
	AddEnemy("0:Type:1@0:HP:25@750:Locate:400:60@870:Bezier:300:169:60:-50:117@870:BarrageName:60:-1:30:5:4:ZakouAttack4");

	//패턴5
	AddEnemy("0:Type:1@0:HP:25@1200:Locate:400:60@1200:Bezier:300:169:60:-50:117@1200:BarrageName:5:-1:-1:0:0:ZakouAttack6");
	AddEnemy("0:Type:1@0:HP:25@1200:Locate:400:60@1230:Bezier:300:169:60:-50:117@1230:BarrageName:4:-1:-1:0:0:ZakouAttack6");
	AddEnemy("0:Type:1@0:HP:25@1200:Locate:400:60@1260:Bezier:300:169:60:-50:117@1260:BarrageName:3:-1:-1:0:0:ZakouAttack6");
	AddEnemy("0:Type:1@0:HP:25@1200:Locate:400:60@1290:Bezier:300:169:60:-50:117@1290:BarrageName:4:-1:-1:0:0:ZakouAttack6");
	AddEnemy("0:Type:1@0:HP:25@1200:Locate:400:60@1320:Bezier:300:169:60:-50:117@1320:BarrageName:5:-1:-1:0:0:ZakouAttack6");

	//패턴6
	AddEnemy("0:Type:2@0:HP:35@1400:Locate:171:-50@1400:Bezier:120:141:-50:146:82@1400:BarrageName:5:1:5:25:100:ZakouAttack5@2200:Bezier:120:-50:81:-50:337");

	//패턴7
	AddEnemy("0:Type:5@0:HP:35@1500:Locate:75:-50@1500:Speed:25@1500:GoTo:75:132@1600:BarrageName:120:8:0:0:0:ZakouAttack2@2500:GoTo:-50:378");
	AddEnemy("0:Type:5@0:HP:35@1500:Locate:295:-50@1500:Speed:25@1500:GoTo:295:132@1600:BarrageName:120:8:0:0:0:ZakouAttack2@2500:GoTo:430:378");

	//패턴8
	AddEnemy("0:Type:1@0:HP:35@1600:Locate:-50:79@1600:Bezier:300:194:79:450:138@1600:BarrageName:60:-1:30:10:3:ZakouAttack7");
	AddEnemy("0:Type:1@0:HP:35@1600:Locate:-50:79@1630:Bezier:300:194:79:450:138@1630:BarrageName:60:-1:30:10:3:ZakouAttack7");
	AddEnemy("0:Type:1@0:HP:35@1600:Locate:-50:79@1660:Bezier:300:194:79:450:138@1660:BarrageName:60:-1:30:10:3:ZakouAttack7");
	AddEnemy("0:Type:1@0:HP:35@1600:Locate:-50:79@1690:Bezier:300:194:79:450:138@1690:BarrageName:60:-1:30:10:3:ZakouAttack7");
	AddEnemy("0:Type:1@0:HP:35@1600:Locate:-50:79@1720:Bezier:300:194:79:450:138@1720:BarrageName:60:-1:30:10:3:ZakouAttack7");


	//패턴10-1
	AddEnemy("0:Type:2@0:HP:35@2050:Locate:115:-50@2050:Speed:30@2050:GoTo:143:120@2050:BarrageName:5:1:15:2:0:ZakouAttack10@2350:GoTo:-50:359");

	//패턴12-1
	AddEnemy("0:Type:2@0:HP:35@2350:Locate:310:-50@2350:Speed:30@2350:GoTo:222:194@2350:BarrageName:5:1:15:2:0:ZakouAttack10@2650:GoTo:-450:356");

	//패턴14-1
	AddEnemy("0:Type:2@0:HP:35@2650:Locate:135:-50@2650:Speed:30@2650:GoTo:173:130@2650:BarrageName:5:1:15:2:0:ZakouAttack10@3000:GoTo:-50:359");

	//패턴16
//	AddEnemy("0:Type:3@0:HP:10@3000:Locate:32:-1350@3000:Speed:30@3000:Angle:270@3000:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:72:-1320@3000:Speed:30@3000:Angle:270@3001:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:112:-1290@3000:Speed:30@3000:Angle:270@3002:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:152:-1260@3000:Speed:30@3003:Angle:270@3000:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:192:-1230@3000:Speed:30@3000:Angle:270@3004:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:232:-1200@3000:Speed:30@3000:Angle:270@3000:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:272:-1170@3000:Speed:30@3000:Angle:270@3001:BarrageName:45:1:20:3:1:ZakouAttack10");
//	AddEnemy("0:Type:3@0:HP:10@3000:Locate:312:-1140@3000:Speed:30@3000:Angle:270@3002:BarrageName:45:1:20:3:1:ZakouAttack10");

//	AddEnemy("0:Type:3@0:HP:10@3000:Locate:352:-1100@3000:Speed:30@3000:Angle:270@3003:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:312:-1070@3000:Speed:30@3000:Angle:270@3004:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:272:-1040@3000:Speed:30@3000:Angle:270@3000:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:232:-1010@3000:Speed:30@3000:Angle:270@3001:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:192:-980@3000:Speed:30@3000:Angle:270@3002:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:152:-950@3000:Speed:30@3000:Angle:270@3003:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:112:-920@3000:Speed:30@3000:Angle:270@3004:BarrageName:45:1:20:3:1:ZakouAttack10");
//	AddEnemy("0:Type:3@0:HP:10@3000:Locate:72:-890@3000:Speed:30@3000:Angle:270@3000:BarrageName:45:1:20:3:1:ZakouAttack10");

//	AddEnemy("0:Type:3@0:HP:10@3000:Locate:32:-860@3000:Speed:30@3000:Angle:270@3001:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:72:-830@3000:Speed:30@3000:Angle:270@3002:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:112:-800@3000:Speed:30@3000:Angle:270@3003:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:152:-770@3000:Speed:30@3000:Angle:270@3004:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:192:-740@3000:Speed:30@3000:Angle:270@3000:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:232:-710@3000:Speed:30@3000:Angle:270@3001:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:272:-680@3000:Speed:30@3000:Angle:270@3002:BarrageName:45:1:20:3:1:ZakouAttack10");
//	AddEnemy("0:Type:3@0:HP:10@3000:Locate:312:-650@3000:Speed:30@3000:Angle:270@3003:BarrageName:45:1:20:3:1:ZakouAttack10");

//	AddEnemy("0:Type:3@0:HP:10@3000:Locate:352:-620@3000:Speed:30@3000:Angle:270@3004:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:312:-590@3000:Speed:30@3000:Angle:270@3000:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:272:-560@3000:Speed:30@3000:Angle:270@3001:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:232:-530@3000:Speed:30@3000:Angle:270@3002:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:192:-500@3000:Speed:30@3000:Angle:270@3003:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:152:-470@3000:Speed:30@3000:Angle:270@3004:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:112:-440@3000:Speed:30@3000:Angle:270@3000:BarrageName:45:1:20:3:1:ZakouAttack10");
//	AddEnemy("0:Type:3@0:HP:10@3000:Locate:72:-410@3000:Speed:30@3000:Angle:270@3001:BarrageName:45:1:20:3:1:ZakouAttack10");

//	AddEnemy("0:Type:3@0:HP:10@3000:Locate:32:-380@3000:Speed:30@3000:Angle:270@3002:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:72:-350@3000:Speed:30@3000:Angle:270@3003:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:112:-320@3000:Speed:30@3000:Angle:270@3004:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:152:-290@3000:Speed:30@3000:Angle:270@3000:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:192:-260@3000:Speed:30@3000:Angle:270@3001:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:232:-230@3000:Speed:30@3000:Angle:270@3002:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:272:-200@3000:Speed:30@3000:Angle:270@3003:BarrageName:45:1:20:3:1:ZakouAttack10");
	AddEnemy("0:Type:3@0:HP:10@3000:Locate:312:-170@3000:Speed:30@3000:Angle:270@3004:BarrageName:45:1:20:3:1:ZakouAttack10");
//	AddEnemy("0:Type:3@0:HP:10@3000:Locate:352:-140@3000:Speed:30@3000:Angle:270@3000:BarrageName:45:1:20:3:1:ZakouAttack10");

	//패턴17
	AddEnemy("0:Type:0@0:HP:25@3480:Locate:260:-130@3480:Speed:30@3480:GoTo:260:45@3480:BarrageName:30:5:20:5:3:ZakouAttack3@3600:GoTo:-102:98");
	AddEnemy("0:Type:0@0:HP:25@3480:Locate:312:-130@3480:Speed:30@3480:GoTo:312:45@3480:BarrageName:30:5:20:5:3:ZakouAttack3@3600:GoTo:-50:98");
	AddEnemy("0:Type:0@0:HP:25@3480:Locate:260:-90@3480:Speed:30@3480:GoTo:260:85@3495:BarrageName:40:-1:30:0:0:ZakouAttack9@3600:GoTo:-102:138");
	AddEnemy("0:Type:0@0:HP:25@3480:Locate:312:-90@3480:Speed:30@3480:GoTo:312:85@3490:BarrageName:40:-1:30:0:0:ZakouAttack9@3600:GoTo:-50:138");
	AddEnemy("0:Type:0@0:HP:25@3480:Locate:260:-50@3480:Speed:30@3480:GoTo:260:125@3485:BarrageName:40:-1:30:0:0:ZakouAttack9@3600:GoTo:-102:178");
	AddEnemy("0:Type:0@0:HP:25@3480:Locate:312:-50@3480:Speed:30@3480:GoTo:312:125@3480:BarrageName:40:-1:30:0:0:ZakouAttack9@3600:GoTo:-50:178");

	AddEnemy("0:Type:0@0:HP:25@3600:Locate:56:-130@3600:Speed:30@3600:GoTo:56:45@3600:BarrageName:30:5:20:5:3:ZakouAttack3@3720:GoTo:415:98");
	AddEnemy("0:Type:0@0:HP:25@3600:Locate:108:-130@3600:Speed:30@3600:GoTo:108:45@3600:BarrageName:30:5:20:5:3:ZakouAttack3@3720:GoTo:467:98");
	AddEnemy("0:Type:0@0:HP:25@3600:Locate:56:-90@3600:Speed:30@3600:GoTo:56:85@3615:BarrageName:40:-1:30:0:0:ZakouAttack9@3720:GoTo:415:138");
	AddEnemy("0:Type:0@0:HP:25@3600:Locate:108:-90@3600:Speed:30@3600:GoTo:108:85@3610:BarrageName:40:-1:30:0:0:ZakouAttack9@3720:GoTo:467:138");
	AddEnemy("0:Type:0@0:HP:25@3600:Locate:56:-50@3600:Speed:30@3600:GoTo:56:125@3605:BarrageName:40:-1:30:0:0:ZakouAttack9@3720:GoTo:415:178");
	AddEnemy("0:Type:0@0:HP:25@3600:Locate:108:-50@3600:Speed:30@3600:GoTo:108:125@3600:BarrageName:40:-1:30:0:0:ZakouAttack9@3720:GoTo:467:178");

	AddEnemy("0:Type:0@0:HP:25@3720:Locate:260:-130@3720:Speed:30@3720:GoTo:260:45@3720:BarrageName:30:5:20:5:3:ZakouAttack3@3840:GoTo:-102:98");
	AddEnemy("0:Type:0@0:HP:25@3720:Locate:312:-130@3720:Speed:30@3720:GoTo:312:45@3720:BarrageName:30:5:20:5:3:ZakouAttack3@3840:GoTo:-50:98");
	AddEnemy("0:Type:0@0:HP:25@3720:Locate:260:-90@3720:Speed:30@3720:GoTo:260:85@3735:BarrageName:40:-1:30:0:0:ZakouAttack9@3840:GoTo:-102:138");
	AddEnemy("0:Type:0@0:HP:25@3720:Locate:312:-90@3720:Speed:30@3720:GoTo:312:85@3730:BarrageName:40:-1:30:0:0:ZakouAttack9@3840:GoTo:-50:138");
	AddEnemy("0:Type:0@0:HP:25@3720:Locate:260:-50@3720:Speed:30@3720:GoTo:260:125@3725:BarrageName:40:-1:30:0:0:ZakouAttack9@3840:GoTo:-102:178");
	AddEnemy("0:Type:0@0:HP:25@3720:Locate:312:-50@3720:Speed:30@3720:GoTo:312:125@3720:BarrageName:40:-1:30:0:0:ZakouAttack9@3840:GoTo:-50:178");

	AddEnemy("0:Type:0@0:HP:25@3840:Locate:56:-130@3840:Speed:30@3840:GoTo:56:45@3840:BarrageName:30:5:20:5:3:ZakouAttack3@3960:GoTo:415:98");
	AddEnemy("0:Type:0@0:HP:25@3840:Locate:108:-130@3840:Speed:30@3840:GoTo:108:45@3840:BarrageName:30:5:20:5:3:ZakouAttack3@3960:GoTo:467:98");
	AddEnemy("0:Type:0@0:HP:25@3840:Locate:56:-90@3840:Speed:30@3840:GoTo:56:85@3855:BarrageName:40:-1:30:0:0:ZakouAttack9@3960:GoTo:415:138");
	AddEnemy("0:Type:0@0:HP:25@3840:Locate:108:-90@3840:Speed:30@3840:GoTo:108:85@3850:BarrageName:40:-1:30:0:0:ZakouAttack9@3960:GoTo:467:138");
	AddEnemy("0:Type:0@0:HP:25@3840:Locate:56:-50@3840:Speed:30@3840:GoTo:56:125@3845:BarrageName:40:-1:30:0:0:ZakouAttack9@3960:GoTo:415:178");
	AddEnemy("0:Type:0@0:HP:25@3840:Locate:108:-50@3840:Speed:30@3840:GoTo:108:125@3840:BarrageName:40:-1:30:0:0:ZakouAttack9@3960:GoTo:467:178");




	AddEnemy("0:Type:0@0:HP:25@3960:Locate:260:-130@3960:Speed:30@3960:GoTo:260:45@3960:BarrageName:30:5:20:5:3:ZakouAttack3@4080:GoTo:-102:98");
	AddEnemy("0:Type:0@0:HP:25@3960:Locate:312:-130@3960:Speed:30@3960:GoTo:312:45@3965:BarrageName:30:5:20:5:3:ZakouAttack3@4080:GoTo:-50:98");
	AddEnemy("0:Type:0@0:HP:25@3960:Locate:260:-90@3960:Speed:30@3960:GoTo:260:85@3970:BarrageName:40:-1:30:0:0:ZakouAttack9@4080:GoTo:-102:138");
	AddEnemy("0:Type:0@0:HP:25@3960:Locate:312:-90@3960:Speed:30@3960:GoTo:312:85@3960:BarrageName:40:-1:30:0:0:ZakouAttack9@4080:GoTo:-50:138");
	AddEnemy("0:Type:0@0:HP:25@3960:Locate:260:-50@3960:Speed:30@3960:GoTo:260:125@3965:BarrageName:40:-1:30:0:0:ZakouAttack9@4080:GoTo:-102:178");
	AddEnemy("0:Type:0@0:HP:25@3960:Locate:312:-50@3960:Speed:30@3960:GoTo:312:125@3960:BarrageName:40:-1:30:0:0:ZakouAttack9@4080:GoTo:-50:178");

	AddEnemy("0:Type:0@0:HP:25@4080:Locate:56:-130@4080:Speed:30@4080:GoTo:56:45@4080:BarrageName:30:5:20:5:3:ZakouAttack3@4200:GoTo:415:98");
	AddEnemy("0:Type:0@0:HP:25@4080:Locate:108:-130@4080:Speed:30@4080:GoTo:108:45@4100:BarrageName:30:5:20:5:3:ZakouAttack3@4200:GoTo:467:98");
	AddEnemy("0:Type:0@0:HP:25@4080:Locate:56:-90@4080:Speed:30@4080:GoTo:56:85@4080:BarrageName:40:-1:30:0:0:ZakouAttack9@4200:GoTo:415:138");
	AddEnemy("0:Type:0@0:HP:25@4080:Locate:108:-90@4080:Speed:30@4080:GoTo:108:85@4085:BarrageName:40:-1:30:0:0:ZakouAttack9@4200:GoTo:467:138");
	AddEnemy("0:Type:0@0:HP:25@4080:Locate:56:-50@4080:Speed:30@4080:GoTo:56:125@4080:BarrageName:40:-1:30:0:0:ZakouAttack9@4200:GoTo:415:178");
	AddEnemy("0:Type:0@0:HP:25@4080:Locate:108:-50@4080:Speed:30@4080:GoTo:108:125@4085:BarrageName:40:-1:30:0:0:ZakouAttack9@4200:GoTo:467:178");

	AddEnemy("0:Type:0@0:HP:25@4200:Locate:260:-130@4200:Speed:30@4200:GoTo:260:45@4205:BarrageName:30:5:20:5:3:ZakouAttack3@4320:GoTo:-102:98");
	AddEnemy("0:Type:0@0:HP:25@4200:Locate:312:-130@4200:Speed:30@4200:GoTo:312:45@4200:BarrageName:30:5:20:5:3:ZakouAttack3@4320:GoTo:-50:98");
	AddEnemy("0:Type:0@0:HP:25@4200:Locate:260:-90@4200:Speed:30@4200:GoTo:260:85@4210:BarrageName:40:-1:30:0:0:ZakouAttack9@4320:GoTo:-102:138");
	AddEnemy("0:Type:0@0:HP:25@4200:Locate:312:-90@4200:Speed:30@4200:GoTo:312:85@4200:BarrageName:40:-1:30:0:0:ZakouAttack9@4320:GoTo:-50:138");
	AddEnemy("0:Type:0@0:HP:25@4200:Locate:260:-50@4200:Speed:30@4200:GoTo:260:125@4200:BarrageName:40:-1:30:0:0:ZakouAttack9@4320:GoTo:-102:178");
	AddEnemy("0:Type:0@0:HP:25@4200:Locate:312:-50@4200:Speed:30@4200:GoTo:312:125@4205:BarrageName:40:-1:30:0:0:ZakouAttack9@4320:GoTo:-50:178");

	AddEnemy("0:Type:0@0:HP:25@4320:Locate:56:-130@4320:Speed:30@4320:GoTo:56:45@4325:BarrageName:30:5:20:5:3:ZakouAttack3@4440:GoTo:415:98");
	AddEnemy("0:Type:0@0:HP:25@4320:Locate:108:-130@4320:Speed:30@4320:GoTo:108:45@4320:BarrageName:30:5:20:5:3:ZakouAttack3@4440:GoTo:467:98");
	AddEnemy("0:Type:0@0:HP:25@4320:Locate:56:-90@4320:Speed:30@4320:GoTo:56:85@4320:BarrageName:40:-1:30:0:0:ZakouAttack9@4440:GoTo:415:138");
	AddEnemy("0:Type:0@0:HP:25@4320:Locate:108:-90@4320:Speed:30@4320:GoTo:108:85@4330:BarrageName:40:-1:30:0:0:ZakouAttack9@4440:GoTo:467:138");
	AddEnemy("0:Type:0@0:HP:25@4320:Locate:56:-50@4320:Speed:30@4320:GoTo:56:125@4320:BarrageName:40:-1:30:0:0:ZakouAttack9@4440:GoTo:415:178");
	AddEnemy("0:Type:0@0:HP:25@4320:Locate:108:-50@4320:Speed:30@4320:GoTo:108:125@4320:BarrageName:40:-1:30:0:0:ZakouAttack9@4440:GoTo:467:178");





	/* Unused (패턴9)
 	AddEnemy("0:Type:1@0:HP:20@4300:Locate:20:-50@4300:Speed:17@4300:Angle:275@4300:BarrageName:15:-1:20:0:0:ZakouAttack9");
 	AddEnemy("0:Type:1@0:HP:20@4330:Locate:20:-50@4330:Speed:17@4330:Angle:275@4330:BarrageName:10:-1:25:0:0:ZakouAttack9");
 	AddEnemy("0:Type:1@0:HP:20@4360:Locate:20:-50@4360:Speed:17@4360:Angle:275@4360:BarrageName:15:-1:20:0:0:ZakouAttack9");
 	AddEnemy("0:Type:1@0:HP:20@4390:Locate:20:-50@4390:Speed:17@4390:Angle:275@4390:BarrageName:30:-1:30:0:0:ZakouAttack9");
 	AddEnemy("0:Type:1@0:HP:20@4420:Locate:20:-50@4420:Speed:17@4420:Angle:275@4420:BarrageName:15:-1:20:0:0:ZakouAttack9");
 	AddEnemy("0:Type:1@0:HP:20@4450:Locate:20:-50@4450:Speed:17@4450:Angle:275@4450:BarrageName:15:-1:20:0:0:ZakouAttack9");
 	
 
 	AddEnemy("0:Type:1@0:HP:20@4600:Locate:341:-50@4600:Speed:17@4600:Angle:265@4600:BarrageName:15:-1:20:0:0:ZakouAttack9");
 	AddEnemy("0:Type:1@0:HP:20@4630:Locate:341:-50@4630:Speed:17@4630:Angle:265@4630:BarrageName:10:-1:25:0:0:ZakouAttack9");
 	AddEnemy("0:Type:1@0:HP:20@4660:Locate:341:-50@4660:Speed:17@4660:Angle:265@4660:BarrageName:15:-1:20:0:0:ZakouAttack9");
 	AddEnemy("0:Type:1@0:HP:20@4690:Locate:341:-50@4690:Speed:17@4690:Angle:265@4690:BarrageName:30:-1:30:0:0:ZakouAttack9");
 	AddEnemy("0:Type:1@0:HP:20@4720:Locate:341:-50@4720:Speed:17@4720:Angle:265@4720:BarrageName:15:-1:20:0:0:ZakouAttack9");
 	AddEnemy("0:Type:1@0:HP:20@4750:Locate:341:-50@4750:Speed:17@4750:Angle:265@4750:BarrageName:15:-1:20:0:0:ZakouAttack9");

 	AddEnemy("0:Type:3@0:HP:30@5000:Locate:89:-50@5000:Speed:20@5030:Speed:0@5120:Speed:20@5120:GoTo:89:600");
 	AddEnemy("0:Type:3@0:HP:30@5000:Locate:130:-50@5030:Speed:20@5060:Speed:0@5120:Speed:20@5120:GoTo:130:600");
 	AddEnemy("0:Type:3@0:HP:30@5000:Locate:160:-50@5060:Speed:20@5090:Speed:0@5120:Speed:20@5120:GoTo:160:600");
 
 	AddEnemy("0:Type:3@0:HP:30@5200:Locate:220:-50@5200:Speed:20@5230:Speed:0@5320:Speed:20@5320:GoTo:89:600");
 	AddEnemy("0:Type:3@0:HP:30@5200:Locate:267:-50@5230:Speed:20@5260:Speed:0@5320:Speed:20@5320:GoTo:130:600");
 	AddEnemy("0:Type:3@0:HP:30@5200:Locate:310:-50@5260:Speed:20@5290:Speed:0@5320:Speed:20@5320:GoTo:160:600");
 
 	AddEnemy("0:Type:3@0:HP:30@5400:Locate:130:-50@5400:Speed:20@5400:Speed:0@5520:Speed:20@5520:GoTo:130:600");
 	AddEnemy("0:Type:3@0:HP:30@5400:Locate:89:-50@5430:Speed:20@5430:Speed:0@5520:Speed:20@5520:GoTo:89:600");
 	AddEnemy("0:Type:3@0:HP:30@5400:Locate:160:-50@5460:Speed:20@5460:Speed:0@5520:Speed:20@5520:GoTo:160:600");
 
 	AddEnemy("0:Type:3@0:HP:30@5600:Locate:220:-50@5600:Speed:20@5630:Speed:0@5720:Speed:20@5720:GoTo:89:600");
 	AddEnemy("0:Type:3@0:HP:30@5600:Locate:267:-50@5630:Speed:20@5690:Speed:0@5720:Speed:20@5720:GoTo:130:600");
 	AddEnemy("0:Type:3@0:HP:30@5600:Locate:310:-50@5690:Speed:20@5720:Speed:0@5720:Speed:20@5720:GoTo:160:600");
	*/


	/* Unused (패턴4) */
	
	/*
	AddEnemy("0:Type:1@0:HP:15@960:Locate:430:113@960:Speed:30@960:GoTo:-50:378@960:BarrageName:60:-1:30:5:5:ZakouAttack1");
	AddEnemy("0:Type:1@0:HP:15@990:Locate:430:113@990:Speed:30@990:GoTo:-50:378@990:BarrageName:60:-1:30:5:5:ZakouAttack1");
	AddEnemy("0:Type:1@0:HP:15@1020:Locate:430:113@1020:Speed:30@1020:GoTo:-50:378@1020:BarrageName:60:-1:30:5:5:ZakouAttack1");
	AddEnemy("0:Type:1@0:HP:15@1050:Locate:430:113@1050:Speed:30@1050:GoTo:-50:378@1050:BarrageName:150:-1:15:30:5:ZakouAttack3");
	AddEnemy("0:Type:1@0:HP:15@1080:Locate:430:113@1080:Speed:30@1080:GoTo:-50:378@1080:BarrageName:150:-1:15:30:5:ZakouAttack3");
	AddEnemy("0:Type:1@0:HP:15@1110:Locate:430:113@1110:Speed:30@1110:GoTo:-50:378@1110:BarrageName:60:-1:30:5:5:ZakouAttack1");
	AddEnemy("0:Type:1@0:HP:15@1140:Locate:430:113@1140:Speed:30@1140:GoTo:-50:378@1140:BarrageName:60:-1:30:5:5:ZakouAttack1");
	AddEnemy("0:Type:1@0:HP:15@1170:Locate:430:113@1170:Speed:30@1170:GoTo:-50:378@1170:BarrageName:150:-1:15:30:5:ZakouAttack3");
	AddEnemy("0:Type:1@0:HP:15@1200:Locate:430:113@1200:Speed:30@1200:GoTo:-50:378@1200:BarrageName:60:-1:30:5:5:ZakouAttack1");

	*/

	//패턴10

	// 	AddEnemy("0:Type:1@0:HP:20@2050:Locate:-50:79@2050:Bezier:120:194:79:450:138@2050:BarrageName:52:-1:25:8:0:ZakouAttack8");
	// 	AddEnemy("0:Type:1@0:HP:20@2050:Locate:-50:79@2080:Bezier:120:194:79:450:138");
	// 	AddEnemy("0:Type:1@0:HP:20@2050:Locate:-50:79@2110:Bezier:120:194:79:450:138@2110:BarrageName:52:-1:25:8:0:ZakouAttack8");
	// 	AddEnemy("0:Type:1@0:HP:20@2050:Locate:-50:79@2140:Bezier:120:194:79:450:138");
	// 	AddEnemy("0:Type:1@0:HP:20@2050:Locate:-50:79@2170:Bezier:120:194:79:450:138");

	//패턴11
	// 	AddEnemy("0:Type:1@0:HP:20@2200:Locate:-50:79@2200:Bezier:120:194:99:450:158@2200:BarrageName:33:-1:25:0:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2200:Locate:-50:79@2230:Bezier:120:194:99:450:158@2230:BarrageName:28:-1:20:0:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2200:Locate:-50:79@2260:Bezier:120:194:99:450:158@2260:BarrageName:40:-1:25:0:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2200:Locate:-50:79@2290:Bezier:120:194:99:450:158@2290:BarrageName:20:-1:30:0:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2200:Locate:-50:79@2320:Bezier:120:194:99:450:158@2320:BarrageName:15:-1:10:0:0:ZakouAttack9");

	//패턴12
	// 	AddEnemy("0:Type:1@0:HP:20@2350:Locate:-50:79@2350:Bezier:120:194:89:450:148@2350:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2350:Locate:-50:79@2380:Bezier:120:194:89:450:148@2380:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2350:Locate:-50:79@2410:Bezier:120:194:89:450:148@2410:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2350:Locate:-50:79@2440:Bezier:120:194:89:450:148@2440:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2350:Locate:-50:79@2470:Bezier:120:194:89:450:148@2470:BarrageName:28:-1:25:8:0:ZakouAttack9");

	// 	//패턴4-1
	// 	AddEnemy("0:Type:1@0:HP:20@930:Locate:-50:105@930:Bezier:90:194:105:194:178@1020:Bezier:90:194:268:450:268@1110:BarrageName:60:-1:30:5:5:ZakouAttack1");
	// 	AddEnemy("0:Type:1@0:HP:20@960:Locate:-50:105@960:Bezier:90:194:105:194:178@1050:Bezier:90:194:268:450:268@1140:BarrageName:60:-1:30:5:5:ZakouAttack1");
	// 	AddEnemy("0:Type:1@0:HP:20@990:Locate:-50:105@990:Bezier:90:194:105:194:178@1080:Bezier:90:194:268:450:268@1170:BarrageName:60:-1:30:5:5:ZakouAttack1");
	// 	AddEnemy("0:Type:1@0:HP:20@1020:Locate:-50:105@1020:Bezier:90:194:105:194:178@1110:Bezier:90:194:268:450:268@1200:BarrageName:60:-1:30:5:5:ZakouAttack1");
	// 	AddEnemy("0:Type:1@0:HP:20@1050:Locate:-50:105@1050:Bezier:90:194:105:194:178@1140:Bezier:90:194:268:450:268@1230:BarrageName:60:-1:30:5:5:ZakouAttack1");
	// 	AddEnemy("0:Type:1@0:HP:20@1080:Locate:-50:105@1080:Bezier:90:194:105:194:178@1170:Bezier:90:194:268:450:268@1260:BarrageName:60:-1:30:5:5:ZakouAttack1");
	// 	AddEnemy("0:Type:1@0:HP:20@1110:Locate:-50:105@1110:Bezier:90:194:105:194:178@1200:Bezier:90:194:268:450:268@1290:BarrageName:60:-1:30:5:5:ZakouAttack1");
	// 	AddEnemy("0:Type:1@0:HP:20@1140:Locate:-50:105@1140:Bezier:90:194:105:194:178@1230:Bezier:90:194:268:450:268@1320:BarrageName:60:-1:30:5:5:ZakouAttack1");
	// 	AddEnemy("0:Type:1@0:HP:20@1170:Locate:-50:105@1170:Bezier:90:194:105:194:178@1260:Bezier:90:194:268:450:268@1350:BarrageName:60:-1:30:5:5:ZakouAttack1");
	// 	AddEnemy("0:Type:1@0:HP:20@1200:Locate:-50:105@1200:Bezier:90:194:105:194:178@1290:Bezier:90:194:268:450:268@1380:BarrageName:60:-1:30:5:5:ZakouAttack1");
	// 	AddEnemy("0:Type:1@0:HP:20@1230:Locate:-50:105@1230:Bezier:90:194:105:194:178@1320:Bezier:90:194:268:450:268@1410:BarrageName:60:-1:30:5:5:ZakouAttack1");

	//패턴13
	// 	AddEnemy("0:Type:1@0:HP:20@2500:Locate:-50:79@2500:Bezier:120:194:89:450:148@2500:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2500:Locate:-50:79@2530:Bezier:120:194:89:450:148@2530:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2500:Locate:-50:79@2560:Bezier:120:194:89:450:148@2560:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2500:Locate:-50:79@2590:Bezier:120:194:89:450:148@2590:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2500:Locate:-50:79@2620:Bezier:120:194:89:450:148@2620:BarrageName:28:-1:25:8:0:ZakouAttack9");

	//패턴14
	// 	AddEnemy("0:Type:1@0:HP:20@2650:Locate:-50:79@2650:Bezier:120:194:99:450:158@2650:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2650:Locate:-50:79@2680:Bezier:120:194:99:450:158@2680:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2650:Locate:-50:79@2710:Bezier:120:194:99:450:158@2710:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2650:Locate:-50:79@2740:Bezier:120:194:99:450:158@2740:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2650:Locate:-50:79@2770:Bezier:120:194:99:450:158@2770:BarrageName:28:-1:25:8:0:ZakouAttack9");

	//패턴15
	// 	AddEnemy("0:Type:1@0:HP:20@2800:Locate:-50:79@2800:Bezier:120:194:79:450:138@2800:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2800:Locate:-50:79@2830:Bezier:120:194:79:450:138@2830:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2800:Locate:-50:79@2860:Bezier:120:194:79:450:138@2860:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2800:Locate:-50:79@2890:Bezier:120:194:79:450:138@2890:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2800:Locate:-50:79@2920:Bezier:120:194:79:450:138@2920:BarrageName:28:-1:25:8:0:ZakouAttack9");


	StopMusicAllinOne();
	FreeMusicAllInOne();
#ifndef TESTMODE
	if (bBGM_Use == true)
	{
		Music_Stage2Field.LoadSound("data.rom", "music/stage2_field.ogg", &MySoundManager);
		Music_Stage2Field.Play(true, NULL, fVolume_BGM);
		ShowBGMName("얼티밋 트루스");
	}
#endif
}

void InitStage2Boss()
{

	GameBoss * pNewBoss = new GameBoss();
	pBoss = pNewBoss;
	pBoss->SetSprite(&Spr_Boss_Stage2);
	pBoss->bAutoNextFrame = false;
	pBoss->bRotate = false;
	pBoss->iCurrentFrame = 0;
	
	pBoss->x = ((double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X) / 2.0 - ((double)(pBoss->GetSprite()->GetWidth()) / (double)2.0);
	pBoss->y = -100;
	pBoss->bPermitOutside = true;
	
	pBoss->speed = 3.0;
	//	pBoss->acc = 0.2;
	pBoss->fDest_X = pBoss->x;
	pBoss->fDest_Y = 123.0;
	pBoss->SetAngle(GetAngle(pBoss->x, pBoss->y, pBoss->fDest_X, pBoss->fDest_Y));
	pBoss->bGoTo = true;
	pBoss->bMovable = true;

	pBoss->AddCollision(0.0, -15.0, COLLISIONMODEL_CIRCLE, 15.0);
	pBoss->AddCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, 15.0);
	pBoss->AddCollision(0.0, 15.0, COLLISIONMODEL_CIRCLE, 15.0);

	pBoss->AddGrazeCollision(0.0, -15.0, COLLISIONMODEL_CIRCLE, 15.0);
	pBoss->AddGrazeCollision(0.0, 0.0, COLLISIONMODEL_CIRCLE, 15.0);
	pBoss->AddGrazeCollision(0.0, 15.0, COLLISIONMODEL_CIRCLE, 15.0);

	pBoss->iCurrentSpell = 0;	//0부터.

	pBoss->pSpellPortrait = &Spr_CutIn_Yuuko;

	GameSmallSizeFont.PrintFont(&PrintedBossName, "사이교우지 유유코", 119, 221, 153, FONT_BLENDED);

 	RegisterSpell(pBoss, "망향 「망아향 -오랜 죄-」", 1000, (SpellInit)(&Stage2BossSpell0Init), (SpellInit)(&Stage2BossSpell0), 90);
	RegisterSpell(pBoss, "망무 「생자필멸의 이치 -사접-」", 1000, (SpellInit)(&Stage2BossSpell1Init), (SpellInit)(&Stage2BossSpell1), 90);
	RegisterSpell(pBoss, "화령 「스월로테일 버터플라이」", 1000, (SpellInit)(&Stage2BossSpell2Init), (SpellInit)(&Stage2BossSpell2), 90);
	RegisterSpell(pBoss, "유곡 「리포지터리 오브 히로카와 -망령-」", 1000, (SpellInit)(&Stage2BossSpell3Init), (SpellInit)(&Stage2BossSpell3), 90);
	RegisterSpell(pBoss, "앵부 「완전한 칠흑의 벚꽃 -망아-」", 1000, (SpellInit)(&Stage2BossSpell4Init), (SpellInit)(&Stage2BossSpell4), 90);
	RegisterSpell(pBoss, "Perfect Cherry Blossom", 0, (SpellInit)(&Stage2BossFinalSpellInit), (SpellInit)(&Stage2BossFinalSpell), 60, true, false);

	GameEnemyVector.push_back(pBoss);
	
	Stage.SetSprite(&Spr_Stage2_Boss);
	Stage.iScrollType = SCROLLTYPE_NONE;
	Stage.fSpeedX = 0.0;
	Stage.fPosX = UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + 1;
	Stage.fPosY = UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT + 1;
	Stage.x = Stage.fPosX;
	Stage.y = Stage.fPosY;

	iHangonchou_CurrentAngle = 0;
}

void InitStage2Event()
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
		RegisterChara("유유코", 1, &Spr_Portrait_Yuuko0);
		RegisterChara("???", 0, NULL);

		AddScript("레이무", 0, "", 0, 0, "아 정말!");
		AddScript("레이무", 0, "", 0, 0, "죽은 영혼뿐이라 지긋지긋해!");
		AddScript("레이무", 0, "???", 0, 1, "멋대로 다른사람네 정원에 쳐들어와서는 불평만 하고 있다니.");
		AddScript("레이무", 0, "", 0, 0, "!?");
		AddScript("레이무", 0, "유유코", 0, 1, "뭔가 아니잖아.");
		AddScript("레이무", 0, "유유코", 0, 1, "하긴 뭐 이쪽은 죽은 영혼 뿐입니다만.");
		AddScript("레이무", 0, "유유코", 0, 0, "근데, 용무가 뭐였더라?");
		AddScript("레이무", 0, "유유코", 0, 0, "멋진 벚꽃에 정신이 팔려서 잊어버렸네");
		AddScript("레이무", 0, "유유코", 0, 1, "꽃놀이 아닐까?");
		AddScript("레이무", 0, "유유코", 0, 1, "의외로 자리는 많이 남아 있어.");
		AddScript("레이무", 0, "유유코", 0, 0, "아 그래?");
		AddScript("레이무", 0, "유유코", 0, 0, "그럼 꽃놀이라도 하고 갈까.");
		AddScript("레이무", 0, "유유코", 0, 1, "하지만, 당신은 초대한 적이 없어서.");
		AddScript("레이무", 0, "유유코", 0, 0, "그래그래. 생각 났다.");
		AddScript("레이무", 0, "유유코", 0, 1, "뭐지?");
		AddScript("레이무", 0, "유유코", 0, 0, "난 우리 신사에서 꽃놀이를 할 거라서 말이야.");
		AddScript("레이무", 0, "유유코", 0, 1, "......");
		AddScript("레이무", 0, "유유코", 0, 0, "그러니까, 훌륭한 벚꽃이긴 하지만.");
		AddScript("레이무", 0, "유유코", 0, 0, "모은 봄을 돌려주지 않겠어?");
		AddScript("레이무", 0, "유유코", 0, 1, "이제 곧인걸.");
		AddScript("레이무", 0, "유유코", 0, 1, "이제 곧, '사이교우 아야카시' 가 활짝 피게 된다구.");
		AddScript("레이무", 0, "유유코", 0, 0, "뭔데. 사이교우 아야카시란 게.");
		AddScript("레이무", 0, "유유코", 0, 1, "우리 요괴 벚꽃.");
		AddScript("레이무", 0, "유유코", 0, 1, "이 정도의 봄으로는, 이 벚나무의 봉인을 풀수 없어서 그래.");
		AddScript("레이무", 0, "유유코", 0, 0, "일부러 봉인해 둔 거니까 그거,");
		AddScript("레이무", 0, "유유코", 0, 0, "풀지 않는게 나은거 아니야?");
		AddScript("레이무", 0, "유유코", 0, 0, "무슨 봉인인지도 모르고.");
		AddScript("레이무", 0, "유유코", 0, 1, "결계를 깨고 들어온 당신이 할 말?");
		AddScript("레이무", 0, "유유코", 0, 0, "뭐 좋아, 봉인을 풀면 어떻게 되는 거지?");
		AddScript("레이무", 0, "유유코", 0, 1, "아아주 흐드러지게 꽃이 필 거야.");
		AddScript("레이무", 0, "유유코", 0, 0, "...");
		AddScript("레이무", 0, "유유코", 0, 1, "와 동시에, 무언가가 부활한다는 듯 싶어.");
		AddScript("레이무", 0, "유유코", 0, 0, "흥미본위로 부활시키면 안되겠지.");
		AddScript("레이무", 0, "유유코", 0, 0, "뭔지도 모르고.");
		AddScript("레이무", 0, "유유코", 0, 1, "어머, 난 흥미본위로 사람도 요괴도 죽음으로 이끄는걸.");
		AddScript("레이무", 0, "유유코", 0, 0, "혼을 되돌리는것과 죽음을 똑같이 생각하면 안되지.");
		AddScript("레이무", 0, "유유코", 0, 0, "성가신게 부활해 버리면 어쩌자는 거야.");
		AddScript("레이무", 0, "유유코", 0, 1, "시험해 보지 않고선 모르는 일이잖아.");
		AddScript("레이무", 0, "유유코", 0, 1, "어쨌든 간에, 부름받지도 않은 당신이 여기 있는 그 시점에서 죽은것과 이미 마찬가지.");
		AddScript("레이무", 0, "유유코", 0, 1, "라고 할까, 여기에 있는 일 자체가 죽었다고 할 일이야.");
		AddScript("레이무", 0, "유유코", 0, 0, "난 죽어서도 꽃구경을 할 수 있는 거구나.");
		AddScript("레이무", 0, "유유코", 0, 1, "당신이 갖고 있는 '얼마 없는 봄' 이 있으면 진짜 벚꽃을 볼 수 있겠지.");
		AddScript("레이무", 0, "유유코", 0, 1, "...무언가의 덤도 딸려서 말이야.");
		AddScript("레이무", 0, "유유코", 0, 0, "자 그럼, 농담은 거기까지 해 두고 환상향의 봄을 돌려주겠어?");
		AddScript("레이무", 0, "유유코", 0, 1, "처음부터 그렇게 말했으면 될 것을.");
		AddScript("레이무", 0, "유유코", 0, 0, "처음부터 두 번이나 말했어.");
		AddScript("레이무", 0, "유유코", 0, 1, "마지막의 끝맺음이 중요한 거라구.");
		AddScript("레이무", 0, "유유코", 0, 0, "꽃 아래로 돌아가도록, 봄의 망령 !");
		AddScript("레이무", 0, "유유코", 0, 1, "꽃 아래에서 잠들도록, 홍백의 나비 !");

		break;
	case PLAYERCHARA_MARISA:
		RegisterChara("마리사", 1, &Spr_Portrait_Marisa0);
		RegisterChara("유유코", 1, &Spr_Portrait_Yuuko0);
		RegisterChara("???", 0, NULL);

		AddScript("마리사", 0, "", 0, 0, "어딜 가도 만발이로군.");
		AddScript("마리사", 0, "???", 0, 1, "아직. 이제 얼마 안 남았어.");
		AddScript("마리사", 0, "유유코", 0, 1, "조금만 더 봄이 있으면 '사이교우 아야카시' 도 완전히 필 거야.");
		AddScript("마리사", 0, "유유코", 0, 0, "가져 왔다. 그 '얼마 없는 봄' 을.");
		AddScript("마리사", 0, "유유코", 0, 1, "어머나, 당신의 요우무의 계승자?");
		AddScript("마리사", 0, "유유코", 0, 0, "설마. 난 이런 촌구석에서 일생을 마치고 싶진 않다고.");
		AddScript("마리사", 0, "유유코", 0, 1, "그럼, 대용품?");
		AddScript("마리사", 0, "유유코", 0, 0, "얘길 듣고 있는 거냐?");
		AddScript("마리사", 0, "유유코", 0, 1, "듣고 있어.");
		AddScript("마리사", 0, "유유코", 0, 1, "죽을 때는 벚나무 아래서 죽고 싶다는 얘기잖아.");
		AddScript("마리사", 0, "유유코", 0, 0, "무슨 엉뚱한 소릴 하고 있는건데?");
		AddScript("마리사", 0, "유유코", 0, 1, "아무튼, 어떻게 해서든 '사이교우 아야카시' 의 봉인을 풀고 싶은 거야.");
		AddScript("마리사", 0, "유유코", 0, 0, "그러니까, 그렇게 해 주겠다니까.");
		AddScript("마리사", 0, "유유코", 0, 0, "뭔가 좋은일이라도 생기냐?");
		AddScript("마리사", 0, "유유코", 0, 1, "글쎄.");
		AddScript("마리사", 0, "유유코", 0, 0, "그냥은 못 줘.");
		AddScript("마리사", 0, "유유코", 0, 1, "꽃놀이라던가 하는거 어때.");
		AddScript("마리사", 0, "유유코", 0, 1, "우리가 하는 꽃놀이는 떠들썩해서 즐겁다구.");
		AddScript("마리사", 0, "유유코", 0, 0, "아까 전에, 떠들썩할 듯한 녀석들을 쓰러뜨리고 온 것 같기도...");
		AddScript("마리사", 0, "유유코", 0, 1, "어차피, 저승의 벚꽃은 인간에겐 보기 싫은 것일까.");
		AddScript("마리사", 0, "유유코", 0, 0, "아아. 이 근방은 죽음의 냄새가 가득하군 그래.");
		AddScript("마리사", 0, "유유코", 0, 1, "어머. 당신은 눈으로 냄새를 맡는구나.");
		AddScript("마리사", 0, "유유코", 0, 0, "아아. 맡지.");
		AddScript("마리사", 0, "유유코", 0, 0, "이렇게 혹독한 느낌의 봄도 처음이다.");
		AddScript("마리사", 0, "유유코", 0, 1, "예의 없네.");
		AddScript("마리사", 0, "유유코", 0, 1, "그런 여기의 봄은, 당신들이 사는 환상향의 봄인걸. ");
		AddScript("마리사", 0, "유유코", 0, 0, "실례잖아.");
		AddScript("마리사", 0, "유유코", 0, 0, "누가 눈으로 냄새를 맡겠냐!");
		AddScript("마리사", 0, "유유코", 0, 1, "얘기가 어긋나고 있어.");
		AddScript("마리사", 0, "유유코", 0, 0, "저 세상은 음이 닿는 속도가 느려.");
		AddScript("마리사", 0, "유유코", 0, 0, "이렇게 음속이 느린 곳에 이 봄을 넘겨줄수는 없지.");
		AddScript("마리사", 0, "유유코", 0, 1, "그건 아쉽네.");
		AddScript("마리사", 0, "유유코", 0, 1, "이제부턴, 공기의 온도를 올려서 얘기하도록 하겠습니다아.");
		AddScript("마리사", 0, "유유코", 0, 0, "다음부터라도 상관 없는데...");
		AddScript("마리사", 0, "유유코", 0, 1, "하지만, 모처럼이고 하니.");
		AddScript("마리사", 0, "유유코", 0, 0, "혹독한 느낌의 봄을 돌려받아야겠어, 죽은 몸의 아가씨!");
		AddScript("마리사", 0, "유유코", 0, 1, "'얼마 없는 봄' 을 받아가겠어, 검은 마녀!");
		break;
	case PLAYERCHARA_REISEN:
		RegisterChara("사쿠야", 1, &Spr_Portrait_Reisen0);
		RegisterChara("유유코", 1, &Spr_Portrait_Yuuko0);
		RegisterChara("???", 0, NULL);

		AddScript("사쿠야", 0, "", 0, 0, "저 세상에는.");
		AddScript("사쿠야", 0, "", 0, 0, "'죽은자는 말이 없다' 라는 말은 없는 걸까?");
		AddScript("사쿠야", 0, "???", 0, 1, "어머나. 물론 그런 말은 없다지.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "저 세상은 언제나 번화하고 소란스러운 곳이라구.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "번화한 건, 환상향의 봄을 빼앗았기 때문이 아니라?");
		AddScript("사쿠야", 0, "유유코", 0, 1, "어라, 봄 싫어해?");
		AddScript("사쿠야", 0, "유유코", 0, 0, "좋아하니까 화내고 있잖아.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "왜 환상향의 봄을 빼앗은 거야?");
		AddScript("사쿠야", 0, "유유코", 0, 1, "봄이라면 뭐라도 상관없었지.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "하지만 아직 조금 부족해.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "...아까의 죽은 자는 당신과 날 싸우게 하고 싶었던 모양인데.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "이제 곧, 최후의 벚나무, '사이교우 아야카시'가 필 거야.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "그것만 피면, 모든 의문이 풀릴 터.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "그 나무, 말라죽어 있다던가 하는 거 아냐?");
		AddScript("사쿠야", 0, "유유코", 0, 1, "이제 곧 필 것 같아.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "분명히, 요우무는 당신이 가진 '얼마없는 봄' 으로 꽃이 필 거라 생각했던 거겠지.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "흥미 없어.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "그것보다, 여기까지 오는데 하루 종일이 걸려버린게 신경쓰여.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "어머. 금방 돌려보내 줄께.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "당신은 아직 부르지도 않았고 하니.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "방금 한 말 정정. '여기까지 오는데' 가 아니라 '환상향에 봄이 오게 하는데' 로.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "어라. 지상엔 아직 벚꽃이 피지 않은 거야?");
		AddScript("사쿠야", 0, "유유코", 0, 0, "꽃은 커녕, 복수초도 돋아나지 않았어.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "그러면 심장병이 걸렸을때 곤란하겠는걸.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "곤란하지 않아.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "도대체가, 집에 계시는 아가씨께서 심장이 약하신 것도 아니고.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "그건 유감이네.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "유감?");
		AddScript("사쿠야", 0, "유유코", 0, 0, "뭐, 풀 얘기는 이제 됐어.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "슬슬 온기가 아쉽다니까.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "돌려 주실까, 온기를.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "유해는 한군데에 모여 있으니까 아름다운 거야.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "봄도 벚꽃도 마찬가지...");
		AddScript("사쿠야", 0, "유유코", 0, 0, "원래부터 시체는 아름답지 않지만 말이지.");
		AddScript("사쿠야", 0, "유유코", 0, 1, "그래서 말이야.");
		AddScript("사쿠야", 0, "유유코", 0, 0, "반드시 지상에서 꽃놀이를 벌이겠어, 공주의 유해!");
		AddScript("사쿠야", 0, "유유코", 0, 1, "반드시 봉인을 풀어 보이겠어, 악마의 개!");
		break;
	}


	StartScript();

	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;
	iGameState_Game_Status = GAMESTATE_GAME_EVENT;
}


void Stage2BossSpell0Init()
{
	StopMusicAllinOne();
	FreeMusicAllInOne();
#ifndef TESTMODE
	if (bBGM_Use == true)
	{
		Music_Stage2Boss.LoadSound("data.rom", "music/stage2_boss.ogg", &MySoundManager);
		Music_Stage2Boss.Play(true, NULL, fVolume_BGM);
		ShowBGMName("Border of Life ～ The Black Cherry Blossom");
	}
#endif

	DeleteAllBarrage();
	RegisterBarrage("Stage2BossAttack0", (BarrageFunctionInit)&InitStage2BossAttack0, (BarrageFunction)&Stage2BossAttack0);
	RegisterBarrage("Stage2BossAttack0MicroThread0", (BarrageFunctionInit)&InitStage2BossAttack0MicroThread0, (BarrageFunction)&Stage2BossAttack0MicroThread0);
	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;

	bOldStatus2 = true;
}

void Stage2BossSpell0()
{
 
 	if (bOldStatus2 & (pBoss->bMovable) == false)	//수정 요망.
 	{
		MakeBossBarrage("Stage2BossAttack0", 500, 900, 60, 5, 0);
		MakeBossBarrage("Stage2BossAttack0", 1000, 2700, 60, 2, 1);
 	}
 
 	bOldStatus2 = pBoss->bMovable;
 
}

void Stage2BossSpell1Init()
{
	DeleteAllBarrage();
	RegisterBarrage("Stage2BossAttack1", (BarrageFunctionInit)&InitStage2BossAttack1, (BarrageFunction)&Stage2BossAttack1);
	RegisterBarrage("Stage2BossAttack1MicroThread0", (BarrageFunctionInit)&InitStage2BossAttack1MicroThread0, (BarrageFunction)&Stage2BossAttack1MicroThread0);
/*	RegisterBarrage("Stage2BossAttack1MicroThread0", (BarrageFunctionInit)&InitStage1BossAttack1MicroThread1, (BarrageFunction)&Stage1BossAttack1MicroThread1);*/
	//	RegisterBarrage("SixWingsAst", (BarrageFunctionInit)&InitSixWingsAst, (BarrageFunction)&SixWingsAst);

	pBoss->fDest_X = ((double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X) / 2.0 - ((double)(Spr_Boss_Stage2.GetWidth()) / (double)2.0), 123.0;
	pBoss->fDest_Y = 123;
	pBoss->SetAngle(GetAngle(pBoss->x, pBoss->y, pBoss->fDest_X, pBoss->fDest_Y));
	pBoss->speed = 2.0;
	pBoss->bGoTo = true;
	pBoss->bMovable = true;

	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;

	bOldStatus2 = true;
	bSpellMade2 = false;
}
void Stage2BossSpell1()
{

	if (bOldStatus2 & (pBoss->bMovable) == false)	//수정 요망.
	{
		if (bSpellMade2 == false)
		{
			MakeBossBarrage("Stage2BossAttack1", 300, 900, 60, 4, 0);
			MakeBossBarrage("Stage2BossAttack1", 300, 900, 60, 4, 1);
			bSpellMade2 = true;
		}
	}

	if (iGameFrame >= 44)
	{
		AddBullet(BULLET_TYPE15, rand()%8, pBoss->GetCenterX(), pBoss->GetCenterY(), GetAngle(pBoss, &Player), 0.0, 4.0, 0.0);
		iGameFrame = 0;
	}

	bOldStatus2 = pBoss->bMovable;

}

void Stage2BossSpell2Init()
{
	DeleteAllBarrage();
	RegisterBarrage("Stage2BossAttack2", (BarrageFunctionInit)&InitStage2BossAttack2, (BarrageFunction)&Stage2BossAttack2);
	RegisterBarrage("Stage2BossAttack2_1", (BarrageFunctionInit)&InitStage2BossAttack3, (BarrageFunction)&Stage2BossAttack3);

	pBoss->fDest_X = ((double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X) / 2.0 - ((double)(Spr_Boss_Stage2.GetWidth()) / (double)2.0), 123.0;
	pBoss->fDest_Y = 120;
	pBoss->SetAngle(GetAngle(pBoss->x, pBoss->y, pBoss->fDest_X, pBoss->fDest_Y));
	pBoss->speed = 2.0;
	pBoss->bGoTo = true;
	pBoss->bMovable = true;

	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;

	bOldStatus2 = true;
}
void Stage2BossSpell2()
{
	if (bOldStatus2 & (pBoss->bMovable) == false)	//수정 요망.
	{
		DeleteAllBarrage(pBoss);
		MakeBossBarrage("Stage2BossAttack2", 900, 25, 5, 6, rand()%8);
		//너무 어려워서 뺐음..
//  		MakeBossBarrage("Stage2BossAttack2_1", 900, -50, 20, 15, -1230);
//  		MakeBossBarrage("Stage2BossAttack2_1", 900, 50, 20, 15, 1230);
	}

	std::vector<GameBarrage*>::iterator Iter = pBoss->pvBarrage.begin();
	while ( true )
	{
		if ( Iter == pBoss->pvBarrage.end())
		{
			break;
		}
		if ( (*Iter)->pFunction == (BarrageFunction)(&Stage2BossAttack2))
		{
			int * iDone = &((*Iter)->iBarrageParameters[7]);
			int * iCompleteCount = &((*Iter)->iBarrageParameters[8]);

			if (*iDone == 1) //iDone
			{
				int * iAngle = &((*Iter)->iBarrageParameters[0]);

				*iAngle = Angle360(*iAngle + 50);
				*iDone = 0;

				if (*iCompleteCount >= 3)
				{
					//전범위 랜덤이동
					// 				MoveBoss((UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + (pBoss->GetSprite()->GetWidth()) / 2 + 
					// 					rand()% ( UI_WINDOW_RIGHT_X - UI_WINDOW_LEFT_WIDTH - UI_WINDOW_LEFT_X - (pBoss->GetSprite()->GetWidth()) / 2)),
					// 					UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT +(pBoss->GetSprite()->GetHeight()) / 2 + 
					// 					rand()% ( UI_WINDOW_BOTTOM_Y - UI_WINDOW_TOP_HEIGHT - UI_WINDOW_TOP_Y - (pBoss->GetSprite()->GetHeight()) / 2));
					// 						
//					MoveBoss((UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH + (pBoss->GetSprite()->GetWidth()) / 2 + 
//						rand()% ( UI_WINDOW_RIGHT_X - UI_WINDOW_LEFT_WIDTH - UI_WINDOW_LEFT_X - (pBoss->GetSprite()->GetWidth()) / 2)),
//						123 + 
//						rand()%67);

//					MoveBoss(Player.GetCenterX() - (double)(UI_WINDOW_LEFT_X + UI_WINDOW_LEFT_WIDTH), Player.GetCenterY() - (double)(UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT));

					*iCompleteCount = 0;
				}
			}
		}

		Iter++;
	}

	bOldStatus2 = pBoss->bMovable;

}

void Stage2BossSpell3Init()
{
	DeleteAllBarrage();
	RegisterBarrage("Stage2BossAttack3", (BarrageFunctionInit)&InitStage2BossAttack3, (BarrageFunction)&Stage2BossAttack3);
	RegisterBarrage("Stage2BossAttack3_1", (BarrageFunctionInit)&InitStage2BossAttack3_1, (BarrageFunction)&Stage2BossAttack3_1);

	pBoss->fDest_X = ((double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X) / 2.0 - ((double)(Spr_Boss_Stage2.GetWidth()) / (double)2.0), 123.0;
	pBoss->fDest_Y = 120;
	pBoss->SetAngle(GetAngle(pBoss->x, pBoss->y, pBoss->fDest_X, pBoss->fDest_Y));
	pBoss->speed = 2.0;
	pBoss->bGoTo = true;
	pBoss->bMovable = true;

	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;

	bOldStatus2 = true;
}
void Stage2BossSpell3()
{
	if (bOldStatus2 & (pBoss->bMovable) == false)
	{
		MakeBossBarrage("Stage2BossAttack3_1", (int)(GetAngle(pBoss, &Player) * 10.0), 100, 25, 25, 0);
		MakeBossBarrage("Stage2BossAttack3", 900, -50, 20, 20, -1230);
		MakeBossBarrage("Stage2BossAttack3", 900, 50, 20, 20, 1230);
	}
	
	bOldStatus2 = pBoss->bMovable;
}

void Stage2BossSpell4Init()
{
	DeleteAllBarrage();
	RegisterBarrage("Stage2BossAttack4", (BarrageFunctionInit)&InitStage2BossAttack4, (BarrageFunction)&Stage2BossAttack4);
	RegisterBarrage("Stage2BossAttack4MicroThread0", (BarrageFunctionInit)&InitStage2BossAttack4MicroThread0, (BarrageFunction)&Stage2BossAttack4MicroThread0);
	RegisterBarrage("Stage2BossAttack4_1", (BarrageFunctionInit)&InitStage2BossAttack4_1, (BarrageFunction)&Stage2BossAttack4_1);

	pBoss->fDest_X = ((double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X) / 2.0 - ((double)(Spr_Boss_Stage2.GetWidth()) / (double)2.0), 123.0;
	pBoss->fDest_Y = 120;
	pBoss->SetAngle(GetAngle(pBoss->x, pBoss->y, pBoss->fDest_X, pBoss->fDest_Y));
	pBoss->speed = 2.0;
	pBoss->bGoTo = true;
	pBoss->bMovable = true;

	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;

	bOldStatus2 = true;
}
void Stage2BossSpell4()
{
	if (bOldStatus2 & (pBoss->bMovable) == false)
	{
		MakeBossBarrage("Stage2BossAttack4", 5, 50, 1, 300, 0);
		MakeBossBarrage("Stage2BossAttack4_1", 70, 16, 3600, 0, 0);
	}

	bOldStatus2 = pBoss->bMovable;
}

void Stage2BossFinalSpellInit()
{
	DeleteAllBarrage();
	RegisterBarrage("Stage2BossAttackFinal", (BarrageFunctionInit)&InitStage2BossAttackFinal, (BarrageFunction)&Stage2BossAttackFinal);
	RegisterBarrage("Stage2BossAttackFinalMicroThread0", (BarrageFunctionInit)&InitStage2BossAttackFinalMicroThread0, (BarrageFunction)&Stage2BossAttackFinalMicroThread0);
	RegisterBarrage("Stage2BossAttackFinal_1", (BarrageFunctionInit)&InitStage2BossAttackFinal_1, (BarrageFunction)&Stage2BossAttackFinal_1);

	pBoss->SetSprite(&Spr_Boss_Stage2_Invincible);
	pBoss->fDest_X = ((double)UI_WINDOW_LEFT_X + (double)UI_WINDOW_LEFT_WIDTH + (double)UI_WINDOW_RIGHT_X) / 2.0 - ((double)(pBoss->GetSprite()->GetWidth()) / (double)2.0), 123.0;
	pBoss->fDest_Y = (double)( UI_WINDOW_TOP_Y + UI_WINDOW_TOP_HEIGHT + UI_WINDOW_BOTTOM_Y) / 2.0 - (double)(pBoss->GetSprite()->GetHeight()) / 2.0;
	pBoss->SetAngle(GetAngle(pBoss->x, pBoss->y, pBoss->fDest_X, pBoss->fDest_Y));
	pBoss->speed = 2.0;
	pBoss->bGoTo = true;
	pBoss->bMovable = true;


	iGameFrame = 0;
	iOldGameFrame = 0;
	iOldGameFrame_EnemyDamaged = 0;
	iOldGameFrame_EnemyDead = 0;

	bOldStatus2 = true;

}

void Stage2BossFinalSpell()
{
	if (bOldStatus2 & (pBoss->bMovable) == false)
	{
		MakeBossBarrage("Stage2BossAttackFinal", 5, 20, 90, 0, 0);
		MakeBossBarrage("Stage2BossAttackFinal_1", 20, 60, 0, 0, 0);
	}

	bOldStatus2 = pBoss->bMovable;
}

void InitStage2Event_After_Boss()
{
	DeleteAllChara();
	DeleteAllScripts();
	Music_Stage2Boss_Final.Stop();

	AddScript("", 0, "", 0, 0, "원컨대 꽃잎아래서 봄에 죽기를");
	AddScript("", 0, "", 0, 0, "그 2월의 보름밤에...");
	AddScript("", 0, "", 0, 0, "더러운 흙을 싫어하고 깨끗한 흙을 좋아하고");
	AddScript("", 0, "", 0, 0, "그대 세상에는 여인의 사해.");
	AddScript("", 0, "", 0, 0, "부처님에겐 벚꽃을 올리고");
	AddScript("", 0, "", 0, 0, "후세에 사람으로 태어나면");
	AddScript("", 0, "", 0, 0, "시름을 절감하고 고심을 버려");
	AddScript("", 0, "", 0, 0, "등지면 해가 없는 세상 있기를. -西行法師-");

	StartScript();
}

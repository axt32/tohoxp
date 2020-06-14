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


	//����1
	AddEnemy("0:Type:0@0:HP:25@90:Locate:103:-117@90:Speed:30@90:GoTo:103:103@160:BarrageName:60:10:5:0:0:ZakouAttack0@600:GoTo:95:500");
	AddEnemy("0:Type:2@0:HP:25@90:Locate:222:-50@90:Speed:30@90:GoTo:208:170@160:BarrageName:60:10:5:0:0:ZakouAttack0@600:GoTo:198:500");
	AddEnemy("0:Type:0@0:HP:25@90:Locate:341:-117@90:Speed:30@90:GoTo:341:103@160:BarrageName:60:10:5:0:0:ZakouAttack0@600:GoTo:301:500");

	//����2
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

	// 	//����3

	AddEnemy("0:Type:1@0:HP:25@750:Locate:400:60@750:Bezier:300:169:60:-50:117@750:BarrageName:60:-1:30:5:4:ZakouAttack4");
	AddEnemy("0:Type:1@0:HP:25@750:Locate:400:60@780:Bezier:300:169:60:-50:117@780:BarrageName:150:-1:15:30:4:ZakouAttack3");
	AddEnemy("0:Type:1@0:HP:25@750:Locate:400:60@810:Bezier:300:169:60:-50:117@810:BarrageName:150:-1:15:30:4:ZakouAttack3");
	AddEnemy("0:Type:1@0:HP:25@750:Locate:400:60@840:Bezier:300:169:60:-50:117@840:BarrageName:60:-1:30:5:4:ZakouAttack4");
	AddEnemy("0:Type:1@0:HP:25@750:Locate:400:60@870:Bezier:300:169:60:-50:117@870:BarrageName:60:-1:30:5:4:ZakouAttack4");

	//����5
	AddEnemy("0:Type:1@0:HP:25@1200:Locate:400:60@1200:Bezier:300:169:60:-50:117@1200:BarrageName:5:-1:-1:0:0:ZakouAttack6");
	AddEnemy("0:Type:1@0:HP:25@1200:Locate:400:60@1230:Bezier:300:169:60:-50:117@1230:BarrageName:4:-1:-1:0:0:ZakouAttack6");
	AddEnemy("0:Type:1@0:HP:25@1200:Locate:400:60@1260:Bezier:300:169:60:-50:117@1260:BarrageName:3:-1:-1:0:0:ZakouAttack6");
	AddEnemy("0:Type:1@0:HP:25@1200:Locate:400:60@1290:Bezier:300:169:60:-50:117@1290:BarrageName:4:-1:-1:0:0:ZakouAttack6");
	AddEnemy("0:Type:1@0:HP:25@1200:Locate:400:60@1320:Bezier:300:169:60:-50:117@1320:BarrageName:5:-1:-1:0:0:ZakouAttack6");

	//����6
	AddEnemy("0:Type:2@0:HP:35@1400:Locate:171:-50@1400:Bezier:120:141:-50:146:82@1400:BarrageName:5:1:5:25:100:ZakouAttack5@2200:Bezier:120:-50:81:-50:337");

	//����7
	AddEnemy("0:Type:5@0:HP:35@1500:Locate:75:-50@1500:Speed:25@1500:GoTo:75:132@1600:BarrageName:120:8:0:0:0:ZakouAttack2@2500:GoTo:-50:378");
	AddEnemy("0:Type:5@0:HP:35@1500:Locate:295:-50@1500:Speed:25@1500:GoTo:295:132@1600:BarrageName:120:8:0:0:0:ZakouAttack2@2500:GoTo:430:378");

	//����8
	AddEnemy("0:Type:1@0:HP:35@1600:Locate:-50:79@1600:Bezier:300:194:79:450:138@1600:BarrageName:60:-1:30:10:3:ZakouAttack7");
	AddEnemy("0:Type:1@0:HP:35@1600:Locate:-50:79@1630:Bezier:300:194:79:450:138@1630:BarrageName:60:-1:30:10:3:ZakouAttack7");
	AddEnemy("0:Type:1@0:HP:35@1600:Locate:-50:79@1660:Bezier:300:194:79:450:138@1660:BarrageName:60:-1:30:10:3:ZakouAttack7");
	AddEnemy("0:Type:1@0:HP:35@1600:Locate:-50:79@1690:Bezier:300:194:79:450:138@1690:BarrageName:60:-1:30:10:3:ZakouAttack7");
	AddEnemy("0:Type:1@0:HP:35@1600:Locate:-50:79@1720:Bezier:300:194:79:450:138@1720:BarrageName:60:-1:30:10:3:ZakouAttack7");


	//����10-1
	AddEnemy("0:Type:2@0:HP:35@2050:Locate:115:-50@2050:Speed:30@2050:GoTo:143:120@2050:BarrageName:5:1:15:2:0:ZakouAttack10@2350:GoTo:-50:359");

	//����12-1
	AddEnemy("0:Type:2@0:HP:35@2350:Locate:310:-50@2350:Speed:30@2350:GoTo:222:194@2350:BarrageName:5:1:15:2:0:ZakouAttack10@2650:GoTo:-450:356");

	//����14-1
	AddEnemy("0:Type:2@0:HP:35@2650:Locate:135:-50@2650:Speed:30@2650:GoTo:173:130@2650:BarrageName:5:1:15:2:0:ZakouAttack10@3000:GoTo:-50:359");

	//����16
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

	//����17
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





	/* Unused (����9)
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


	/* Unused (����4) */
	
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

	//����10

	// 	AddEnemy("0:Type:1@0:HP:20@2050:Locate:-50:79@2050:Bezier:120:194:79:450:138@2050:BarrageName:52:-1:25:8:0:ZakouAttack8");
	// 	AddEnemy("0:Type:1@0:HP:20@2050:Locate:-50:79@2080:Bezier:120:194:79:450:138");
	// 	AddEnemy("0:Type:1@0:HP:20@2050:Locate:-50:79@2110:Bezier:120:194:79:450:138@2110:BarrageName:52:-1:25:8:0:ZakouAttack8");
	// 	AddEnemy("0:Type:1@0:HP:20@2050:Locate:-50:79@2140:Bezier:120:194:79:450:138");
	// 	AddEnemy("0:Type:1@0:HP:20@2050:Locate:-50:79@2170:Bezier:120:194:79:450:138");

	//����11
	// 	AddEnemy("0:Type:1@0:HP:20@2200:Locate:-50:79@2200:Bezier:120:194:99:450:158@2200:BarrageName:33:-1:25:0:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2200:Locate:-50:79@2230:Bezier:120:194:99:450:158@2230:BarrageName:28:-1:20:0:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2200:Locate:-50:79@2260:Bezier:120:194:99:450:158@2260:BarrageName:40:-1:25:0:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2200:Locate:-50:79@2290:Bezier:120:194:99:450:158@2290:BarrageName:20:-1:30:0:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2200:Locate:-50:79@2320:Bezier:120:194:99:450:158@2320:BarrageName:15:-1:10:0:0:ZakouAttack9");

	//����12
	// 	AddEnemy("0:Type:1@0:HP:20@2350:Locate:-50:79@2350:Bezier:120:194:89:450:148@2350:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2350:Locate:-50:79@2380:Bezier:120:194:89:450:148@2380:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2350:Locate:-50:79@2410:Bezier:120:194:89:450:148@2410:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2350:Locate:-50:79@2440:Bezier:120:194:89:450:148@2440:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2350:Locate:-50:79@2470:Bezier:120:194:89:450:148@2470:BarrageName:28:-1:25:8:0:ZakouAttack9");

	// 	//����4-1
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

	//����13
	// 	AddEnemy("0:Type:1@0:HP:20@2500:Locate:-50:79@2500:Bezier:120:194:89:450:148@2500:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2500:Locate:-50:79@2530:Bezier:120:194:89:450:148@2530:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2500:Locate:-50:79@2560:Bezier:120:194:89:450:148@2560:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2500:Locate:-50:79@2590:Bezier:120:194:89:450:148@2590:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2500:Locate:-50:79@2620:Bezier:120:194:89:450:148@2620:BarrageName:28:-1:25:8:0:ZakouAttack9");

	//����14
	// 	AddEnemy("0:Type:1@0:HP:20@2650:Locate:-50:79@2650:Bezier:120:194:99:450:158@2650:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2650:Locate:-50:79@2680:Bezier:120:194:99:450:158@2680:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2650:Locate:-50:79@2710:Bezier:120:194:99:450:158@2710:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2650:Locate:-50:79@2740:Bezier:120:194:99:450:158@2740:BarrageName:28:-1:25:8:0:ZakouAttack9");
	// 	AddEnemy("0:Type:1@0:HP:20@2650:Locate:-50:79@2770:Bezier:120:194:99:450:158@2770:BarrageName:28:-1:25:8:0:ZakouAttack9");

	//����15
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
		ShowBGMName("��Ƽ�� Ʈ�罺");
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

	pBoss->iCurrentSpell = 0;	//0����.

	pBoss->pSpellPortrait = &Spr_CutIn_Yuuko;

	GameSmallSizeFont.PrintFont(&PrintedBossName, "���̱����� ������", 119, 221, 153, FONT_BLENDED);

 	RegisterSpell(pBoss, "���� �������� -���� ��-��", 1000, (SpellInit)(&Stage2BossSpell0Init), (SpellInit)(&Stage2BossSpell0), 90);
	RegisterSpell(pBoss, "���� �������ʸ��� ��ġ -����-��", 1000, (SpellInit)(&Stage2BossSpell1Init), (SpellInit)(&Stage2BossSpell1), 90);
	RegisterSpell(pBoss, "ȭ�� ������������ �����ö��̡�", 1000, (SpellInit)(&Stage2BossSpell2Init), (SpellInit)(&Stage2BossSpell2), 90);
	RegisterSpell(pBoss, "���� ���������͸� ���� ����ī�� -����-��", 1000, (SpellInit)(&Stage2BossSpell3Init), (SpellInit)(&Stage2BossSpell3), 90);
	RegisterSpell(pBoss, "�޺� �������� ĥ���� ���� -����-��", 1000, (SpellInit)(&Stage2BossSpell4Init), (SpellInit)(&Stage2BossSpell4), 90);
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
		RegisterChara("���̹�", 1, &Spr_Portrait_Reimu0);
		RegisterChara("������", 1, &Spr_Portrait_Yuuko0);
		RegisterChara("???", 0, NULL);

		AddScript("���̹�", 0, "", 0, 0, "�� ����!");
		AddScript("���̹�", 0, "", 0, 0, "���� ��ȥ���̶� ����������!");
		AddScript("���̹�", 0, "???", 0, 1, "�ڴ�� �ٸ������ ������ �ĵ��ͼ��� ���� �ϰ� �ִٴ�.");
		AddScript("���̹�", 0, "", 0, 0, "!?");
		AddScript("���̹�", 0, "������", 0, 1, "���� �ƴ��ݾ�.");
		AddScript("���̹�", 0, "������", 0, 1, "�ϱ� �� ������ ���� ��ȥ ���Դϴٸ�.");
		AddScript("���̹�", 0, "������", 0, 0, "�ٵ�, �빫�� ��������?");
		AddScript("���̹�", 0, "������", 0, 0, "���� ���ɿ� ������ �ȷ��� �ؾ���ȳ�");
		AddScript("���̹�", 0, "������", 0, 1, "�ɳ��� �ƴұ�?");
		AddScript("���̹�", 0, "������", 0, 1, "�ǿܷ� �ڸ��� ���� ���� �־�.");
		AddScript("���̹�", 0, "������", 0, 0, "�� �׷�?");
		AddScript("���̹�", 0, "������", 0, 0, "�׷� �ɳ��̶� �ϰ� ����.");
		AddScript("���̹�", 0, "������", 0, 1, "������, ����� �ʴ��� ���� ���.");
		AddScript("���̹�", 0, "������", 0, 0, "�׷��׷�. ���� ����.");
		AddScript("���̹�", 0, "������", 0, 1, "����?");
		AddScript("���̹�", 0, "������", 0, 0, "�� �츮 �Ż翡�� �ɳ��̸� �� �Ŷ� ���̾�.");
		AddScript("���̹�", 0, "������", 0, 1, "......");
		AddScript("���̹�", 0, "������", 0, 0, "�׷��ϱ�, �Ǹ��� �����̱� ������.");
		AddScript("���̹�", 0, "������", 0, 0, "���� ���� �������� �ʰھ�?");
		AddScript("���̹�", 0, "������", 0, 1, "���� ���ΰ�.");
		AddScript("���̹�", 0, "������", 0, 1, "���� ��, '���̱��� �ƾ�ī��' �� Ȱ¦ �ǰ� �ȴٱ�.");
		AddScript("���̹�", 0, "������", 0, 0, "����. ���̱��� �ƾ�ī�ö� ��.");
		AddScript("���̹�", 0, "������", 0, 1, "�츮 �䱫 ����.");
		AddScript("���̹�", 0, "������", 0, 1, "�� ������ �����δ�, �� �������� ������ Ǯ�� ��� �׷�.");
		AddScript("���̹�", 0, "������", 0, 0, "�Ϻη� ������ �� �Ŵϱ� �װ�,");
		AddScript("���̹�", 0, "������", 0, 0, "Ǯ�� �ʴ°� ������ �ƴϾ�?");
		AddScript("���̹�", 0, "������", 0, 0, "���� ���������� �𸣰�.");
		AddScript("���̹�", 0, "������", 0, 1, "��踦 ���� ���� ����� �� ��?");
		AddScript("���̹�", 0, "������", 0, 0, "�� ����, ������ Ǯ�� ��� �Ǵ� ����?");
		AddScript("���̹�", 0, "������", 0, 1, "�ƾ��� ��巯���� ���� �� �ž�.");
		AddScript("���̹�", 0, "������", 0, 0, "...");
		AddScript("���̹�", 0, "������", 0, 1, "�� ���ÿ�, ���𰡰� ��Ȱ�Ѵٴ� �� �;�.");
		AddScript("���̹�", 0, "������", 0, 0, "��̺����� ��Ȱ��Ű�� �ȵǰ���.");
		AddScript("���̹�", 0, "������", 0, 0, "������ �𸣰�.");
		AddScript("���̹�", 0, "������", 0, 1, "���, �� ��̺����� ����� �䱫�� �������� �̲��°�.");
		AddScript("���̹�", 0, "������", 0, 0, "ȥ�� �ǵ����°Ͱ� ������ �Ȱ��� �����ϸ� �ȵ���.");
		AddScript("���̹�", 0, "������", 0, 0, "�����Ű� ��Ȱ�� ������ ��¼�ڴ� �ž�.");
		AddScript("���̹�", 0, "������", 0, 1, "������ ���� �ʰ� �𸣴� �����ݾ�.");
		AddScript("���̹�", 0, "������", 0, 1, "��·�� ����, �θ������� ���� ����� ���� �ִ� �� �������� �����Ͱ� �̹� ��������.");
		AddScript("���̹�", 0, "������", 0, 1, "��� �ұ�, ���⿡ �ִ� �� ��ü�� �׾��ٰ� �� ���̾�.");
		AddScript("���̹�", 0, "������", 0, 0, "�� �׾�� �ɱ����� �� �� �ִ� �ű���.");
		AddScript("���̹�", 0, "������", 0, 1, "����� ���� �ִ� '�� ���� ��' �� ������ ��¥ ������ �� �� �ְ���.");
		AddScript("���̹�", 0, "������", 0, 1, "...������ ���� ������ ���̾�.");
		AddScript("���̹�", 0, "������", 0, 0, "�� �׷�, ����� �ű���� �� �ΰ� ȯ������ ���� �����ְھ�?");
		AddScript("���̹�", 0, "������", 0, 1, "ó������ �׷��� �������� �� ����.");
		AddScript("���̹�", 0, "������", 0, 0, "ó������ �� ���̳� ���߾�.");
		AddScript("���̹�", 0, "������", 0, 1, "�������� �������� �߿��� �Ŷ�.");
		AddScript("���̹�", 0, "������", 0, 0, "�� �Ʒ��� ���ư�����, ���� ���� !");
		AddScript("���̹�", 0, "������", 0, 1, "�� �Ʒ����� ��鵵��, ȫ���� ���� !");

		break;
	case PLAYERCHARA_MARISA:
		RegisterChara("������", 1, &Spr_Portrait_Marisa0);
		RegisterChara("������", 1, &Spr_Portrait_Yuuko0);
		RegisterChara("???", 0, NULL);

		AddScript("������", 0, "", 0, 0, "��� ���� �����̷α�.");
		AddScript("������", 0, "???", 0, 1, "����. ���� �� �� ���Ҿ�.");
		AddScript("������", 0, "������", 0, 1, "���ݸ� �� ���� ������ '���̱��� �ƾ�ī��' �� ������ �� �ž�.");
		AddScript("������", 0, "������", 0, 0, "���� �Դ�. �� '�� ���� ��' ��.");
		AddScript("������", 0, "������", 0, 1, "��ӳ�, ����� ��칫�� �����?");
		AddScript("������", 0, "������", 0, 0, "����. �� �̷� �̱������� �ϻ��� ��ġ�� ���� �ʴٰ�.");
		AddScript("������", 0, "������", 0, 1, "�׷�, ���ǰ?");
		AddScript("������", 0, "������", 0, 0, "��� ��� �ִ� �ų�?");
		AddScript("������", 0, "������", 0, 1, "��� �־�.");
		AddScript("������", 0, "������", 0, 1, "���� ���� ������ �Ʒ��� �װ� �ʹٴ� ����ݾ�.");
		AddScript("������", 0, "������", 0, 0, "���� ������ �Ҹ� �ϰ� �ִ°ǵ�?");
		AddScript("������", 0, "������", 0, 1, "�ƹ�ư, ��� �ؼ��� '���̱��� �ƾ�ī��' �� ������ Ǯ�� ���� �ž�.");
		AddScript("������", 0, "������", 0, 0, "�׷��ϱ�, �׷��� �� �ְڴٴϱ�.");
		AddScript("������", 0, "������", 0, 0, "���� �������̶� �����?");
		AddScript("������", 0, "������", 0, 1, "�۽�.");
		AddScript("������", 0, "������", 0, 0, "�׳��� �� ��.");
		AddScript("������", 0, "������", 0, 1, "�ɳ��̶���� �ϴ°� �.");
		AddScript("������", 0, "������", 0, 1, "�츮�� �ϴ� �ɳ��̴� ������ؼ� ��̴ٱ�.");
		AddScript("������", 0, "������", 0, 0, "�Ʊ� ����, ������� ���� �༮���� �����߸��� �� �� ���⵵...");
		AddScript("������", 0, "������", 0, 1, "������, ������ ������ �ΰ����� ���� ���� ���ϱ�.");
		AddScript("������", 0, "������", 0, 0, "�ƾ�. �� �ٹ��� ������ ������ �����ϱ� �׷�.");
		AddScript("������", 0, "������", 0, 1, "���. ����� ������ ������ �ô±���.");
		AddScript("������", 0, "������", 0, 0, "�ƾ�. ����.");
		AddScript("������", 0, "������", 0, 0, "�̷��� Ȥ���� ������ ���� ó���̴�.");
		AddScript("������", 0, "������", 0, 1, "���� ����.");
		AddScript("������", 0, "������", 0, 1, "�׷� ������ ����, ��ŵ��� ��� ȯ������ ���ΰ�. ");
		AddScript("������", 0, "������", 0, 0, "�Ƿ��ݾ�.");
		AddScript("������", 0, "������", 0, 0, "���� ������ ������ �ðڳ�!");
		AddScript("������", 0, "������", 0, 1, "��Ⱑ ��߳��� �־�.");
		AddScript("������", 0, "������", 0, 0, "�� ������ ���� ��� �ӵ��� ����.");
		AddScript("������", 0, "������", 0, 0, "�̷��� ������ ���� ���� �� ���� �Ѱ��ټ��� ����.");
		AddScript("������", 0, "������", 0, 1, "�װ� �ƽ���.");
		AddScript("������", 0, "������", 0, 1, "��������, ������ �µ��� �÷��� ����ϵ��� �ϰڽ��ϴپ�.");
		AddScript("������", 0, "������", 0, 0, "�������Ͷ� ��� ���µ�...");
		AddScript("������", 0, "������", 0, 1, "������, ��ó���̰� �ϴ�.");
		AddScript("������", 0, "������", 0, 0, "Ȥ���� ������ ���� �����޾ƾ߰ھ�, ���� ���� �ư���!");
		AddScript("������", 0, "������", 0, 1, "'�� ���� ��' �� �޾ư��ھ�, ���� ����!");
		break;
	case PLAYERCHARA_REISEN:
		RegisterChara("�����", 1, &Spr_Portrait_Reisen0);
		RegisterChara("������", 1, &Spr_Portrait_Yuuko0);
		RegisterChara("???", 0, NULL);

		AddScript("�����", 0, "", 0, 0, "�� ���󿡴�.");
		AddScript("�����", 0, "", 0, 0, "'�����ڴ� ���� ����' ��� ���� ���� �ɱ�?");
		AddScript("�����", 0, "???", 0, 1, "��ӳ�. ���� �׷� ���� ������.");
		AddScript("�����", 0, "������", 0, 1, "�� ������ ������ ��ȭ�ϰ� �Ҷ������� ���̶�.");
		AddScript("�����", 0, "������", 0, 0, "��ȭ�� ��, ȯ������ ���� ���Ѿұ� ������ �ƴ϶�?");
		AddScript("�����", 0, "������", 0, 1, "���, �� �Ⱦ���?");
		AddScript("�����", 0, "������", 0, 0, "�����ϴϱ� ȭ���� ���ݾ�.");
		AddScript("�����", 0, "������", 0, 0, "�� ȯ������ ���� ������ �ž�?");
		AddScript("�����", 0, "������", 0, 1, "���̶�� ���� ���������.");
		AddScript("�����", 0, "������", 0, 1, "������ ���� ���� ������.");
		AddScript("�����", 0, "������", 0, 0, "...�Ʊ��� ���� �ڴ� ��Ű� �� �ο�� �ϰ� �;��� ����ε�.");
		AddScript("�����", 0, "������", 0, 1, "���� ��, ������ ������, '���̱��� �ƾ�ī��'�� �� �ž�.");
		AddScript("�����", 0, "������", 0, 1, "�װ͸� �Ǹ�, ��� �ǹ��� Ǯ�� ��.");
		AddScript("�����", 0, "������", 0, 0, "�� ����, �����׾� �ִٴ��� �ϴ� �� �Ƴ�?");
		AddScript("�����", 0, "������", 0, 1, "���� �� �� �� ����.");
		AddScript("�����", 0, "������", 0, 1, "�и���, ��칫�� ����� ���� '�󸶾��� ��' ���� ���� �� �Ŷ� �����ߴ� �Ű���.");
		AddScript("�����", 0, "������", 0, 0, "��� ����.");
		AddScript("�����", 0, "������", 0, 0, "�װͺ���, ������� ���µ� �Ϸ� ������ �ɷ������� �Ű澲��.");
		AddScript("�����", 0, "������", 0, 1, "���. �ݹ� �������� �ٲ�.");
		AddScript("�����", 0, "������", 0, 1, "����� ���� �θ����� �ʾҰ� �ϴ�.");
		AddScript("�����", 0, "������", 0, 0, "��� �� �� ����. '������� ���µ�' �� �ƴ϶� 'ȯ���⿡ ���� ���� �ϴµ�' ��.");
		AddScript("�����", 0, "������", 0, 1, "���. ���� ���� ������ ���� ���� �ž�?");
		AddScript("�����", 0, "������", 0, 0, "���� Ŀ��, �����ʵ� ���Ƴ��� �ʾҾ�.");
		AddScript("�����", 0, "������", 0, 1, "�׷��� ���庴�� �ɷ����� ����ϰڴ°�.");
		AddScript("�����", 0, "������", 0, 0, "������� �ʾ�.");
		AddScript("�����", 0, "������", 0, 0, "����ü��, ���� ��ô� �ư������� ������ ���Ͻ� �͵� �ƴϰ�.");
		AddScript("�����", 0, "������", 0, 1, "�װ� �����̳�.");
		AddScript("�����", 0, "������", 0, 0, "����?");
		AddScript("�����", 0, "������", 0, 0, "��, Ǯ ���� ���� �ƾ�.");
		AddScript("�����", 0, "������", 0, 0, "���� �±Ⱑ �ƽ��ٴϱ�.");
		AddScript("�����", 0, "������", 0, 0, "���� �ֽǱ�, �±⸦.");
		AddScript("�����", 0, "������", 0, 1, "���ش� �ѱ����� �� �����ϱ� �Ƹ��ٿ� �ž�.");
		AddScript("�����", 0, "������", 0, 1, "���� ���ɵ� ��������...");
		AddScript("�����", 0, "������", 0, 0, "�������� ��ü�� �Ƹ����� ������ ������.");
		AddScript("�����", 0, "������", 0, 1, "�׷��� ���̾�.");
		AddScript("�����", 0, "������", 0, 0, "�ݵ�� ���󿡼� �ɳ��̸� ���̰ھ�, ������ ����!");
		AddScript("�����", 0, "������", 0, 1, "�ݵ�� ������ Ǯ�� ���̰ھ�, �Ǹ��� ��!");
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
		ShowBGMName("Border of Life �� The Black Cherry Blossom");
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
 
 	if (bOldStatus2 & (pBoss->bMovable) == false)	//���� ���.
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

	if (bOldStatus2 & (pBoss->bMovable) == false)	//���� ���.
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
	if (bOldStatus2 & (pBoss->bMovable) == false)	//���� ���.
	{
		DeleteAllBarrage(pBoss);
		MakeBossBarrage("Stage2BossAttack2", 900, 25, 5, 6, rand()%8);
		//�ʹ� ������� ����..
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
					//������ �����̵�
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

	AddScript("", 0, "", 0, 0, "������ ���پƷ��� ���� �ױ⸦");
	AddScript("", 0, "", 0, 0, "�� 2���� �����㿡...");
	AddScript("", 0, "", 0, 0, "������ ���� �Ⱦ��ϰ� ������ ���� �����ϰ�");
	AddScript("", 0, "", 0, 0, "�״� ���󿡴� ������ ����.");
	AddScript("", 0, "", 0, 0, "��ó�Կ��� ������ �ø���");
	AddScript("", 0, "", 0, 0, "�ļ��� ������� �¾��");
	AddScript("", 0, "", 0, 0, "�ø��� �����ϰ� ����� ����");
	AddScript("", 0, "", 0, 0, "������ �ذ� ���� ���� �ֱ⸦. -�������-");

	StartScript();
}

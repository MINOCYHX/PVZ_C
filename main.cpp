/*

*/

#include <stdio.h>
#include<graphics.h>
#include"tools.h"

#define WIN_WIDTH 900  //窗口宽
#define WIN_HEIGHT 600  //窗口长

//用于替代数组下标
enum {
	XIANG_RI_KUI,   //0
	WAN_DOU,   //1
	ZHI_WU_COUNT    //2
};

IMAGE imgBg;  //背景图片
IMAGE imgBar;  //背包
IMAGE imgCards[ZHI_WU_COUNT];  //植物卡片

//初始化——————————————————
void gameInit()
{
	//加载图片  ps：多字节字符集
	loadimage(&imgBg, "res/bg.jpg");
	loadimage(&imgBar, "res/bar5.png");
	char name[64]; 
	for (int i = 0; i < ZHI_WU_COUNT; i++)
	{
		sprintf_s(name,sizeof(name), "res/Cards/card_%d.png", i + 1);
		loadimage(&imgCards[i], name);
	}
	//创建窗口（加载内存）
	initgraph(WIN_WIDTH,WIN_HEIGHT);
}

//更新——————————————————
void updateWindow()
{
	BeginBatchDraw(); //双缓冲

	putimage(0,0,&imgBg);//图片放入窗口
	putimagePNG(250, 0, &imgBar);  //图片消黑边后放入

	//放植物
	for (int i = 0; i < ZHI_WU_COUNT; i++)
	{
		int x = 338 + i * 65;
		int y = 6;
		putimage(x, y, imgCards + i);
	}

	EndBatchDraw();
}

void userclick()
{
	ExMessage msg;

	if (peekmessage(&msg))
	{

	}

}

//主循环——————————————————
int main()
{
	gameInit();

	while (1)
	{
		userclick();
		updateWindow();
	}
	

	system("pause");
	return 0;
}



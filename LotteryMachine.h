#pragma once
 
#include "LotteryPaper.h"
#include <cstdlib>
#include <ctime>




class LotteryMachine
{

private:
	//该机器的收入
	int incomeMoney = 0;
	//前区随机摇奖
	int getRandomNum(int a[]);
	//后区随机摇奖
	int getRanDomNumBack(int a[]);
public: 
	//机选一注彩票
	LotteryPaper randomLotteryPaper();

	LotteryMachine() {
		srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	}
	
	int getIncomeMoney() {
		return incomeMoney;
	}
 
};

 
#include "LotteryMachine.h"
#include <cstdlib>
#include <ctime>

 
 
 

LotteryPaper LotteryMachine::randomLotteryPaper(){
	
	//一注彩票两块钱
	incomeMoney += 2;
	LotteryPaper lp;
	//数字池,0为未被取出,1为被取出
	int pool[35],poolBack[12];
	lp.setFrontArea(getRandomNum(pool), getRandomNum(pool), getRandomNum(pool), getRandomNum(pool), getRandomNum(pool));
	lp.setBackArea(getRanDomNumBack(poolBack), getRanDomNumBack(poolBack));
	return lp;
}

int LotteryMachine::getRandomNum(int a[]) {

	int result =  rand() % 35;
	//如果该号码被取出则一直重复取号码
	while (a[result] == 1) {
		//生成随机范围 0~35
		result = rand() % 35;
		
	
	}
	//将其标记为取出
	a[result] = 1;
	return result+1;
}

int LotteryMachine::getRanDomNumBack(int a[])
{
	int result = rand() % 12;
	//如果该号码被取出则一直重复取号码
	while (a[result] == 1) {
		//生成随机范围 0~12
		result = rand() % 12;


	}
	//将其标记为取出
	a[result] = 1;
	return result+1; 
}

 
#pragma once
 
#include "LotteryPaper.h"
#include <cstdlib>
#include <ctime>




class LotteryMachine
{

private:
	//�û���������
	int incomeMoney = 0;
	int getRandomNum(int a[]);
	int getRanDomNumBack(int a[]);
public: 
	//��ѡһע��Ʊ
	LotteryPaper randomLotteryPaper();

	LotteryMachine() {
		srand((int)time(0));  // �����������  ��0����NULLҲ��
	}
	
	int getIncomeMoney() {
		return incomeMoney;
	}
 
};

 
#pragma once
 
#include "LotteryPaper.h"
#include <cstdlib>
#include <ctime>




class LotteryMachine
{

private:
	//�û���������
	int incomeMoney = 0;
	//ǰ�����ҡ��
	int getRandomNum(int a[]);
	//�������ҡ��
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

 
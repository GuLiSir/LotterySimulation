#include "LotteryMachine.h"
#include <cstdlib>
#include <ctime>

 
 
 

LotteryPaper LotteryMachine::randomLotteryPaper(){
	
	//һע��Ʊ����Ǯ
	incomeMoney += 2;
	LotteryPaper lp;
	//���ֳ�,0Ϊδ��ȡ��,1Ϊ��ȡ��
	int pool[35],poolBack[12];
	lp.setFrontArea(getRandomNum(pool), getRandomNum(pool), getRandomNum(pool), getRandomNum(pool), getRandomNum(pool));
	lp.setBackArea(getRanDomNumBack(poolBack), getRanDomNumBack(poolBack));
	return lp;
}

int LotteryMachine::getRandomNum(int a[]) {

	int result =  rand() % 35;
	//����ú��뱻ȡ����һֱ�ظ�ȡ����
	while (a[result] == 1) {
		//���������Χ 0~35
		result = rand() % 35;
		
	
	}
	//������Ϊȡ��
	a[result] = 1;
	return result+1;
}

int LotteryMachine::getRanDomNumBack(int a[])
{
	int result = rand() % 12;
	//����ú��뱻ȡ����һֱ�ظ�ȡ����
	while (a[result] == 1) {
		//���������Χ 0~12
		result = rand() % 12;


	}
	//������Ϊȡ��
	a[result] = 1;
	return result+1; 
}

 
#pragma once
#include <string>
/**
��Ʊֽ
*/
class LotteryPaper
{
private:
	//ǰ������
	int frontArea[5];
	//��������
	int backArea[2];
public :
	int * getFrontArea();
	int * getBackArea();
	void setFrontArea(int num1, int num2, int num3, int num4, int num5);
	void setBackArea(int num1,int num2);
	void printPaper();
	std::string getNumnString();
	int getFrontAreaSize() {
		return 5;
	}
	int getBackAreaSize() {
		return 2;
	}

};


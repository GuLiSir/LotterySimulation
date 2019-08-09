#pragma once
#include <string>
/**
彩票纸
*/
class LotteryPaper
{
private:
	//前区号码
	int frontArea[5];
	//后区号码
	int backArea[2];
public :
	int * getFrontArea();
	int * getBackArea();
	//设置该彩票前区
	void setFrontArea(int num1, int num2, int num3, int num4, int num5);
	//设置该彩票后区
	void setBackArea(int num1,int num2);
	//打印该彩票信息
	void printPaper();
	std::string getNumnString();
	int getFrontAreaSize() {
		return 5;
	}
	int getBackAreaSize() {
		return 2;
	}

};


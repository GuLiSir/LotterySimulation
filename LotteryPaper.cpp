#include "LotteryPaper.h"
#include <iostream>
#include <string>
using namespace std;
 
int * LotteryPaper::getFrontArea(){
	return frontArea;
}


int* LotteryPaper::getBackArea(){
	return backArea;
}
void LotteryPaper::setFrontArea(int num1, int num2, int num3, int num4, int num5) {
	frontArea[0] = num1;
	frontArea[1] = num2;
	frontArea[2] = num3;
	frontArea[3] = num4;
	frontArea[4] = num5;
}

void LotteryPaper::setBackArea(int num1, int num2) {
	backArea[0] = num1;
	backArea[1] = num2;
}

void LotteryPaper::printPaper(){

	string str = getNumnString();
	std::cout << str << endl;
}

string LotteryPaper::getNumnString()
{
	string str = "";

	for (int i = 0; i < 5; i++) {
		str.append(to_string(frontArea[i]));
		str.append(" ");
	}
	str.erase(str.end() - 1);

	str.append(" * ");
	str.append(to_string(backArea[0]) + " " + to_string(backArea[1]));
	return str;
}

 
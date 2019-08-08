 

#include <iostream>
#include <cstdlib>
#include <string>
#include "LotteryMachine.h"
#include "LotteryPaper.h"
#include "Prize.h"
#include <list>

using namespace std;
 

void printInfo(int pn, Prize * p, LotteryPaper lp, int buyCount,int totalPrizeMoney) {
	int day = (buyCount / 3) * 7;//每周开奖三期,每期购买一注
	day += (buyCount % 3) * 2;//这里假设每两天开一期,总误差不会超过一天
	int buyMoney = (buyCount * 2);
	cout << "第" << buyCount << "期,已经过去" << day << "天," << day / 365 << "年" << (day%365) / 30 << "月" << day % 30 << "日" << endl;
	cout << "恭喜中得" << pn << "等奖,本等奖金:" << p->Money(lp, lp) << "元,目前已花费:" << buyMoney << "元,中奖总金额:"<< totalPrizeMoney
		<< "元,盈利:" << (totalPrizeMoney - buyMoney) << "元" << endl << endl;
}


int main()
{
    //std::cout << "Hello World!\n" ;

	LotteryMachine machine;
	LotteryPaper lp = machine.randomLotteryPaper();//抽奖的号码
	
 
	Prize9 p9;
	Prize8 p8;
	Prize7 p7;
	Prize6 p6;
	Prize5 p5;
	Prize4 p4;
	Prize3 p3;
	Prize2 p2;
	Prize1 p1;
	Prize& p = p8;

	LotteryPaper lp2;

	list<Prize*> pList(0);
	pList.push_back(&p9);
	pList.push_back(&p8);
	pList.push_back(&p7);
	pList.push_back(&p6);
	pList.push_back(&p5);
	pList.push_back(&p4);
	pList.push_back(&p3);
	pList.push_back(&p2);
	pList.push_back(&p1);
	
	cout << "开始计算..."<<endl;

	//购买期数
	int buyCount = 0;
	//总中奖金额
	int totlalPrizeMonry = 0;

	bool run = true;
	do {
		lp = machine.randomLotteryPaper();
		lp2 = machine.randomLotteryPaper();
		buyCount++;
		
		int sortName = 9;
		for (list<Prize *>::iterator it = pList.begin(); it != pList.end(); it++) {
			
			if ((*it)->isWinPrize(lp, lp2))
			{
			
				//每次中奖都打印一次号码
				//cout << "出奖号码:   ";
				//lp.printPaper();
				//cout << "购买的号码: ";
				//lp2.printPaper();
				//printInfo(sortName, (*it), lp2, buyCount, totlalPrizeMonry);

				totlalPrizeMonry += (*it)->Money(lp2, lp2);//统计中奖金额
				//printInfo(sortName, (*it) , lp2, buyCount, totlalPrizeMonry);
				if (sortName==1 || sortName == 2)//数字代表n等奖
				{
					//打印该得奖的号码 
					//得到目标奖项,不继续运行了
					run = false;

					//打印中奖的号码
					cout << "出奖号码:   ";
					lp.printPaper();
					cout << "购买的号码: ";
					lp2.printPaper();
					printInfo(sortName, (*it), lp2, buyCount, totlalPrizeMonry);
				}
			}
			sortName--;
		}

	} while (run);
	
	
	
	

}



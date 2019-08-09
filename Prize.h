#pragma once
#include "LotteryPaper.h"
#include <string>

class Prize
{
public:
	//是否中奖了
	virtual bool isWinPrize(LotteryPaper lpSrc/*开奖的号码*/, LotteryPaper lp) = 0;
	//中了多少钱
	virtual int Money(LotteryPaper lpSrc, LotteryPaper lp) = 0;
 
	//获取后区的中奖个数(计算交集)
	int getBackIntersectionSize(LotteryPaper lpSrc, LotteryPaper lp) {
		int* srcBack = lpSrc.getBackArea();
		int* back = lp.getBackArea();

		return getIntersectionSize(srcBack, back,lp.getBackAreaSize());
	}

	//获取前区的中奖个数
	int getFrontIntersectionSize(LotteryPaper lpSrc, LotteryPaper lp) {
		int* srcFront = lpSrc.getFrontArea();
		int* front = lp.getFrontArea();

		return getIntersectionSize( srcFront, front,lp.getFrontAreaSize());
	}

private:
	int getIntersectionSize(  int  a[],int    b[],int size) {
		int result = 0;
		//int la = arrLength(a);
		//int lb = arrLength(b);
		for (int i = 0; i < size; i++)
		{
			for (int i2 = 0; i2 < size; i2++)
			{
				if (a[i] == b[i2])
				{
					result++;
					break;
				}
			}
		}
		return result;
	}

	 

};

class Prize9 :public Prize {
public:
	bool Prize::isWinPrize(LotteryPaper lpSrc, LotteryPaper lp) override;
	int Prize::Money(LotteryPaper lpSrc, LotteryPaper lp) override;
	 
};

//直接根据中奖数量来进行判断中奖,不考虑顺序
class PrizeCount : public   Prize {
public:
	bool Prize::isWinPrize(LotteryPaper lpSrc, LotteryPaper lp) override {
		int frontIS = getFrontIntersectionSize(lpSrc, lp);
		int backIS = getBackIntersectionSize(lpSrc, lp);
		//调用抽象的判定方法
		return isWin(frontIS, backIS);
	}
 
	virtual bool isWin(int frontIS,int backIS) = 0;
};

class Prize8 : public PrizeCount {
public:
	bool isWin(int frontIS, int backIS) override{
		return (frontIS == 3 && backIS == 1)
			|| (frontIS == 2 && backIS == 2);
	}

	int Money(LotteryPaper lpSrc, LotteryPaper lp) override {
		return 15;
	}
};


class Prize7 : public PrizeCount {
public:
	bool isWin(int frontIS, int backIS) override {
		return (frontIS == 4 && backIS == 0) ;
	}

	int Money(LotteryPaper lpSrc, LotteryPaper lp) override {
		return 100;
	}
};


class Prize6 : public PrizeCount {
public:
	bool isWin(int frontIS, int backIS) override {
		return  (frontIS == 3 && backIS == 2);
	}

	int Money(LotteryPaper lpSrc, LotteryPaper lp) override {
		return 200;
	}
};



class Prize5 : public PrizeCount {
public:
	bool isWin(int frontIS, int backIS) override {
		return  (frontIS == 4 && backIS == 1);
	}

	int Money(LotteryPaper lpSrc, LotteryPaper lp) override {
		return 300;
	}
};


class Prize4 : public PrizeCount {
public:
	bool isWin(int frontIS, int backIS) override {
		return  (frontIS == 4 && backIS == 2);
	}

	int Money(LotteryPaper lpSrc, LotteryPaper lp) override {
		return 3000;
	}
};


class Prize3 : public PrizeCount {
public:
	bool isWin(int frontIS, int backIS) override {
		return  (frontIS == 5 && backIS == 0);
	}

	int Money(LotteryPaper lpSrc, LotteryPaper lp) override {
		return 10000;
	}
};

class Prize2 : public PrizeCount {
public:
	bool isWin(int frontIS, int backIS) override {
		return  (frontIS == 5 && backIS == 1);
	}

	int Money(LotteryPaper lpSrc, LotteryPaper lp) override {
		return 500000;
	}
};

class Prize1 : public PrizeCount {
public:
	bool isWin(int frontIS, int backIS) override {
		return  (frontIS == 5 && backIS == 2);
	}

	int Money(LotteryPaper lpSrc, LotteryPaper lp) override {
		return 10000000;
	}
};
 
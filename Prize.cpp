#include "Prize.h"
#include <iostream>
#include <string>
 

bool Prize9::isWinPrize(LotteryPaper lpSrc , LotteryPaper lp) {
	int frontIS = getFrontIntersectionSize(lpSrc, lp);
	int backIS = getBackIntersectionSize(lpSrc, lp);
	
	if (
		(backIS == 2)//��������������
		|| (frontIS == 2 && backIS == 1)//����ǰ��һ������
		|| (frontIS == 1 && backIS == 2)
		|| (frontIS == 3 && backIS == 0)
		)
	{
		//std::cout << "front:" << frontIS << "   back:" << backIS << std::endl;
		return true;
	}
	int a = 0;
	return false;
}

int Prize9::Money(LotteryPaper lpSrc , LotteryPaper lp) {
	//ÿע�����Ǯ
	return 5;
}

 

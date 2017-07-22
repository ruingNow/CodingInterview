/******************************************************************
一场精彩的自定义规则球赛，规则如下，A队每一次投入2分球，需要20秒时间，并且每三次投篮对方会获得关照分1分，
每一次投3分球，需要35秒时间，每三次投篮，对方会获得关照分2分。在给定剩下时间的情况下，需要最大化拉开与对
方的得分差距，A队的得分策略应该怎么安排，如果有多种策略符合，则优先输出A队得分高的方案，优先选择2分球投入
次数最多的方案。
输入：剩下的时间，以秒为单位
输出：A队的得分策略, 第一个数字表示几个2分，第二个数据表示几个3分
如：表示2个2分，0个3分
输入：40
输出：2,0  

思路：Z = 2x + 3y - x/3 - 2 * (y/3)
      T >= 20x + 35y 
******************************************************************/

#include <iostream>

using namespace std;

int main(void)
{
    int times;
    while(cin >> times)
	{
		int count2 = 0;
		int count3 = 0;
		int maxScore = 0;

		for(int x = 0; x <= times/20; ++x)
		{
			int y = (times - 20 * x)/35;
			int temp = 2*x + 3*y - x/3 - 2*(y/3);
			
			if(maxScore == temp)
			{
				if(count2 <= x)
				{
					count2 = x;
					count3 = y;
				}
			}
			if(maxScore < temp)
			{
				count2 = x;
				count3 = y;
				maxScore = temp;
			}
		}
		cout << count2 << "," << count3 << endl;
	}

    return 0;
}
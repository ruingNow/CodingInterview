/***************************************************************************
[编程题] 保卫方案
时间限制：1秒
空间限制：32768K
战争游戏的至关重要环节就要到来了，这次的结果将决定王国的生死存亡，小B负责首都的防卫工作。
首都位于一个四面环山的盆地中，周围的n个小山构成一个环，作为预警措施，小B计划在每个小山上设
置一个观察哨，日夜不停的瞭望周围发生的情况。 一旦发生外地入侵事件，山顶上的岗哨将点燃烽烟，
若两个岗哨所在的山峰之间没有更高的山峰遮挡且两者之间有相连通路，则岗哨可以观察到另一个山峰
上的烽烟是否点燃。由于小山处于环上，任意两个小山之间存在两个不同的连接通路。满足上述不遮挡
的条件下，一座山峰上岗哨点燃的烽烟至少可以通过一条通路被另一端观察到。对于任意相邻的岗哨，
一端的岗哨一定可以发现一端点燃的烽烟。 小B设计的这种保卫方案的一个重要特性是能够观测到对方
烽烟的岗哨对的数量，她希望你能够帮她解决这个问题。 

输入描述:
输入中有多组测试数据，每一组测试数据的第一行为一个整数n(3<=n<=10^6),为首都周围的小山数量，
第二行为n个整数，依次表示为小山的高度h（1<=h<=10^9）.


输出描述:
对每组测试数据，在单独的一行中输出能相互观察到的岗哨的对数。

输入例子1:
5
1 2 4 5 3

输出例子1:
7
***************************************************************************/
#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std; 

bool isFind(vector<pair<int, int>> flag, int i, int j)
{
    if(flag.size() == 0)
        return false;
    
    vector<pair<int, int>>::iterator itVec;
    itVec = find(flag.begin(), flag.end(), make_pair(i, j));
    if(itVec == flag.end())
        return false;
    
    return true;

}
int main() 
{ 
    int n; 
    while(cin >> n) 
    { 
		int x; 
		vector<int> mon; 
		int sum = 0; 
		int max; 
        for(int i = 0; i < n; i++)
        { 
            cin >> x; 
            mon.push_back(x); 
        } 
        sum = n; 
		vector<pair<int, int>> flag;
        for(int i = 0; i < n; i++) 
        { 
            max = mon[(i+1) % n];
            for(int j = (i+2)%n; j != ((i-1+n)%n); j = (++j)%n) 
            { 
           
                if((max <= mon[i]) && (max <= mon[j]) && !isFind(flag, i, j)) 
                {
					sum++;
					flag.push_back(make_pair(i, j));
					flag.push_back(make_pair(j, i));
                }
  
                if(mon[j] > max) 
                    max = mon[j]; 
            } 
        } 
        cout << sum << endl; 
    }

	return 0;
} 

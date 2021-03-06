/*********************************************
编程题：最高分是多少

老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。当然，老师有时候需要更新某位同学的成绩. 
输入描述:
输入包括多组测试数据。
每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
学生ID编号从1编到N。
第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。


输出描述:
对于每一次询问操作，在一行里面输出最高成绩.

输入例子:
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

输出例子:
5
6
5
9
********************************************/
#include <iostream>

using namespace std;

#define N 30000
#define SWAP(x, y) {x = x ^ y; y = x ^ y; x = x ^ y;}

int main(void)
{
    int m, n, A, B, maxVal = 0;
    int studentSocre[N] = {0};
    char oper;

	while(cin >> n >> m)
    {
		for(int i = 0; i < n; ++i)
		{
			cin >> studentSocre[i];
		}

		for(int k = 0; k < m; ++k)
		{
			cin >> oper >> A >> B;
			if(oper == 'Q')
			{
				maxVal = 0;
				if(A > n || B > n)
					return 0;
				if(A > B)
					SWAP(A, B);
				for(int i = A-1; i < B; ++i)
				{
					if(maxVal < studentSocre[i])
						maxVal =studentSocre[i];
				}
				cout << maxVal << endl;
			}
			else if(oper == 'U')
			{
				if(A > n)
					return 0;
				else
					studentSocre[A-1] = B;
			}
      
		}
    }

    return 0;
}
/******************************************************************************
题目描述：
根据调查，学计算机的学生IQ比较高。举个例子，如果我们把学计算机的一些学生调去学数学，那么
两个班级的学生平均IQ都会提升。
现在给出一群数学班级全体学生的IQ和计算机班级全体学生的IQ,问最多能把几个学计算机的学生调去
学数学，而两个班级的学生平均IQ都有提升呢？
每次只调一个学生，而且每次调配，两个班级的学生平均IQ都要提升。

输入：
第一行：一个正整数N（N<=100），代表数学班级学生的数目。
第二行：有N个正整数，代表每个数学学生的IQ（1~200）。
第三行：一个整数M（M<=100),代表计算机班级学生数目。
第四行：有M个正整数，代表每个计算机班级数学生的IQ（1~200）。
输入数据保证计算机学生平均IQ高于数学学生。

输出：
一个正整数，代表能从计算机调去学数学的学生的个数。

输入示例：
3
3 2 3
3
3 2 5

输出示例：
1

思想：
遍历计算机的每个学生IQ， 这个IQ满足 IQ > 数学班平均IQ && IQ < 计算机平均IQ，对满足条件
的IQ进行以下操作：
1. 把这个计算机的IQ拿出来 放到数学班里去，更新他们的平均成绩；
2. 如果他们的平均成绩均升高，则ans++，
3. 如果没有，则继续遍历下一个计算机IQ。
*****************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int M, N;
	cin >> N;
	int arrN[105], arrM[105];

	int sumN = 0, sumM = 0;
	for(int i = 0; i < N; ++i)
	{
		cin >> arrN[i];
		sumN += arrN[i];
	}

	cin >> M;
	for(int i = 0; i < M; ++i)
	{
		cin >> arrM[i];
		sumM += arrM[i];
	}

	double aveN = sumN/(double)N;
	double aveM = sumM/(double)M;

	double oldAveN = aveN;
	double oldAveM = aveM;
	int ans = 0;
	for(int i = M-1; i >= 0; --i)
	{
		if((arrM[i] - oldAveN >= 0)&&(oldAveM - arrM[i] >= 0))
		{
			int tempM = sumM - arrM[i];
			int tempN = sumN + arrM[i];

			if(((tempM/(double)(M-1)) - aveM) > 0 && ((tempN/(double)(N+1)) - aveN) > 0)
			{
				ans++;
				aveM = tempM/(double)(M-1);
				aveN = tempN/(double)(N+1);

				sumM = tempM;
				sumN = tempN;
				M--;
				N++;

			}
		}
	}

	cout << ans << endl;

	return 0;
}
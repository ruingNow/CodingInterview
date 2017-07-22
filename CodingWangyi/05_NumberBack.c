/******************************************************************
[编程题] 数字翻转
时间限制：1秒
空间限制：32768K
对于一个整数X，定义操作rev(X)为将X按数位翻转过来，并且去除掉前导0。例如:
如果 X = 123，则rev(X) = 321;
如果 X = 100，则rev(X) = 1.
现在给出整数x和y,要求rev(rev(x) + rev(y))为多少？ 
输入描述:
输入为一行，x、y(1 ≤ x、y ≤ 1000)，以空格隔开。


输出描述:
输出rev(rev(x) + rev(y))的值
******************************************************************/

#include <stdio.h>

int rev(int num)
{
  int modNum = 0;
  int result = 0;
  while(num/10 !=0)
  {
    modNum = num%10;
    num = num /10;
    result = result*10 + modNum;
  }
  return result * 10 + num;
}

int main(void)
{
  int a,b;
  scanf("%d %d",&a,&b);
  
  printf("%d",rev(rev(a)+rev(b)));
  return 0;
}

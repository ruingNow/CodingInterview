/*********************************************
题目描述
计算字符串最后一个单词的长度，单词以空格隔开。 
输入描述:
一行字符串，非空，长度小于5000。
输出描述:
整数N，最后一个单词的长度。
示例1
输入

hello world
输出

5
********************************************/

//思路1：通过strtok函数分割字符串，取最后一个分割 求其长度

/*
#include <stdio.h>
#include <string.h>

int main(void){
    char str[5000];
    char *temp;
    char *p;
    
    gets(str);
    
    temp = strtok(str, " ");
    while(temp){
        p = temp;
        temp = strtok(NULL, " ");
    }
    
    printf("%d\n",strlen(p));
    
    return 0;
    
}*/

//思路2：count计数，遇到空格 复位0 则最后count值为最后一个单词长度
#include <iostream>
using namespace std;
 
int main(void)
{
    string str;
    int count = 0;
    while(getline(cin, str))
    {
        int i = 0;
        while(str[i] != '\0')
        {
            if(str[i] == ' ')
                count = 0;
            else
                count++;
            i++;
        }
        cout << count << endl;
    }

    return 0;
}
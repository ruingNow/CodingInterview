/***************************************************************
[编程题] 数独
时间限制：1秒
空间限制：32768K
数独是一个我们都非常熟悉的经典游戏，运用计算机我们可以很快地解开数独难题，现在有一些简单的数独题目，请编写一个程序求解。

输入描述:
输入9行，每行为空格隔开的9个数字，为0的地方就是需要填充的。


输出描述:
输出九行，每行九个空格隔开的数字，为解出的答案。
**************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> blank;
int map[9][9] = {0};
int candidate[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void printSudo(void)
{
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            cout << map[i][j];
            if(j != 8)
                cout << " ";
        }
        cout << endl;
    }
   // cout << endl;
}

bool judge(int x, int y)
{
    for(int i = 0; i < 9; ++i)
    {
        if(map[x][i] == map[x][y] && i!=y)
            return false;
    }

    for(int j = 0; j < 9; ++j)
    {
        if(map[j][y] == map[x][y] && j != x)
            return false;
    }

    for(int i = x/3*3; i < x/3*3+3; ++i)
    {
        for(int j = y/3*3; j < y/3*3+3; ++j)
        {
            if(map[i][j] == map[x][y] && (i != x || j != y))
                return false;
        }
    }

    return true;
}

void cleanBlank(int depth)
{
    for(int i = depth - 1; i < blank.size(); ++i)
    {
        map[blank[i].first][blank[i].second] = 0;
    }
}

void dfs(pair<int, int> pos, int depth)
{
    for(int i = 0; i < 9; ++i)
    {
        map[pos.first][pos.second] = candidate[i];
        bool pass = judge(pos.first, pos.second);
        if(pass)
        {
            if(depth == blank.size())
            {
                printSudo();
                //return;
            }
            if(depth < blank.size())
            {
                dfs(blank[depth], depth + 1);
            }
        }
        cleanBlank(depth);
    }
}

int main(void)
{
   /* 
    string inputStr;
    int row = 0, k = 0;
    while(getline(cin, inputStr))
    {
        for(int i = 0; i < 9; ++i, k += 2)
        {
            map[row][i] = inputStr[k] - '0';
        }
        row++;
    }*/
  //  printSudo();
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            cin >> map[i][j];
            if(map[i][j] == 0)
            {
                blank.push_back(make_pair(i,j));
            }
        }
    }
    
    dfs(blank[0], 1);
    //printSudo();
    return 0;
}
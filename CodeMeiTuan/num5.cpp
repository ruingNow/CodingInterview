/*******************************************************
围棋是起源于中国有悠久历史的策略性棋类游戏。它的规则如下：
1. 棋盘19*19。
2. 棋子分黑白两色，双方各执一色。
3. 下法：每次黑或白着一子于棋盘的空点上。棋子下定后，不再向其他点移动。
4. 棋子的气：一个棋子在棋盘上，与它相邻的空点是这个棋子的“气”（这里相邻是指两个点有公共边）。 相邻的点上如果有同色棋子存在，这些棋子就相互连接成一个不可分割的整体，气合并计算。
相邻的点上如果有异色棋子存在，此处的气便不存在。
如果棋子所在的连通块失去所有的气，即为无气之子，不能在棋盘上存在。
5. 提子：把无气之子清理出棋盘的手段叫“提子”。提子有二种：
1) 着子后，对方棋子无气，应立即提取对方无气之子。
2) 着子后，双方棋子都呈无气状态，应立即提取对方无气之子。
6. 禁着点：棋盘上的任何一空点，如果某方在此下子，会使该子立即呈无气状态，同时又不能提取对方的棋子，这个点叫做“禁着点”，该方不能在此下子。
7. 禁止全局同形：无论哪一方，在成功进行了着子、提子操作后，棋盘局面不能和任何之前的局面相同。

你要做的是：输入一些操作，从空棋盘开始模拟这些操作。
对于每一步，若结果不正确，则输出对应的miss并且忽略这个操作，并在最后输出棋盘的局面。 
输入描述:
第一行，测试数据组数≤100

第二行，每组测试数据，执行的步数 n ≤ 2000 

然后 n 行 

B x y 

W x y 

(1 ≤ x ≤ 19,1 ≤ y ≤ 19)
其中，二元组 x,y 表示围棋棋盘上第 x 行第 y 列对应的点。
输入数据保证是黑白轮流下的。


输出描述:
多行
对于miss的情况，输出是哪一种错误格式，其中：
miss 1 表示下的位置已经有棋了
miss 2 表示违反规则6
miss 3 表示违反规则7
对于正常的操作，不用输出。
最后输出最终盘面。“B表示黑子，W表示白子，如果是空点的话，就输出'.'字符。”

输入例子:
1
12
B 1 3
W 1 2
B 2 4
W 2 1
B 1 1
W 2 3
B 3 3
W 3 2
B 1 1
W 2 3
B 2 2
W 2 3

对应的棋形是这样的：


输出例子:
miss 2
miss 2
miss 1
miss 3
.WB................
WB.B...............
.WB................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
*******************************************************/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef unsigned long long ull;
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char cur[25][25],nxt[25][25];
set<pair<ull,ull> > st;
inline void init()
{
    st.clear();
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
            cur[i][j]='.';
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
            nxt[i][j]='.';
}
inline void cop()
{
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
            nxt[i][j]=cur[i][j];
}
inline void pas()
{
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
            cur[i][j]=nxt[i][j];
}
inline bool check()
{
    ull has[2]={0,0};
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
        {
            has[0]=has[0]*131+nxt[i][j];
            has[1]=has[1]*137+nxt[i][j];
        }
    if(st.find(make_pair(has[0],has[1]))==st.end())
    {
        st.insert(make_pair(has[0],has[1]));
        return 1;
    }
    else return 0;
}
inline void show()
{
    for(int i=1;i<=19;i++)
        printf("%s\n",cur[i]+1);
}
int vis[25][25];
inline void fre()
{
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
            vis[i][j]=0;
}
bool dfs(int x,int y,char g)
{
    if(nxt[x][y]=='.')return 1;
    if(nxt[x][y]!=g)return 0;
    vis[x][y]=1;
    bool isok=0;
    for(int i=0;i<4;i++)
    {
        int tx=x+dir[i][0],ty=y+dir[i][1];
        if(!vis[tx][ty])
            isok|=dfs(tx,ty,g);
    }
    return isok;
}
void pick(int x,int y,char g)
{
    nxt[x][y]='.';
    for(int i=0;i<4;i++)
    {
        int tx=x+dir[i][0],ty=y+dir[i][1];
        if(nxt[tx][ty]==g)pick(tx,ty,g);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        init();
        check();
        for(int i=1;i<=n;i++)
        {
            char go[5];
            int x,y;
            scanf("%s%d%d",go,&x,&y);
            char a=go[0],b="BW"[a=='B'];
            if(cur[x][y]!='.')printf("miss 1\n");
            else
            {
                cop();
                nxt[x][y]=a;
                fre();
                bool isok=dfs(x,y,a);
                for(int i=0;i<4;i++)
                {
                    int tx=x+dir[i][0],ty=y+dir[i][1];
                    if(!vis[tx][ty] && nxt[tx][ty]==b && !dfs(tx,ty,b))
                    {
                        pick(tx,ty,b);
                        isok=1;
                    }
                }
                if(isok)
                {
                    if(check())pas();
                    else printf("miss 3\n");
                }
                else printf("miss 2\n");
            }
        }
        show();
    }
    return 0;
}
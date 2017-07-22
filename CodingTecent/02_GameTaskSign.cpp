/*********************************************************
[编程题] 游戏任务标记
时间限制：1秒
空间限制：32768K
游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。
请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态都是未完成。 输入两个参数，都是任务ID，
需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。 输出一个参数，如果第二个ID的任务已
经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。 
输入描述:
输入包括一行,两个整数表示人物ID.


输出描述:
输出是否完成

输入例子1:
1024 1024

输出例子1:
1

算法思想：该题目主要是理解应用题的题意，意思是每个玩家都有1024个任务要做，要么全做完了，要么没做。
其实简单说就还是判断连个任务是否相等

********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
int main() {
    using namespace std;
    unsigned int n, m;
    while (cin >> n >> m) {
        if (n < 1 || n > 1024 || m < 1 || m > 1024) {
            cout << -1 << endl;
        }
        else {
            if (n == m) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}

/*
32个 unsigned int 型整数，正好有32*32 = 1024个bit，每个 bit 表示一个 任务即可。

#include <iostream>
using namespace std;

unsigned int arr[32];

int main()
{
    int id1, id2;
    while(cin>>id1>>id2)
    {
        int group1 = (id1-1)/32, group2 = (id2-1)/32;
        if(!(id2>=1&&id2<=1024))
        {
            cout<<-1<<endl;
            continue;
        }
        arr[group1] |= (1<<((id1-1)%32));
        cout<<( (arr[group2] & (1<<((id2-1)%32))) != 0)<<endl;
    }
    return 0;
}
*/

/*
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

    //1024 1024
    static Map<Integer,Boolean> record= new LinkedHashMap<>();//记录完成任务的玩家信息
    public static int calId(int id1,int id2){//id1完成任务，开始检测id2是否完成任务
        if(id1<1||id1>1024||id2<1||id2>1024){//条件检测
            return -1;
        }
        //id1玩家设置任务id
        record.put(id1,true);//id1做完了任务
        if(record.get(id2)!=null){
            if(record.get(id2)==true){
                return 1;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int id1,id2;
        while (scanner.hasNext()){
            id1=scanner.nextInt();
            id2=scanner.nextInt();
            System.out.println(calId(id1,id2));
        }
    }
}
*/
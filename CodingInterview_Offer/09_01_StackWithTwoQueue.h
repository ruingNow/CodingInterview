/*
用两个队列实现栈
*/
#pragma once
#include <queue>
#include <exception>

using namespace std;

template <typename T> class CStack
{
public:
    CStack(void);
    ~CStack(void);

    void cpush(const T& node);
    T cpop();
private:
    queue<T> que1;
    queue<T> que2;
};

template <typename T> CStack<T>::CStack(void)
{

}
template <typename T> CStack<T>::~CStack(void)
{

}

template <typename T> void CStack<T>::cpush(const T& node)
{
    if(!que1.empty() && !que2.empty())
        throw new exception("push error");

    if(!que2.empty())
        que2.push(node);
    else
        que1.push(node);
}

template <typename T> T CStack<T>::cpop()
{
    T tailNode;
    if(que1.empty() && que2.empty())
        throw new exception("stack empty");

    if(que1.empty() && !que2.empty())
    {
        tailNode = que2.back();
        while(tailNode != que2.front())
        {
            que1.push(que2.front());
            que2.pop();
        }
        que2.pop();
    }else if(!que1.empty() && que2.empty())
    {
        tailNode = que1.back();
        while(tailNode != que1.front())
        {
            que2.push(que1.front());
            que1.pop();
        }
        que1.pop();
    }

    return tailNode;
}
//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

#pragma once
#include <stack>
#include <exception>

using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    // 在队列末尾添加一个结点
    void appendTail(const T& node);

    // 删除队列的头结点
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};
/**********************************
算法思想：
弹出元素：新插入的元素都放入stack1，当stack2不为空时，在stack2中的栈顶元素是
最先进入队列的元素，可以弹出；当stack2为空时，我们把stack1中的元素出栈依次压入
stack2.
压入元素：都压入stack1
**********************************/
template <typename T> CQueue<T>::CQueue(void)
{

}

template <typename T> CQueue<T>::~CQueue(void)
{

}

template <typename T> void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
}
template <typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size() <= 0)
    {
        T& data = stack1.top();
        stack1.pop();
        stack2.push(data);
    }
    if(stack2.size() == 0)
        throw new exception("queue is empty");

    T head = stack2.top();
    stack2.pop();

    return head;
}

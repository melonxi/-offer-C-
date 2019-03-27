//用两个栈实现一个队列；
//栈stackIn用于入队，queue的push操作，都在stackIn的push实现；
//栈stackOut用于出队，如果stackOut是空的，就将stackIn的值依次入stackOut栈，如果stackOut非空，出队列时就stackOut.pop。
//

#include <iostream>
#include <stack>
#include <exception>

using namespace std;

class StackToQueue
{
private:
    stack <int> stackIn;
    stack <int> stackOut;
    
public:
    StackToQueue(void);
    void push(int obj);
    int pop(void);
};

StackToQueue::StackToQueue()
{
    stack <int> s1;
    stack <int> s2;
    stackIn = s1;
    stackOut = s2;
}

void StackToQueue::push(int obj)
{
    stackIn.push(obj);
}

int StackToQueue::pop()
{
    if(stackIn.empty() && stackOut.empty())
    {
        //logic_error ex("queue is empty.");
        //throw std::exception(ex);
        cout <<"queue is empty."<<endl;
        return -1;
    }
    if(stackOut.empty())
    {
        while(!stackIn.empty())
        {
            stackOut.push(stackIn.top());
            stackIn.pop();
        }
    }
    int temp = stackOut.top();
    stackOut.pop();
    
    return temp;
    
}

int main()
{
    StackToQueue sTQ;
    sTQ.push(1);
    sTQ.push(2);
    sTQ.push(3);
    cout << sTQ.pop() << endl;
    cout << sTQ.pop() << endl;
    cout << sTQ.pop() << endl;
    cout << sTQ.pop() << endl;
    sTQ.push(3);
    cout << sTQ.pop() << endl;
    return 0;
}

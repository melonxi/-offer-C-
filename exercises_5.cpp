//题目：反向打印链表
//思路：利用栈顺序保存节点地址，然后出栈打印

#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

void addToList(ListNode**, int);
void printListRevers(ListNode*);

int main()
{
    ListNode* pHead = new ListNode();
    pHead->m_nKey = 1;
    pHead->m_pNext = nullptr;
    addToList(&pHead, 2);
    addToList(&pHead, 3);
    addToList(&pHead, 4);
    addToList(&pHead, 5);
    
    printListRevers(pHead);
    
    return 0;
}

void printListRevers(ListNode* pHead)
{
    stack <ListNode*> nodes;
    
    ListNode* pNode = pHead;
    while(pNode!=nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    
    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode->m_nKey <<" ";
        nodes.pop();
    }
}

void addToList(ListNode** pHead, int nodeValue)
{
    ListNode* pNew = new ListNode();//初始化新列表节点
    pNew->m_nKey = nodeValue;//给新节点赋值
    pNew->m_pNext = nullptr;//新节点的下一个节点的地址未知
    
    if(*pHead == nullptr)//如果这是一个空链表（头节点都没有地址）
    {
        *pHead = pNew;//把新节点的地址赋给头节点（pHead是一个指向指针的指针）
    }
    else
    {
        ListNode* pNode = *pHead;
        
        while(pNode->m_pNext!=nullptr)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}

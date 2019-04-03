#include <iostream>
struct ListNode
{
    int nValue;
    ListNode* pNext;
};

using namespace std;

void deleteNode(ListNode** pListHead, ListNode* pToBeDeleted);
void addListNode(int value, ListNode** HeadNode);


int main()
{
    ListNode* pHead = new ListNode();
    addListNode(1, &pHead);
    addListNode(2, &pHead);
    addListNode(3, &pHead);
    addListNode(4, &pHead);
    
    return 0;
}

void deleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
    {
        return;
    }
    if(pToBeDeleted->pNext != nullptr)
     {
        ListNode* nextNode = pToBeDeleted->pNext;
        pToBeDeleted->nValue = nextNode->nValue;
        pToBeDeleted->pNext = nextNode->pNext;
        
        delete nextNode;
        nextNode = nullptr;
    }
    
    else if(*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    else
    {
        ListNode* pCurrent = *pListHead;
        
        while(pCurrent->pNext != pToBeDeleted)
        {
            pCurrent = pCurrent->pNext;
        }
        
        pCurrent->pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        
    }
}

void addListNode(int value, ListNode** HeadNode)
{
    ListNode* endNode = new ListNode();
    endNode->nValue = value;
    endNode->pNext = nullptr;
    
    if(*HeadNode == nullptr)
    {
        *HeadNode = endNode;
    }
    else
    {
        ListNode* pNode = *HeadNode;
        while(pNode->pNext != nullptr)
        {
            pNode = pNode->pNext;
        }
        pNode->pNext = endNode;
       
    }
}
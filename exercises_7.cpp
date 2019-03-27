//给定二叉树和其中的一个节点，如何找出**中序遍历**序列的下一个节点？（树中的节点除了有指向左右子节点的指针，还有一个指向父节点的指针）
//分三中情况：
//1.节点有右子树，那么下一个节点就是右子树的最左节点；
//2.节点没有右子树，且是其父节点的左子节点，那么下一个节点就是其父节点；
//3.节点没有右子树，且是其父节点的右子节点，那么向上循环寻找父节点，直到找到一个节点是其父节点的左子节点，那么当前节点的父节点就是下一个节点。
#include <iostream>

using namespace std;

struct binaryTreeNode
{
    int nValue;
    binaryTreeNode* pLeft;
    binaryTreeNode* pRight;
    binaryTreeNode* pFather;
};

binaryTreeNode* createBinaryTreeNode(int value);
binaryTreeNode* getNextNode(binaryTreeNode* pNode);
void connectTreeNodes(binaryTreeNode* pF, binaryTreeNode* pL, binaryTreeNode* pR);
void destroyTree(binaryTreeNode* pRoot);
void Test(const char* testName, binaryTreeNode* pNode, binaryTreeNode* expected);

int main()
{
    binaryTreeNode* pNode8 = createBinaryTreeNode(8);
    binaryTreeNode* pNode6 = createBinaryTreeNode(6);
    binaryTreeNode* pNode10 = createBinaryTreeNode(10);
    binaryTreeNode* pNode5 = createBinaryTreeNode(5);
    binaryTreeNode* pNode7 = createBinaryTreeNode(7);
    binaryTreeNode* pNode9 = createBinaryTreeNode(9);
    binaryTreeNode* pNode11 = createBinaryTreeNode(11);

    connectTreeNodes(pNode8, pNode6, pNode10);
    connectTreeNodes(pNode6, pNode5, pNode7);
    connectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, nullptr);

    destroyTree(pNode8);
    
    return 0;
}

binaryTreeNode* getNextNode(binaryTreeNode* pNode)
{
    if(pNode == nullptr)
    {
        return nullptr;
    }
    
    binaryTreeNode* pNext = nullptr;
    
    if(pNode->pRight!=nullptr)
    {
        binaryTreeNode* pRight = pNode->pRight;
        while(pRight->pLeft!=nullptr)
        {
            pRight = pRight->pLeft;
        }
        pNext = pRight;
    }
    else if(pNode->pFather!=nullptr)
    {
        binaryTreeNode* pCurrent = pNode;
        binaryTreeNode* pDad = pNode->pFather;
        
        while(pDad!=nullptr && pCurrent==pDad->pRight)
        {
            pCurrent = pDad;
            pDad = pDad->pFather;
        }
    
        pNext = pDad;
    }
    
    return pNext;
}

//================辅助代码用来构建二叉树=================
binaryTreeNode* createBinaryTreeNode(int value)
{
    binaryTreeNode* pNode = new binaryTreeNode();
    pNode->nValue = value;
    pNode->pLeft = nullptr;
    pNode->pRight = nullptr;
    pNode->pFather = nullptr;
    
    return pNode;
}

void connectTreeNodes(binaryTreeNode* pF, binaryTreeNode* pL, binaryTreeNode* pR)
{
    if(pF!=nullptr)
    {
        pF->pLeft = pL;
        pF->pRight = pR;
        if(pL!=nullptr)
        {
            pL->pFather = pF;
        }
        if(pR!=nullptr)
        {
            pR->pFather = pF;
        }
    }
}

void destroyTree(binaryTreeNode* pRoot)
{
    if(pRoot!=nullptr)
    {
        binaryTreeNode* pL = pRoot->pLeft;
        binaryTreeNode* pR = pRoot->pRight;
        
        delete pRoot;
        pRoot = nullptr;
        
        destroyTree(pL);
        destroyTree(pR);
    }
}

void Test(const char* testName, binaryTreeNode* pNode, binaryTreeNode* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    binaryTreeNode* pNext = getNextNode(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

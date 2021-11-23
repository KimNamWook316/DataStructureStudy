#include <queue>
#include "LinkBinaryTree.h"

CLinkBinaryTree::CLinkBinaryTree()  :
    mpRoot(nullptr)
{
}

CLinkBinaryTree::~CLinkBinaryTree()
{
}

void CLinkBinaryTree::SetRoot(CBinaryNode* node)
{
    mpRoot = node;
}

CBinaryNode* CLinkBinaryTree::GetRoot()
{
    return mpRoot;
}

bool CLinkBinaryTree::IsEmpty()
{
    return mpRoot == nullptr;
}

void CLinkBinaryTree::InOrder()
{
    if (!IsEmpty())
    {
        std::cout << "InOrder : " << std::endl;
        mpRoot->InOrder();
    }
}

void CLinkBinaryTree::PreOrder()
{
    if (!IsEmpty())
    {
        std::cout << "PreOrder : " << std::endl;
        mpRoot->PreOrder();
    }
}

void CLinkBinaryTree::PostOrder()
{
    if (!IsEmpty())
    {
        std::cout << "PostOrder : " << std::endl;
        mpRoot->PostOrder();
    }
}

void CLinkBinaryTree::LevelOrder()
{
    if (!IsEmpty())
    {
        std::cout << "LevelOrder : " << std::endl;
        std::queue<CBinaryNode*> queue;
        queue.push(mpRoot);

        while (!queue.empty())
        {
            CBinaryNode* curNode = queue.front();
            queue.pop();

            curNode->Print();

            if (curNode->GetLeft() != nullptr)
            {
                queue.push(curNode->GetLeft());
            }
            if (curNode->GetRight() != nullptr)
            {
                queue.push(curNode->GetRight());
            }
        }
    }
}

int CLinkBinaryTree::GetCount()
{
    return 0;
}

int CLinkBinaryTree::GetHeight()
{
    return 0;
}

int CLinkBinaryTree::GetLeafCount()
{
    return 0;
}
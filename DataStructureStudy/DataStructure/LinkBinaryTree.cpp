#include <queue>
#include <cassert>
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
    if (IsEmpty())
    {
        return 0;
    }

    return getCount(mpRoot);
}

int CLinkBinaryTree::GetHeight()
{
    if (IsEmpty())
    {
        return 0;
    }

    return getHeight(mpRoot);
}

int CLinkBinaryTree::GetLeafCount()
{
    if (IsEmpty())
    {
        return 0;
    }

    return getLeafCount(mpRoot);
}

int CLinkBinaryTree::Caculate()
{
    return calculate(mpRoot);
}

int CLinkBinaryTree::getCount(CBinaryNode* node)
{
    if (nullptr == node)
    {
        return 0;
    }

    return 1 + getCount(node->GetLeft()) + getCount(node->GetRight());
}

int CLinkBinaryTree::getLeafCount(CBinaryNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (node->GetLeft() == nullptr && node->GetRight() == nullptr)
    {
        return 1;
    }

    else
    {
        return getLeafCount(node->GetLeft()) + getLeafCount(node->GetRight());
    }
}

int CLinkBinaryTree::getHeight(CBinaryNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int lHeight = 1 + getHeight(node->GetLeft());
    int rHeight = 1 + getHeight(node->GetRight());

    return lHeight > rHeight ? lHeight : rHeight;
}

int CLinkBinaryTree::calculate(CBinaryNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (node->IsLeaf())
    {
        return node->GetData();
    }

    int lResult = calculate(node->GetLeft());
    int rResult = calculate(node->GetRight());

    switch ((char)node->GetData())
    {
    case '+':
        return lResult + rResult;
        break;
    case '-':
        return lResult - rResult;
        break;
    case '*':
        return lResult * rResult;
        break;
    case '/':
        return lResult / rResult;
    default:
        assert(false);
        break;
    }
}

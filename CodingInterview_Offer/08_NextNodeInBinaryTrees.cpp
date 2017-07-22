// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
/**
算法思想:分类讨论 1. 如果一个节点有右子树，那个它的下一个节点就是它右子树
中最左子节点。也就是说，从右子节点出发一直沿着指向左子节点的指针，我们就能找到
它的下一个节点。
2. 一个节点没有右子树。如果节点是它父节点的左子节点，那么它的下一个节点就是它
的父节点。
3. 一个节点没有右子树，并且他还是父节点的右子节点。我们可以沿着指向父节点的指针
一直向上遍历，直到找到一个是它父节点的左子节点。如果这样的节点存在，那么这个节点
的父节点就是我们要找的下一个节点。

*/

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
        return nullptr;

    BinaryTreeNode* pNext = nullptr;
    if(pNode->m_pRight != nullptr)
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != nullptr)
            pRight = pRight->m_pLeft;
        
        pNext = pRight;
    }
    else if(pNode->m_Parent != nullptr)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != nullptr && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }
    return pNext;
}
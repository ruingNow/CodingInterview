// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。
/*
算法思想：在二叉树的前序遍历序列中，第一个数字总是树的根节点的值，但在中序遍
历序列中，根节点的值在序列的中间，左子树的节点的值位于根节点的值的左边，而右
子树的节点的值位于根节点的值的右边。
*/

/*
struct BinaryTreeNode
{
    int             m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
*/
BinaryTreeNode* Construct(int* preorder, int inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length -1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    //前序遍历序列的第一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    if(startPreorder == endPreorder)
    {
        if(startInorder == endPreorder && *startPreorder == *startInorder)
            return root;
        else
            throw std:: exception("Invalid input.")；
    }
    //在中序遍历序列中找到根节点的值
    int* rootInorder == startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;
    
    if(rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception("Invalid input.");
    
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return root;
}
#include <iostream>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> stk;
    while (root != nullptr || !stk.empty())
    {
        while (root != nullptr)
        {
            stk.push(root);    // 左子树压入栈
            root = root->left; // 循环到最左下结点
        }
        root = stk.top();
        stk.pop();
        k--;
        if (k == 0)
            return root->val;
        root = root->right; // 左子树全部遍历，开始向上遍历右子树
    }
    return root->val;
}

int main()
{

    return 0;
}
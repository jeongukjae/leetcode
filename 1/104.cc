// 104. Maximum Depth of Binary Tree

#include <algorithm>

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

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return dfs(root, 1);
    }

private:
    int dfs(TreeNode *node, int currentDepth)
    {
        if (node->left == nullptr && node->right == nullptr)
            return currentDepth;

        if (node->right == nullptr)
            return dfs(node->left, currentDepth + 1);

        if (node->left == nullptr)
            return dfs(node->right, currentDepth + 1);

        return max(dfs(node->left, currentDepth + 1), dfs(node->right, currentDepth + 1));
    }
};

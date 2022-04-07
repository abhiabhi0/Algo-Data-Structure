/**
 * Diameter of tree = Length of the longest path b/w any two nodes
 * of the tree.
**/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class NodeInfo
{
    public:
    int height;
    int diameter;
  
    NodeInfo(int h, int d) : height(h),
                             diameter(d)
                             {}
};

int tree_height(TreeNode* A)
{
    if (A == NULL)
    {
        return -1;
    }

    return 1 + max(tree_height(A->left), tree_height(A->right));
}

NodeInfo tree_diameter(TreeNode* A)
{
    if (A == NULL)
    {
        return NodeInfo(-1, -1);
    }

    NodeInfo l = tree_diameter(A->left);
    NodeInfo r = tree_diameter(A->right);

    return NodeInfo(max(l.height, r.height)+1, max(max(l.diameter, r.diameter), l.height + r.height + 2));
}

int solve(TreeNode* A) {
    NodeInfo obj = tree_diameter(A);
    return obj.diameter;
}


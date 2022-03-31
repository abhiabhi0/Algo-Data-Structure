/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    if (A == NULL)
    {
        return {};
    }

    vector<int> res;

    queue<TreeNode*> q;
    q.push(A);

    while (!q.empty())
    {
        int q_sz = q.size();

        for (int i = 0; i < q_sz; ++i)
        {
            TreeNode* tmp = q.front();
            q.pop();

            res.push_back(tmp->val);

            if (tmp->left != NULL)
            {
                q.push(tmp->left);
            }

            if (tmp->right != NULL)
            {
                q.push(tmp->right);
            }
        }
        res.push_back(-1);
    }

    vector<int> ans;

    for (int i = 0; i < res.size()-1; ++i)
    {
        if (res[i+1] == -1)
        {
            ans.push_back(res[i]);
        }
    }
    return ans;
}

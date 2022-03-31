//If Vertical Order doesn't matter

// map<distance, list of nodes>
std::unordered_map<int, std::vector<int> > um;

// starts dist with 0
void vertical_order_traversal(TreeNode* root, int dist)
{
	if (root == NULL)
		return NULL;

	if (um.find(dist) == um.end())
	{
		um.insert({dist, {}});
	}

	um[dist] = root->val;
	vertical_order_traversal(root->left, dist-1);
	vertical_order_traversal(root->right, dist+1);
}

//If vertical order matters

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > vertical_order_traversal(TreeNode* A) {
    //map dist and values
    if (A == NULL)
    {
        return {{}};
    }
    unordered_map<int, vector<int>> um;
    vector<int> distances;

    //queue dist and node
    queue<pair<int, TreeNode*>>q;
    q.push({0, A});

    while (!q.empty())
    {
        int q_sz = q.size();

        for (int i = 0; i < q_sz; ++i)
        {
            pair<int, TreeNode*> p = q.front();
            q.pop();

            int dist = p.first;
            TreeNode*tmp = p.second;

            if (um.find(dist) == um.end())
            {
                std::vector<int> v_tmp = {tmp->val};
                um.insert({dist, v_tmp});
                distances.push_back(dist);
            }
            else  
            {
                um[dist].push_back(tmp->val);
            }

            if (tmp->left != NULL)
            {
                q.push({dist-1, tmp->left});
            }

            if (tmp->right != NULL)
            {
                q.push({dist+1, tmp->right});
            }
        }
    }

    vector<vector<int>> res;
    sort(distances.begin(), distances.end());

    for (int i = 0; i < distances.size(); ++i)
    {
        res.push_back(um[distances[i]]);
    }
    return res;
}

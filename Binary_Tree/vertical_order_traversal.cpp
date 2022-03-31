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

// map<distance, list of nodes>
std::unordered_map<int, std::vector<int> > um;

void vertical_order_traversal(TreeNode* root)
{
	if (root == NULL)
		return NULL;

	//Queue of Node and dist
	std::queue<TreeNode*, int> q;
	q.push({root, 0});

	while (!q.empty())
	{
		int q_sz = q.size();

		for (int i = 0; i < q_sz; ++i)
		{
			pair<int, TreeNode*> pr = q.front();
			q.pop();

			int dist = pr.first;
			TreeNode* tmp = pr.second;

			if (i == 0)
			{
				if (um.find(dist) == um.end())
				{
					um.insert({dist, {root->val}});
				}
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
}

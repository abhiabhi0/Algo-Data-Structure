//Calculate number of nodes a a distance k from source node

bool add_path(vector<TreeNode*>& path, TreeNode* root, int v)
{
	if (root == NULL)
	{
		return false;
	}

	if (root->val == v)
	{
		path.push_back(root);
		return true;
	}

	if (add_path(path, root->left, v) || add_path(path, root->right, v))
	{
		path.push_back(root);
		return true;
	}
	return false;
}

int below_nodes_at_k(TreeNode* node, int k)
{
	if (node == NULL || k < 0)
	{
		return 0;
	}

	if (k == 0)
	{
		return 1;
	}

	int l = below_nodes_at_k(node->left, k-1);
	int r = below_nodes_at_k(node->right, k-1);

	return l+r;
}

int count_all(TreeNode* root, int v, int k)
{
	//calculate path from given node to root node
	vector<TreeNode*> path;
	bool res = add_path(path, root, v);

	int count = below_nodes_at_k(path[0], k);

	for (int i = 1; i < path.size(); ++i)
	{
		//curr node path[i] and child node path[i-1]
		if (path[i]->left == path[i-1])
		{
			//goto right and search
			count = count + below_nodes_at_k(path[i]->right, k-i-1);
		}
		else  
		{
			//goto left and search
			count = count + below_nodes_at_k(path[i]->left, k-i-1);
		}
	}

	return count;
}

//TC O(N)
//SC O(H)

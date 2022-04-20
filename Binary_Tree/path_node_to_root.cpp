//Find path from givrn node to root node in BT

bool add_path(vector<TreeNode*>& path, TreeNode* root, int k)
{
	if (root == NULL)
	{
		return false;
	}

	if (root->val == k)
	{
		path.push_back(root);
		return true;
	}

	if (add_path(path, root->left, k) || add_path(path, root->right, k))
	{
		path.push_back(root);
		return true;
	}
	return false;
}

vector<int> find_path(TreeNode* root, int k)
{
	vector<TreeNode*> path;
	bool val = add_path(path, root, k);
	return path;
}

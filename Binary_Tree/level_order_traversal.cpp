std::vector<vector<int>> level_order_traversal(TreeNode* root)
{
	if (root == NULL)
		return NULL;

	std::vector<vector<int>> res;

	std::queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		std::vector<int> level;
		int q_sz = q.size();

		for (int i = 0; i < q_sz; ++i)
		{
			TreeNode* tmp = q.front();
			q.pop();

			level.push(tmp->val);

			if (tmp->left != NULL)
			{
				q.push(tmp->left);
			}

			if (tmp->right != NULL)
			{
				q.push(tmp->right);
			}
		}
		res.push_back(level);
	}
	return res;
}

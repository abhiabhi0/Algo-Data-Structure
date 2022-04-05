TreeNode* insert(TreeNode* root, int value)
{
	if (root == NULL)
	{
		return new TreeNode(value);
	}

	if (root->val > value)
	{
		root->left = insert(root->left, value);
	}
	else if (root->val < value)
	{
		root->right = insert(root->right, value);
	}
	return root;
}

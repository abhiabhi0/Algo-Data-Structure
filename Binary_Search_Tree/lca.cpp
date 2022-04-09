int lca_bst(TreeNode* root, int n1, int n2)
{
	if (root == NULL)
	{
		return -1;
	}

	if (root->val >= n1 && root->val <= n2)
	{
		return root->val;
	}

	if (root->val > n1 && root->val > n2)
	{
		return lca_bst(root->left, int n1, int n2);
	}

	if (root->val < n1 && root->val < n2)
	{
		return lca_bst(root->right, int n1, int n2);
	}
}

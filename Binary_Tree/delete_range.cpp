/**
 * Given a BST. Given a range l to h. Delete every node which has a
 * value outside the range [l, h]
**/

TreeNode* trim_bst(TreeNode* root, int l, int h)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->val < l)
	{
		return trim_bst(root->right, l, h);
	}

	if (root->val > h)
	{
		return trim_bst(root->left, l, h);
	}

	root->left = trim_bst(root->left, l, h);
	root->right = trim_bst(root->right, l, h);
	return root;
}

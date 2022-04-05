bool is_leaf(TreeNode* root)
{
	if (root->left == NULL && root->right == NULL)
	{
		return true;
	}
	return false;
}

TreeNode* get_max(TreeNode* root)
{
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root;
}

TreeNode* delete_node(TreeNode* root, int value)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->val > value)
	{
		root->left = delete_node(root->left, value);
	}
	else if (root->val < value)
	{
		root->right = delete_node(root->right, value);
	}
	else  //root is the node to be deleted
	{
		//case 1 : root is a leaf node
		if (is_leaf(root))
		{
			return NULL;
		}

		//case 2 : root has 1 child
		if (root->left == NULL)
		{
			return root->right;
		}
		else if (root->right == NULL)
		{
			return root->left;
		}

		//case 3 : root has both childs
		TreeNode* mx_value_node = get_max(root->left);
		root->val = mx_value_node->val;
		root->left = delete_node(root->left, mx_value_node->val);
		return root;
	}
}

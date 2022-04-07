void morris_inorder_traversal(TreeNode* root)
{
	TreeNode* curr = root;

	while (curr != NULL)
	{
		if (curr->left == NULL)
		{
			cout << curr->val << "\n";
			curr = curr->right;
		}
		else  
		{
			TreeNode* tmp = curr->left;

			while (tmp->right != NULL && tmp->right != curr)
			{
				tmp = tmp->right;
			}

			if (tmp->right == NULL)
			{
				tmp->right = curr;
				curr = curr->left;
			}
			else  
			{
				tmp->right = NULL;
				cout << curr->val << "\n";
				curr = curr->right;
			}
		}
	}
}

//TC = O(3N) = O(N)
//Sc = O(1)

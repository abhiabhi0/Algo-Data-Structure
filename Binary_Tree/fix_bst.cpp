/**
 * Given a BST where two nodes have been swapped. Fix the BST
**/

void fix_bst(TreeNode* root)
{
	TreeNode* prev = NULL;
	TreeNode* n1 = NULL;
	TreeNode* n2 = NULL;

	if (root == NULL)
	{
		return;
	}

	fix_bst(root->left);
	if (prev != NULL)
	{
		if (prev->val > root->val)
		{
			if (n1 == NULL)
			{
				n1 = prev;
				n2 = root;
			}
			else  
			{
				n2 = root;
			}
		}
	}
	prev = root;
	fix_bst(root->right);
} 

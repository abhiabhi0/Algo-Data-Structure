void iterative_inorder_traversal(TreeNode* root)
{
	stack<TreeNode*> st;

	TreeNode* curr = root;

	while (curr != NULL || (!st.empty()))
	{
		if (curr != NULL)
		{
			st.push(curr);
			curr = curr->left;
		}
		else  
		{
			TreeNode* tmp = st.pop();
			cout << tmp->val << "\n";
			curr = tmp->right();
		}
	}
}

//TC O(N)
//SC O(N)

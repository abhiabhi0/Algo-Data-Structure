//Map node's valuw with its index using preorder vector
std::unordered_map<int, int> map_value_index(std::vector<int>& preorder)
{
	std::unordered_map<int, int>um;

	for (int i = 0; i < preorder.size(); ++i)
	{
		um.insert({ preorder[i], i});
	}
}

TreeNode* build_tree(std::unordered_map<int, int>& um, 
	std::vector<int>& inorder, int start_in, int end_in, 
	std::vector<int>& preorder, int start_pre, int end_pre)
{
	if (start_in > end_in || start_pre > end_pre)
	{
		return NULL;
	}

	TreeNode* root = new TreeNode(preorder[start_pre]);
	int idx = um[preorder[start_pre]];
	int x = idx = start_in;

	root->left = build_tree(um, inorder, start_in, idx-1,
		preorder, start_pre+1, start_pre+x);

	root->right = build_tree(um, inorder, idx+1, end_in,
		preorder, start_pre+x+1, end_pre);

	return root;
}

TreeNode* solve(std::vector<int>& inorder, std::vector<int>& preorder)
{
	std::unordered_map<int, int> preorde_val_idx = map_value_index(preorder);

	return build_tree(um, inorder, 0, inorder.size()-1,
		preorder, 0, preorder.size()-1);
}

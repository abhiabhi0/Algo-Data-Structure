
//TC O(N^2)
bool is_balanced(TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}

	int left_height = height(root->left);
	int right_height = height(root->right);

	if (abs(left_height - right_height) > 1)
	{
		return false;
	}

	return is_balanced(root->left) && is_balanced(root->right);
}

//Optimization using Post order approach

class NodeInfo
{
	bool balanced;
	int height;

  public:
	NodeInfo(bool bal, int h) : balanced(bal), 
								height(h)
								{}
};

NodeInfo is_balanced(TreeNode* root)
{
	if (root == NULL)
	{
		return NodeInfo(true, -1);
	}

	NodeInfo l_info = is_balanced(root->left);
	NodeInfo r_info = is_balanced(root->right);

	if (l_info.balanced && r_info.balanced 
		&& abs(l_info.height - r_info.height) <= 1)
	{
		return NodeInfo(true, max(l_info.height, r_info.height)+1);
	}
	return NodeInfo(false, max(l_info.height, r_info.height)+1)
}


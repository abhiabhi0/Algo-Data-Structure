/**
 * Given a Binary Tree. Find the size of max sized BST subtree 
 * in the tree
**/ 

class NodeInfo
{
  public :
	bool is_bst;
	int mx_size;
	int own_size;
	int mx;
	int mn;

	NodeInfo(bool is_bst, int mx_size, int own_size, int mx, 
		int mn) : is_bst(is_bst), mx_size(mx_size), 
		own_size(own_size), mx(mx), mn(mn) {}
};

NodeInfo max_size_bst(TreeNode* root)
{
	if (root == NULL)
	{
		return NodeInfo(true, 0, 0, INT_MIN, INT_MAX);
	}

	NodeInfo l = max_size_bst(root->left);
	NodeInfo r = max_size_bst(root->right);

	int own_size = l.own_size + r.own_size + 1;

	if (l.is_bst && r.is_bst && l.mx < root->val && r.mn > root->val)
	{
		return NodeInfo(true, max(l.mx_size, r.mx_size, own_size),
			own_size, max(root->val, l.mx, r.mx), 
			min(root->val, l.mn, r.mn));
	}
	else  
	{
		return NodeInfo(false, max(l.mx_size, r.mx_size), own_size,
			max(root->val, l.mx, r.mx), 
			min(root->val, l.mn, r.mn));
	}
}

//TC O(N)
//SC O(N)

/**
 * Diameter of tree = Length of the longest path b/w any two nodes
 * of the tree.
**/

class NodeInfo
{
	int height;
	int diameter;

  public:
  	NodeInfo(int ht, int dia) : height(ht),
  								diameter(dia)
  								{}
}

NodeInfo tree_diameter(TreeNode* root)
{
	if (root == NULL)
	{
		return new NodeInfo(-1, -1);
	}

	NodeInfo l = tree_diameter(root->left);
	NodeInfo r = tree_diameter(root->right);

	return new NodeInfo(max(l.height, r.height)+1,
		max(max(l.diameter, r.diameter), (l.height + r.height+2)));
}

int bst_height(BST* root)
{
    if (root == NULL)
        return 0;

    int left_height = bst_height(root->left);
    int right_height = bst_height(root->right);

    return 1+max(left_height, right_height);   
}

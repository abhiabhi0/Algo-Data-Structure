int isValidBST(TreeNode* A) {
    if (A == NULL)
    {
        return 1;
    }
    bool l = true, r = true;

    if (A->left != NULL && A->val > A->left->val)
    {
        l = isValidBST(A->left);
    }
    else  
    {
        l = false;
    }

    if (A->right != NULL && A->val < A->right->val)
    {
        r = isValidBST(A->right);
    }
    else  
    {
        r = false;
    }

    return l && r;
}

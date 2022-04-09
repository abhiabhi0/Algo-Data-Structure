/**
* Given a binary tree,
*
* Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
*
* Initially, all next pointers are set to NULL.
*
* Assume perfect binary tree and try to solve this in constant extra space.
**/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

TreeLinkNode* next_right_child(TreeLinkNode* A)
{
    if (A == NULL)
    {
        return NULL;
    }

    TreeLinkNode* tmp = A->next;

    while (tmp != NULL)
    {
        if (tmp->left != NULL)
        {
            return tmp->left;
        }

        if (tmp->right != NULL)
        {
            return tmp->right;
        }

        tmp = tmp->next;
    }
    return NULL;
}

void connect(TreeLinkNode* A) {
    TreeLinkNode* level = A;    

    while (level != NULL)
    {
        TreeLinkNode* curr = level;

        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                if (curr->right != NULL)
                {
                    curr->left->next =curr->right;  
                }
                else
                {
                    curr->left->next = next_right_child(curr);
                }
            }

            if (curr->right != NULL)
            {
                curr->right->next = next_right_child(curr);
            }
            curr = curr->next;
        }

        if (level->left != NULL)
        {
            level = level->left;
        }
        else if (level->right != NULL)
        {
            level = level->right;
        }
        else   
        {
            level = next_right_child(level);
        }
    }
}

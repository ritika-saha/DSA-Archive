/** DELETING  a given node in Binary search tree*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return NULL;
        
        if(root->val == key)
            return helper(root);
        
        TreeNode* cur = root;
        
        while(cur)
        {
            //for left sub tree
            if(cur->val > key)
            {
                if(cur->left != NULL && cur->left->val == key)
                {
                    cur->left = helper(cur->left);
                    break;
                }
                else
                    cur = cur->left;
            }
            
            //for right sub tree
            else
            {
                if(cur->right != NULL && cur->right->val == key)
                {
                    cur->right = helper(cur->right);
                    break;
                }
                else
                    cur = cur->right;
            }
        }
        return root;
    }
    
    //it removes the node to be deleted and rearrange the tree; 
    //it connects left child of deleted node to the parant of deleted node
    //and right child of the deleted node to the right most node of the left subtree
    TreeNode* helper(TreeNode* root)
    {
        if(root->left == NULL) return root->right;
        
        else if(root->right == NULL) return root->left;
        
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findlastRight(root->left);
        lastRight->right =rightChild;
        return root->left;
    }
    
    //it finds the right most child and helps in re-arrangement of the tree
    TreeNode* findlastRight(TreeNode* root)
    {
        if(root->right == NULL)
            return root;
        
        return findlastRight(root->right);
    }
};

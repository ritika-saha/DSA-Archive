/*
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. 
Trimming the tree should not change the relative structure of the elements that will remain in the tree.

EXAMPLE --
Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]

Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]

**/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
      if(!root) return nullptr;
        
        if(root->val < low) {
            return trimBST(root->right, low, high);
        } else if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};

/*---------------------------------------------------------------------NOTES-------------------------------------------------------------------------------
1) if the root value is smaller than the lower bound then return the right of the tree because the right nodes will have greater values
2) if the root value is greater than the upper bound then return the left of the tree because the left nodes will have smaller values
3) Continue this with DFS recussive call on the tree
4) at last return the root

**/

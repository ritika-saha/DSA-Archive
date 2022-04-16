/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is 
changed to the original key plus the sum of all keys greater than the original key in BST.

EXAMPLE --
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Example 2:

Input: root = [0,null,1]
Output: [1,null,1]

**/


class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return root;
        convertBST(root->right);
        sum+=root->val;
        root->val=sum;
        convertBST(root->left);
        return root;
    }
};


/*--------------------------------------------------------------------NOTES--------------------------------------------------------------------------------
1) Here we are doing a reverse inorder traversal
2) we are updating the sum with every element to its right and then updating the current node value
**/

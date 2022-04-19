/**
LEETCODE 99

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.
Recover the tree without changing its structure.

EXAMPLE----
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 
*/

class Solution {
public:
    TreeNode* firstViolation=NULL,*secondViolation=NULL,*prev=NULL;
    
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        
        inorder(root->left);
        if(prev!=NULL && root->val<prev->val){
            if(firstViolation==NULL)
                firstViolation=prev;
            secondViolation=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(firstViolation->val,secondViolation->val);
      
    }
};


/**
-----------------------------------------------------------------------NOTES-------------------------------------------------------------------------------
1)inorder traversal traverses the tree in sorted order and thus we can find the violations
2) when we find that the value of root is smaller than previous node value then the first violation is previous node and initially the second violation is root
3) as we traverse the tree if we find another root satisfying the above condition we update the secons violation
4) at the end of traversal we'll have the two violation nodes
5) swap 'em
*/

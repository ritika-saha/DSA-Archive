/**
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

 

Example 1:


Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
*/

class Solution {
public:
    int ans=0;
    int ziggy(TreeNode* root,bool left,int curlen){
        if(root==NULL)
        return ans;
        ans=max(ans,curlen);
        if(left){
            ziggy(root->right,false,curlen+1);
          //we choose left so we increment curlength for it but since we gotta eliminate the right we pass 1 so it gets eleminated whe max is considered
            ziggy(root->left,true,1);
        }
        else{
            ziggy(root->left,true,curlen+1);
            ziggy(root->right,false,1);
        }
        return ans;
    }
    int longestZigZag(TreeNode* root) {
        int lefty=ziggy(root,true,0);
        int righty=ziggy(root,false,0);
        return max(lefty,righty);
    }
};

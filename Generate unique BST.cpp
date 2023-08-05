/**
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. 
Return the answer in any order.

 

Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> solve(int start,int end){
        vector<TreeNode*> trees;
        if(start>end){
            trees.push_back(NULL);
            return trees;
        }

      //loop to traverse each from 1 to n
        for(int i=start;i<=end;i++){
          //passing start to i-1 so that lower values go to left subtree and i+1 to end so higher values go to right subtree , hence maintaining the bst rule
            vector<TreeNode*>leftsubtree=solve(start,i-1);
            vector<TreeNode*>rightsubtree=solve(i+1,end);
            for(int j=0;j<leftsubtree.size();j++){
                TreeNode* leftnode=leftsubtree[j];
                for(int k=0;k<rightsubtree.size();k++){
                    TreeNode* rightnode=rightsubtree[k];
                    TreeNode* rootnode=new TreeNode(i);
                    rootnode->left=leftnode;
                    rootnode->right=rightnode;
                    trees.push_back(rootnode);
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};

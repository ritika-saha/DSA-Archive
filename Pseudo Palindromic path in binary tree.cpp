/**
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic 
if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

Example 1:



Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: 
the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths 
since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).


*/


class Solution {
public:int ans = 0;
    //storing the number of palindrome
     unordered_map<int, int> um;
    // for storing the occurence of each integer
    void helper(TreeNode* root){
        if(root==NULL) return ;
        //when we will call the left or right child of leaf node or our node will be empty
        um[root->val]++;
        // we will increase the occurece of digit by one 
        
             if(root->left==NULL && root->right==NULL)
             {// this if condition is for the child nodes, where we will check whether it is palindromic or not
                 
            // here we are checking whether number of occurence of each integer is odd or even and counting the odd one, if we have odd occurence more than one it means it won't be palindromic so we are not increasing the ans value;
                    int temp=0;
              for(int i=0; i<=9; i++)
                {
                   if(um[i]%2!=0) 
                   temp++;
                }
              if(temp<=1) ans++;
            
              }
         helper(root->left);
        // calling left child of node
    helper(root->right);
        // caling right child of node
    um[root->val]--;
        // removing the occurence of node, when we are going one step back
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
       
        helper(root);
        return ans;
    }
};

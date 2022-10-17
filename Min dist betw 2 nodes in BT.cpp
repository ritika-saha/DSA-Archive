/**
Given a binary tree and two node values your task is to find the minimum distance between them.
The given two nodes are guaranteed to be in the binary tree.
Please Note that a and b are not always leaf node.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 
*/

class Solution{
    public:
    
     Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL || root->data==n1 || root->data==n2)
       return root;
       
       Node* left=lca(root->left,n1,n2);
       Node* right=lca(root->right,n1,n2);
       
       if(left==NULL)
       return right;
       if(right==NULL)
       return left;
       return root;
    }
   int solve(Node* root,int val){
           if(root==NULL)

        return 0;

        

        if(root->data==val)

        return 1;

        int a=solve(root->left,val);

        int b=solve(root->right,val);

        if(!a and !b)

        return 0;

        else

        return  (a+b+1);
        
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* LCA=lca(root,a,b);
       int disa=solve(LCA,a);
       int disb=solve(LCA,b);
       return disa+disb-2;
    }
};

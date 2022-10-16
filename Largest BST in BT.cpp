/**
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8
*/

//DATA STRUCTURE TO STORE THE MAX NODE FROM LEFT AND THE MIN NODE FROM RIGHT FOR EACH NODE ALONG WITH SIZE AT THAT PARTICUALR NODE 
class Nodeval{
    public:
    int mini;
    int maxi;
    int size;
  //CONSTRUCTOR TO INITIALIZE THE VARIABLE 
    Nodeval(int m,int ma,int s){
        this->mini=m;
        this->maxi=ma;
        this->size=s;
    }
};

//---------------------------------SOLUTION CLASS------------------------------------
class Solution{
    public:
    
    // Return the size of the largest sub-tree which is also a BST
  
  //FUNCTION OF THE DATA STRUCTURE WE CREATED TYPE
    Nodeval solver(Node* root){
      //WHEN ROOT NULL MEANS WE ARE AT THE END OF THE TREE SO WE INITILAISE THEM WITH THE STARTING VALUE
        if(root==NULL)
        return Nodeval(INT_MAX,INT_MIN,0);
        
      //-------------------------------------POST ORDER TRAVERSAL BECAUSE WE NEED BOTH THE LEFT AND RIGHT TO BE COMPUTED BEFORE WE CAN DO ANY WORK ON CURRENT NODE
        auto left=solver(root->left);
        auto right=solver(root->right);
      
      //CONDITION IF IT IS A BST--- IF THE CURRENT NODE IS GREATER THAN THE LARGEST NODE AT LEFT MEANS ALL NODES AR LEFT ARE SMALLER AND IF THE CURRENT NODE IS
      // SMALLLER THAN THE SMALLEST NODE AT RIGHT MEANS THAT THE CURRENT NODE IS SMALLER THAN ALL THE NODES AT RIGHT WHICH IS THE CONDITON FOR BST
         if(left.maxi < root->data && right.mini > root->data){
           
           //INITIALISING MINIMMUN OF LEFT AND CURRENT FOR MINI OF CURRENT AND MAXIMUM OF RIGHT AND CURRENT FOR CURRENT'S MAXI AND SIZE ADDITON OF BOTH +1
           return  Nodeval(min(left.mini,root->data),max(right.maxi,root->data),left.size+right.size+1);
           
         }
      
      //IF CONDITIONH IS NOT MET THEN WE INITIALIZE BOTH AS SMALLEST AND LARGEST VALUES SO THAT THIS PARTICULAR PATH CAN NEVER SATISFY THE CONDITION AND IS EXCLUDED
         return Nodeval(INT_MIN,INT_MAX,max(left.size,right.size));
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	return solver(root).size;
    }
};

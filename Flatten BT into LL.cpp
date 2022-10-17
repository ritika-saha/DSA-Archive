/**
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same Node class where the right child pointer points to the next   node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
*/

//----------------------------------------------------------------RECURSIVE SOLUTION---------------------------------------------------------------------
class Solution
{
    public:
  //KEEPING TRACK OF THE NODES WHICH WE HAVE TO ATTACH TO THE RIGHT
    Node* prev=NULL;
  //REVERSE POSTORDER BECAUSE WE DO THE ATTACHING OF NODES FROM THE BOTTOM USING THE PREV VARIABLE
    void solve(Node* root){
        if(root==NULL) return;
        solve(root->right);
        solve(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
    void flatten(Node *root)
    {
        //code here
        Node * ans=root;
        solve(root);
        
    }
};


//----------------------------------------O(1) SPACE COMPLEXITY SOLUTION -----------------------------------------------------------------------------------------
class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node* curr=root;
        while(curr!=NULL){
          //IF LEFT IS NOR NULL THEN ONLY WE REQUIRE TO PERFORM THE OPERATION 
            if(curr->left!=NULL){
              //STORING THE LEFT NODE 
            Node* prev=curr->left;
              //GETIING THE RIGHTMOST NODE OF THAT NODE
            while(prev->right)
            prev=prev->right;
              //CONNECTING THE LEFT'S RIGHT TO CURRENT'S RIGHT
            prev->right=curr->right;
              //MOVING THE LEFT SUBTREE TO RIGHT
            curr->right=curr->left;
              //MAKING THE LEFT SUBTREE NULL
            curr->left=NULL;
            }
          //TRAVERSING THE TREE THROUGH THE RIGHT
            curr=curr->right;
        }
    }
};

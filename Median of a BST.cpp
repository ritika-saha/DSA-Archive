//USING MORRIS TRAVERSAL

/**
Given a Binary Search Tree of size N, find the Median of its Node values.

Example 1:

Input:
       6
     /   \
   3      8   
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.

Example 2:

Input:
       6
     /   \
   3      8   
 /   \    /   
1    4   7   
Output: 5
Explanation:Inorder of Given BST will be:
1, 3, 4, 6, 7, 8. So, here median will
(4 + 6)/2 = 10/2 = 5.
 
*/


float findMedian(struct Node *root)
{
      //Code here
  
  //-----------------------------------MORRIS TRAVERSAL USING O(1) STACK SPACE AND NEARLY O(N) TIMECOMPLEXITY----------------------------------------------
      struct Node* curr=root;
      vector<int>inorder;
      while(curr!=NULL){
        //1ST CONDITION -> IF LEFT IS NULL THEN THE CURRNT NODE IS PART OF INORDER 
          if(curr->left==NULL){
              inorder.push_back(curr->data);
            //MOVE CURR TO RIGHT
              curr=curr->right;
          }
        //SECOND CONDITION-> IF LEFT IS NOT NULL
          else{
            //GETTING HOLD OF THE LEFT NODE
              struct Node *temp=curr->left;
            
            //TRAVERING THROUGH THE LEFT NODE TO REACH ITS RIGHT MOST GUY AND MAKING SURE TRAVERSAL DOESN'T REACH BACK TO THE CURR DUE TO PREVIOUSLY MADE THREAD
              while(temp->right && temp->right!=curr)
              temp=temp->right;
              
            //THIRD CONDITON -> IF THE RIGHT IS NULL THEN WE CREATE A THREAD AND CONNECT IT TO THE CURR
              if(temp->right==NULL)
              {
                //THREAD CREATION
                  temp->right=curr;
                //MOVING TO LEFT
                  curr=curr->left;
              }
            
            //FOURTH CONDITION -> IF RIGHT IS NOT NULL THAT IS THE THREAD IS ALREADY PRESENT 
              else{
                //BREAKING THE THREAD BY MAKING THE RIGHT AS NULL
                  temp->right=NULL;
                //PUSHING BACK CURR NOW BECAUSE IT IS PART OF THE INORDER
                  inorder.push_back(curr->data);
                //MOVING CURR TO RIGHT NOW SINCE LEFT HAS BEEN DONE
                  curr=curr->right;
              }
          }
      }
  
  //------------------------------------------------------END OF MORRIS TRAVERSAL----------------------------------------------------------------------
      int len=inorder.size();
      if(len%2!=0)
      return inorder[len/2];
      else{
          float a=(inorder[len/2]+inorder[len/2-1])/2.0;
          return a;
      }
}

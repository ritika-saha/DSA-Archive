/**
LEETCODE HARD 

You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can 
monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 
Example :


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.




*/

class Solution {
public:
    //Return value - Description
    //0 - node don't have camera(0) and is not being watched(0) total 0.
    //1 - node don't have camera(0) and is being watched(1) total 1.
    //2 - node has camera(1) and is being watched(1) total 2.
    int status(TreeNode* root,int &n){
        
        //Base case in NULL node returns (1) as it don't has camera and  if it returns 0 then the actuall end node of the tree will install camera which is not needed as it will be watched by its parent's camera.
        if(root == NULL){
            return 1;
        }
        
        int l = status (root->left,n);
        int r = status (root->right,n);
        
        //If any of the l or r is not watched install the camera and return the condition of the current node as have camera (2)
        if(l==0 || r==0){
            n++;
            return 2;
        }
        
        //If any of the l or r has camera then current node is being watched so don't install camera and return (1)
        if(l==2 || r==2){
            return 1;
        }
        
        //This gets executed if both l and r returns 1 i.e. is being watched but don't have cameras. So don't install camera and return (0)
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int n=0;
        
        //If root->right and root->left both don't have canera and are being watched then camera was not installed in recursion i.e. (0). As there is no parent node of it so install a camera here.
        if(status(root,n) == 0){
            n++;
        }
        return n;
    }
};

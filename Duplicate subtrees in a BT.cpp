
/**
Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.

Example:

Input : 

Output : 2 4
         4
*/


string solve(Node * root,vector<Node*>&ans,unordered_map<string,int>&mp){
  //IF NULL WE RETURN N
    if(root==NULL) return "N";
  
  //STRING VARIABLE TO STORE CURRENT NODE CONVERTED TO STIRNG AND RECURSIVE CALLED LEFT AND RIGHT-------------------------PREORDER TRAVERSAL
  //HERE WE ADD AN EXTRA "_" IN BETWEEN TO MAKE THE PATH UNIQUE 
    string s=to_string(root->data)+"_"+solve(root->left,ans,mp)+"_"+solve(root->right,ans,mp);
  //CHECKING IF ITS DUPLICATE 
    if(mp[s]++==1) ans.push_back(root);
    return s;
}
vector<Node*> printAllDups(Node* root)
{
    // Code here
  //MAP TO STORE THE UNIQUE PREORDERS AND THEIR NUMBER OF OCCURANCES
    unordered_map<string,int>mp;
    vector<Node*>ans;
    solve(root,ans,mp);
    return ans;
}




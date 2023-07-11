/**
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>and;
      //map to store node value and its parent pointer
        unordered_map<int,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
      //loop to build the map with child parent relationship
        while(q.empty()==false){
            auto top=q.front();
            q.pop();
            if(top->left){
                parent[top->left->val]=top;
                q.push(top->left);
            }
            if(top->right){
                parent[top->right->val]=top;
                q.push(top->right);
            }
        }

      //map to mark if a node is visited
        unordered_map<int,int>visited;
        q.push(target);

      //this loop will run k times and will make a BFS traversal to reach all the nodes at a k distance
        while(k-- && q.empty()==false){
            int size = q.size();
//here we traverse level wise thus the inner loop is required to be run with all nodes at the particular level
            for(int i = 0; i < size; i++){
                auto top = q.front();
                q.pop();

                visited[top -> val] = 1;
//for left
                if(top -> left && !visited[top->left->val]){
                    q.push(top -> left);
                }
//for right
                if(top -> right && !visited[top->right->val]){
                    q.push(top -> right);
                }
//going backwards in the tree that is by the parent route
                if(parent[top->val] && !visited[parent[top->val] -> val]){
                    q.push(parent[top->val]);
                }

            }
        }

      //after running of the upper loop k times the nodes that will remain in the queue are the nodes at a k distance from the target node
        while(q.empty()==false){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};


//TIME COMPLEXITY - O(N)
//SPACE COMPLEXITY - O(N)

/**
In terms of auxiliary space, the code uses several data structures:

The parent unordered map is used to store the parent mapping of each node. It can potentially store N-1 entries (excluding the root node). Therefore, the space required for this unordered map is O(N).

The visited unordered map is used to keep track of visited nodes during the BFS traversal. It can store at most N entries since each node can be visited once. Hence, the space required for this unordered map is also O(N).

The q queue is used for the BFS traversal. At any given time, the queue can hold a maximum of N nodes in the worst case (when all nodes are at the same level). Therefore, the space required for the queue is O(N).

The ans vector is used to store the final result, which can have a maximum of N elements in the worst case (when all nodes are at a distance of k from the target). Hence, the space required for the vector is also O(N).

Adding up the space complexities of these data structures, we get a total space complexity of O(N).
*/

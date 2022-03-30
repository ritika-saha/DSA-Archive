/**LEETCODE 74

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

examples---
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int n=matrix[i].size();
            if(matrix[i][0]<= target && target<=matrix[i][n-1]){
                int l=0,r=n-1;
                for(int j=0;j<n;j++){
                    int mid=l+(r-l)/2;
                    if(matrix[i][mid]==target)
                        return true;
                    if(target<matrix[i][mid])
                        r=mid-1;
                    else if(target>matrix[i][mid])
                        l=mid+1;
                }
                return false;
            }
        }
        return false;
    }
};


/**
-------------------------------------------------------------------NOTES-------------------------------------------------------------------------------------
1)run a loop for the entire matrix size
2) check if the current row 1st element is smaller or equal to the target && the last of the same greater than or equal to target
3) if yes then element is present in the current row
4) if above conditions are satisfied then performing binary search will give us the answer
5) if not then return false
*/

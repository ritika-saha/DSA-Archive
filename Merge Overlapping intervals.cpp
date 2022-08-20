/**
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        vector<vector<int>>ans;
     //sorting the array to get the smallest first
        sort(inter.begin(),inter.end());
     //taking the initial elements as the first elements
        int start=inter[0][0];
        int end=inter[0][1];
        for(int i=1;i<inter.size();i++){
         //finding the greatest end time for all the overlapping intervals
            if(inter[i][0]<=end){
                end=max(end,inter[i][1]);
            }
         //inserting the merged interval and reinitialising the start and end to get another interval
            else{
                ans.push_back({start,end});
                start=inter[i][0];
                end=inter[i][1];
            }
        }
     //pushing the last element in because the loop would have been terminated before inserting it
        ans.push_back({start,end});
        return ans;
    }
};

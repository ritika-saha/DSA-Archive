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
      //sorting according to the start time
        sort(inter.begin(),inter.end());
        int n=inter.size();
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
          //storing start and end time for that particular index
            int start=inter[i][0];
            int end=inter[i][1];
          //checking if the interval already exists between present interval if yes then ignore it and continue without inseting
            if(ans.size()>0){
                if(start<=ans[ans.size()-1][1])
                    continue;
            }
          //if not then find the end time that covers all the oevrlapping intervals
            for(int j=i+1;j<n;j++){
              //for all the start times that are smaller than the current end time we take the max among all
                if(inter[j][0]<=end)
                    end=max(end,inter[j][1]);
            }
        //push in the merged interval
        ans.push_back({start,end});
        }
        
        return ans;
        
    }
};

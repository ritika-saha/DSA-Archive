/**
You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.

 

Example 1:

Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation: 
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.
Example 2:

Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
Output: 30
Explanation: 
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
 


*/

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>vec;
        for(int i=0; i<n; i++)
            vec.push_back({nums2[i],nums1[i]});//store nums2[i] and nums1[i] as pair to sort according to nums2[i]
        
        sort(vec.begin(),vec.end());//will give sorted array in ascending order basred on the nums2[i]
        
        long long res=0,currSum=0;
        priority_queue<int, vector<int>, greater<int>>pq;//we need priority queue (min heap) so that we can remove the minimum element from the selected element as we are bound to take only k elements 
        
        for(int i=n-1; i>n-1-k; i--)
        {
            pq.push(vec[i].second);//push nums1[i] in the min heap
            currSum+=vec[i].second;//store the sum of all those numbers
        }
        
        res=max(res,currSum*vec[n-k].first);//and the score will be sum*(minimum of selected index of nums2[i])
        
        for(int i=n-1-k; i>=0; i--)//now we will run the loop over all the starting form the last selected index to get the naximum score(if any)
        {
            int mini=pq.top();
            pq.pop();
            currSum-=mini;//we will remove the smallest number of all the taken numbers till now and will add the current number
            
            currSum+=vec[i].second;
            pq.push(vec[i].second);
            
            res=max(res,currSum*vec[i].first);
        }
        
        return res;
    }
};

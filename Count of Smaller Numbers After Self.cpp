/**
LEETCODE HARD -------------------------------------> using merge sort count inversion problem technique for optimal solution

You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]





*/


class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r,vector<pair<int,int>>& v,vector<int>& count)
    {
         // Your code here
        vector<pair<int,int>> temp(r-l+1);
        int i = l;
        int j= mid + 1;
        int k = 0;
        
        while(i<=mid && j<=r){                                                    // Step 4
            if(v[i].first<=v[j].first) temp[k++] = v[j++];
            else{
                count[v[i].second] += r-j+1;
                temp[k++] = v[i++];
            }
        }
        
        while(i<=mid){
            temp[k++] = v[i++];
        }
        while(j<=r){
            temp[k++] = v[j++];
        }
        
        for(int i=l;i<=r;i++){
            v[i] = temp[i-l];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r,vector<pair<int,int>>& v,vector<int>& count)
    {
        //code here
        if(l>=r) return ;
        int mid = (l+r)/2;
        mergeSort(arr,l,mid,v,count);
        mergeSort(arr,mid+1,r,v,count);
        merge(arr,l,mid,r,v,count);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);                                        // step 1
        for(int i=0;i<n;i++) v[i] = {nums[i],i};
        vector<int> count(n,0);                                             // step 2
        mergeSort(nums,0,n-1,v,count);                                // step 3
       // for(int i=0;i<n;i++) cout<<v[i].first<<" ";
        return count;
    }
};



/**
-----------------------------------------------------------------------------NOTE-----------------------------------------------------------------------------
Approach:-
Step 1 : Make vector of pair (v) and add elements with its indexes
Step 2 : Make another vector (count) for storing our ans
Step3 : Just do simple merge sort with some little modification in void merge()
Step 4 : In void merge() while merging two arrays check if right is greater than left then its ok but if left is greater than right add total
element left in right in count array where the index can be find by vector of pairs;



*

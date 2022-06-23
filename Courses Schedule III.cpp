/**
LEETCODE HARD

There are n different online courses numbered from 1 to n. 
You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for 
durationi days and must be finished before or on lastDayi.

You will start on the 1st day and you cannot take two or more courses simultaneously.

Return the maximum number of courses that you can take.

 

Example 1:

Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
Explanation: 
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
Example 2:

Input: courses = [[1,2]]
Output: 1



*/

class Solution {
public:
  
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        priority_queue<int>pq;
         sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int currTime=0;
        for(int i=0;i<courses.size();i++){
            currTime+=courses[i][0];
            pq.push(courses[i][0]);
            if(currTime>courses[i][1]){
                currTime-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};


/**
-------------------------------------------------------------------NOTE--------------------------------------
writing the compare function for sorting the array according to the second elemnt will give a TLE but writing it in the same function won't.


*/

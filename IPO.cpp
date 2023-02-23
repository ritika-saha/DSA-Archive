//-----------------------------------------------------------------GREEDY , SORTTING , HEAP----------------------------------------------------------------------------
/**
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase 
its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to 
maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      //STORING CAPITAL AND PROFITS AS VECTOR PAIR AND SORTING THE VECTOR ASCENDING ORDER OF THE MINIMUM CAPITAL REQUIRED
        vector<pair<int,int>>v;
        int n=capital.size();
        for(int i=0;i<n;i++)
        v.push_back({capital[i],profits[i]});

        sort(v.begin(),v.end());

      //PRIORITY QUEUE TO STORE THE MAX PROFIT WE CAN GET OUT OF ALL THE CAPITALS THAT ARE WITHIN THE AMMOUNT THAT IS W WE HAVE
        priority_queue<int>pq;
        int i=0;
        
        while(k--){
          //GETTING THE MAX PEOFIT WE CAN GET IN OUR LIMIT
            while(i<n && w>=v[i].first ){
                pq.push(v[i].second);
                i++;
            }
          //IF THE PQ IS EMOTY MEANS THERE IS NO CAPITAL WITHIN OUR LIMIT
            if(pq.empty())
            break;
            w+=pq.top();
            pq.pop();

        }
        return w;
    }
};

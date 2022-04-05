/**LEETCODE-11

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

EXAMPLE--
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.

*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=INT_MIN,w,h;
        int i=0,j=height.size()-1;
        
        while(i!=j){
            w=abs(i-j);
            h=min(height[i],height[j]);
            if(water<(w*h))
                water=w*h;
            if(height[i]<=height[j])
                i++;
            else
                j--;
        }
        return water;
    }
};





/**  ----------------------------------------------------------------------NOTES-----------------------------------------------------------------------------
1)take two pointers one at the beginning  and one at the end of the array
2) in the while loop calculate width which is the space between two bars and consider the height minimun between the two pointers
3) if the previous volume of water is less than the current then replace the water with the current volume
4) if height pointed by i is smaller than the one pointed at the end then increment i else increment j
5) at the end of the loop we are left with highest volume we can get

*/

/**
A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.

 

Example 1:

Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
Example 2:

Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
*/

class Solution
{
public:
    int minFlipsMonoIncr(string S)
    {
        int count_flip = 0, count_one = 0;
        for (auto i : S)
        { 
 //keep track of all one (we will use count_one in else condition if we need)  
//if we want flip one into 0
            if (i == '1')
                count_one++;
            else{
                count_flip++;
            count_flip = min(count_flip, count_one);
            }
        }
        return count_flip;
    }
};

/**
Char=='1'
It will not impact our minimum flips just keep the record of count of 1
Char=='0'
Here will be 2 cases
Keep is as 0 and flip all the 1 so far ,for that we need to know about the count the one so far
Flip it to 1 and update our count_flip
Take the minmum of count_flip and count_one and update the count_flip because we want minimum
*/

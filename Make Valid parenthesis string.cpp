/**LeetCode 1249 MINIMUN REMOVE TO MAKE VALID PARENTHESIS
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.

example----
Input: s = "a)b(c)d"
Output: "ab(c)d"

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
         stack<int> st;
        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (st.empty())
                    s[i] = '!';
                else
                    st.pop();
            }
        }

        while (!st.empty())
        {
            s[st.top()] = '!';
            st.pop();
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '!')
                ans+=(s[i]);
        }

        return ans;
        
    }
};


/**------------------------------------------------------------------NOTES--------------------------------------------------------------------------------------------
here stack data structure has been used 
traverse the string from start to end and on encountering ( push the index to the stack
on encountering ) if the stack is empty that means the ) is an unbalanced one and thus replace the string's index with !
else if the stack is not empty that means the ) is the closing for previously encountered ( this pop the previous (
after the loop endes is the stack isnt empty then replace the indexes of the string in the stack with !
now form a string excluding the ! and voila thats the answer
*/

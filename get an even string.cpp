/**
CODEFORCES Round 780 div 3

A string a=a1a2…an is called even if it consists of a concatenation (joining) of strings of length 2 consisting of the same characters. In other words, a string a is even if two conditions are satisfied at the same time:

its length n is even;
for all odd i (1≤i≤n−1), ai=ai+1 is satisfied.
For example, the following strings are even: "" (empty string), "tt", "aabb", "oooo", and "ttrrrroouuuuuuuukk". The following strings are not even: "aaa", "abab" and "abba".

Given a string s consisting of lowercase Latin letters. Find the minimum number of characters to remove from the string s to make it even. The deleted characters do not have to be consecutive.

EXAMPLE-------

6
aabbdabdccc
zyx
aaababbb
aabbcc
oaoaaaoo
bmefbmuyw

output
3
3
2
0
2
7


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
ios::sync_with_stdio(0);cin.tie(0);

	int n;
	cin>>n;
	while(n--)
	{
		int cnt=0,i;
		string s;
		cin>>s;
		map<char,int>m;
		for(i=0;i<s.length();i++)
		{
			m[s[i]]++;
			if(m[s[i]]==2){
				cnt-=2;
				m.clear();
			}
			cnt++;
		}
		cout<<cnt<<endl;
	}

return 0;
}



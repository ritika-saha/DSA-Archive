/*
LEETCODE- 535
TinyURL is a URL shortening service where you enter a 
URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. 
Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. 
You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

**/

class Solution {
public:
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    long long MOD = 56800235583; //6 ^62 
    unordered_map<string, string> urlMap;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        long long randomNum = rand() % MOD;
        string tinyThing = convertToB62(randomNum);
        while(urlMap.find(tinyThing) != urlMap.end()) {
            randomNum = rand() % MOD;
            tinyThing = convertToB62(randomNum);
        }
        urlMap[tinyThing] = longUrl;
        return tinyThing;
    }

    string convertToB62(long long num) {
        string ans = "";
        while(num) {
            int mod = num % 62;
            ans += characters[mod];
            num /= 62;
        }
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urlMap[shortUrl];
    }
};

/*---------------------------------------------------------------------------NOTES----------------------------------------------------------------------

1) here we have a string with values from a to z , A to Z, 0 to 9 which we use to append the random characters for our hashmap.
2) we generate a random number and mod it to 6^62 (because that can be the largest that can be there)
3) then we convert the modded number to base 62 string
4) we take each digit from the number and find characters from the string and append to the tiny string
5) then we hash the tiny string that we got to the large url.
6) if in step 2 the number generated is already generated before we keep generating numbers until we get a unique number.





**/

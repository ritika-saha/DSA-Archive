//------------------------------------LEETCODE 721--------------------UNION FIND----------------------------------DISJOINT SET-----------------------------------------

/**
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
*/

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n = acc.size();

        // Create a mapping from email to account index
        unordered_map<string, int> emailToAccount;

        // Initialize DisjointSet with account indices
        DisjointSet ds(n);

        // Populate the mapping and perform unions
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < acc[i].size(); j++) {
                string email = acc[i][j];
                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i; // Associate email with account i
                } else {
                    // Perform the union of accounts using unionBySize
                    ds.unionBySize(i, emailToAccount[email]);
                }
            }
        }

        // Collect merged accounts
        unordered_map<int, vector<string>> mergedAccounts;
        for (const auto& entry : emailToAccount) {
            int accountIndex = entry.second;
            int parentAccount = ds.findUPar(accountIndex);
            mergedAccounts[parentAccount].push_back(entry.first);
        }

        // Create the result in the required format
        vector<vector<string>> result;
        for (const auto& entry : mergedAccounts) {
            int accountIndex = entry.first;
            const vector<string>& emails = entry.second;

            vector<string> mergedAccount;
            mergedAccount.push_back(acc[accountIndex][0]); // Account name

            // Sort the emails
            vector<string> sortedEmails(emails.begin(), emails.end());
            sort(sortedEmails.begin(), sortedEmails.end());

            // Add sorted emails to the merged account
            mergedAccount.insert(mergedAccount.end(), sortedEmails.begin(), sortedEmails.end());

            // Add the merged account to the result
            result.push_back(mergedAccount);
        }

        return result;
    }
};


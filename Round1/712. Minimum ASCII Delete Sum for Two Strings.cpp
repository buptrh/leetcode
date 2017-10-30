/*class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        map<pair<int, int>, int> table;
        return helper(s1, 0, s2, 0, table);
    }

    int helper(string &s1, int start1, string &s2, int start2, map<pair<int, int>, int> & table) {
        if(table.find(pair<int, int>(start1, start2)) != table.end()) {
            // cout<<"find"<<endl;
            return  table[pair<int, int>(start1, start2)];
        }
        int sum1 = 0, sum2 = 0, sum = 0, total2 = 0, total1 = 0;
        for(int j = start2; j < s2.size(); j++) {
            total2 += s2[j];
        }
        int ret = INT_MAX;
        int j = start2;
        bool dup[26] = {false};
        for(int i = start1; i < s1.size(); i++) {
            if(dup[s1[i]-'a']) {
                sum1 += s1[i];
                continue;
            }
            dup[s1[i]-'a'] = true;
            sum2 = 0;
            int sumChild = -1;
            for(j = start2; j < s2.size(); j++) {
                if(s1[i] == s2[j]) {
                    sumChild = helper(s1, i+1, s2, j+1, table);
                    ret = min(ret, sum1 + sum2 + sumChild);
                    break;
                }
                sum2 += s2[j];
            }
            sum1 += s1[i];
        }
        ret = min(ret, sum1 + total2);
        table[pair<int, int>(start1, start2)] = ret;
        // cout<<s1.substr(start1) << "  " << s2.substr(start2) << "  " << ret<<endl;
        return ret;
    }
};*/


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

        for(int j = 0; j < s2.size(); j++) {
            dp[0][j+1] = dp[0][j] + s2[j];
        }
        for(int i = 0; i < s1.size(); i++) {
            dp[i+1][0] = dp[i][0] + s1[i];
            for(int j = 0; j < s2.size(); j++) {
                int val = 0;
                dp[i+1][j+1] = dp[i][j];
                if(s1[i] != s2[j]) {
                    dp[i+1][j+1] += s1[i] + s2[j];
                }
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1] + s1[i]);
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j] + s2[j]);
                // cout<<i<<" "<< j <<". " << dp[i+1][j+1]<<endl;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};



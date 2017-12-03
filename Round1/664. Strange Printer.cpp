//  There is a strange printer with the following two special requirements:

//     The printer can only print a sequence of the same character each time.
//     At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.

// Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.

// Example 1:

// Input: "aaabbb"
// Output: 2
// Explanation: Print "aaa" first and then print "bbb".

// Example 2:

// Input: "aba"
// Output: 2
// Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

// Hint: Length of the given string will not exceed 100.

class Solution {
public:
    int strangePrinter(string s) {
    	if(s.size() <= 1) {
    		return s.size();
    	}
    	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    	for(int i = s.size()-1; i >= 0; i--) {
    		for(int j = i; j < s.size(); j++) {
    			dp[i][j] = (i==j) ? 1 : 1 + dp[i+1][j];
    			for(int k = i+1; k <= j; k++) {
    				if(s[i] == s[k]) {
    					dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j] );
    				}
    			}
    		}
    	}
    	return dp[0][s.size()-1];


    }
};







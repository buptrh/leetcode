class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),
            [](vector<int> a, vector<int> b){return a[0]<b[0];});
        map<int, int> dp;
        for(int i = 0; i < pairs.size(); i++) {
        	dp[i] = 1;
        }
        int max_len = 0;
        for(int i = 1; i < pairs.size(); i++) {
        	for(int j = 0; j < pairs.size(); j++) {
	            if (pairs[i][0] > pairs[j][1]) 
            	{
            		dp[i] = dp[i] < dp[j]+1?  dp[j]+1:dp[i];  
            	} else if(pairs[i][1] < pairs[j][0] ){
            		break;
            	}
	            max_len = max( dp[i], max_len);  
        	}
        }


        return max_len;
    }
};
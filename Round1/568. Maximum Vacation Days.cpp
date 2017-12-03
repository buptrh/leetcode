//9:21
// class Solution {
// public:
//     int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
//     	if(flights.size() == 0 || flights[0].size() == 0) {
//     		return 0;
//     	}
//         map<int, set<int>> flightMap;
//         map<pair<int, int>, int> dp;
//         for(int i = 0; i < flights.size(); i++) {
//         	for(int j = 0; j < flights[0].size(); j++) {
//         		if(flights[i][j] == 1) {
//         			flightMap[i].insert(j);
//         		}
//         	}
// 			flightMap[i].insert(i);
//         }

//         int maxDays = dfs(flightMap, days, dp, 0, -1, days[0].size());
//         return maxDays;
//     }

//     int dfs(map<int, set<int>> & flightMap, vector<vector<int>>& days, map<pair<int, int>, int> & dp, int startPos, int day, int totalDay) {
//     	int maxDays = 0;
//     	if(day == totalDay) {
//     		return maxDays;
//     	}
//     	if(dp.find(make_pair(day, startPos)) != dp.end()) {
//     		return dp[make_pair(day, startPos)];
//     	}
//     	for(int target : flightMap[startPos]) {
//     		maxDays = max(maxDays, dfs(flightMap, days, dp, target, day+1, totalDay));
//     	}
//     	if(day >= 0) {
//     		maxDays += days[startPos][day];
//     	}
//     	dp[make_pair(day, startPos)] = maxDays;
//     	// cout<< day << "  " << startPos << "  " << maxDays << "  " << days[startPos][day]<<endl;
//     	return maxDays;
//     }
// };

//9:53


class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        if(flights.size() == 0 || flights[0].size() == 0) {
            return 0;
        }
        vector<vector<int>> dp(days[0].size()+1, vector<int>(flights.size(), -1));
        dp[0][0] = 0;
        int res = 0;
        for(int i = 1; i <= days[0].size(); i++) {
            for(int j = 0; j < flights.size(); j++) {
                for(int m = 0; m < flights.size(); m++) {
                    if(dp[i-1][m] >= 0 && (flights[m][j] == 1 || m == j)) {
                        dp[i][j] = max(dp[i][j], dp[i-1][m] + days[j][i-1]);
                    }
                }
                if(i == days[0].size()) {
                    res = max(res, dp[i][j]);
                }
                // cout<<i << "  " << j << "  " << dp[i][j] << endl;
            }
        }
        return res;
    }
};
//10:20













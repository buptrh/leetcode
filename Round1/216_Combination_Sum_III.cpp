class Solution {
public:
	vector<vector<int>> ret;
    vector<vector<int>> combinationSum3(int k, int n) {
    	std::vector<int> vResult;
        solve(vResult, k, n, 1);
        return ret;
    }


    void solve(vector<int> vResult, int k, int n, int start) {
    	for(int i = start; i < 10; i++) {
    		if(k == 1 && i == n) {
    			vResult.emplace_back(i);
    			ret.emplace_back(vResult);
    			vResult.pop_back();
    			break;
    		} else if(i * k >= n) {
    			break;
    		} 
    		vResult.emplace_back(i);
    		solve(vResult, k-1, n-i, i+1);
    		vResult.pop_back();
    	}
    }
};
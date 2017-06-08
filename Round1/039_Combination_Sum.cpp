class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return solve(candidates, target, 0);
    }

    vector<vector<int>> solve(vector<int>& candidates, int target, int index) {
    	// cout<<"solve start~~~target:" << target <<endl;;
    	vector<vector<int>> ret;
    	if(target <= 0 ) {
    		return ret;
    	}


    	for(int i = index; i < candidates.size(); i++) {

    		if(candidates[i] > target) {
    			continue;
    		}
    		else if(target - candidates[i] == 0) {
    			// cout<<"find.  i:" <<i<<". target:" << target<<endl;
    			std::vector<int> v;
				v.emplace_back(candidates[i]);
				ret.emplace_back(v);
    		} else {
    			// cout<<"try.  target:" << target << " | " << target - candidates[i]<<endl;
    			vector<vector<int>> results = solve(candidates, target - candidates[i], i);
    			if(results.size() > 0) {
	    			for(int j = 0; j < results.size(); j++) {
	    				results[j].emplace_back(candidates[i]);
	    				ret.emplace_back(results[j]);
	    			}
    			}
    		}
    		
    	}

    	// cout<<"solve end~~~target:" << target << "  retSize" << ret.size()<<endl;;
    	return ret;
	}
};
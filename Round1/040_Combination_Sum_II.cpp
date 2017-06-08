class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	sort(candidates.begin(), candidates.end());
        return solve(candidates, target, -1);
    }

    vector<vector<int>> solve(vector<int>& candidates, int target, int index) {
    	// cout<<"solve start~~~target:" << target <<endl;;
    	vector<vector<int>> ret;
    	if(target <= 0 ) {
    		return ret;
    	}


    	for(int i = index+1; i < candidates.size(); i++) {
    		if(i > index + 1 && candidates[i] == candidates[i-1]) {
    			continue;
    		}

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
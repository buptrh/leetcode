class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    	std::vector<std::vector<int> > vRet;
    	if(nums.size() <= 1) {
    		return vRet;
    	}
        set< std::vector<int> > retSet;
        for(int i = nums.size()-1; i >= 0; i--) {
        	std::set< std::vector<int> >::iterator it;
        	set< std::vector<int> > newretSet(retSet);
        	for(it = retSet.begin(); it != retSet.end(); it++) {
        		if((*it)[(*it).size()-1] >= nums[i]) {
        			vector<int> vec = (*it);
        			vec.emplace_back(nums[i]);
        			newretSet.emplace(vec);
        		}
         	}
         	retSet = newretSet;
        	std::vector<int> vec;
        	vec.emplace_back(nums[i]);
        	retSet.emplace(vec);
        }

    	std::set<std::vector<int>>::iterator it;
    	for(it = retSet.begin(); it != retSet.end(); it++) {
    		if((*it).size() > 1) {
    			vector<int> vec = *it;
    			reverse(vec.begin(), vec.end());
    			vRet.emplace_back( vec );
    		}
     	}

        return vRet;
    }
};


// copy from discuss. don't understand
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        dfs(res, seq, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
    	cout<<"dfs:" << pos<<endl;
        if(seq.size() > 1) {
        	res.push_back(seq);
        	cout<<"push:" ;
        	for(int i = 0; i < res.size(); i++) {
        		cout<< res[i] << "  ";
        	}
        	cout<<endl;
        }
        unordered_set<int> hash;
        for(int i = pos; i < nums.size(); ++i) {
            if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
                seq.push_back(nums[i]);
                dfs(res, seq, nums, i + 1);
                seq.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
};
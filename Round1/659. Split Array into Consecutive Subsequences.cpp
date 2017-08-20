class Solution {
public:
    bool isPossible(vector<int>& nums) {
        std::vector<vector<int>> ret;
        for(int i = 0; i < nums.size(); i++) {
        	int right = i;
        	while(right < nums.size() && nums[right] == nums[i]) {
        		right++;
        	}
        	int count = right - i;
        	for(vector<vector<int>>::iterator it = ret.begin(); it != ret.end();) {
        		int size = it->size();
        		if(nums[i] - (*it)[size-1] > 1) {
        			if((*it).size() < 3) {
        				return false;
        			} else {
        				ret.erase(it);
        			}
        		} else {
        			if(count > 0 && (*it).size() < 3) {
        				count--;
        				(*it).emplace_back(nums[i]);
        			}
        			it++;
        		}
        	}

        	for(vector<vector<int>>::iterator it = ret.begin(); it != ret.end();) {
        		int size = (*it).size();
        		if(nums[i] - (*it)[size-1] > 1) {
        			if((*it).size() < 3) {
        				return false;
        			} else {
        				ret.erase(it);
        			}
        		} else if(nums[i] - (*it)[size-1] == 1) {
        			if(count > 0) {
						count--;
    					(*it).emplace_back(nums[i]);
        			}
        			it++;
        		} else {
        			it++;
        		}
        	}
        	while(count > 0) {
        		ret.push_back(vector<int>(1, nums[i]));
        		count--;
        	}
        	i = right-1;
        }
        for(int i = 0; i < ret.size(); i++) {
        	if(ret[i].size() < 3) {
        		return false;
        	}
        }

        return true;
    }
};
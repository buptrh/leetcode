class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	vector<string> ret;
    	if(nums.size() == 0) {
    		return ret;
    	}
    	int current = nums[0], start = nums[0];
        for(int i = 1; i < nums.size(); i++) {
        	if(nums[i] == current + 1) {
        		current++;
        	} else {
        		string r = to_string(start);
        		if(current != start) {
        			r += "->" + to_string(current);
        		}
    			start = nums[i];
    			current = nums[i];
    			ret.emplace_back(r);
        	}
        }
		string r = to_string(start);
		if(current != start) {
			r += "->" + to_string(current);
		}
		ret.emplace_back(r);
		return ret;
    }
};
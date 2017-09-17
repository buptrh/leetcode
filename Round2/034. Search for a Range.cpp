class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid;
        vector<int> ret;
    	if(nums.size() == 0) {
        	ret.emplace_back(-1);
        	ret.emplace_back(-1);
    		return ret;
    	}
        while(start + 1 < end ) {
        	mid = start + (end - start) / 2;
        	if(nums[mid] == target) {
        		end = mid;
        	} else if(nums[mid] < target) {
        		start = mid;
        	} else {
        		end = mid;
        	}
        }
        if(nums[start] == target) {
        	ret.emplace_back(start);
        } else if(nums[end] == target) {
        	ret.emplace_back(end);
        } else {
        	ret.emplace_back(-1);
        }
        // cout<< start << "  " << end << endl;
        start = 0, end = nums.size()-1;
        while(start + 1 < end ) {
        	mid = start + (end - start) / 2;
        	if(nums[mid] == target) {
        		start = mid;
        	} else if(nums[mid] < target) {
        		start = mid;
        	} else {
        		end = mid;
        	}
        }
        // cout<< start << "  " << end << endl;
        if(nums[end] == target) {
        	ret.emplace_back(end);
        } else if(nums[start] == target) {
        	ret.emplace_back(start);
        } else {
        	ret.emplace_back(-1);
        }
        return ret;
    }
};
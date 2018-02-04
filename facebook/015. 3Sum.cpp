class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++) {
        	if(i > 0 && nums[i] == nums[i-1]) {
        		continue;
        	}
        	int j = i+1;
        	int end = nums.size()-1;
        	while(j < end) {
        		if(nums[i]+nums[j]+nums[end] == 0) {
	        		vector<int> r;
	        		r.push_back(nums[i]);
	        		r.push_back(nums[j]);
	        		r.push_back(nums[end]);
	        		res.push_back(r);
	        		while(j < end && nums[j+1] == nums[j]) {
	        			j++;
	        		}
	        		
	        		while(j < end && nums[end-1] == nums[end]) {
	        			end--;
	        		}
	        		j++;
	        		end--;
	        	} else if(nums[i]+nums[j]+nums[end] > 0) {
	        		end--;
	        	} else {
	        		j++;
	        	}
        	}
        }
        return res;
    }
};
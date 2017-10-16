class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    	if( k == 1) {
    		return true;
    	}
    	if( k <= 0) {
    		return false;
    	}
        int total = 0;
        for(int i = 0; i < nums.size(); i++) {
        	total += nums[i];
        }
        if(total % k != 0) {
        	return false;
        }
        total = total / k;
        vector<bool> used(nums.size(), false);
        return helper(nums, used, total);
    }

    bool helper(vector<int>& nums, vector<bool>& used, int sum) {
    	auto comp = [](int a, int b) {
		    return a > b;
		};
    	sort(nums.begin(), nums.end(), comp);
        for(int i = 0; i < nums.size(); i++) {
        	if(used[i]) {
        		continue;
        	}
        	used[i] = true;
        	if(!subSum(nums, used, sum - nums[i])) {
        		cout<<"fail" << nums[i]<<endl;
        		return false;
        	}
        }
        return true;
    }

    bool subSum (vector<int>& nums, vector<bool>& used, int sum) {
    	if(sum < 0) {
    		return false;
    	}
    	if(sum == 0){
    		return true;
    	}

        for(int i = 0; i < nums.size(); i++) {
        	if(used[i]) {
        		continue;
        	}
        	used[i] = true;
        	if(subSum(nums, used, sum - nums[i])) {
        		return true;
        	}
        	used[i] = false;
        }
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	std::vector<std::vector<int>> vRet;
    	sort(nums.begin(), nums.end())
        for(int i = 0; i < nums.size(); i++) {
        	int target = 0 - nums[i];
        	int front = i + 1 , end = nums.size()-1;
        	while(front < end){
        		int sum = nums[front] + nums[end];
        		if(sum < target) {
        			front++;
        		} else if(sum > target) {
        			front--;
        		} else {
        			vector<int> vec(3,0);
        			vec[0] = nums[i];
        			vec[1] = nums[front];
        			vec[2] = nums[end];
        			vRet.push_back(vec);
        			while(front < end && nums[front] == vec[1]) {
        				front++;
        			}
        			while(front < end && nums[end] == vec[2]) {
        				end--;
        			}
        		}
        	}

	        while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
	       	    i++;
	        }
        }
        return vRet;
    }
};

//sort is important
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int closest = INT_MAX, ret = target;
    	if(nums.size() <= 2) return target;
    	sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
        	int front = i + 1, end = nums.size() -1;
        	while(front < end) {
        		int sum = nums[i] + nums[front] + nums[end];
        		if(sum < target) {
        			front++;
        			int val = abs(target - sum);
        			if ( val < closest) {
        				closest = val;
        				ret = sum;
        			}
        		} else if(sum > target) {
        			end--;
        			int val = abs(target - sum);
        			if ( val < closest) {
        				closest = val;
        				ret = sum;
        			}
        		} else {
        			return target;
        		}
        	}
        }
        return ret;
    }
};


//INT_MAX
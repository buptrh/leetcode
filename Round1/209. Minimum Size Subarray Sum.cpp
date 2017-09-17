class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ret = 0, left = 0, sum = 0;
        bool flag = false;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            flag = false;
            if(sum >= s) {
                flag = true;
            }
            while(left < i && sum - s >= nums[left]) {
                sum -= nums[left];
                left++;
            }
            if(flag) {
	            if(ret > 0){
	           		ret = min(ret, i - left + 1);
	            } else {
	            	ret = i - left + 1;
	            }
            }
        }
        return ret;
    }
};
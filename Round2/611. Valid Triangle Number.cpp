class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0) {
                continue;
            }
            int left = i+1, right = left+1;
            while(left < nums.size()) {
                right = max(right, left + 1);
                if(nums[left] == 0) {
                    continue;
                }
                while(right < nums.size() && nums[i] + nums[left] > nums[right]) {
                    right++;
                }
                ret += right - left - 1;
                // cout<<nums[i] << "  " << nums[left] << "  " << nums[right] << endl;
                left++;
            }
        }

        return ret;
    }
};
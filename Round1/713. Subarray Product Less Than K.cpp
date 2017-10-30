class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size(), prod = 1, ans = 0, left = 0;
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            while (prod >= k) {
                prod /= nums[left];
                left++;
            }
            ans += i - left + 1;
        }
        return ans;
    }
};


// class Solution {
// public:
//     int count(vector<int>& nums, int k) {
//         if (k <= 1) return 0;
//         int n = nums.size(), ans = 0, left = 0;
//         for (int i = 0; i < n; i++) {
//             while (left <= i && nums[i] + nums[left] > k) {
//                 left++;
//             }
//             ans += i - left + 1;
//         }
//         return ans;
//     }
// };
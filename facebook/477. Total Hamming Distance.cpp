class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bits(32, 0);
        for(int i : nums) {
        	for(int j = 0; j < 32; j++) {
        		if(i & 1<<j) {
        			bits[j]++;
        		}
        	}
        }
        int res = 0;

        for(int i : bits) {
        	res += i * (nums.size()-i);
        }
        return res;
    }
};
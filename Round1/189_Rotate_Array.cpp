class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	int size = nums.size();
    	if(size <= 1) {
    		return;
    	}
    	k = k % size;
    	vector<int> nums2 = nums;
    	for(int i = 0; i < size; i++) {
    		nums[i] = nums2[(i-k + size) % size];
    	}
    }
};

//first: don't need to copy all items. only k part of them is ok.
//second solution is reverse. like a linked list
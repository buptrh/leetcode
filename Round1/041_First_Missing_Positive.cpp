class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            if(nums[0] == 1) {
                return 2;
            }
            else {
                return 1;
            }
        }
        for(int i = 0; i < size; i++) {
        	int val = nums[i];
        	if(val <= 0 || val > size || val == i + 1) {
        		continue;
        	}
        	while( val <= size && val > 0 && val != i+1) {
        		int temp = nums[val-1];
        		nums[val-1] = val;
        		if(temp == val){
        			break;
        		}
        		val = temp;
        	}
        	nums[i] = val;
        }
        for(int i = 0; i < size; i++) {
        	if(i+1 != nums[i]) {
        		return i + 1;
        	}
        }
        return size + 1;
    }
};


// [1,4,5,3,2,5,6]. 
// spend 2 hours thinking and 1 hour debuging



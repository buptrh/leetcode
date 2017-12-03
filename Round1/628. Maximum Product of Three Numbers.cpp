class Solution {
public:
    int maximumProduct(vector<int>& nums) {
    	int maxV[3], minV[2];
    	for(int i = 0; i < 3; i ++) {
    		maxV[i] = INT_MIN;
    	}
    	for(int i = 0; i < 2; i ++) {
    		minV[i] = 0;
    	}
    	int temp = 0, val  = 0;
        for(int i = 0; i < nums.size(); i++) {
        	temp = nums[i];
        	if(nums[i] > maxV[0]) {
        		if(nums[i] > maxV[1]) {
        			if(nums[i] > maxV[2]) {
        				val = maxV[2];
        				maxV[2] = temp;
        				temp = val;
        			}
        			val = maxV[1];
        			maxV[1] = temp;
        			temp = val;
        		}

    			val = maxV[0];
    			maxV[0] = temp;
    			temp = val;
        	}

        	if(nums[i] < 0 && nums[i] < minV[0]) {
        		temp = nums[i];
        		if(nums[i] < minV[1]) {
        			val = minV[1];
        			minV[1] = temp;
        			temp = val;
        		}
    			val = minV[0];
    			minV[0] = temp;
    			temp = val;
        	}
        }

        int ret = maxV[2], ret1 = maxV[0] * maxV[1], ret2 = minV[0] * minV[1];
        ret *= (ret1 > ret2 ? ret1 : ret2);
        return ret;

    }
};
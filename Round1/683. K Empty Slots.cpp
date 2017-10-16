class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
    	int left = 0;
    	vector<int> dp(flowers.size()+1, 0);
        for(int i = 0; i < flowers.size(); i++) {
        	int index = flowers[i];
        	dp[index] =  1;
        	int left = index-1, right = index+1;
        	while(index - left - 1 <= k && left > 0) {
        		if(dp[left] == 0) {
        			left --;
        		} else {
        			break;
        		}
        	}
        	if(left > 0 && index - left - 1 == k) {
        		return i + 1;
        	}
        	while(right - index - 1 <= k && right <= flowers.size()) {
        		if(dp[right] == 0) {
        			right++;
        		} else {
        			break;
        		}
        	}
        	if(right <= flowers.size() && right - index - 1 == k) {
        		return i + 1;
        	}
        	
        }
        return -1;
    }
};
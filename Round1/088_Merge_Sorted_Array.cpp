class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	int left = m -1, right = n-1;
        for(int i = m + n -1; i >= 0; i--){
        	if(left < 0 && right < 0) {
        		break;
        	} else if(left < 0) {
        		nums1[i] = nums2[right--];
        	} else if (right < 0) {
        		break;
        	} else {
        	    nums1[i] = nums1[left] > nums2[right] ? nums1[left--] : nums2[right--];
        	}
        }

    }
};
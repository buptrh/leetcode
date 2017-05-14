class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int i = 0, j = 0;
    	int ret = 0;
        while( true ) {
        	int sum = nums1.size() + nums2.size();
        	if( 2*(i + j + 1) >= sum) {
        		if(i >= nums1.size()) {
        			ret += nums2[j];
        		} else if(j >= nums2.size()) {
        			ret += nums1[i];
        		} else{
        			ret += nums1[i] < nums2[j] ? nums1[i] : nums2[j];
        		}
        	}
        	if( 2*(i + j + 2) > sum + 2 ) {
        		if(sum % 2 == 0) {
        			return (double)ret/2.0;
        		} else {
        			return ret;
        		}
        	}
        	
        	if(j >= nums2.size() || (nums1.size() > 0 && i <= nums1.size() -1 && nums1[i] < nums2[j])) {
        		i++;
        	} else {
        		j++;
        	}
        }
    }
};

//the median is used for dividing a set into two equal length subsets, that one subset is always greater than the other
//use binary search instead of traversal
//j = (sum1 + sum2 + 1) / 2 - i, so use binary search to search in nums1
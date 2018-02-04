class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int n1 = nums1.size(), n2 = nums2.size();
    	if(n1 > n2) {
    		return findMedianSortedArrays(nums2, nums1);
    	}

    	int start = 0, end = 2*n1, mid, mid2;
    	while(start <= end) {
    		mid = start + (end - start)/2;
    		mid2 = n1+n2-mid;
    		double l1 = (mid == 0) ? INT_MIN : nums1[(mid-1)/2];
    		double l2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
    		double r1 = (mid == n1*2) ? INT_MAX : nums1[(mid)/2];
    		double r2 = (mid2 == n2*2) ? INT_MAX : nums2[(mid2)/2];
    		cout<<start<< " " << end << " : " << l1 << " " << r1 <<  " " << l2 << " " << r2 << endl;
    		if(l2 > r1) {
    			start = mid + 1;
    		} else if(l1 > r2) {
    			end = mid - 1;
    		} else {
    			return (double)((double)max(l1, l2) + (double)min(r1, r2))/2.0;
    		}
    	}
        return -1;
    }
};
// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

// Note:
// Each element in the result must be unique.
// The result can be in any order.

vector<int> solve(vector<int> & nums1, vector<int> & nums2) {
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int p1 = 0, p2 = 0;
	vector<int> ret;
	while(p1 < nums1.size() && p2 < nums2.size()){
		if(p1 < nums1.size()-1 && nums1[p1] == nums1[p1+1]) {
			p1++;
		}
		if(p2 < nums2.size()-1 && nums2[p2] == nums2[p2+1]) {
			p2++;
		}
		if(nums1[p1] <  nums2[p2]) {
			p1++;
		} else if(nums1[p1] > nums2[p2]) {
			p2++;
		} else {
			ret.emplace_back(nums1[p1]);
		}
	}
	return ret;
}
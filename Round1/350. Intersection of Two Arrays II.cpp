// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

// Note:
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
// Follow up:
// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


//follow up 2;
vector<int> solve(vector<int> & nums1, vector<int> & nums2) {
	sort(nums1.begin(), nums1.end());
	for(int i = 0; i < nums2.size(); i++) {
		if(search(nums1, 0, nums1.size()-1, nums2[i])) {
			ret.emplace_back(nums2[i]);
		}
	}
	return ret;
}

bool search(vector<int> & nums1, int start, int end, int val) {
	if(start == end) {
		return val == nums[start];
	} else if(start > end) {
		return false;
	}

	int mid = (start+end)/2;
	if(val == nums1[mid]) {
		return true;
	} else if(val > nums1[mid]) {
		return search(nums1, mid+1, end, val);
	} else{
		return search(nums1, start, mid-1, val);
	}
}

//follow up 3?
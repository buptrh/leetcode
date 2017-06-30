class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1, right = -1;
        std::vector<int> ret;
        binarySearch(nums,target,0, nums.size(), left, right);
        ret.emplace_back(left);
        ret.emplace_back(right);
        return ret;
    }

   	void binarySearch(std::vector<int>& nums, int target, int start, int end, int& left, int& right) {
   		// cout<<"search:" << start<<". " << end<<endl;
   		if(end <= start) {
   			return;
   		}
   		if(left > -1 && right > -1) {
   			return;
   		}
   		int mid = (start+end)/2;
   		// cout<<"mid:" << mid<< " mid:" << nums[mid]<<endl;
   		if(nums[mid] == target) {
   			if(left < 0) {
	   			if(mid == 0 || nums[mid-1] < target) {
	   				// cout<<"left:" << mid<<endl;
	   				left = mid;
	   			} else {
	   				binarySearch(nums,target, start, mid, left, right);
	   			}
   			}
   			if(right < 0) {
	   			if( mid == nums.size()-1 || nums[mid+1] > target) {
	   				// cout<<"right:" << mid<<endl;
	   				right = mid;
	   			} else {
	   				binarySearch(nums, target, mid+1, end, left, right);
	   			}
   			}
   		} else if(nums[mid] > target) {
   			binarySearch(nums, target, start, mid, left, right);
   		} else {
   			binarySearch(nums, target, mid+1, end, left, right);
   		}
   	}
};
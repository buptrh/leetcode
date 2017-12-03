class Solution {
public:
    int search(vector<int>& nums, int target) {
    	return searchNoOrder(nums, 0, nums.size()-1, target);

    }
    int searchNoOrder(vector<int>& nums, int from, int to, int target) {
    	if(nums.size() == 0 || from > to) {
    		return -1;
    	}
    	if(to == from) {
    		if(nums[from] == target) {
    			return from;
    		} else {
    			return -1;
    		}
    	}
    	if(nums[to] >= nums[from]){
    		return searchInOrder(nums, from, to, target);
    	}

    	int separate = (to - from) /2 + from;
    	if(target == nums[separate] ){
    		return separate;
    	} else if(nums[separate] < nums[from]) { //pivot in left
    		if(separate > from && separate < to && (nums[separate] > nums[separate+1] || nums[separate] < nums[separate-1])){
    			if(target >= nums[0]) {
					return searchInOrder(nums, from, separate-1, target);
    			} else {
					return searchInOrder(nums, separate+1, to, target);
    			}
    		}
    		else if(target > nums[separate] && target < nums[from]) {
    			return searchInOrder(nums, separate+1, to, target);
    		} else {
    			return searchNoOrder(nums, from, separate-1, target);
    		}
    	} else { //pivot in right
    		if(target >= nums[from] && target < nums[separate]) {
    			return searchInOrder(nums, from, separate-1, target);
    		} else {
    			return searchNoOrder(nums, separate+1, to, target);
    		}
    	}

    }

    int searchInOrder(vector<int>& nums, int from, int to, int target) {
    	if(nums.size() == 0 || from > to) {
    		return -1;
    	}
    	int separate = (to - from) /2 + from;
    	if(target == nums[separate]) {
    		return separate;
    	} else if(target < nums[separate] ) {
    		return searchInOrder(nums, from, separate-1, target);
    	} else {
    		return searchInOrder(nums, separate+1, to, target);
    	}
    }
};




//my solution is to complicated. don't need in order or no order.




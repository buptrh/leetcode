class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-1, mid = 0;
        while(right >= left) {
        	if(left >= 0 && arr[left] >= x) {
        		mid = left;
        		break;
        	}
        	if(right < arr.size() && arr[right] <= x) {
        		mid = right;
        		break;
        	}
        	mid = left + (right-left)/2;
        	if(arr[mid] > x) {
        		right = mid - 1;
        	} else if(arr[mid] < x) {
        		left = mid + 1;
        	} else {
        		break;
        	}
        	// cout<<"mid:" << mid << "  " << left << "  " << right << endl;
        }
        // cout<< "final" << mid<<endl;

        std::vector<int> ret;
        left = mid; right = mid+1;
        while(k > 0) {
        	if(right >= arr.size() || (left >= 0 && abs(arr[left]-x) <= abs(arr[right]-x)) ) {
        		if(k > 1) {
        			left--;
        		} else {
        			right--;
        		}
        	} else {
        		if(k > 1) {
        			right++;
        		} else {
        			left++;
        		}
        	}
        	k--;
        }
        for(int i = left; i <= right; i++) {
        	ret.emplace_back(arr[i]);
        }
        return ret;
    }
};
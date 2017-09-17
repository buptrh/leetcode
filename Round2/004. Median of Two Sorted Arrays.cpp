//1:30
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        if(nums1.size() == 0) {
            if(nums2.size() %2 == 0) {
                return double(nums2[nums2.size()/2] + nums2[(nums2.size()-1)/2]) / 2.0;
            } else {
                return double(nums2[nums2.size()/2]);
            }
        }
        return helper(nums1, nums2, 0, nums1.size()-1);
    }

    double helper(vector<int>& nums1, vector<int>& nums2, int start1, int end1) {
        int mid1, mid2;
        while(start1 + 1< end1) {
            mid1 = start1 + (end1 - start1) / 2;
            mid2 = (nums1.size() + nums2.size()+1)/2 - mid1-2;
            // cout<<start1<< "  " << end1 << ": " << mid1 << "  " << mid2 << endl;
            if(nums1[mid1] < nums2[mid2]) {
                return helper(nums1, nums2, mid1, end1);
            } else if(nums1[mid1] > nums2[mid2]) {
                return helper(nums1, nums2, start1, mid1);
            } else {
                start1 = mid1;
                end1 = mid1+1;
                break;
            }
        }

        int index1 = start1, index2 = (nums1.size() + nums2.size()+1)/2 - end1-2;
        if(index1+1 < nums1.size() && nums1[index1+1] < nums2[index2]) {
            index1 ++;
            index2--;
        } else if(nums1[index1] > nums2[index2+1]) {
            index1--;
            index2++;
        }
        int total = nums1.size() + nums2.size();
        int count = index1 + index2 + 2;
        // cout<<"Final " << start1 << "  " << end1 << "  " << index1 << "  " << index2 << "  " << count << " total " << total << endl;
        while(count > (total-1)/2) {
            if(index1 < 0) {
                index2--;
            } else if(index2 < 0) {
                index1--;
            } else if(nums1[index1] < nums2[index2]) {
                index2--;
            } else {
                index1--;
            }
            count = index1 + index2 + 2;
        }
        // cout<<"After " << index1 << "  " << index2 << "  " << count << " total " << total << endl;
        double output = 0.0;
        if(total % 2 == 0) {
            if(index1 + 1 >= nums1.size()) {
                index2++;
                output = nums2[index2];
            } else if(index2 + 1 >= nums2.size()) {
                index1++;
                output = nums1[index1];
            } else {
                if(nums1[index1+1] < nums2[index2+1]) {
                    index1++;
                    output = nums1[index1];
                } else {
                    index2++;
                    output = nums2[index2];
                } 
            }

            if(index1 + 1 >= nums1.size()) {
                output += nums2[index2+1];
            } else if(index2 + 1 >= nums2.size()) {
                output += nums1[index1+1];
            } else {
                output += min(nums1[index1+1], nums2[index2+1]);
            }
            output = output / 2.0;

        } else {
            if(index1 + 1 >= nums1.size()) {
                output = nums2[index2+1];
            } else if(index2 + 1 >= nums2.size()) {
                output = nums1[index1+1];
            } else {
                output = min(nums1[index1+1], nums2[index2+1]);
            }
        }
        return output;
        
    }
};

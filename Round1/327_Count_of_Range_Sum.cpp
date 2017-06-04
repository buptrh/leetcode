
// 1. merge sort
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0) {
            return 0;
        }
        long cache[ nums.size()] = {0};
    	std::vector<long> sums;
        for(int i = 0; i < nums.size(); i++) {
            long prev = 0;
            if(i > 0) {
                prev = sums[i-1];
            }
            sums.emplace_back(prev + nums[i]);
            // cout<<sums[i]<<endl;
        }
        // cout<<"!!!" << sums.size()<<endl;;
        return countAndMergeSort(sums, cache, lower, upper, 0, nums.size());

    }

    int countAndMergeSort (std::vector<long> & sums, long* cache, long lower, long upper, int from, int to) {
        if(to - from <= 1) {
            if(sums[from] <= upper && sums[from] >= lower) {
                return 1;
            } else {
                return 0;
            }
        }
        int mid = (from + to) /2;
        int count = countAndMergeSort(sums, cache, lower, upper, from, mid) 
                + countAndMergeSort(sums, cache, lower, upper, mid, to);

        // cout<<"IIIN:" << from<< "  " << to<< "  " << mid<< endl;
        int left = mid, right = mid, copyRight = mid, copy = from;
        for(int i = from; i < mid; i++) {
            while(left < to && sums[left] - sums[i] < lower) {
                left++;
            }
            while(right < to && sums[right] - sums[i] <= upper) {
                right++;
            }
            while(copyRight < to && sums[copyRight] < sums[i]) {
                cache[copy++] = sums[copyRight++];
            }
            cache[copy++] = sums[i];
            count += right-left;
            // cout<< "right:" << right << " left:" << left << " count:" <<  count << " | leftsum:" << sums[left] - sums[i] << " rightsum:" << sums[right] - sums[i]
            //     << " ~ isum:"<< i << " " <<sums[i] <<endl;
        }
        for(int i = from; i < copy; i++) {
            sums[i] = cache[i];
        }

        return count;
    }
};


//2.another solution is binary search tree, see #315


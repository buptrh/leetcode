class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	std::vector<std::vector<int> > vRet;
        if(nums.size() < 4) {
            return vRet;
        }
        int size = nums.size();
        sort(nums.begin(), nums.end());
    	for(int i = 0; i < size - 3; i++) {
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[size-3]+nums[size-2]+nums[size-1]<target) continue;
    		for(int j = i + 1; j < size - 2; j++) {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[size-2]+nums[size-1]<target) continue;
    			int front = j + 1, end = size - 1;
    			while(front < end) {
    				int sum = nums[i] + nums[j] + nums[front] + nums[end];
                    if(sum < target) {
                        front++;
                    } else if( sum > target) {
                        end--;
                    } else {
                        vector<int> vec(4, 0);
                        vec[0] = nums[i];
                        vec[1] = nums[j];
                        vec[2] = nums[front];
                        vec[3] = nums[end];
                        vRet.push_back(vec);
                        while(front < end && nums[front] == vec[2]) {
                            front++;
                        }
                        while(front < end && nums[end] == vec[3]) {
                            end--;
                        }
                    }
    			}
                while(j < size - 3 && nums[j] == nums[j+1]) {
                    j++;
                }
    		}
            while(i < size - 2 && nums[i] == nums[i+1]) {
                i++;
            }
    	}
        return vRet;
    }
};


//note that there are some conditions that we can break or continue to next loop.
// vRet.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});




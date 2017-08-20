class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    	vector<int> ret;
    	if(nums.size() <= 1) {
    		return ret;
    	}
    	int m = 0;
        for(int i = 0; i < nums.size(); i ++) {
        	if(nums[i] == -1 || nums[i] == 0) {
        		continue;
        	}
        	m = nums[i];
        	nums[i] = -1;
        	while(nums[m-1] != 0 && nums[m-1] != -1) {
                cout<<nums[m-1] <<endl;
                int temp = nums[m-1];
                nums[m-1] = 0;
                m = temp;
        	}
        	if(nums[m-1] == -1) {
        		nums[m-1] = 0;
        	} else if(nums[m-1] == 0 ) {
        		ret.emplace_back(m);
        		// cout<<"push" << m<<endl;
        	}
        }

        return ret;
    }
};
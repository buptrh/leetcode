class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::vector<int> ret(nums.size(), -1);
        int size = nums.size();
        // nums.insert(nums.end(),nums.begin(),nums.end()); 
        stack<int> sta;
    	for(int i = 0; i < nums.size(); i++) {
    		// cout<<" out" << nums[i] <<endl;
    		if(sta.size() == 0 || nums[sta.top()] >= nums[i]) {
    			sta.push(i);
    		// cout<<" push" <<  i <<endl;
    		} else {
    			// cout<< " ~~" << sta.size() << endl;
    			while(sta.size() != 0 && nums[sta.top()] < nums[i]) {
    				ret[sta.top()%size] = nums[i];
    				sta.pop();
    			}
    			// cout<< " !!" << lastIndex << "  " << i <<  endl;
    			sta.push(i);
    		}
        }

        return ret;
    }
};
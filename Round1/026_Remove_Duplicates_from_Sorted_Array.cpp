class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int length = nums.size();
    	if(length == 0) {
    		return length;
    	}
    	vector<int>::iterator it = nums.begin();
    	int value = *it;
    	it++;
        while(it != nums.end())  {
        	if(*it == value) {
        		length--;
        		it = nums.erase(it);
        	} else{
        		value = *it;
        		it++;
        	}
        }
        return length;
    }
};

//don't erase. just copy to first length items.
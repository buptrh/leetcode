class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    	if(k < 0 ){
    		return 0;
    	}
        map<int, int> table;
        set< pair<int, int> > dup;
        for(int i : nums) {
        	// table[i]++;
        }
        for(int i : nums) {
        	if( table[i+k] != 0 && dup.find(pair<int, int>(i, i+k)) == dup.end()) {
	        	dup.insert(pair<int, int>(i, i+k));
        	}

        	if( table[i-k] != 0 && dup.find(pair<int, int>(i, i-k)) == dup.end()) {
	        	dup.insert(pair<int, int>(i-k, i));
        	}
        	table[i]++;
        }
        return dup.size();
    }
};
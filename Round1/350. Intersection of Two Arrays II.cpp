class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	map<int, int> table;
    	vector<int> ret;
        for(int i = 0; i < nums1.size(); i++) {
        	table[nums1[i]] ++;
        }

        for(int i = 0; i < nums2.size(); i++) {
        	if(table[nums2[i]]) {
        		ret.emplace_back(nums2[i]);
        		table[nums2[i]]--;
        	}
        }
        return ret;
    }
};
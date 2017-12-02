class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
    	vector<int> dic(255, 0);
    	int size = 0, left = 0, res = 0;
        for(int i = 0; i < s.size(); i++) {
        	if(dic[s[i]] == 0) {
        		size++;
        	}
        	dic[s[i]]++;
    		while(size > k) {
    			dic[s[left]]--;
    			if(dic[s[left]] <= 0) {
    				size--;
    			}
    			left++;
    		}
			res = max(res, i - left + 1);
        }
        res = max(res, (int)s.size()-left);
        return res;
    }
};
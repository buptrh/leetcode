class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> juset;
        for(char c : J) {
        	juset.insert(c);
        }
        int count = 0;
        for(char c : S ) {
        	if(juset.count(c)) {
        		count++;
        	}
        }
        return count;
    }
};
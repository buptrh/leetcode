class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char c = 0;
        for(char i : letters) {
        	if(c == 0 || (i > target &&  i < c) || (i > target && c <= target)) {
        		c = i;
        	}
        }
        return c;
    }
};
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int minCount = B.size()/A.size();
        string comp = "";
        for(int i = 1; i <= minCount + 2; i ++) {
        	comp += A;
        	if(comp.find(B) != -1) {
        		return i;
        	}
        }
        return -1;
    }
};
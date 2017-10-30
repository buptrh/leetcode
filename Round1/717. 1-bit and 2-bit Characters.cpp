class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
    	if(bits.size() <= 1) {
    		return true;
    	}
        int index = bits.size()-1;
    	if(bits[index] == 1) {
    		return false;
    	}
    	index--;
        while(index >= 0 && bits[index] == 1) {
        	index--;
        	if(index < 0 || bits[index] == 0) {
        		return false;
        	}
        	index--;
        }
        return true;
    }

};
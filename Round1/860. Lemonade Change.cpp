class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    	vector<int> money(3, 0);
        for(int i : bills) {
        	if(i == 5) {
        		money[0]++;
        	} else if(i == 10) {
        		if(money[0] > 0) {
        			money[0]--;
        			money[1]++;
        		} else {
        			return false;
        		}
        	} else {
        		if(money[1] > 0 && money[0] > 0) {
        			money[1] --;
        			money[0] --;
        		} else if(money[0] >= 3) {
        			money[0] -= 3;
        		} else {
        			return false;
        		}
        		money[2] ++;
        	}
        }
        return true;
    }
};
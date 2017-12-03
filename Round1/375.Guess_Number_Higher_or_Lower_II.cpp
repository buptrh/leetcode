class Solution {
public:
    int getMoneyAmount(int n) {
        int start = 0, end = n, money = 0;
        while (start < end) {
        	int mid = (start+end+1)/2;
        	money += mid;
        	start = mid+1;
        }
        return money;
    }
};
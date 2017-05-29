class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
    	int x = m, y = n;
    	for(int i = 0; i < ops.size(); i++) {
    		std::vector<int> op = ops[i];
    		x = min(x, op[0]);
    		y = min(y, op[1]);
    	}
        return x*y;
    }
};
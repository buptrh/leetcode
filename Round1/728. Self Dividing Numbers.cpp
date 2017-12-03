class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(int i = left; i <= right; i++) {
        	bool finish = true;
        	int v = i;
        	while(v != 0) {
        		if((v%10) == 0 || i%(v%10) != 0) {
        			finish = false;
        			break;
        		} else {
        			v = v / 10;
        		}
        	}
        	if(finish) {
        		ret.emplace_back(i);
        	}
        }
        return ret;
    }
};
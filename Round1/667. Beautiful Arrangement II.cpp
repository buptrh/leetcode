class Solution {
public:
    vector<int> constructArray(int n, int k) {
    	int max = k+1, current = k, next = 1;
    	vector<int> ret;
    	bool add = true;
    	for(int i = 1; i <= max && i <= n; i++){
    		ret.emplace_back(next);
    		if(add){
    			next += current;
    		} else {
    			next -= current;
    		}
    		add = !add;
    		current--;
    	}
    	for(int i = max + 1; i <= n; i++) {
    		ret.emplace_back(i);
    	}
    	return ret;

    }

};
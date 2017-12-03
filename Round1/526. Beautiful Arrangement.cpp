class Solution {
public:
	int count;
    int countArrangement(int N) {
    	count = 0;
    	vector<bool> used(N+1, false);
    	vector<int> path;
        helper(N, used, 1);
        return count;
    }

    void helper(int n, vector<bool> & used,  int pos) {
    	if(pos-1 == n) {
    		count++;
    		return;
    	}
    	for(int i = 1; i <= n; i++) {
    		if(used[i] || (pos % i != 0 && i % pos != 0)) {
    			continue;
    		}
    		used[i] = true;
    		helper(n, used, pos+1);
    		used[i] = false;
    	}
    }
};
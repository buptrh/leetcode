class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {

        int sum = 0;
        for(int v : A) {
        	sum += v;
        }

        map<int, unordered_set<int>> values;
        values[0].insert(0);
    	for(int c : A) {
        	for(int i = A.size()/2; i > 0; i--) {
        		// cout<< i << ": ";
        		bool flag = false;
        		double target = (double)sum / (double)(A.size()) * (double)i;
        		if(sum * i % A.size() == 0) {
        			flag = true;
        		} else {
        			flag = false;
        		}
        		for(int v : values[i-1]) {
        			if(flag && v + c == (int)target) {
        				// cout << i << " " << v+c << "  " << c << endl;
        				return true;
        			}
        			values[i].insert(v+c);
        			// cout<< v+c<<". ";
        		}
        		// cout<<" !!! " << ((double)(int) target) << "  " << target << endl;
        	}
        }
        return false;
        
    }
};
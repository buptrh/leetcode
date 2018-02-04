class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    	map<int, vector<int>> table;
    	for(int i = 0; i < arr.size(); i++) {
    		table[arr[i]].push_back(i);
    	}
    	vector<int> newarr = arr;
    	sort(newarr.begin(), newarr.end());
    	int cur = -1;
    	stack<int> res;
    	for(int i = 0; i < arr.size(); i++) {
    		int val = newarr[i];
    		int j = table[val][0];
    		while(res.size() != 0 && !(j > res.top() && i > res.top())) {
    			res.pop();
    		}
    		if(res.empty() || (j > res.top() && i > res.top())){
				res.push(max(j, i));
    		}
    		table[val].erase(table[val].begin());
    		// cout<< i <<endl;
    		// output(res);
    		// cout<<endl;
    	}
        return res.size();
    }

    void output(stack<int> vec) {
    	while(vec.size() > 0 ) {
    		cout << vec.top() << "  " ;
    		vec.pop();
    	}
    	cout<<endl;
    }
};
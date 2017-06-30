class Solution {
public:
    map<char, int> table;
     struct {
        bool operator()(int a, int b) const
        {   
            return a < b;
        }   
    } customLess;

    int leastInterval(vector<char>& tasks, int n) {
        std::vector<char> vec;
        int count = 0;
        for(int i = 0; i < tasks.size(); i++) {
        	if(table[tasks[i]] == 0) {
        		vec.emplace_back(tasks[i]);
        	}
        	count ++;
        	table[tasks[i]] ++;
        }
        int ret = 0;
	    std::sort(vec.begin(), vec.end(), customLess);
	    int interval = n, current = 0;
	    set<int> currentInterval;
	    // cout<<"start" << count<<endl;
	    while(count > 0) {
	    	// cout<<current << " ";
	    	while(current < vec.size() && table[vec[current]] > 0 && currentInterval.find(vec[current]) != currentInterval.end()) {
	    		current++;
	    	}
	    	if(current == vec.size() || table[vec[current]] <= 0) {
	    		ret += interval+1;
	    		interval = -1;
	    		current = 0;
	    		if(interval < 0) {
		    		interval = n;
		    		currentInterval.clear();
	    		}
	    		// cout<<endl;
	    		continue;
	    	}

	    	currentInterval.emplace(vec[current]);
	    	// cout<<vec[current] << " " <<endl;
	    	interval--;
	    	table[vec[current]] --;
	    	char temp = vec[current];
	    	int index = current+1;
	    	while(index < vec.size() && table[temp] < table[vec[index]]) {
	    		vec[index-1] = vec[index];
	    		index++;
	    	}
	    	vec[index-1] = temp;

	    	// for(int i = 0; i < vec.size(); i++) {
	    	// 	cout<<vec[i]<< "  " ;
	    	// }
	    	// cout<<endl;
	    	count--;
	    	current = 0;
	    	ret ++;
	    	if(interval < 0) {
	    		interval = n;
	    		current = 0;
	    		currentInterval.clear();
	    	}
	    }
    	return ret;
    }
};
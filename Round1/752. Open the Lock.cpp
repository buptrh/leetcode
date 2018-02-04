class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        return bfs("0000", deadends, target);
    }

    int bfs(string from, vector<string>& deadends, string target) {
    	if(from == target) {
    		return 0;
    	}
    	queue<string> numStart;
    	queue<string> numEnd;
    	unordered_set<string> setStart;
    	unordered_set<string> setEnd;
    	unordered_set<string> setBlocks;
    	int res = -1;
    	for(string s : deadends) {
    		setBlocks.insert(s);
    	}
    	numStart.push(from);
    	numEnd.push(target);
    	while(!numStart.empty() && !numEnd.empty()) {
    		int sizeStart = numStart.size();
    		for(int i = 0; i < sizeStart; i++) {
    			string start = numStart.front();
    			numStart.pop();
    			// cout<< start << "  " << res<<endl;
    			if(setStart.find(start) != setStart.end() || setBlocks.find(start) != setBlocks.end()) {
    				continue;
    			}
    			setStart.insert(start);
    			if(setEnd.find(start) != setEnd.end() || setBlocks.find(start) != setBlocks.end()) {
    				return res;
    			}
    			for(int j = 0; j < 4; j++) {
    				numStart.push(getLeft(start, j));
    				numStart.push(getRight(start, j));
    			}
    		}
			res++;


    		int sizeEnd = numEnd.size();
    		for(int i = 0; i < sizeEnd; i++) {
    			string end = numEnd.front();
    			numEnd.pop();
    			if(setEnd.find(end) != setEnd.end() || setBlocks.find(end) != setBlocks.end()) {
    				continue;
    			}
    			// cout<< end << "  " << res<<endl;
    			setEnd.insert(end);
    			if(setStart.find(end) != setStart.end()) {
    				return res;
    			}
    			for(int j = 0; j < 4; j++) {
    				numEnd.push(getLeft(end, j));
    				numEnd.push(getRight(end, j));
    			}
    		}
			res++;
    	}

    	return -1;
    }

    string getLeft(string & num, int i) {
    	string res = num;
    	if(res[i] == '0') {
    		res[i] = '9';
    	} else {
    		res[i] = (res[i] - 1);
    	}
    	return res;
    }
    string getRight(string & num, int i) {
    	string res = num;
    	if(res[i] == '9') {
    		res[i] = '0';
    	} else {
    		res[i] = (res[i] + 1);
    	}
    	return res;
    }
};
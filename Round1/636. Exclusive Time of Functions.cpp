class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        int index = -1, prev = 0;
        stack<int> sta;
        for(string s : logs) {
        	vector<string> task = split(s, ':');
        	int id = stoi(task[0]);
        	int time = stoi(task[2]);
        	if(index >= 0) {
	        	if(task[1] == "start") {
	        		res[index] += (time - prev);
		        } else {
	        		res[index] += (time - prev + 1);
	        	}
        	}
        	// cout << index << "  " << res[index] << " : " << id << " " << task[1] << "  "<< time << endl;
        	if(task[1] == "start") {
        		prev = time;
        		sta.push(index);
        		index = id;
	        } else {
        		prev = time + 1;
        		index = sta.top();
        		sta.pop();
        	}
        }
        return res;
    }

    vector<string> split(string t, char sp) {
        vector<string> words;
        istringstream iss(t);
        string s;
        while (getline(iss, s, sp)) {
            words.push_back(s);
        }
        return words;
    }
};
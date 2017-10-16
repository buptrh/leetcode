class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        int sum = 0, index = 0;
        for(int i = 0; i < ops.size(); i ++) {
        	if(ops[i] == "+") {

        		int val = 0;
        		if(index > 0) {
        			val += score[index-1];
        		}
        		if(index > 1) {
        			val += score[index-2];
        		}
        		pushToScore(score, index, val);
        		index++;
        		sum += val;
        	} else if(ops[i] == "C") {
        		if(index <= 0) {
        			continue;
        		}
        		index--;
        		sum -= score[index];
        	} else if(ops[i] == "D") {
        		int val = 0;
        		if(index > 0) {
        			val += (2 * score[index-1]);
        		}
        		pushToScore(score, index, val);
        		index++;
        		sum += val;
        	} else {
        		int val = stoi(ops[i]);
        		pushToScore(score, index, val);
        		sum += val;
        		index++;
        	}
        }
        return sum;
    }

    void pushToScore(vector<int>& score, int index, int val) {

		if(index == score.size()) {
			score.emplace_back(val);
		} else {
			score[index] = val;
		}

    }
};
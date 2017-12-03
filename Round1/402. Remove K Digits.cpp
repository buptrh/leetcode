class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret;
        set<int> remove;
        stack<int> sta;
        for(int i = 0; i < num.size() && k > 0; i++) {
        	if(sta.size() == 0 || num[sta.top()] <= num[i]) {
        		sta.push(i);
        	} else {
        		while(k > 0 && sta.size() != 0 && num[sta.top()] > num[i]) {
        			remove.insert(sta.top());
        			sta.pop();
        			k--;
        		}
        		sta.push(i);
        	}
        }
        while(k > 0 && sta.size() > 0) {
    		remove.insert(sta.top());
    		sta.pop();
    		k--;
        }

        int index = 0;
        for(int i = 0; i < num.size(); i++) {
        	if(index >= num.size() || remove.find(i) == remove.end() ) {
        		if(ret.size() == 0 && num[i] == '0'){

        		} else {
        			ret += num[i];
        		}
        	} else {
        		index++;
        	}
        }
        if(ret.size() == 0) {
        	ret = "0";
        }
        return ret;
    }
};
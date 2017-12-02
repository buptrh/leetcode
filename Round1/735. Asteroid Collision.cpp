class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> sta;
        vector<int> res;
        for(int ast : asteroids) {
        	if(ast > 0) {
        		sta.push(ast);
        	} else {
        		while(!sta.empty()) {
        			if(sta.top() < 0 - ast) {
        				sta.pop();
        			} else if(sta.top() == 0 - ast) {
        				ast = 0;
        				sta.pop();
        				break;
        			} else {
        				break;
        			}
        		}

        		if(ast < 0 && sta.empty()) {
        			res.push_back(ast);
        		}
        	}
        }

        stack<int> sta2;
        while(!sta.empty()) {
        	sta2.push(sta.top());
        	sta.pop();
        }

        while(!sta2.empty()) {
        	res.push_back(sta2.top());
        	sta2.pop();
        }
        return res;
    }
};
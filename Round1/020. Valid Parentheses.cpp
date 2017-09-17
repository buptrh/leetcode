class Solution {
public:
    bool isValid(string s) {
        char left[3] = {'(', '{', '['};
        char right[3] = {')', '}', ']'};
        stack<int> arr;

        for(char c : s) {
    		for(int i = 0; i < 3; i++) {
    			if(c == left[i]) {
    				arr.push(i);
    			} else if(c == right[i]) {
    				if(arr.size() == 0 || arr.top() != i) {
    					return false;
    				} else {
    					arr.pop();
    				}
    			}
    		}
        }
        return arr.empty();
    }
};
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> sta;
        int minVal = INT_MIN;
        for(int i = 0; i < preorder.size(); i++) {
        	if(preorder[i] < minVal) {
        		return false;
        	}
    		while(!sta.empty() && sta.top() < preorder[i]) {
        		minVal = sta.top();
        		sta.pop();
    		}
    		sta.push(preorder[i]);
        }
        return true;
    }
};
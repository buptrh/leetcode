class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
    	map<int, int> table;
    	vector<int> ret;
    	int maxHeight = 0;
        for(pair<int, int> position : positions) {
        	int leftHeight = position.second;
        	bool findLeft = false;
        	int rightHeight = 0;
        	for(auto it = table.begin(); it != table.end(); it++) {
        		if(it->first <= position.first) {
        			leftHeight = it->second + position.second;
        		}
        		if(it->first > position.first && position.second + position.first > it->first) {
        			leftHeight = max(leftHeight, it->second + position.second);
        		}
        		if(it->first <= position.first + position.second) {
        			rightHeight = it->second;
        		} else {
        			break;
        		}
        	}
        	maxHeight = max(maxHeight, leftHeight);
        	ret.emplace_back(maxHeight);
        	table[position.first] = leftHeight;
        	table[position.first+position.second] = rightHeight;
        	for(auto it = table.begin(); it != table.end(); it++) {
        		if(it->first > position.first && it->first < position.first + position.second) {
        			it->second = leftHeight;
        		} else if(it->first >= position.first + position.second) {
        			break;
        		}
        	}
        }
        return ret;
    }
};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string path;
        map<char, vector<char>> table;
        table['0'] = {' '};
        table['1'] = {};
        table['2'] = {'a', 'b', 'c'};
        table['3'] = {'d', 'e', 'f'};
        table['4'] = {'g', 'h', 'i'};
        table['5'] = {'j', 'k', 'l'};
        table['6'] = {'m', 'n', 'o'};
        table['7'] = {'p', 'q', 'r', 's'};
        table['8'] = {'t', 'u', 'v'};
        table['9'] = {'w', 'x', 'y', 'z'};

        backTracking(digits, res, path, table, 0);
        return res;
    }

    void backTracking(string digits, vector<string>& res, string & path, map<char, vector<char>>& table, int start) {
    	if(digits.size() == start) {
    		if(path.size() > 0) {
    			res.push_back(path);
    		}
    		return;
    	}
    	vector<char> & dict = table[digits[start]];
    	for(char c : dict) {
    		path.push_back(c);
    		backTracking(digits, res, path, table, start+1);
    		path.pop_back();
    	}
    }
};
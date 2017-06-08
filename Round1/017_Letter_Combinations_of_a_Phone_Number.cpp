class Solution {
public:
	vector<string> ret;
    vector<string> letterCombinations(string digits) {
        map<char, string> table;
        table['1'] = "";
        table['2'] = "abc";
        table['3'] = "def";
        table['4'] = "ghi";
        table['5'] = "jkl";
        table['6'] = "mno";
        table['7'] = "pqrs";
        table['8'] = "tuv";
        table['9'] = "wxyz";
        table['0'] = " ";
        table['*'] = "+";
        table['#'] = "#";
        string results;
        solve(table, results, digits, 0);
        return ret;
    }

    void solve(map<char, string> table, string results, string digits, int index ) {
    	if(index >= digits.size() ) {
    		if(results.size() > 0) {
    			ret.emplace_back(results);
    		}
    		return;
    	}
    	string str = table[digits[index]];
        for(int i = 0; i < str.size(); i++) {
        	results = results + str[i];
        	solve(table, results, digits, index+1);
        	results.pop_back();
        }
    }
};
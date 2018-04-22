class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> res;
        vector<string> morses{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        for(string s : words) {
        	res.insert(getMorse(s, morses));
        }

        return res.size();
    }

    string getMorse(string s, vector<string> & morses) {
    	string res;
    	for(char c : s) {
    		res += morses[c-'a'];
    	}
    	return res;
    }
};
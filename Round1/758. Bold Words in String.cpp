class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        unordered_set<string> wordset;
        for(string s : words) {
          wordset.insert(s);
        }

        string res;
        int lastIndex = -1;
        for(int i = 0; i < S.size(); i++) {
          for(int j = i; j < S.size(); j++) {
            if( wordset.count(S.substr(i, j-i+1))) {
              if(lastIndex < 0) {
                res += "<b>";
              }
              lastIndex = max(lastIndex, j);
            }
          }

        if(lastIndex >= 0 && lastIndex < i) {
          res += "</b>";
          lastIndex = -1;
        }
          res.push_back(S[i]);
        }
        if(lastIndex >= 0) {
          res += "</b>";
          lastIndex = -1;
        }
        return res;
    }
};
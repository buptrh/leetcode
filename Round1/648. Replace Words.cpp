


class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        std::vector<string> sens = split(sentence, ' ');
        for(int i = 0; i < sens.size(); i++) {
        	int minLength = INT_MAX;
        	int foundDic = -1;
        	int foundPos = -1;
        	for(int j = 0; j < dict.size(); j++) {
        		std::size_t found = sens[i].find(dict[j]);
			  	if (found!=std::string::npos ){
			  		if(minLength > dict[j].size()  && found == 0) {
				    	foundDic = j;
				    	minLength = dict[j].size();
				    	foundPos = found;
			  		}
			  	}
        	}
        	if(foundDic >= 0) {
        		sens[i] = dict[foundDic];
        	}
        }
        string ret;
        for(int i = 0; i < sens.size(); i++) {
        	ret += sens[i];
        	if(i != sens.size()-1) {
        		ret += " ";
        	}
        }
        return ret;
    }

    vector<string> split(string t, char sp) {
        vector<string> words;
        istringstream iss(t);
        string s;
        while (getline(iss, s, sp)) {
            words.push_back(s);
        }
        return words;
    }
};
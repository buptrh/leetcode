class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
    	int maxSize = 0;
    	string ret;
    	int left = 0;
    	unordered_map<string, int> table;
    	unordered_set<string> ban;
    	for(string s : banned) {
    		ban.insert(s);
    	}
        for(int i = 0; i <= paragraph.size(); i++) {
        	char c = ' ';
            if(i < paragraph.size()) {
                c = paragraph[i];
            }
        	switch(c){
        		case ' ':
                case ',':
        		case '\'':
                case '.':
                case ';':
                case '!':
        		case '?':
        		case '\n':
        			string current = paragraph.substr(left, i - left);
					std::transform(current.begin(), current.end(), current.begin(), ::tolower);
        			if(current.size() == 0 || ban.count(current) > 0) {
        				left = i+1;
        				continue;
        			}
        			table[current]++;
        			// cout<<current << "  " << table[current]<<endl;
        			if(table[current] > maxSize) {
        				maxSize = table[current];
        				ret = current;
        			}
        			left = i+1;
        		break;
        	}
        }
        return ret;
    }
};
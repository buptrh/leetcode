class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string> > filesMap;
        vector<vector<string>> ret;
        for(int i = 0; i < paths.size(); i++) {
        	int prePos = 0;
        	int pos = paths[i].find(" ", prePos);
        	string path = paths[i].substr(prePos, pos - prePos);

        	do {
	        	prePos = pos + 1;
	        	pos = paths[i].find(" ", prePos);
	        	string fileContent = paths[i].substr(prePos, pos - prePos); 

	        	int pos2 = 0;
	        	pos2 = fileContent.find("(", 0);
	        	string file = fileContent.substr(0, pos2);

	        	string content = fileContent.substr(pos2+1, fileContent.size() - 2 - pos2);

	        	if(filesMap.find(content) == filesMap.end()) {
        			std::vector<string> vFiles;
	        		filesMap[content] = vFiles;
	        	}
        		filesMap[content].emplace_back(path + "/" + file);
	        	prePos = pos+1;

	        	
        	}while (pos >= 0);
        }

        for(map<string,vector<string>>::iterator it=filesMap.begin(); it!=filesMap.end(); ++it) {
        	if(it->second.size() > 1) {
        		ret.emplace_back(it->second);
        	}
        }
        return ret;
    }
};
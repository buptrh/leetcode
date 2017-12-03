class Excel {
public:
	vector<vector<int>>data;
	map<pair<int, int>, vector<string> > formulas;
    Excel(int H, char W) {
        data.clear();
        formulas.clear();
        for(int i = 0; i <= H; i ++) {
        	data.emplace_back(vector<int>());

	        for(int j = 0; j <= W - 'A'; j ++) {
        		data[i].emplace_back(0);
	        }
        }
    }
    
    void set(int r, char c, int v) {
        data[r][c-'A'] = v;
        pair<int, int> k(r, c-'A');

	    auto pos = formulas.find(k) ;
	    // cout<< "!!" << formulas.size()<<endl;
	    if(pos != formulas.end()) {
            formulas.erase(pos);  
	    } 
	    // cout<< "!!"<<formulas.size()<<endl;

    }
    
    int get(int r, char c) {
    	// cout<<"get start" <<endl;
        pair<int, int> k(r, c-'A');
    	// cout<<"get start 1" <<endl;
        int ret = 0;
	   	if(formulas.find(k) == formulas.end()) {
    	// cout<<"get start 2" <<endl;
        	ret = data[r][c-'A'];
	   	}  else {
	   		ret = sum(r,c,formulas[k]);
	   	}
    	// cout<<"get end" << ret <<endl;
    	return ret;
    }
    
    int sum(int r, char c, vector<string> strs) {
    	// cout<<"sum start" <<endl;
        formulas[pair<int, int>(r, c-'A')] = strs;

   		int sum = 0;

   		for(int i = 0; i < strs.size(); i++) {
   			int startCol = 0, startRow = 1, endCol = 0, endRow = 1;
   			string str = strs[i];
	   		int pos = str.find(':');
	   		string strsStart = str, strsEnd = "";
	   		startCol = endCol = strsStart[0] - 'A';
	   		startRow = endRow = stoi(strsStart.substr(1));
	   		// cout<<startRow <<". " << startCol <<". " << endRow<<". "  << endCol<<endl;
	   		if(pos > 0) {

	   			strsEnd = str.substr(pos+1);
		   		endCol = strsEnd[0] - 'A';
		   		endRow = stoi(strsEnd.substr(1));
	   		}
	   		for(int m = startCol; m <= endCol; m++) {
    				// cout<<"row" << str.substr(1) << "  " << row <<endl;

	   			for(int j = startRow; j <= endRow; j++) {
    				// cout<<"add" << j << "  " << m << " A" + m<<endl;
	   				sum += get(j, 'A' + m);
	   			}
	   		}
   		}
    	// cout<<"sum end" << sum <<endl;
   		return sum;
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
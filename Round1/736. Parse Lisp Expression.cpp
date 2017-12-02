class Solution {
public:
	map<string, int> table;
    int evaluate(string expression) {
    	int start = 0;
    	return helper(expression, start);
    }

    int getVal(string & expression, int & start, map<string, int>& table1 ) {
    	int res = 0;
    	int flag = 0;
    	string s = getStr(expression, start);
    	while(s.back() == ')') {
    		// cout<<"!!!!" << endl;
    		s = s.substr(0, s.size()-1);
    		// cout<<"!!!!~~~" << endl;
    		flag ++;
    	}
    	// cout<<"getval |"<< s <<"|. " << start << endl;
    	if(s[0] == '(') {
    		start++;
    		// cout<<"goto helper: " << s << endl;
    		res = helper(expression, start);
    	} else {
    		if(isLower(expression[start])) {
    			res = table1[s];
    		} else {
    			res = stoi(s);
    		}
			start += s.size() + 1;
    	}
		start += flag;
    	// cout<<"    retval "<< s << "  " << res<< "  " << start << "  " <<  endl;

     	return res;
    }

    int helper(string  & expression, int & start) {
    	string s = getStr(expression, start);
    	if(s[0] == '(') {
    		// cout<<"!!!!" << endl;
    		s = s.substr(1, s.size()-1);
    		// cout<<"!!!!~~~" << endl;
    		start++;
    	}
    	// cout<<"helper: " << s << endl;
    	bool finish = false;
    	int res = 0;
    	if(s == "add") {
    		start += 4;
    		int a = 0, b = 0;
			map<string, int> table1 = table;
    		a = getVal(expression, start, table1);
    		b = getVal(expression, start, table1);
    		res = a+b;

    	} else if(s == "mult") {
    		start += 5;
    		int a = 0, b = 0;

			map<string, int> table1 = table;
    		a = getVal(expression, start, table1);
    		b = getVal(expression, start, table1);
    		res = a*b;

    	} else if(s == "let") {
    		start += 4;
			string s = getStr(expression, start);
    		while( (s[0] != '(') && (s.find(')') == string::npos)) {
    			// cout<<".  let continue: " << s <<". " << start <<endl;
    			start += s.size() + 1;
    			table[s] = getVal(expression, start, table);
    			// cout<<".      Set:" << s << " |" << table[s]<<endl;
    			s = getStr(expression, start);
    		}
    		// cout<<".  finish let" << endl;
    		res = getVal(expression, start, table);
    	} else {
    		cout<<"ERROR: " << s <<endl;
    	}

    	// cout<<"helper ret: " << s << "   " <<res<<". " << start<< endl;
    	return res;
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

    bool isLower(char c) {
    	if(c >= 'a' && c <= 'z') {
    		return true;
    	} else {
    		return false;
    	}
    }

    string getStr(string  & expression, int & start) {
    	// cout<<"find: " << start ;

    	int i = expression.substr(start).find(" ");
    	// cout<< "  " << i << endl;
    	if( i == string::npos) {
    		return expression.substr(start);
    	} else {
    		return expression.substr(start, i);;
    	}
    }

};
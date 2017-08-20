class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        std::vector<double> ret;
        map<string, pair<double, string>> table;
        for(int i = 0; i < equations.size(); i++) {
        	pair<string, string> equation = equations[i];
        	if(table.find(equation.first) != table.end() && table[equation.first].first != 1.0) {
        		table[equation.second] = pair<double,string>(table[equation.first].first/values[i], table[equation.first].second);
        	} else {
        		table[equation.first] = pair<double, string>(values[i], equation.second);
        	}
        	if(table.find(equation.second) == table.end()) {
        		table[equation.second] = pair<double, string>(1.0, equation.second);
        	} 
        }
        // cout<<"~~~" <<endl;

        for(int i = 0; i < queries.size(); i++) {
        	pair<string, string> query = queries[i];
        	// cout<< query.first << "  " << query.second ;
        	if(table.find(query.second) == table.end() || table.find(query.first) == table.end()) {
        		ret.emplace_back(-1.0);
        	} else if(query.first == query.second) {
        		ret.emplace_back(1);
        	}else {
        		double d1 = 1.0, d2 = 1.0;
        		string s1 = query.first, s2 = query.second;
        		while(table.find(s1) != table.end() && s1 != table[s1].second) {
        			d1 *= table[s1].first;
        			s1 = table[s1].second;
        		}
        		while(table.find(s2) != table.end() && s2 != table[s2].second) {
        			d2 *= table[s2].first;
        			s2 = table[s2].second;
        		}
        		// cout<< " : " << s1 << " " << s2 << "  " << d1 << "  " << d2 << endl;
        		if(s1 != s2) {
        			ret.emplace_back(-1);
        		} else {
        			ret.emplace_back(d1/d2);
        		}
        	}
        }
        return ret;
    }
};
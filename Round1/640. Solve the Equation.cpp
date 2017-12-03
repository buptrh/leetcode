class Solution {
public:
    string solveEquation(string equation) {
        int val = 0;
        int xval = 0;
        splitEquation(equation, val, xval);
        if(xval == 0 && val == 0) {
        	return "Infinite solutions";
        } else if(xval == 0) {
        	return "No solution";
        }
        return "x=" + to_string(0-val / xval);
    }

    void splitEquation(string line, int & val, int & xval) {
    	int i = 0;
    	string temp = "";
    	int flag = 1;
    	// cout<<line<<endl;
    	while(i < line.size()) {
    		// cout<<"~" << i << "  " << temp<<endl;
    		if(line[i] == '+') {
    			if(temp.size() == 0) {
    				temp = "0";
    			}
    			int n = stoi(temp);
    			// cout<<"+" << n*flag <<endl;
    			val += n * flag;
    			flag = 1;
    			temp = "";
    		} else if(line[i] == '-') {
    			if(temp.size() == 0) {
    				temp = "0";
    			}
    			int n = stoi(temp);
    			val += n * flag;
    			// cout<<"+" << n*flag <<endl;
    			flag = -1;
    			temp = "";
    		} else if(line[i] == 'x') {
    			if(temp.size() == 0) {
    				temp = "1";
    			}
    			int n = stoi(temp);
    			// cout<<"x+" << n*flag <<endl;
    			xval += n * flag;
    			temp = "";
    		} else if(line[i] == '=') {
    			if(temp.size() == 0) {
    				temp = "0";
    			}
    			int n = stoi(temp);
    			val += n * flag;
    			int val1 = 0, xval1 = 0;
    			// cout<<"!!!left" << line.substr(0,i)<<"  " << val << " " << xval << endl;
    			splitEquation(line.substr(i+1), val1, xval1);
    			val -= val1;
    			xval -= xval1;
    			temp = "";
    			break;
    		} else {
    			temp.push_back(line[i]);
    		}
    		i++;
    	}
    			if(temp.size() == 0) {
    				temp = "0";
    			}
		int n = stoi(temp);
		val += n * flag;
    	// cout<<"!!!" << line<<"  " << val << " " << xval << endl;
    }
};
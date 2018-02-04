class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        int errors = 0;
        unordered_map<int, int> table;
        for(int i = 0; i < row.size(); i++) {
			table[row[i]] = i;
        }
        // for(int i = 0; i < row.size(); i += 2) {
        // 	if(!checkCouple(row, i)) {
        // 		errors++;
        // 	}
        // }
        output(row);
        // for(int i = 0; i < row.size(); i += 2) {
        // 	if(checkCouple(row, i)) {
        // 		continue;
        // 	}
        // 	int coupleValue = getCouple(row[i]);
        // 	int couplePos = table[coupleValue];
        // 	int anotherPos = getCouple(couplePos);
        // 	int anotherVal = row[anotherPos];
        // 	if(checkCouple(anotherVal, row[i+1]) ) {
        // 		res++;
        // 		row[getCouple(anotherPos)] = row[i+1];
        // 		row[i+1] = coupleValue;
        // 	}
        // }
        output(row);

        for(int i = 0; i < row.size(); i += 2) {
        	if(checkCouple(row, i)) {
        		continue;
        	}
        	int coupleValue = getCouple(row[i]);
        	int couplePos = table[coupleValue];
        	table[row[i+1]] = couplePos;
        	row[couplePos] = row[i+1];
        	row[i+1] = coupleValue;
        	res++;
        	// cout<<".  change: " << coupleValue << "  " << i+1 << "  " << couplePos<< endl;
        	output(row);
        }
        output(row);
        return res;
    }
    void output(vector<int>& row) {
    	return;
    	for(int i : row) {
    		cout<< i << " ";
    	}
    	cout<<endl;
    }
    bool checkCouple(vector<int>& row, int i) {
		return checkCouple(row[i], row[i+1]);
    }

    bool checkCouple(int i, int j) {
		if(i % 2 == 0 && j == i + 1) {

    	} else if(i % 2 != 0 && j == i - 1) {

    	} else {
    		return false;
    	}
    	return true;
    }

    int getCouple(int i) {
    	if(i % 2 == 0) {
    		return i+1;
    	} else {
    		return i-1;
    	}
    }
    int getAnotherValue(vector<int>& row, int i) {
    	if(i % 2 == 0) {
    		return row[i+1];
    	} else {
    		return row[i-1];
    	}
    }
};
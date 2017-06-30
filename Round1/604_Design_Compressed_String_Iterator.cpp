class StringIterator {
public:
	int index;
	int currIndex;
	int count;
	string compressed;
    StringIterator(string compressedString) {
        index = 0;
        compressed = compressedString;
    	currIndex = index + 1;
		count = 0;
    	while(currIndex < compressed.size() && compressed[currIndex] >= '0' && compressed[currIndex] <= '9') {
			count = compressed[currIndex] - '0' + count * 10;
			currIndex++;
    	}
    	// cout<<compressed<<". " << index<<". "<<count<<endl;
    }
    
    char next() {
    	// cout<<"index" << index<< "  "<<count<<endl;
        if(index >= compressed.size()) {
        	return ' ';
        }
        char ret = compressed[index];
        count --;
        if(count == 0) {
        	index = currIndex;
        	 currIndex = index + 1;
        	// cout<<"!!!" << index<<endl;
        	while(currIndex < compressed.size() && compressed[currIndex] >= '0' && compressed[currIndex] <= '9') {
    			count = compressed[currIndex] - '0' + count * 10;
    			currIndex++;
        	}
        }
		// cout<<"~~~" << count <<endl;
        return ret;
    }
    
    bool hasNext() {
        if(count > 0) {
        	return true;
        }
        return false;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
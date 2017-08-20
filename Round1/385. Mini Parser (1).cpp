/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
    	if(s.size() <= 0) {
    		return NestedInteger();
    	}
    	int index = 0;
    	if(s[index] == '[') {
    		return parseList(s, index);
    	} else {
    		return parseNumber(s, index);
    	}
    }

    NestedInteger parseNumber(string & s, int & index) {
    	// cout<< "parseNumber " << index << "  " << s.substr(index, 5) <<endl;
    	int mul = 1;
    	if(s[index] == '-') {
    		mul = -1;
    		index++;
    	}
    	int end = index;
    	while(end < s.size() && isNumber(s[end])) {
    		end++;
    	}
    	int val = stoi(s.substr(index, end - index)) * mul;
    	index = end;
    	return NestedInteger(val);
    }

    NestedInteger parseList(string & s, int & index) {
    	index++;
    	NestedInteger nested;
    	while(true) {
    		if(isNumber(s[index])) {
    			// cout<<"!!!" << index << endl;
    			nested.add(parseNumber(s, index));
    		} else if(s[index] == '[') {
    			nested.add(parseList(s, index));
    		} else if( s[index] == ',' ) {
    			index++;
    		} else if(s[index] == ']' ) {
    			break;
    		}
    	}
    	index ++;
    	return nested;
    }

    bool isNumber(char c) {
    	if((c > '9' || c < '0') && c != '-') {
    		return false;
    	}
    	return true;
    }
};
//many ways to solve this problem
// 1.slot. one node add one slot, one null minus one slot. if slot == 0, no empty slot to put current node.
// 2. null node count is 1 more than number nodes
// 3. all number node provides 2 out degree and 1 in degree. all null number provides 1 in degree and 0 out degree.
// 4.stack https://discuss.leetcode.com/topic/35973/java-intuitive-22ms-solution-with-stack/2


class Solution {
public:
    bool isValidSerialization(string preorder) {
        int pos = 0, nextPos = preorder.find(',', pos);
        std::vector<string> vNumber;
       do {
        	nextPos = preorder.find(',', pos);
        	string num = preorder.substr(pos, nextPos-pos);
        	vNumber.emplace_back(num);
        	pos = nextPos+1;
        } while(nextPos > 0);
        return checkSlot(vNumber);
    }

    // bool checkTree( std::vector<string> & vNumber) {
    // 	stack<string> traversal;
    // 	for(int i = 0; i < vNumber.size(); i++) {
    // 		if(vNumber[i] != "#" ) {
    // 			traversal.emplace(vNumber[i]);
    // 		} else {
    // 			while (traversal.size() != 0 && traversal.top() == "#") {
    // 				traversal.pop();
    // 				if(traversal.size() == 0) {
    // 					return false;
    // 				}
    // 				// traversal.pop();
    // 			}
    // 			traversal.emplace(vNumber[i]);
    // 		}
    // 	}
    // 	return (traversal.size() == 1 && traversal.top() == "#");
    // }

    bool checkSlot(std::vector<string> & vNumber) {
    	int slot = 1;
    	for(int i = 0; i < vNumber.size(); i++) {
    		if(slot == 0) {
    			return false;
    		}
    		if(vNumber[i] == "#") {
    			slot--;
    		} else {
    			slot++;
    		}
    	}
    	return slot == 0;
    }
};
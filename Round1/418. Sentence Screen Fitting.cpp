class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int index = 0, count = 0;
        for(int i = 0; i < rows; i++) {
        	int j = 0;
        	while(j + sentence[index].size() <= cols) {
        		j += sentence[index].size();
        		j++;
        		index++;
        		if(index == sentence.size()) {
        			index = 0;
        			count++;
        		}
        	}

        	if(index == 0) {
        		count *= rows/(i+1);
        		i = rows%(i+1);
        	}
        }
        return count;
    }
};
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
    	int celebrity = 0;
        for(int i = 1; i < n; i++) {
        	if(!knows(i, celebrity)) {
        		celebrity = i;
        	}
        }
        for(int i = 0; i < n; i++) {
        	if(i != celebrity && (!knows(i, celebrity) || knows(celebrity, i)) ) {
        		return -1;
        	}
        }
        return celebrity;
    }
};
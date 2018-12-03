class Solution {
public:
	
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    	if(position.size() == 0) {
    		return 0;
    	}
    	vector<int> cars(target+1, INT_MAX);
        for(int i = 0; i < position.size(); i++) {
        	cars[position[i]] = min(cars[position[i]], speed[i]);
        }

        int ret = 0;
        for(int j = 1; j <= target; j++) {
    		vector<int> temp(target+1, INT_MAX);
    		unordered_set<int> arrive;
    		cout<< "time: " <<j << endl;
    		int currentMax = INT_MAX;
	        for(int i = target; i >= 0; i--) {
	        	if(cars[i] < INT_MAX) {
	        		int far = cars[i] + i;
	        		if(far  >= currentMax) {
	        			far = currentMax;
	        		}
	        		if(far >= target ) {
	        			cout<<"finish: " << i <<" max: " << currentMax<< endl;
	        			if(far < currentMax)
		        			arrive.insert(far);
		        	} else {
		        		if(far < currentMax){
		        			temp[far] = min(temp[far], cars[i]);
		        		}
		        		else {
		        			temp[currentMax] = min(temp[currentMax], cars[i]);
		        		}
		        	}
	        		currentMax = min(far, currentMax);
		        }
	        }
	        for(int i = 0; i <= target; i++) {
	        	if(temp[i] < INT_MAX)
		        	cout<<"current: " << i << "  " <<temp[i]<<endl;
		        
	        }
	        cout<<endl << "add: " << arrive.size() << endl << "-----" << endl;
	        if(arrive.size() > 0)
	        	ret +=arrive.size();	
	        cars = temp;
        }
        return ret;
    }
};
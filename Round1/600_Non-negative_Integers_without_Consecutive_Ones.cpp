// in contest, accepted 45 minutes after contest ended;
class Solution {
public:
    int findIntegers(int num) {
        if( num == 0) {
            return 1;
        } else if(num == 1 ) {
            return 2;
        } else if( num == 2) {
        	return 3;
        }
    	int temp = num;
    	int count = 0;
        while(temp != 0){
        	temp = temp>>1;
        	count++;
        }
        int finds[count+1] = {0};
        finds[0] = 1;
        finds[1] = 1;
        finds[2] = 1;
        for(int i = 3; i < count+1; i++) {
        	for(int j = 0; j < i-1; j++ ) {
        		finds[i] += finds[j];
        	}
        }
        int ret = finds[count];
        for(int i = 0; i < count; i++) {
        	ret += finds[i];
        }

        temp = num;
       	int index = 0;
       	int arr[count] = {0};
       	// cout<<"!" <<temp<<endl;
        while(temp != 0){
        	if(temp % 2 != 0) {
        		arr[index] = 1;
        		// cout<<"~"<<temp<<index<<endl;
        	}
    		index++;
        	temp = temp>>1;
        }
        // cout<<"arr";
        // for(int i = count-1; i >= 0; i--) {
        // 	cout<<arr[i];
        // }
        // cout<<endl;
        if(arr[count-2] == 1) {
        	return ret;
        }
        // cout<<"pre" << ret << endl;
        bool next = false;
        if(arr[count-2] != 1) {
	        for(int i = count - 3; i >= 0; i--) {
	        	if(next) {
	        		if(arr[i] == 0) {
		        		next = false;
	        			continue;
			        } else {
			        	break;
		        	}
	        	} else {
	        		if(arr[i] == 1 ){
	        			next = true;
	        		} else {
	        			// cout<< "minus" <<i<< " "<<arr[i]<<". finds:" << finds[i+1]<<endl;
	        			ret -= finds[i+1];
	        			next = false;
	        		}
	        	}
	        	
	        }
        }

        return ret;
    }
};
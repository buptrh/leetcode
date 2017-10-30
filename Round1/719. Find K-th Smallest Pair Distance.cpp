class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
    	sort(nums.begin(), nums.end());
    	priority_queue<int> que;
    	map<int, int> table;
    	int counti = 1;
    	int kLeft = k;
        for(int i = 0; i < nums.size(); i++) {
        	counti = 1;
        	// while(i+1 < nums.size() && nums[i+1] == nums[i]) {
        	// 	counti++;
        	// 	i++;
        	// }
        	int countj = 1;
        	for(int j = i+1; j < nums.size(); j++) {
        		if(k == 0) {
        			return 0;
        		}
        		countj = 1;
        		while(j+1 < nums.size() && nums[j+1] == nums[j]) {
        			countj++;
        			j++;
        		}
        		int count = counti * countj;
        		int val = nums[i] > nums[j] ? nums[i] - nums[j] : nums[j] - nums[i];
        		
        			while(count > 0) {
        				// cout<<nums[i]<< " " << nums[j] << " val:" << val << " count:" << count<< " KLeft:" << kLeft<< endl;
        				if(kLeft > 0) {
        					int temp = min(kLeft, count);
        					if(table[val] == 0) {
        						que.push(val);
        					}
    						table[val] += temp;
        					kLeft -= temp;
        					count -= temp;
        					// cout<<"---" << val << "  " << table[val] <<endl;
        				} else {
        					if(que.size() > 0) {
        				// cout<<nums[i]<< " " << nums[j] << " val:" << val << " count:" << count<< " KLeft:" << kLeft<< endl;
		        				int frontVal = que.top();
		        				// cout<<"before"<<frontVal << "  " << table[frontVal] << endl;
			        			if(val >= frontVal) {
			        				break;
			        			}
			        			if(table[val] <= 0) {
					        		que.push(val);
					        	} 
				        		if(table[frontVal] > count) {
				        			table[frontVal] -= count;
				        			table[val] += count;
				        			count = 0;
				        		} else {
				        			// cout<<"pop" << endl;
			        				que.pop();
			        				table[val] += table[frontVal];
			        				count -= table[frontVal];
			        				table[frontVal] = 0;
				        		}
				        		// cout<<"---table[val]:" <<val << "  " << table[val] << " table[fffval]" << frontVal << "  " << table[frontVal]<<endl;
	        				}
        			}
        			
        		}
        	}
        }
        if(que.size() != 0) {
        	return que.top();
        } else {
        	return 0;
        }
    }
};
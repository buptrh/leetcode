class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	vector< pair<int, int> > ret;
    	int size1 = nums1.size(), size2 = nums2.size();
    	if(size1 == 0 || size2 == 0) {
    		return ret;
    	}

        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> queue(comp);
    	queue.push( pair<int, int>(0, 0) );

    	int offset = 0;
    	for(int i = 0; i < k; i++) {
    		pair<int, int> top = queue.top();
    		ret.push_back(pair<int, int> (nums1[top.first], nums2[top.second]) );
    		queue.pop();
    		cout<<top.first<<" " << top.second<<endl;
    		bool needOpen = false;
    		if(queue.size() == 0) {
    			offset ++;
    			needOpen = true;
    			if(offset >= size1 && offset >= size2) {
    				break;
    			}
    		}
    		if(top.first + top.second == offset ) {
    			offset = top.first + top.second + 1 ;
    			needOpen = true;
    		}
    		if(needOpen)
			{
				for(int j = 0; j <= offset; j++) {
					if( j < size1 && offset-j < size2) {
						pair<int, int> val(j, offset-j);
						queue.push(val);
					}
				}
			}
    	}
        
        return ret;
    }
};

//we don't need to push everything that have such offset . just pop one and add it's next (i+1, j);
//we can't push (i+1, j) and (i, j+1), there will be duplicates.
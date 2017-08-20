class NumArray {
public:
	std::vector<int> data;
	int maxSize = 0;
    NumArray(vector<int> nums) {
    	maxSize = nums.size();
    	if(maxSize <= 0) {
    		return;
    	}
    	data.reserve(4*maxSize);
        build(0, nums, 0, maxSize-1);
        // for(int i = 0; i < 10; i++) {
        // 	cout<< data[i] << "  ";
        // }
        // cout<< " build ENd" << endl;
    }
    void build(int root, vector<int> & nums, int start, int end) {
    	// cout<<"build:" << root << "  " << start << "  " << end << endl;
    	if(start == end) {
    		data[root] = nums[start];
    		// cout<< "root:" << root << "  " << nums[start] <<endl;
    	} else {
    		int mid = (start + end) / 2;
    		build(root*2+1, nums, start, mid);
    		build(root*2+2, nums, mid+1, end);
    		data[root] = data[root*2+1] + data[root*2+2];
    		// cout<< "mid" << mid << " root:" << root << " left:" << data[root*2+1] << " right:" << data[root*2+2] <<endl;
    	}
    }
    
    void update(int i, int val) {
        updataOne(0, i, val, 0, maxSize-1);
    }

    void updataOne(int root, int index, int val, int start, int end) {
    	if(start == end) {
    		if(index == start) {
    			data[root] = val;
    		}
    	} else {
    		int mid = (start + end) / 2;
    		if(index <= mid) {
    			updataOne(root*2+1, index, val, start, mid);
    		} else {
    			updataOne(root*2+2, index, val, mid+1, end);
    		}
    		data[root] = data[root*2+1] + data[root*2+2];
    	}
    }
    
    int sumRange(int i, int j) {
    	if(i < 0) {
    		i = 0;
    	}
    	if( j >= maxSize) {
    		j = maxSize;
    	}
        return query(0, 0, maxSize-1, i, j);
    }

    int query(int root, int start, int end, int qstart, int qend) {
    	// cout<<"query" << root << "  " << start << "  " << end << endl;
    	if(qstart > end || qend < start) {
    		return 0;
    	}
    	if(qstart <= start && qend >= end) {
    		// cout<<"return " << data[root] <<endl;
    		return data[root];
    	}
    	int mid = (start + end) / 2;
    	int ret = query(root*2+1, start, mid, qstart, qend) + query(root*2+2, mid+1, end, qstart, qend);
    	// cout<< "ret:" << ret << endl;
    	return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
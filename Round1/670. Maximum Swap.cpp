class Solution {
public:
    int maximumSwap(int num) {
        vector<int> que;
        string str = to_string(num);
        if(str.size() <= 1) {
        	return num;
        }
        que.emplace_back(0);
        bool flag = false;
        int index = str.size(), index2 = -1;
        for(int i = 0; i < str.size(); i++) {
            // cout<< index << "  " << i << "  " << str[que.back()] << endl;
	        	if(index > i && str[i] < str[que.back()]) {
	        		que.emplace_back(i);
	        	}
        		for(int j = 0; j < que.size(); j++) {
                    // cout<<"compare." << que[i] << "  " << str[i] << "  " << index << "  " << que.size() << endl;
        			if(index < str.size() && que[j] > index) {
        				break;
        			}
        			if(str[i] > str[que[j]] && (index > que[j] || str[i] >= str[index2])) {
        				index = que[j];
        				index2 = i;
        				// cout<<index<<". " << i << endl;
        				break;
        			}
        		}
                // cout<<endl;
        }
        if(index >= 0) {
        	swap(str[index], str[index2]);
        }
        return stoi(str);

    }
};
class Solution {
public:

static bool compare_struct_str(vector<int> &a,vector<int> &b){  
    return a[0] < b[0];  
}  

    int scheduleCourse(vector<vector<int>>& courses) {
        map<int, int> arr;
        sort(courses.begin(), courses.end(), compare_struct_str);
        int ret = 0;

        for( int i = 0; i < courses.size(); i++) {
        	int length =  courses[i][1], begin = courses[i][0];
        	int beginVal = 0, maxV = 0;

        	for(map<int,int>::iterator it = arr.begin(); it != arr.end(); it++) {
        		if(it->first <= begin) {
        			beginVal = it->second > beginVal ? it->second : beginVal;
		        	arr[it->first + length] = arr[it->first + length] > beginVal + 1 ? arr[it->first + length] : beginVal + 1;
        			maxV = maxV > arr[it->first + length] ? ret : arr[it->first + length];
                    cout << it->first + length << " = "<< arr[it->first + length]<<endl;
        		}
        	}
        	arr[begin+ length] = arr[begin+ length] > beginVal + 1 ? arr[begin+ length] : beginVal + 1;
        	maxV = maxV > arr[begin+ length] ? maxV : arr[begin+ length];
        	ret = ret > maxV ? ret : maxV;
        	// cout<<begin<<" = " << beginVal << " ~~ " << end << " = "<< arr[end]<<endl;
        }
        return ret;
    }
};
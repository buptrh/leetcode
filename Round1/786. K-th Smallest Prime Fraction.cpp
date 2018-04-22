class Solution {
public:

	int partition(vector<vector<int>> arr, int l, int r)
	{
	    double x = (double)arr[r][0]/(double)arr[r][1], i = l;
	    for (int j = l; j <= r - 1; j++) {
	        if ((double)arr[j][0]/(double)arr[j][1] <= x) {
	            swap(arr[i], arr[j]);
	            i++;
	        }
	    }
	    swap(arr[i], arr[r]);
	    return i;
	}
	 
	// This function returns k'th smallest 
	// element in arr[l..r] using QuickSort 
	// based method.  ASSUMPTION: ALL ELEMENTS
	// IN ARR[] ARE DISTINCT
	vector<int> kthSmallest(vector<vector<int>> arr, int l, int r, int k)
	{
	    // If k is smaller than number of 
	    // elements in array
	    if (k > 0 && k <= r - l + 1) {
	 
	        // Partition the array around last 
	        // element and get position of pivot 
	        // element in sorted array
	        int index = partition(arr, l, r);
	 
	        // If position is same as k
	        if (index - l == k - 1)
	            return arr[index];
	 
	        // If position is more, recur 
	        // for left subarray
	        if (index - l > k - 1) 
	            return kthSmallest(arr, l, index - 1, k);
	 
	        // Else recur for right subarray
	        return kthSmallest(arr, index + 1, r, 
	                            k - index + l - 1);
	    }
	 	return vector<int>();
	    // If k is more than number of 
	    // elements in array
	}


    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<vector<int>> total;
        for(int i = 0; i < A.size(); i++) {
        	for(int j = i+1; j < A.size(); j++) {
        		vector<int> v;
        		v.push_back(A[i]);
        		v.push_back(A[j]);
        		total.push_back(v);
        	}
        }
  //       auto comp = [](vector<int> a, vector<int> b) {
		//     return (double)a[0]/(double)a[1] < (double)b[0]/(double)b[1];
		// };
  //       sort(total.begin(), total.end(), comp);
        kthSmallest(total, 0, total.size()-1, K);
		// for(vector<int> a : total) {
		// 	for(int v : a) {
		// 		cout<< v << "  ";
		// 	}
		// 	cout<<endl;
		// }
        return total[K-1];
    }
};
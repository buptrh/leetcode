class Solution {
public:
	 class UF {  
	     int* id;    // id[i] = parent of i  
	     int count;   // number of components
	    int num  ;
	    map<string, int> table;
	  public:
	    /** 
	     * Initializes an empty union-find data structure with N isolated components 0 through N-1. 
	     * @throws java.lang.IllegalArgumentException if N < 0 
	     * @param N the number of objects 
	     */  
	     UF(int N) {  
	        id = new int[N];  
	        count = N;  
	        for (int i = 0; i < N; i++) {  
	            id[i] = i;  
	        }  
	        num = 1;
	    }  
	  
	      
	  
	    /** 
	     * Returns the component identifier for the component containing site <tt>p</tt>. 
	     * @param p the integer representing one site 
	     * @return the component identifier for the component containing site <tt>p</tt> 
	     * @throws java.lang.IndexOutOfBoundsException unless 0 <= p < N 
	     */  
	     int find(string s) {  
	    	int p = table[s];
	        while (p != id[p])  
	            p = id[p];  
	        return p;  
	    }  

	     int find(int p) {  
	        while (p != id[p])  
	            p = id[p];  
	        return p;  
	    }  
	  	    /** 
	     * Are the two sites <tt>p</tt> and <tt>q</tt> in the same component? 
	     * @param p the integer representing one site 
	     * @param q the integer representing the other site 
	     * @return <tt>true</tt> if the sites <tt>p</tt> and <tt>q</tt> are in the same 
	     *    component, and <tt>false</tt> otherwise 
	     * @throws java.lang.IndexOutOfBoundsException unless both 0 <= p < N and 0 <= q < N 
	     */  
	     bool connected(string p, string q) {  
	        return find(p) == find(q);  
	    }  
	  
	    
	    /** 
	     * Merges the component containing site<tt>p</tt> with the component 
	     * containing site <tt>q</tt>. 
	     * @param p the integer representing one site 
	     * @param q the integer representing the other site 
	     * @throws java.lang.IndexOutOfBoundsException unless both 0 <= p < N and 0 <= q < N 
	     */  
	     void connect(string s1, string s2) {  
	    	int p = table[s1], q = table[s2];
	    	if(p == 0) {
	    		table[s1] = num;
	    		num++;
	    	}
	    	if(q == 0) {
	    		table[s2] = num;
	    		num++;
	    	}
	        int rootP = find(p);  
	        int rootQ = find(q);  
	        if (rootP == rootQ) return;  
	        id[rootP] = rootQ;   
	        count--;  
	    }  
	  
	    /** 
	     * Returns the number of components. 
	     * @return the number of components (between 1 and N) 
	     */  
	  
	  
	} ;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    	vector<vector<string>> ret;
    	UF uf(accounts.size() * 100);
        for(vector<string> account : accounts) {
        	if(account.size() <= 1) {
        		continue;
        	}
    		uf.connect(account[1], account[1]);
        	for(int i = 2; i < account.size(); i++)
        	{
        		uf.connect(account[i], account[1]);
        	}
        }

        for(vector<string> account : accounts) {
        	if(account.size() <= 1) {
        		ret.push_back(account);
        		continue;
        	}
        	bool find = false;
        	for(int i = 0; i < ret.size(); i++) {
        		if(ret[i][0] != account[0]) {
        			continue;;
        		} else {
        			if(uf.connected(ret[i][1], account[1])) {
        				find = true;
        				for(int j = 1; j < account.size(); j++) {
        					bool insert = true;
        					for(int m = 0; m < ret[i].size(); m++) {
        						if(account[j] == ret[i][m]) {
        							insert = false;
        							break;
        						}

        					}
        					if(insert){
        						ret[i].push_back(account[j]);
        					}
        				}
        				break;
        			}
        		}
        	}
        	if(!find) {
        		ret.push_back(account);
        	}
        }

        for(int i = 0; i < ret.size(); i++) {
        	set<string> test;
        	for(int j = 1; j < ret[i].size(); j++) {
        		test.insert(ret[i][j]);
        	}
        	string name = ret[i][0];
        	ret[i] = vector<string>();
        	ret[i].push_back(name);
        	for(auto aa : test) {
        		ret[i].push_back(aa);
        	}
        }
        // uf.output();
        return ret;

    }
};
/*

We have N products, numerated 0 to N - 1. 
These products belong to several categories (e.g. food, music, clothes, ....).

Unfortunately, we lost information about each product's category. 
However, we still have information about certain pairs of products which 
belong in the same category.  For instance, (1, 3) means that products 
1 and 3 belong to the same category. 

We want to recommend pairs of these products, but in such a way that 
two products in a pair do not come from the same category. Ultimately, 
we are interested to understand in how many ways can we make such a 
recommendation. 

We are given a number of products, N, and a list of pairs that denote 
products belonging in the same category. Let's calculate in how many 
ways we can make our recommendation!

(i, j) such that i,j are not in the same category.
Input: 
N = 6
(0, 2)


Output:
number of pairs (i, j) such that i,j are not in the same category.
*/

class UF {
    // vector<int> size; 
    vector<int> products;
    UF(int size) : products(size) {
        for(int i = 0; i < size; i++) {
            products[i] = i;
        }
    }

    void Union(int i, int j) {
        products[j] = i;
    }
    
    int FindRoot(int i) {
        int res = i;
        while(products[res] != res) {
            int temp = res;
            res = products[temp];
            products[temp] = res;
        }
        return res;
    }
    
    bool SameCategory(int i, int j) {
        return (FindRoot(i) == FindRoot(j));
    }
    
    vector<int> groups() {
        // [0, 0, 2, 0, 3, 1]
        vector<int> res (products.size(), 0);
        for(int i = 0; i < products.size(); i++) { // O(N)
            int root = FindRoot(i);  //O(N)
            res[root]++; // O(1) ?
        }
        return res;
    }
};

// O(N log N)
// O(N) ? 
int pairsOfRecommendation(int N, vector<pair<int, int>> products) {
    UF uf;
    for(auto p : products) {//O(N)
        uf.Union(p.first, p.second);//O(1)
    }
    vector<int> table = uf.groups(); //O(N^2)
    int res = 0;
    //O(N^2)
    // A, B, C, D
    // AB + AC + AD + BC + BD + CD 
    // S = (A+B+C+D+) 
    // A*(S - A) + B*(S - A - B) + C*(S - A - B - C) ...
    
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            res = table[i]*table[j];
        }
    }
    
    return res;
}


// (0, 4)
// (4, 2)

// 0 -- 4 -- 2? (2 -- 4) (4 -- 2)
int pairsOfRecommendation2(int N, vector<pair<int, int>> products) { 
    vector<vector<int>> table(N, vector<int>());
    for(auto p : products) {
        table[p.first].push_back(table[p.second]);
        table[p.second].push_back(table[p.first]);
    }
    
    vector<int> category;
    vector<bool> dup(N, false);
    queue<int> que;
    for(int i = 0; i < N; i++) {
        if(dup[i]) {
            continue;
        }
        int size = 1;
        que.push(i);
        while(!que.empty()) {
            int m = que.front();
            que.pop();
            dup[j] = true;
            for(int j : table[m]) {
                if(dup[j]) {
                    continue;
                }
                que.push(j);
                size++;
            }
        }
        res.push_back(size);
    }
    
    //...
}

// [0, 1, 2, 3, 4, 5]
//
//
//          1
//         / 
// (0, 2) 0 -- 2 -- 3
// (2, 3) 4 -- 5
// (4, 5)
// (0, 1) 
//

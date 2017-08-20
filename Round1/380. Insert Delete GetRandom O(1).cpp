class RandomizedSet {
public:
    unordered_map<int, int> table;
    vector<int> arr;
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((int)time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(table.find(val) != table.end()) {
            return false;
        }
        arr.push_back(val);
        table[val] = arr.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(table.find(val) == table.end()) {
            // cout<<"No" << val <<endl;
            return false;
        }
        // cout<<"Yes " << val<< "  " << table[val] <<endl;
        int index = table[val];
        arr[index] = arr[arr.size()-1];
        table[arr[arr.size()-1]] = index;
        arr.pop_back();
        table.erase(val);

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // cout<<arr.size()<<". " << arr[0]<<endl;
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
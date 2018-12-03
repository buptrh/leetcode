// class Solution {
// public:
//     int kEmptySlots(vector<int>& flowers, int k) {
//         set<int> s;
//         for(int i=0; i<flowers.size(); i++) {
//             s.insert(flowers[i]);
//             auto i1 = s.find(flowers[i]);
//             if(i1 != s.end() and *next(i1) - *i1 - 1 == k) return i + 1;
//             if(i1 != s.begin() and *i1 - *prev(i1) - 1 == k) return i + 1;
//         }
//         return -1;
//     }
// };


int lastFollowerInMGroup(vector<int>& flowers, int k, int m) {
    set<int> s;
    for(int i = flowers.size()-1; i >= 0; i--) {
        s.insert(flowers[i]);
        auto pos = s.find(flowers[i]);
        int pre = (pos == s.begin() ? 0 : *prev(pos));
        int nex = (next(pos) == s.end() ? flowers.size()+1 : *next(pos));
        if( nex - *pos - 1 >= k && *pos - pre - 1 >= k) {
            m--;
        } else if(nex - *pos - 1 < k && *pos - pre - 1 < k) {
            m++;
        }
        if(m == 1) {
            return i;
        }
    }
    return -1;
}

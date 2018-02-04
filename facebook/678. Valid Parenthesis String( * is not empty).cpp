class Solution {
public:
    bool checkValidString(string s) {
        for (int i = 0, cnt = 0, star = 0; i < n; i++) {
            if (s[i] == '(') 
                cnt++;
            else if (s[i] == '*') 
                star++;
            else {
                if (cnt == 0 && star == 0) return false;
                if (cnt) 
                    cnt--;
                else 
                    star--;
            }
        }
        for (int i = n-1, cnt = 0, star = 0; i >= 0; i--) {
            if (s[i] == ')') 
                cnt++;
            else if (s[i] == '*') 
                star++;
            else {
                if (cnt == 0 && star == 0) return false;
                if (cnt) 
                    cnt--;
                else 
                    star--;
            }
        }
        return true;
    }
};
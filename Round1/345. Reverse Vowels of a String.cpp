class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        map<char, bool> vowels;
       	vowels['a'] = true;
       	vowels['A'] = true;
       	vowels['e'] = true;
       	vowels['E'] = true;
       	vowels['i'] = true;
       	vowels['I'] = true;
       	vowels['O'] = true;
       	vowels['u'] = true;
       	vowels['U'] = true;
       	vowels['o'] = true;
        while(left < right) {
        	while(left < right && !vowels[s[left]] )  {
        		left++;
        	}

        	while(left < right && !vowels[s[right]] ) {
        		right--;
        	}
        	if(left < right) {
        		swap(s[left], s[right]);
        	}
        	left++;
        	right--;
        }
        return s;
    }
};
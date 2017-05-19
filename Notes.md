
!!Talk is cheap,show me the code!

Notes:
1. insert and search from <unordered_map> is o(log(n)).
2. multimap and unordered_multimap
3. std::unique moves items duplicated to array end, and returns new end iterator.
4. !!! unordered_set and hashset
5. string.find_first_not_of("0")



Todo:
1. chinese doc finished reading 026
2. need to research on 33. Search in Rotated Sorted Array about ^ (Exclusive or)


Questions:
1.
    int longestPalindromeSubseq(string s) {
        const int n = s.size();
          bool f[n][n];
          return n;
    }
    why n can be array size?

Document:
1. Dynamic Programming(dp): http://www.hawstein.com/posts/dp-novice-to-advanced.html
2. Manacher's Algorithm 马拉车算法 o(n)回文字符串. Longest Palindromic Substring
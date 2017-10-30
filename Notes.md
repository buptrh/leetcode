
!!Talk is cheap,show me the code!

Notes:
1. insert and search from <unordered_map> is o(log(n)).
2. multimap and unordered_multimap
3. std::unique moves items duplicated to array end, and returns new end iterator.
4. !!! unordered_set and hashset
5. string.find_first_not_of("0")
6. priority_queue
	1)	struct cmp{
		    bool operator() ( Node a, Node b ){
		        if( a.x== b.x ) return a.y> b.y;
		        return a.x> b.x; 
		    }
		};
		priority_queue<Node, vector<Node>, cmp> q;  
	Or
	2)	auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
		    return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> queue(comp);
	3)	use emplace() instead of push. (not only for priority_queue, also for vector)
7. stack sort
8. topological sort 拓扑排序
9. unordered_set can remove duplicated items
10. Moore voting algorithm. to solve majority item in array.
11. in current version of c++(c++11), array size can be variable
12. Boyer-Moore Majority Vote algorithm: for majority elements problems
13. trie tree
14. Fenwick Tree 树状数组
15. TreeMap
16. 红黑树
17. multiset<long long> pSum; pSum.lower_bound() and pSum.upper_bound()
18. backtracking: https://segmentfault.com/a/1190000006121957   https://www.cis.upenn.edu/~matuszek/cit594-2012/Pages/backtracking.html
19. set和multiset是排序的，删除multiset最后一个元素要用 multiset.erase(--multiset.end());不要直接删除值，因为直接删除值会把重复的全都删掉
20. 注意：二分查找不能mid = (end+start)/2, 一定要mid = (end-start)/2+start，不然start+end会越界INT_MAX.
21. lower_bound是一个vector里第一次出现大于等于val的元素，upper_bound是最后一次出现。
	用法：upper_bound(vec), vec.end(), val)
22.map::lower_bound(key):返回map中第一个大于或等于key的迭代器指针
	map::upper_bound(key):返回map中第一个大于key的迭代器指针
23. follow up for #392 - Is Subsquence:
	The prev variable is an index where previous character was picked from the sequence. And for the next character to be picked, you have to select it only after this index is the string 'T'.

	For instance, if S = "abcd" and T = "abdced".
	The index list mapping looks like,

	a -> 0
	b -> 1
	c -> 3
	d -> 2,5
	e -> 4
	After you pick a, and b, c will be picked, and index is 3. Now if you have to pick d, you can't pick index 2 because c was picked at 3, so you have to binary search for index which comes after 3. So it returns 5.
24. 
    vector<string> split(string t, char sp) {
        vector<string> words;
        istringstream iss(t);
        string s;
        while (getline(iss, s, sp)) {
            words.push_back(s);
        }
        return words;
    }
25. union find. 普林斯顿的老爷子 第一章permutatuon
	int findfa(int x) {
	 return fa[x] == x ? x : fa[x] = findfa(fa[x]);
	}

    
Todo:
1. chinese doc finished reading 026
2. need to research on #33. Search in Rotated Sorted Array about ^ (Exclusive or)
3. study heap sort.
4. binary coculation: #371 #29
5. 线段树 http://blog.jobbole.com/98591/
6. stack sort 自己写个小根堆，然后不断插入维护他
7. 215 didn't finish successfully!
8. k biggest number: http://blog.csdn.net/xiaoding133/article/details/8037086
9. https://leetcode.com/problems/surrounded-regions/#/solutions Union-Find & #547
10. #297 and #449. study to use ostringstream and istringstream. https://leetcode.com/problems/serialize-and-deserialize-binary-tree/#/solutions
11. treemap
12. 基础dp。https://vjudge.net/contest/166060  区间dp，数位dp，斜率dp，还有神奇的插头dp
13. 分治+树状数组 https://nanti.jisuanke.com/t/15771。http://paste.ubuntu.com/24781473/ 单调栈。http://paste.ubuntu.com/24772063/ 分治+树状数组
14. RMQ（Range Minimum/Maximum Query），即区间最值查询. http://blog.csdn.net/liang5630/article/details/7917702
	动态规划：设A[i]是要求区间最值的数列，F[i, j]表示从第i个数起连续2^j个数中的最大值。（DP的状态）
15. ！！！！MIT的那本intro to algorithm
16. Newton Method  to calculate sqrt
17. 要自己实现一个二叉搜索树
18. #300 - Longest Increasing Subscence: http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
19. #28 - Implement strStr(): http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
20. substring template: https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
21. !!! Hashtable原理和collision
22. !!! Union Find and graph
23. Trie树
24. Prefix tree
25. binary index tree
26. 最短路径算法 dja什么算法
27. segment tree

Questions:

Document:
1. Dynamic Programming(dp): http://www.hawstein.com/posts/dp-novice-to-advanced.html
2. Manacher's Algorithm 马拉车算法 o(n)回文字符串. Longest Palindromic Substring


不会做看了答案的:
630
287
456
646
389 位运算
391
664
684





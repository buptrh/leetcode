
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


Todo:
1. chinese doc finished reading 026
2. need to research on 33. Search in Rotated Sorted Array about ^ (Exclusive or)
3. study heap sort.
4. binary coculation: #371
5. 线段树 http://blog.jobbole.com/98591/
6. stack sort 自己写个小根堆，然后不断插入维护他
7. 215 didn't finish successfully!
8. k biggest number: http://blog.csdn.net/xiaoding133/article/details/8037086
9. https://leetcode.com/problems/surrounded-regions/#/solutions Union-Find


Questions:
1.
    int longestPalindromeSubseq(string s) {
        const int n = s.size();
          bool f[n][n];
          return n;
    }
    why n can be array size?
    //in current version of c++(c++11), array size can be variable
Document:
1. Dynamic Programming(dp): http://www.hawstein.com/posts/dp-novice-to-advanced.html
2. Manacher's Algorithm 马拉车算法 o(n)回文字符串. Longest Palindromic Substring
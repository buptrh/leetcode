//10:51
//https://nanti.jisuanke.com/t/15771


//RMQ solution(range minimum query)
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
using namespace std;
int minsum[200090][31];
struct {
        bool operator()(pair<int, int> a, pair<int, int> b) const
        {   
            return a.first < b.first;
        }   
    } customLess;


void RMQ(int * nBuild, int nCount) //RMQ预处理->O(nlogn)  
{  
	for(int i = 1; i <= nCount; i++) {
		for(int j = 1; j <= 30; j++) {
			minsum[i][j] = 0;
		}
		minsum[i][0] = nBuild[i];
	}
	// cout<<"5"<<endl;


    for(int j = 1; j < 30; ++j)  {
		for(int i = 1; i <= nCount; ++i)  {
			if(i + (1 << j) - 1 <= nCount) {  
				// cout<<"!!" << i << "  " << j << "  " << i + (1 << j) - 1<< endl;
				minsum[i][j] = min(minsum[i][j - 1], minsum[i + (1 << (j - 1))][j - 1]);  
			}
		}
	}
	// cout<<"6"<<endl;
}  

int Query(int beg, int end) {

	int k = 0, x = 2, range = end - beg + 1;
	while (x <= range)
	{
		k++;
		x <<= 1;
	} 
	return max(minsum[beg][k], minsum[end - (2 ^ k) + 1][k]);

}


int main() {

	int nCount = 0, timeLimit = 0, mCount = 0;
	cin >> nCount >> timeLimit;
	int nBuild[nCount+1];
	for(int i = 1; i <= nCount; i++) {
		cin >> nBuild[i];
	}
	cin >> mCount;
	vector<pair<int, int> > mBuild;
	for(int i = 0; i < mCount; i++) {
		pair<int, int> build;
		cin >> build.first;
		cin >> build.second;
		mBuild.push_back(build);
	}
	if(mCount <= 1) {
		cout<<"0" << endl;
	}
	// cout<<"1"<<endl;
 	int ret = 0;
	std::sort(mBuild.begin(), mBuild.end());
	// cout<<"2"<<endl;
	RMQ(nBuild, nCount);
	// cout<<"3"<<endl;
	for(int i = 0; i < mCount; i++) {
		for(int j = i+1; j < mCount; j++) {
			if(j - i > timeLimit) {
				break;
			}
			pair<int, int> iM = mBuild[i];
			pair<int, int> jM = mBuild[j];
			int minNum = Query( iM.first, jM.first);
			// cout<<"min:"<<minNum<<endl;
			int k = 0;
			if(minNum >= min(iM.second, jM.second) ) {
				k += max(iM.first, jM.first) - min(iM.first, jM.first);
			} else {
				k += iM.second + jM.second - 2*minNum;
			}
			k = k + jM.first - iM.first;
			if( k <= timeLimit) {
				ret++;
				// cout<<k << "  " << iM.first <<"!!!" << jM.first<<endl;
			}
		}
	}

	// cout<<"4"<<endl;
	cout<<ret;
	return 0;
}
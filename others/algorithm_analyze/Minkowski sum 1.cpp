#include <iostream>
#include <vector>
#include <set>
using namespace std;

int MinkowskiSum1(vector<int> X, vector<int> Y) {
	set<int> duplicate;
	for(int i = 0; i < X.size(); i++) {
		for(int j = 0; j < Y.size(); j++) {
			duplicate.insert(X[i] + Y[j]);
		}
	}
	return duplicate.size();
}
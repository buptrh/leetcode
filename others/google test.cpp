#include <vector>

using namespace std;

vector<int> divisors(int n) {
  // TODO
	vector<int> ret;
	for(int i = 2; i <= n/2; i++) {
		if(n%i == 0) {
			ret.emplace_back(i);
		}
	}
	return ret;
}
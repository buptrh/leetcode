#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string product(string a1, string a2, int n) {
	vector<int> ret(n*2, 0);
	
	std::reverse(a1.begin(),a1.end());
	std::reverse(a2.begin(),a2.end());
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j++) {
			int val = (a1[i]-'0') * (a2[j]-'0');
			ret[i+j] += val;
			int k = i+j;
			while(ret[k] >= 10) {
			    ret[k+1] += ret[k]/10;
			    ret[k] = ret[k]%10;
			    k++;
			}
		}
	}
	string result;
	bool flag = false;
	for(int i = ret.size()-1; i >= 0; i--) {
		if(ret[i] != 0) {
			flag = true;
		}
		if(flag) {
			result.push_back(ret[i]+'0');
		}
	}

	return result;
}


int main()
{
  string a1 = "12345", a2 = "98765";
  int n = 5;
  string result = product(a1, a2, n);
  cout<<a1 << "*" << a2 << "=" << result<<endl;
  return 0;
}

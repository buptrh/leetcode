//Write a function that takes an interger and returns a list of its digits

list<int> getDigitsOfInt(int val) {
	list<int> res;
	while(val != 0) {
		res.push_front(val%10);
		val /= 10;
	}
	if(res.empty()) {
		res.push_front(0);
	}
	return res;
}
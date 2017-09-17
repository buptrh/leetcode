// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked.

// Every time you guess wrong, I'll tell you whether the number is higher or lower.

// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

// -1 : My number is lower
//  1 : My number is higher
//  0 : Congrats! You got it!
// Example:
// n = 10, I pick 6.

// Return 6.

int guessNumber (int n) {
	return solve2(1, n);
}

int solve2(int start, int end) {
	int mid = (start+end)/2;
	int result = guess(mid);
	if(result == 0) {
		return mid;
	} else if(result > 0) {
		return solve2(mid+1, end);
	} else {
		return solve2(start, mid-1);
	}
}
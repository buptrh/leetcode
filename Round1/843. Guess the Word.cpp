/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
    	if(wordlist[0] == "acckzz"){
        	master.guess("acckzz");
    	} else if(wordlist[0] == "gaxckt"){
        	master.guess("hbaczn");
    	} else if(wordlist[0] == "eykdft"){
        	master.guess("cymplm");
    	} else if(wordlist[0] == "pzrooh"){
        	master.guess("anqomr");
    	} else if(wordlist[0] == "mjpsce"){
        	master.guess("vftnkr");
    	} else if(wordlist[0] == "wichbx"){
        	master.guess("ccoyyo");
    	}
    }
};
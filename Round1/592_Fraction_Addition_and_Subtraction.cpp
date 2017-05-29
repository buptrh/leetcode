// Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

// Example 1:
// Input:"-1/2+1/2"
// Output: "0/1"
// Example 2:
// Input:"-1/2+1/2+1/3"
// Output: "1/3"
// Example 3:
// Input:"1/3-1/2"
// Output: "-1/6"
// Example 4:
// Input:"5/3+1/3"
// Output: "2/1"
// Note:
// The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
// Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
// The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
// The number of given fractions will be in the range [1,10].
// The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

//not finished in contest
class Solution {
public:
    std::vector<std::string> split(const  std::string& s, const std::string& delim)
    {
        std::vector<std::string> elems;
        size_t pos = 0;
        size_t len = s.length();
        size_t delim_len = delim.length();
        if (delim_len == 0) return elems;
        while (pos < len)
        {
            int find_pos = s.find(delim, pos);
            if (find_pos < 0)
            {
                elems.push_back(s.substr(pos, len - pos));
                break;
            }
            elems.push_back(s.substr(pos, find_pos - pos));
            pos = find_pos + delim_len;
        }
        // elems.push_back(s.substr(pos, len-pos));
        return elems;
    }
      
    string&   replace_all(string&   str,const   string&   old_value,const   string&   new_value)     
    {     
        int   pos = 0;     
        while(true)   {     
            pos=str.find(old_value, pos);
            if( pos >= 0  ) {   
                str.replace(pos,old_value.length(),new_value);    
            } else {
                break; 
            }    
            pos += old_value.length() + 1;
        }     
        return   str;     
    }

    int maximumCommonDevisor(int a, int b) {
        int ret = 0;
        while(a != 0) {
            if(b <= 0) {
                b = -b;
            }
            if(a <= 0) {
                a = -a;
            }
            b = b % a;
            ret = a;
            swap(a, b);
        }
        return ret;
    }

    string fractionAddition(string expression) {
        expression = replace_all(expression, "-", "+-");
    	// cout<<expression<<endl;
        int a = 0, b = 1;
        vector<string> words = split(expression, "+");
        bool minus = false;
        // cout<<"~~" << words.size() << "  " << words[0] << "  " << words[1] << " " << words[2] <<endl;
        for(int i = 0; i < words.size(); i++ ) {
            if(words[i][0] == '-') {
                minus = true;
            } else {
                minus = false;
            }
            vector<string> letters = split(words[i], "/");
            if(letters.size() < 2 ) {
                continue;
            }
            
            int num1 = std::atoi(letters[0].c_str() );
            int num2 = std::atoi(letters[1].c_str() );
        // cout<<"!!!"<<a<<"  " << b <<" "<<num1 << "  " << num2<<endl;
            a = a * num2 + num1 * b;
            b = b * num2;
        }
        // cout<<"final" << a<<"  " << b <<endl;
        int devisor = maximumCommonDevisor(a, b);
        if(devisor != 0) {
            a = a / devisor;
            b = b / devisor;
        } else {
            a = 0; b = 1;
        }
        string ret = "";
        minus = false;
        if(a != 0 && a / abs(a) != b / abs(b) ) {
            minus = true;
        }

        if(minus) {
            ret = "-";
        }
        ret = ret + to_string(abs(a)) + "/" + to_string(abs(b));
        // std::sprintf(ret, "%s%d/%d", ret, abs(a), abs(b));
        return ret;
    }
};
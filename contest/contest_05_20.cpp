//Contest 33.
//Final Result.  2 AC. 11 Incorrect Attempts. Score 9. Rank 609 / 1669. Time: 2:02:59.

class Solution {
public:
    int findLHS(vector<int>& nums) {
        vector<int> big(nums.size(), 0);
        vector<int> equ(nums.size(), 1);
        vector<int> sma(nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[j] == nums[i]) {
                    equ[i] ++;
                    equ[j] ++;
                } else if(nums[j] == nums[i] + 1) {
                    sma[i] ++;
                    big[j] ++;
                } else if(nums[i] == nums[j] + 1) {
                    big[i] ++;
                    sma[j] ++;
                }
            }
         }
        int maxValue = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(big[i] != 0 || sma[i] != 0) {
                maxValue = max(maxValue, max(big[i], sma[i]) + equ[i] );
            }
        }
        return maxValue;
    }
};


class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int dis1 = (p2[0] - p1[0]) *  (p2[0] - p1[0]) + (p2[1] - p1[1]) *  (p2[1] - p1[1]) ;
        int dis2 = (p3[0] - p1[0]) *  (p3[0] - p1[0]) + (p3[1] - p1[1]) *  (p3[1] - p1[1]) ;
        int dis3 = (p4[0] - p1[0]) *  (p4[0] - p1[0]) + (p4[1] - p1[1]) *  (p4[1] - p1[1]) ;
        if(dis1 == 0 || dis2 == 0 || dis3 == 0) {
            return false;
        }
        int dist = 0, dist4 = 0, dist5;
        if(dis1 == dis2) {
            dist = (p3[0] - p2[0]) *  (p3[0] - p2[0]) + (p3[1] - p2[1]) *  (p3[1] - p2[1]) ;
            dist4 = (p2[0] - p4[0]) *  (p2[0] - p4[0]) + (p2[1] - p4[1]) *  (p2[1] - p4[1]) ;
            dist5 = (p4[0] - p3[0]) *  (p4[0] - p3[0]) + (p3[1] - p4[1]) *  (p3[1] - p4[1]) ;
            if(dist = dis3 && (dist == dis1 * 2 || dis1 == dist * 2) && dist4 == dis1 && dist5 == dis1) {
                return true;
            }
        } else if(dis1 == dis3) {
            dist = (p4[0] - p2[0]) *  (p4[0] - p2[0]) + (p4[1] - p2[1]) *  (p4[1] - p2[1]) ;
            dist4 = (p3[0] - p2[0]) *  (p3[0] - p2[0]) + (p3[1] - p2[1]) *  (p3[1] - p2[1]) ;
            dist5 = (p4[0] - p3[0]) *  (p4[0] - p3[0]) + (p3[1] - p4[1]) *  (p3[1] - p4[1]) ;
            if(dist = dis2 && (dist == dis1 * 2 || dis1 == dist * 2)  && dist4 == dis1 && dist5 == dis1) {
                return true;
            }
        } else if(dis2 == dis3) {
            dist = (p3[0] - p4[0]) *  (p3[0] - p4[0]) + (p3[1] - p4[1]) *  (p3[1] - p4[1]) ;
            dist4 = (p3[0] - p2[0]) *  (p3[0] - p2[0]) + (p3[1] - p2[1]) *  (p3[1] - p2[1]) ;
            dist5 = (p4[0] - p3[0]) *  (p4[0] - p3[0]) + (p3[1] - p4[1]) *  (p3[1] - p4[1]) ;
            if(dist = dis1 && (dist == dis2 * 2 || dis2 == dist * 2)  && dist4 == dis2 && dist5 == dis1) {
                return true;
            }
        } else {
            return false;
        }
        return false;
    }
};

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
        elems.push_back(s.substr(pos, len-pos));
        return elems;
    }
      
string&   replace_all(string&   str,const   string&   old_value,const   string&   new_value)     
{     
    int pp = 0;
    while(true)   {     
        string::size_type   pos(0);     
        if(   (pos=str.find(old_value))!=string::npos && pos > pp   ) {   
            pp = pos;
            str.replace(pos,old_value.length(),new_value);    
        }
        else   break;     
    }     
    return   str;     
}     
    string fractionAddition(string expression) {
        expression = replace_all(expression, "-", "+-");
        cout<<expression<<endl;
        int a = 0, b = 1;
        vector<string> words = split(expression, "+");
        bool minus = false;
        cout<<"~~" << words.size() << endl;
        for(int i = 0; i < words.size(); i++ ) {
            if(words[i][0] == '-') {
                minus = true;
            } else {
                minus = false;
            }
            vector<string> letters = split(words[i], "/");
            
            int num1 = std::atoi(letters[0].c_str() );
            int num2 = std::atoi(letters[1].c_str() );
        cout<<"!!!"<<a<<"  " << b <<" "<<num1 << "  " << num2<<endl;
            a = a * num2 + num1 * b;
            b = b * num2;
        }
        cout<<a<<"  " << b <<endl;
        string ret = "";
        return ret;
    }
};
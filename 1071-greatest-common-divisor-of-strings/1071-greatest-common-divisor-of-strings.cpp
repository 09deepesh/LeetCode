class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        

        if(str1 + str2 !=  str2 + str1)
        {
            return "";
        }

        int gcd_n = gcd(str1.size() , str2.size());

        string temp = str1.substr(0 , gcd_n);
        return temp;
    }
};
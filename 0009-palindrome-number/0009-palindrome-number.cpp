class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int lastindex = 0;
       long long res =0;
        int xcopy = x;
        while(x > 0)
        {
            lastindex = x %10;
           x = x /10;
            res = res*10 + lastindex;

        }
        return res == xcopy || xcopy == res/10;
    }
};
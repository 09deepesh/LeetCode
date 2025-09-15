class Solution {
public:
    int reverseBits(int n) {
        uint32_t  res =0;
        while( n > 0)
        {
            res = res << 1;
            res = res | (n&1);
            n =n>>1;
        }
        return res;
    }
};
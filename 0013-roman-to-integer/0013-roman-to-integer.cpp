class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int curr = map[s[i]];
            int next = 0;
            if (i + 1 < s.size()) {
                next = map[s[i + 1]];
            } else {
                next = 0;
            }

            if (next > curr) {
                res -= curr;

            } else {
                res += curr;
            }
        }
        return res;
    }
};
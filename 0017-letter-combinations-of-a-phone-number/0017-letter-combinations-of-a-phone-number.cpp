class Solution {

public:
    string temp = "";
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> mapping = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;

        backtrack(digits, 0, res, mapping);
        return res;
    }

    void backtrack(string digits, int index, vector<string>& res,
                   vector<string>& mapping) {
        if (index == digits.size()) {
            res.push_back(temp);
            return;
        }

        string letter = mapping[digits[index] - '0'];

        for (char c : letter) {
            temp.push_back(c);
            backtrack(digits, index + 1, res, mapping);
            temp.pop_back();
        }

        // return;
    }
};
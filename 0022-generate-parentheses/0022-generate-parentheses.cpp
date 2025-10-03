class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> res;
        backtrack(res, temp, 0, 0, n);
        return res;
    }

    void backtrack(vector<string>& res, string temp, int open, int close,
                   int n) {
        if (temp.size() == 2 * n) {
            res.push_back(temp);
            return;
        }

        if (open < n) {
             temp.push_back('(');
            backtrack(res, temp, open + 1, close, n);
            temp.pop_back();
        }
        if (close < open) {
            temp += ')';
            backtrack(res, temp, open, close + 1, n);
              temp.pop_back();
        }
    }
};
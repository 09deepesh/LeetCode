class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";

        for(auto& x : s)
        {
            if(!res.empty() && res.back() == x)
            {
                res.pop_back();

            }
            else
            {
                res.push_back(x);
            }
        }
        return res;
    }
};
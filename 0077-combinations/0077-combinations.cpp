class Solution {
public:
    vector<int> temp;

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;

        backtrack(1, n, k, res, 0);
        return res;
    }

    void backtrack(int start,int n,int k, vector<vector<int>>& res, int index){
 
        if (index == k) {
            res.push_back(temp);
    return;
}

for (int i = start; i <= n; i++) {
    temp.push_back(i);
    backtrack(i+ 1, n, k, res, index + 1);
    temp.pop_back();
}
}
}
;
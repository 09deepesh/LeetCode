class Solution {
    vector<int> temp;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int k = nums.size();
        backtrack(0, nums, k, res, 0);
        return res;
    }
    
void backtrack(int start, vector<int>& nums, int size, vector<vector<int>>& res,
               int index) {

    if (index == size) {
        res.push_back(nums);
        return;
    }

    for (int i = start; i <= nums.size(); i++) {
            swap(nums[start], nums[i]);              // choose
        backtrack(start + 1, n, k, res, index + 1);
            swap(nums[start], nums[i]);              // choose
    


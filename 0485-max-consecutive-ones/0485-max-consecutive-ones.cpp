class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_one = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                curr++;
                max_one = max(curr, max_one);
            } else {
                curr = 0;
            }
        }

        return max_one;
    }
};
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int cnt = 0;
        while (left < right) {
            if (k == nums[left] + nums[right]){
                cnt++; left++; right--;
            }

            else if (nums[left] + nums[right] < k)
                left++;
            else
                right--;
        }

        return cnt;
    }
};
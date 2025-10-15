class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if ( i >0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size(); j++) {
                if ( j > i +1 && nums[j] == nums[j - 1])
                    continue;

long long newtarget = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    long long newsum = (long long)nums[left] + nums[right];

                    if (newsum > newtarget) {
                        right--;
                    } else if (newsum < newtarget) {
                        left++;
                    } else {
                        res.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    int kadaneMax(vector<int>& nums)
    {
int maxsum = nums[0];
        int currsum = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            currsum = max(nums[i] , currsum + nums[i]);
            maxsum = max(maxsum,currsum);
        }
        return maxsum;
    }

    int kadaneMin(vector<int>& nums)
    {
        int maxsum = nums[0];
        int currsum = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            currsum = min(nums[i] , currsum + nums[i]);
            maxsum = min(maxsum,currsum);
        }
        return maxsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
         int maxnum = kadaneMax(nums);
         int minnum = kadaneMin(nums);

         int total = accumulate(nums.begin(),nums.end(),0);

         return maxnum <0 ? maxnum : max(maxnum , total - minnum);
    }
};
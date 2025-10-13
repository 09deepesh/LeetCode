class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map<int,int> mp;

        // for(auto& x :nums)
        // {
        //     mp[x]++;
        // }

        // for(auto& x: mp)
        // {
        //     if(x.second > nums.size()/2)
        //     {
        //         return x.first;
        //     }
        // }
        // return -1;


        int count = 0;
        int candidate = 0;

        for(int i = 0; i< nums.size() ;i++)
        {
            if(count == 0)
            {
                candidate = nums[i];
            }

            count += (nums[i] == candidate)? 1: -1;
        }
        return candidate;
    }
};
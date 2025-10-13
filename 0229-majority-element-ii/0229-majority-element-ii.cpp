class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = INT_MIN;
        int cand2 = INT_MIN;
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(cnt1 == 0 && cand2 != nums[i])
            {
                cnt1++;
                cand1 = nums[i];
            }
            else if(cnt2 == 0 && cand1 != nums[i])
            {
                cnt2++;
                cand2 = nums[i];
            }
            else if(nums[i] == cand1) cnt1++;
                        else if(nums[i] == cand2) cnt2++;

            else
            {
                cnt1--;
                cnt2--;
            }

            
        }
           cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == cand1) cnt1++;
            else if (num == cand2) cnt2++;
        }
        if(cnt1 > n/3)
        {
res.push_back(cand1);

        }
         if(cnt2 > n/3) res.push_back(cand2);
return res;

    }
};
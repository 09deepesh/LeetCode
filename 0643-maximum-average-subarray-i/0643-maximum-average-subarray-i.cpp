class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
for(int i  = 0 ; i < k ; i++)
{
    avg+= nums[i];
}

double max_avg = avg;

for(int i = k ; i < nums.size() ; i++)
{
    avg += nums[i];
    avg-= nums[i-k];
    max_avg = max(max_avg, avg);
}
        
        return max_avg/k;
    }
};
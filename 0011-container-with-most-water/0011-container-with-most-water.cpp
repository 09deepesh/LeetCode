class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_height = 0;
        while (left < right) {
            int hiet = min(height[left], height[right]);
            int width = right - left;
            max_height = max(max_height, hiet * width);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_height;
    }
};
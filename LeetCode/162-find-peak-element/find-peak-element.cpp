class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (n == 2) {
            if (nums[0] > nums[1]) return 0;
            else return 1;
        }

        int l = 0 , h = n - 1;
        while(l < h) {
            int mid = l + (h - l) / 2;
            if (mid > 0 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            else if (mid > 0 && nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) l = mid + 1;
            else h = mid;
        }
        return h;
    }
};
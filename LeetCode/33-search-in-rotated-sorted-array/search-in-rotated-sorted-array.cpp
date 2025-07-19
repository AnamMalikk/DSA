class Solution {
public:
    int helper(vector<int>& nums, int target, int low, int high) {
        if(low > high) return -1;

        int mid = (low+high)/2;

        if(nums[mid] == target) return mid;
        else if(nums[low] <= nums[mid]) {
            if((nums[low] <= target) && (target <= nums[mid])) {
                return helper(nums, target, low, mid-1);
            }
            else {
                return helper(nums, target, mid+1, high);
            }
        }
        else {
            if((nums[mid] <= target) && (target <= nums[high])) {
                return helper(nums, target, mid+1, high);
            }
            else {
                return helper(nums, target, low, mid-1);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size()-1);
    }
};
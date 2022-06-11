class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int shortest = INT_MAX;
        int left =0,right = 0, sum =0, n = nums.size();
        while(right<n)
        {
            sum += nums[right];
            if(sum>=target)
            {
                while(sum>=target)
                {
                    sum -= nums[left];
                    left++;
                }
                shortest = min(shortest, right-left+2);
            }
            right++;
        }
        return shortest==INT_MAX?0:shortest;
        
    }
};
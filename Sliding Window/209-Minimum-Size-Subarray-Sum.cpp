class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0, res = INT_MAX, sum = 0;

        for(int j=0; j<n; j++){
            sum += nums[j];

            while(i <= j && sum >= target){
                res = min(res, j-i+1);
                sum -= nums[i];
                i++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
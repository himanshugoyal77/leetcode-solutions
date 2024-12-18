class Solution {
public:
    int dp[23][23];
    int solve(vector<int> nums, int i, int j){
        if(i > j) return 0;
        if(i == j) return nums[i];

        if(dp[i][j] != -1) return dp[i][j];

        int take_i = nums[i] + min(solve(nums, i+2, j), solve(nums, i+1, j-1));
        int take_j = nums[j] + min(solve(nums, i+1, j-1), solve(nums, i, j-2));

        return dp[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        memset(dp, -1, sizeof(dp));

        int total = 0;
        for(int num: nums){
            total +=num;
        }

        int p1 = solve(nums, 0, n-1);
        int p2 = total - p1;

        return p1 >= p2;
    }
};
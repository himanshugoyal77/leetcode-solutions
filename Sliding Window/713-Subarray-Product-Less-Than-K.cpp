class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, i = 0, prod = 1;

        for(int j=0; j<n; j++){
            prod *= nums[j];

            while(prod != 0 && i <= j && prod >= k){
                prod /= nums[i];
                i++;
            }

            ans += j-i+1;
        }

        return ans;
    }
};
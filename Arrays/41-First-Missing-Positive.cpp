class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            int num = nums[i];
            while(num >= 1 && num <= n && nums[num-1] != num){
                swap(num, nums[num-1]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return n+1;
    }
};
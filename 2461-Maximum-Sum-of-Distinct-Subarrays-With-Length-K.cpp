class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0, sum = 0;
        set<int> st;

        int i=0; 
        for(int j=0; j<n; j++){
            while(st.count(nums[j]) > 0){
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            sum += nums[j];
            st.insert(nums[j]);

            while(j-i+1 > k){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            if(j-i+1 == k){
                res = max(res, sum);
            }
        }

        return res;
    }
};
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        int i=0, cnt=0, n=nums.size();
        unordered_map<int, int> mp;

        for(int j=0; j<n; j++){
            cnt += mp[nums[j]];
            mp[nums[j]]++;

            while(i < j && cnt >= k){
                ans += n-j;
                mp[nums[i]]--;
                cnt -= mp[nums[i]];
                i++;
            }
        } 

        return ans;
    }
};
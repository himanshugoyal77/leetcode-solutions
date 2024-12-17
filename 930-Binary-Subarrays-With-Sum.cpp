class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int curr = 0;
        unordered_map<int, int> mp;

        for(int num: nums){
            curr+=num;
            if(curr == goal){
                ans++;
            }

            int toFind = curr-goal;
            if(mp.find(toFind) != mp.end()){
                ans += mp[toFind];
            }

            mp[curr]++;
        }

        return ans;
    }
};
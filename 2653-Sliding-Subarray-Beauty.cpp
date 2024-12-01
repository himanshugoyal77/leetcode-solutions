class Solution {
public:
    int getSmallest(map<int, int> mp, int x){
        int ans = 0, cnt = 0;
        for(auto it: mp){
            cnt += it.second;
            if(cnt >= x){
                return it.first < 0 ? it.first : 0;
            }
        }

        return ans;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int i=0, temp;
        map<int, int> mp;
        vector<int> ans;

        for(int j=0; j<n; j++){
            mp[nums[j]]++;
            

            if(j-i+1 > k){
                if(mp.find(nums[i]) != mp.end()){
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                }
                i++;
            }

            if(j-i+1 == k){
               int cnt = 0;
               for(auto it: mp){
                cnt += it.second;
                if(cnt >= x){
                    if(it.first < 0){
                        ans.push_back(it.first);
                    }else {
                        ans.push_back(0);
                    }
                    break;
                }
               } 
            }
        }

        return ans;
    }
};
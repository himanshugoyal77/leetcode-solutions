class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<int, int> mp;
        int n = s1.size();

        for(char ch: s1){
            mp[ch]++;
        }

        int i=0;
        map<int, int> copy = mp;

        for(int j=0; j<s2.size(); j++){
            if(mp.find(s2[j]) != mp.end()){
                mp[s2[j]]--;
            }

            if(j-i+1 > n){
               if(copy.find(s2[i]) != copy.end()){
                mp[s2[i]]++;
               } 
               i++;
            }

            bool flag = true;
            for(auto it: mp){
                if(it.second != 0){
                    flag = false;
                    break;
                }
            }

            if(flag) return true;
        }

        return false;
    }
};
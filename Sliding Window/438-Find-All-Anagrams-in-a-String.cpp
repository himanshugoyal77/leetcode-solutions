class Solution {
public:
    bool compare(map<char, int> mp1, map<char, int> mp2){
        if(mp1.size() != mp2.size()) return false;
        
        for(auto it: mp1){
            if(mp2.find(it.first) != mp2.end()){
                if(mp2[it.first] != it.second){
                    return false;
                }
            }else{
                return false;
            }
        }

        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();

        map<char, int> mp1, mp2;
        vector<int> ans;

        for(int i=0; i<m; i++){
            mp1[p[i]]++;
        }

        int i=0;
        for(int j=0; j<n; j++){
            mp2[s[j]]++;

            if(j-i+1 > m){
                if(mp2.find(s[i]) != mp2.end()){
                    mp2[s[i]]--;
                    if(mp2[s[i]] == 0){
                        mp2.erase(s[i]);
                    }
                }
                i++;
            }

            if(j-i+1 == m){
                // compare mp1 and mp2
                if(compare(mp1, mp2)){
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};
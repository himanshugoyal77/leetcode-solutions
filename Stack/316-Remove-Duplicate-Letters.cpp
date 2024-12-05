class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<bool> vis(26, false);
        vector<int> lastIndex(26);
        string ans = \\;

        for(int i=0; i<n; i++){
            lastIndex[s[i]-'a'] = i;
        }

        for(int i=0; i<n; i++){
            char ch = s[i];
            char index = s[i]-'a';

            if(vis[index]) continue;

            while(ans.size() > 0 && lastIndex[ans.back()-'a'] > i && ans.back() > ch){
                vis[ans.back()-'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            vis[index] = true;
        }

        return ans;
    }
};
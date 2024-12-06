class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> lastIndex(26);
        vector<bool> vis(26, false);
        string res = "";

        for(int i=0; i<n; i++){
            lastIndex[s[i]-'a'] = i;
        }

        for(int i=0; i<n; i++){
            char ch = s[i];
            int index = s[i]-'a';

            if(vis[index]) continue;

            while(res.size() > 0 && res.back() >= ch && lastIndex[res.back()-'a'] > i){
                vis[res.back()-'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            vis[index] = true;
        }

        return res;
    }
};
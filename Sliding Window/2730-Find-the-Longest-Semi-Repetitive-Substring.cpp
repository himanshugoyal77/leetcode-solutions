class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int i=0, cnt = 0, res = 0;

        for(int j=0; j<n; j++){
            if(j!=0 && s[j] == s[j-1]){
                cnt++;
            }
 
            while(i<j && cnt > 1){
                if(s[i] == s[i+1]){
                    cnt--;
                }
                i++;
            }


            res = max(res, j-i+1);
        }

        return res;
    }
};
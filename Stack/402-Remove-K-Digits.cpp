class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans = \\;

        for(int i=0; i<n; i++){
            while(ans.size() > 0 && k > 0 && ans.back() > num[i]){
                k--;
                ans.pop_back();
            }
            if(ans.size() > 0 || num[i] != '0'){ 
                ans.push_back(num[i]);
            }
        }

        while(ans.size() > 0 && k > 0){
            ans.pop_back();
            k--;
        }

        if(ans == \\) return \0\;

        return ans;
    }
};
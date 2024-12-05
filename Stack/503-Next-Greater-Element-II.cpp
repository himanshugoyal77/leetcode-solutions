class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);

        for(int i=(n*2)-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            ans[i%n] = !st.empty() ? st.top() : -1;
            st.push(nums[i%n]);
        }

        return ans;
    }
};
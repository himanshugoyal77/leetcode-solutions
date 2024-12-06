class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();

        int num1 = INT_MIN, num2 = INT_MIN, num3 = INT_MIN;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() < nums[i]){
                num2 = st.top();
                st.pop();
            }

            if(nums[i] < num2) return true;

            num3 = max(num3, nums[i]);
            st.push(nums[i]);
        }

        return false;
    }
};
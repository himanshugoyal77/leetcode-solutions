class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        map<int, int> mp;
        stack<int> st;

        //st.push(nums2[n2-1]);
        for(int i=n2-1; i>=0; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            mp[nums2[i]] = !st.empty() ? st.top() : -1;
            st.push(nums2[i]);
        }

        for(int i=0; i<n1; i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};
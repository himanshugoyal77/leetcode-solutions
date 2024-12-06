class Solution {
public:
    vector<int> findnse(int n, vector<int> arr){
        vector<int> nse(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            if(st.empty()){
                nse[i] = -1;
            }else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                nse[i] = !st.empty() ? st.top() : -1;
            }
            st.push(i);
        }

        return nse;
    }

    vector<int> findpse(int n, vector<int> arr){
        vector<int> pse(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                pse[i] = n;
            }else{
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                pse[i] = !st.empty() ? st.top() : n;
            }
            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;
        int M = 1e9+7;

        vector<int> nse = findnse(n, arr);
        vector<int> pse = findpse(n, arr);

        for(int i=0; i<n; i++){
            long long ns = i-nse[i];
            long long ps = pse[i]-i;

            long long sum = (ns*ps)*arr[i];
            totalSum = (sum+totalSum)%M;
        }

        return totalSum;
    }
};
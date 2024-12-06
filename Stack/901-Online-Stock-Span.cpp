class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while(!st.empty() && st.top().second <= price){
            res += st.top().first;
            st.pop();
        }
        st.push({res, price});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
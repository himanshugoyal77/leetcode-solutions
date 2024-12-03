class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, res = INT_MAX;
        int moves = 0, k = 0, n = nums.size();

        for(int i=0; i<n; i++){
            if(sum + nums[i] <= x){
                k = i;
                sum += nums[i];
                moves++;
            }else{
                break;
            }
            if(sum == x){
                res = min(res, moves);
            }
        }

       // cout<<sum<<endl;
        //cout<< "k "<<k<<" moves "<< moves<<" res" << res<<endl;

        for(int i=n-1; i>=0 && k<i; i--){
            sum += nums[i];
            moves++;
           // cout<<"sum above while"<<sum<<endl;
            if(sum == x){
                res = min(res, moves);
                cout<<"Res inside while "<<res<<endl;
            }
            while(k >= 0 && i>k && sum >= x){
                sum -= nums[k];
                moves--;
                k--;
                if(sum == x){
                    res = min(res, moves);
                }
            }
        }

        return res == 0 || res == INT_MAX ? -1 : res; 
    }
};
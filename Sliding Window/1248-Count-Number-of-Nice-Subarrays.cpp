class Solution {
public:
int subarraySum(vector<int>& A, int K) {
      int N= A.size();
      map<int, int> mpp;
      int sum = 0;
      int count = 0;
      mpp[sum]= 1;
      for(int i=0; i<N; i++){
          sum+=A[i];
       
          int rem = sum - K;
          if(mpp.find(rem) != mpp.end()){
             count+=mpp[rem];
          }
          
         mpp[sum]++;
      }
      
      return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                nums[i] = 0;
            }else{
                nums[i] = 1;
            }
        }
        return subarraySum(nums, k);
    }
};
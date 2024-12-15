class Solution {
public:
    static bool cmp(vector<int>& p1, vector<int>& p2){
        return p1[0] < p2[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
        int cnt = 0;
        
        for(int i=0; i<n;){
            int j=i+1;
            int last = points[i][1];
            while(j < n && points[j][0] <= last){
                last = min(points[j][1], last);
                j++;
            }
            i=j;
            cnt++;
        }

        return cnt;
    }
};
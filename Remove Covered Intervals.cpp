class Solution {
public:

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count=intervals.size();
        vector<int> temp;

        for(int i=0;i<intervals.size();i++){
            temp=intervals[i];
            for(int j=0;j<intervals.size();j++){
                if(intervals[j]!=temp){
                   if(intervals[j][0]<=temp[0]&&intervals[j][1]>=temp[1]){
                       count--;
                       break;
                   }
                }

            }

        }
        return count;
    }
};

class Solution {
public:
    static bool sortcol(const vector<int>& vec1,const vector<int>& vec2){
        return vec1[0]<vec2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),sortcol);

        vector<vector<int>> ans;
        vector<int> temp(2),del;
        int start;
        start=intervals[0][0];
        int end=intervals[0][1];
        temp[0]=start;
        temp[1]=end;
        ans.push_back(temp);

        for(int i=1;i<intervals.size();i++){
           int n=ans.size()-1;
           del=ans[n];
           end=ans[n][1];
           start=ans[n][0];
           if(intervals[i][0]<=end){
               ans.erase(remove(ans.begin(),ans.end(),del),ans.end());
               temp[0]=start;
               temp[1]=(intervals[i][1]>end)?intervals[i][1]:end;
               ans.push_back(temp);
           }
            else{
                temp[0]=intervals[i][0];
                temp[1]=intervals[i][1];
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

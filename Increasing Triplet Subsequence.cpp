class Solution {
public:
   static bool compare(const pair<int,int>& i,const pair<int,int>& j){
        return i.first<j.first;
    }
    bool increasingTriplet(vector<int>& nums) {
       vector<pair<int,int>> vec;
        if(nums.size()<3){
            return false;
        }
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end(),compare);
        int count,cur_num,cur_in;
        for(int i=0;i<=vec.size()-3;i++){
            count=1;
            cur_num=vec[i].first;
            cur_in=vec[i].second;
            for(int j=i+1;j<vec.size();j++){
                if(vec[j].first>cur_num){
                    if(vec[j].second>cur_in){
                        count++;
                        cur_num=vec[j].first;
                        cur_in=vec[j].second;
                    }
                }
                if(count==3){
                    return true;
                }
            }
        }
        return false;
    }
};

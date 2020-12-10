class Solution {
public:
   typedef pair<int,int> pairs;
    int findPairs(vector<int>& nums, int k) {
        auto cmp=[](pairs a ,pairs b){
            if(a.first>a.second){
                swap(a.first,a.second);
            }
            if(b.first>b.second){
                swap(b.first,b.second);
            }
            return a<b;
        };
        set<pairs,decltype(cmp)> s(cmp);
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[j]-nums[i])==k){
                    pairs x=make_pair(nums[i],nums[j]);

                    s.insert(x);

                }
            }
        }

        return s.size();
    }
};

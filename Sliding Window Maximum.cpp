class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int i;
        for(i=0;i<k;i++){
            while((!dq.empty())&&(nums[i]>=nums[dq.back()])){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);
            while((!dq.empty())&&(dq.front()<=i-k)){
                dq.pop_front();
            }
            while((!dq.empty())&&(nums[i]>=nums[dq.back()])){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};

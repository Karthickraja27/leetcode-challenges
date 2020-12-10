class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int x=q.front();

            q.pop();

            if(arr[x]==0){
                return true;
            }
            if(arr[x]<0){
                continue;
            }
            if(x+arr[x]<n){
                q.push(x+arr[x]);
            }
            if(x-arr[x]>=0){
                q.push(x-arr[x]);
            }
            arr[x]=-arr[x];
        }
        return false;
    }
};
};

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=0;
        bool flag=false;
        bool peak=false;
        if(arr.size()<3){
            return false;
        }
        int n=arr.size();
        while(i<n){
            if(arr[i]>=arr[i+1]){

                break;
            }
            peak=true;
            i++;
        }
        i++;
        if(peak){
            while(i<n){
            if(arr[i]>=arr[i-1]){
                flag=false;
                break;
            }
            else{
                flag=true;
            }

            i++;
        }
        }

        return flag;
    }
};

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int k=flowerbed.size();
        for(int i=0;i<k;i++){
            if(count==n){
                return true;
            }
            if(flowerbed[i]==0&&(i==0||flowerbed[i-1]==0)&&(i==k-1||flowerbed[i+1]==0)){
                flowerbed[i]=1;
                count++;
            }
        }
        if(count==n){
            return true;
        }
        else{
            return false;
        }
    }
};

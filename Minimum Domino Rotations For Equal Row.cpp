class Solution {
public:
   static bool comp(int a, int b)
{
    return (a < b);
}
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int swapsA=0,swapsB=0,swapsC=0,swapsD=0;
        int a=A[0];
        int b=B[0];
        int countA=0,countB=0,countC=0,countD=0;
        for(int i=1;i<A.size();i++){
            if(A[i]==a){
                countA++;

            }
            else if(B[i]==a){
                countA++;
                swapsA++;
            }
            else{
                break;
            }
        }
        for(int i=1;i<B.size();i++){
            if(B[i]==b){
                countB++;

            }
            else if(A[i]==b){
                countB++;
                swapsB++;
            }
            else{
                break;
            }
        }
        int temp;
        temp=b;
        b=a;
        a=temp;
        for(int i=1;i<A.size();i++){
            if(A[i]==a){
                countC++;

            }
            else if(B[i]==a){
                countC++;
                swapsC++;
            }
            else{
                break;
            }
        }
        for(int i=1;i<B.size();i++){
            if(B[i]==b){
                countD++;

            }
            else if(A[i]==b){
                countD++;
                swapsD++;
            }
            else{
                break;
            }
        }
        swapsC++;
        swapsD++;
        if(countA==A.size()-1 && countB==B.size()-1 && countC==A.size()-1 && countD==B.size()-1){
            return min({swapsA,swapsB,swapsC,swapsD},comp);
        }
        else if(countA==A.size()-1 && countD==A.size()-1){
            return min(swapsA,swapsD);
        }
        else if(countB==B.size()-1 && countC==B.size()-1){
            return min(swapsB,swapsC);
        }
        else if(countA==A.size()-1){
            return swapsA;
        }
        else if(countB==B.size()-1){
            return swapsB;
        }
        else {
            return -1;
        }


    }
};

class Solution {
public:
    int BinToDec(string s){
        bitset<32> bits(s);
        return (int)bits.to_ulong();
    }
    int bitwiseComplement(int N) {
        string str="",res="",ans="";
        bool flag=false;
        bitset<32> s(N);
        if(N==0){
            return 1;
        }
        for(int i=0;i<s.size();i++){
            str+=to_string(s[i]);
        }
        //cout<<str<<endl;
        reverse(str.begin(),str.end());
        for(int i=0;i<str.length();i++){
            if(flag||str[i]=='1'){
                res+=str[i];
                flag=true;
            }
        }
        //cout<<res<<endl;
        for(int i=0;i<res.length();i++){
            if(res[i]=='0'){
                ans+='1';
            }
            else{
                ans+='0';
            }
        }
        //cout<<ans;

       return BinToDec(ans);
       //OR return stoi(ans,0,2);
    }
};

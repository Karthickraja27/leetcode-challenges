class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        int j=s.length()-9;
        for(int i=0;i<j;i++){
            mp[s.substr(i,10)]++;
        }
        vector<string> res;
        map<string,int>::iterator itr;
        for(itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second>1){
                res.push_back(itr->first);
            }
        }
        return res;
    }
};

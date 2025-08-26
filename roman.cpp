class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char, int>a;
        a['I']=1;
        a['V']=5;
        a['X']=10;
        a['L']=50;
        a['C']=100;
        a['D']=500;
        a['M']=1000;
        
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(a[s[i]]<a[s[i+1]]) ans-= a[s[i]];
            else ans+=a[s[i]];
        }
        return ans;
    }
};
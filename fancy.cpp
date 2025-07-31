class Solution {
public:
    string makeFancyString(string s) {
        int prev=0;
        int freq=1;
        string ans="";
        for(int i=0; i<s.size(); i++){
            if(s[i]== prev){
                freq=freq+1;
            }
            else{
                prev=s[i];
                freq=1;
            }
            if(freq<3){
                ans.push_back(s[i]);
            }
        }
        return ans;
        
    }
};
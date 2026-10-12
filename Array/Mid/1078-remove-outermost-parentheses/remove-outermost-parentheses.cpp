class Solution {
public:
    string removeOuterParentheses(string s) {
        int o=0;
        string ans="";

        for(int i = 0; i<s.size();i++){
            if(s[i]=='('){
                if(o>0){
                    ans+=s[i];
                }
                o++;
            }else{
                o--;
                if(o>0){
                    ans+=s[i];
                }
            }

        }
        return ans;
    }
};
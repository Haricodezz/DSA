class Solution {
public:
    int maxDepth(string s) {
        int dep=0;
        int o=0;
        for(auto i : s){
            if(i=='('){
                o++;
                dep=max(dep,o);
            }else if(i== ')'){
                o--;
            }

        }

        return dep;
    }
};
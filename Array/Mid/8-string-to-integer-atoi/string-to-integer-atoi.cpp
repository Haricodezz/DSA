class Solution {
public:
    int myAtoi(string s) {
       int i =0;
       int n = s.size();
       int sign = 1;
       long long ans = 0;

       //step1
       while(i<n && s[i]==' '){
        i++;
       
       }
    // step 2
        if(i<n && (s[i]=='+'|| s[i]=='-')){

                if(s[i]=='-'){
                    sign*=-1;
                }
                i++;
                
        }

        // step 3 convert

        while(i < n && s[i] >= '0' && s[i] <= '9'){
int digit = s[i] - '0';


if( ans> (INT_MAX -digit)/10LL){
    return sign==1 ? INT_MAX:INT_MIN;
}

ans=ans*10;
ans += digit;

i++;

        }

return ans*sign;

    }
};
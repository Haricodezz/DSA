class Solution {
public:
    bool canAliceWin(int n) {
      int  i=10;
      while(n-i>=0 && i>0){
n-=i;
i--;

      }  

return i%2!=0;
    }

};
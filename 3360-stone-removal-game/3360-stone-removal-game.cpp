class Solution {
public:
    bool canAliceWin(int n) {
        int x=10;
        int a=1;
        while(n>=x){
          n-=x;
          a=1-a;
          x--;
        }
        return a==0;
    }
};
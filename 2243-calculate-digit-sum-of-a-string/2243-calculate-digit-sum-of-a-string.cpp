class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
        string temp=s;
        while(temp.size()>k){
            string dummy="";
            for(int i=0;i<temp.size();i+=k){
                int sz=min((int)temp.size(),i+k);
                int sum=0;
              for(int j=i;j<sz;j++){
                 sum+=(temp[j]-'0');
              }
              dummy+=to_string(sum);
            }
            temp=dummy;
        }
        return temp;
    }
};
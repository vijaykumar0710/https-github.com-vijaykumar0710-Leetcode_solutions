class Solution {
public:
void fn(int op,int cl,string str,vector<string>&res){
    if(op==0 && cl==0){
      res.push_back(str);
      return;
    }
   if(op>0) fn(op-1,cl,str+'(',res);
   if(op<cl) fn(op,cl-1,str+')',res);
}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        fn(n,n,"",res);
        return res;
    }
};
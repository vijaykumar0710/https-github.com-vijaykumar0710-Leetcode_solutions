class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string st="123456789";
        vector<int>res;
        for(int len=log10(low)+1;len<=log10(high)+1;len++){
            for(int i=0;i<9;i++){
            int num=stoi(st.substr(i,len));
            if(num>high) break;
            if(num>=low && num<=high) res.push_back(num);
             }
        }
        return  res;
    }
};
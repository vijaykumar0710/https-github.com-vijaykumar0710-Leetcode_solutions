class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int ones=0,twos=0,zeros=0;
        for(int i=0;i<stones.size();i++){
            if(stones[i]%3==0) zeros++;
            else if(stones[i]%3==1) ones++;
            else twos++;
        }
        if(zeros%2==0)
        return ones>0 && twos>0 ;
        else return abs(ones-twos)>2;
    }
};
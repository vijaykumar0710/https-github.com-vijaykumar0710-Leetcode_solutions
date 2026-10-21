class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string t=s;

        sort(s.begin(),s.end());
        if(s==t) return 0;

        string t1=t,t2=t;
        sort(t1.begin(),t1.begin()+n-1);
        sort(t2.begin()+1,t2.end());
        if(t2==s || t1==s) return 1;

        string t3=t,t4=t;
        sort(t3.begin()+1,t3.end());
        sort(t3.begin(),t3.begin()+n-1);
        sort(t4.begin(),t4.begin()+n-1);
        sort(t4.begin()+1,t4.end());
        if(t4==s || t3==s) return 2;

        string t5=t,t6=t;
        sort(t5.begin()+1,t5.end());
        sort(t5.begin(),t5.begin()+n-1);
        sort(t5.begin()+1,t5.end());
        sort(t6.begin(),t6.begin()+n-1);
        sort(t6.begin()+1,t6.end());
        sort(t6.begin(),t6.begin()+n-1);
        if(t6==s || t5==s) return 3;

        return -1;
    }
};
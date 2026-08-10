class Solution {
public:
int n;
vector<long long>BIT;
vector<int>a;
set<int>st;
void update(int i,long long val){
    for(;i<=n;i+=i&-i) BIT[i]+=val;
}
long long query(int i){
    long long sum=0;
   for(;i>0;i-=i&-i) sum+=BIT[i];
   return sum;
}
// Naya Peak(c) add karne ka function
void in(int c){
    //Right peak(R) ka iterator  
    auto r_it=st.lower_bound(c);
    //Left peak(L) find karo 
    int l=(r_it==st.begin())?-1:*prev(r_it);
    if(r_it!=st.end()){
        int r=*r_it;
        // L and R ka connection todo
        if(l!=-1) update(r,-1LL*r*(r-l));
        // C & R ka connection jodo
        update(r,1LL*r*(r-c));
    }
    // L & C ka connection jodo
    if(l!=-1) update(c,1LL*c*(c-l));
    st.insert(c);
}

// Purana peak C remove ho gya
void out(int c){
   // Cuurent peak (c) ka iterator find karo     
   auto c_it=st.find(c);
   //right peak(R) ka iterator
   auto r_it=next(c_it);
   // left peak 
   int l=(c_it==st.begin())?-1:*prev(c_it);
   // L & C ka connection todo
   if(l!=-1) update(c,-1LL*c*(c-l));
   if(r_it!=st.end()){
    int r=*r_it;
    update(r,-1LL*r*(r-c));
    if(l!=-1) update(r,1LL*r*(r-l));
   }
   st.erase(c);
}
bool peak(int i){
    return i>0 && i<n-1 && a[i]>a[i+1] && a[i]>a[i-1];
}
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        n=nums.size();
        a=nums;
        BIT.assign(n+1,0);
        st.clear();
        vector<long long>res;
        for(int i=1;i<n-1;i++){
            if(peak(i)) in(i);       
        }
        // process queries 
        for(auto v:queries){
            int x=v[1],y=v[2];
            if(v[0]==2){
                for(int i=x-1;i<=x+1;i++){  
                    if(st.count(i)) out(i);
                }
                a[x]=y;
            for(int i=x-1;i<=x+1;i++){  
                    if(peak(i)) in(i);
                }
            }else{
                // Type 1 range quey(x,y)
                auto it=st.lower_bound(x+1);
                if(it==st.end() || *it>=y){
                    res.push_back(0);
                    continue;
                }
                int first_p=*it,last_p=*prev(st.lower_bound(y));
                long long ans=1LL*y*(last_p-x)-1LL*first_p*(first_p-x)-(query(last_p)-query(first_p));
                res.push_back(ans);
            }
        }
        return res;
    }
};
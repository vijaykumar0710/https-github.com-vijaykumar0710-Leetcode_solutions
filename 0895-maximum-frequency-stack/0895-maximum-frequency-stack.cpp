class FreqStack {
public:
unordered_map<int,vector<int>>mp1;
map<pair<int,int>,int>mp2;
int i=0;
    FreqStack() {
        
    }
    
    void push(int val) {
      int sz=0;
      if(mp1.count(val)){
        sz=mp1[val].size();
        int idx=mp1[val].back();
        mp2.erase({sz,idx});
      }
      mp2[{sz+1,i}]=val;
      mp1[val].push_back(i);
      i++;
    }
    
    int pop() {
        auto it=mp2.rbegin()->first;
        int val=mp2.rbegin()->second;
        int sz=it.first;
        int idx=it.second;
        mp1[val].pop_back();
        mp2.erase({it.first,it.second});
        sz--;
        if(sz==0) mp1.erase(val);
        else mp2[{sz,mp1[val].back()}]=val;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
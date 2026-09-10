class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=wage.size();
        vector<pair<double,int>>r;
        for(int i=0;i<n;i++){
            r.push_back({(double)wage[i]/quality[i],quality[i]});
        }
        sort(r.begin(),r.end());
        priority_queue<int>pq;
        double cost=DBL_MAX;
        int qual=0;
        for(int i=0;i<n;i++){
            double cur_r=r[i].first;
            qual+=r[i].second;
            pq.push(r[i].second);
            if(pq.size()>k){
                qual-=pq.top();
                pq.pop();
            }
           if(pq.size()==k) cost=min(cost,cur_r*qual);
        }
        return cost;
    }
};
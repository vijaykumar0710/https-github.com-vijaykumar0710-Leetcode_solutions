class MedianFinder {
public:
priority_queue<int>max_pq;
priority_queue<int,vector<int>,greater<int>>min_pq;
void balancing(){
    if(max_pq.size()>0 && min_pq.size()>0){
        if(max_pq.top()>min_pq.top()){
        int x=max_pq.top();
        int y=min_pq.top();
        max_pq.pop();
        min_pq.pop();
        max_pq.push(y);
        min_pq.push(x);
        }
    }
}
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      if(max_pq.size()<=min_pq.size()) max_pq.push(num);
      else min_pq.push(num);
      balancing();
    }
    
    double findMedian() {
        int sz=max_pq.size()+min_pq.size();
        double res=0.0;
        if(sz%2) res=max_pq.top();
        else{
          res=(min_pq.empty()?0.0:min_pq.top()+max_pq.top())/2.0;
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
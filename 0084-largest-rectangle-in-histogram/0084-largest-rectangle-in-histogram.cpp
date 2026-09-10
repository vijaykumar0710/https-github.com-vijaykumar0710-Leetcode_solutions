class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>PSE(n,-1),NSE(n,n);
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) PSE[i]=st.top();
            st.push(i);
        }
        stack<int>st1;
        st1.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st1.empty() && heights[st1.top()]>=heights[i]) st1.pop();
            if(!st1.empty()) NSE[i]=st1.top();
            st1.push(i);
        }
        int res=0;
        for(int i=0;i<n;i++){
          if(i==0) res=max(res,heights[i]*(NSE[i]-i));
          else if(i==n-1) res=max(res,heights[i]*(i-PSE[i]));
          else{ 
         
          res=max(res,(NSE[i]-PSE[i]-1)*heights[i]);
          }
        }
        return res;
    }
};
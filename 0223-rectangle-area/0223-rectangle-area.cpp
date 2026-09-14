class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x1=max(ax1,bx1),y1=max(ay1,by1);
        int x2=min(ax2,bx2),y2=min(ay2,by2);
        int w=x2-x1;
        int h=y2-y1;
        int total=(ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1);
        if(x1<x2 && y1<y2){
            total-=w*h;
        }
        return total;
    }
};
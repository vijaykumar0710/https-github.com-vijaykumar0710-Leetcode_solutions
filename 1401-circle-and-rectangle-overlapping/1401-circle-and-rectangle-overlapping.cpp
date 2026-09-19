class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    double x = max(x1, min(xCenter, x2));
    double y = max(y1, min(yCenter, y2));
    double dx = xCenter - x;
    double dy = yCenter - y;
    return dx * dx + dy * dy <= radius * radius;
    }
};
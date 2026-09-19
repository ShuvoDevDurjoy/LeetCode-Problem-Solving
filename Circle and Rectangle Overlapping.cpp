
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find closest point on rectangle to circle center
        int nearestX = std::clamp(xCenter, x1, x2);
        int nearestY = std::clamp(yCenter, y1, y2);
        
        // Calculate squared distance from circle center to nearest point
        int dx = xCenter - nearestX;
        int dy = yCenter - nearestY;
        
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};

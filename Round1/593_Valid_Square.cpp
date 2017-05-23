// Given the coordinates of four points in 2D space, return whether the four points could construct a square.

// The coordinate (x,y) of a point is represented by an integer array with two integers.

// Example:
// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
// Output: True
// Note:

// All the input integers are in the range [-10000, 10000].
// A valid square has four equal sides with positive length and four equal angles (90-degree angles).
// Input points have no order.
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int dis1 = (p2[0] - p1[0]) *  (p2[0] - p1[0]) + (p2[1] - p1[1]) *  (p2[1] - p1[1]) ;
        int dis2 = (p3[0] - p1[0]) *  (p3[0] - p1[0]) + (p3[1] - p1[1]) *  (p3[1] - p1[1]) ;
        int dis3 = (p4[0] - p1[0]) *  (p4[0] - p1[0]) + (p4[1] - p1[1]) *  (p4[1] - p1[1]) ;
        if(dis1 == 0 || dis2 == 0 || dis3 == 0) {
            return false;
        }
        int dist = 0, dist4 = 0, dist5;
        if(dis1 == dis2) {
            dist = (p3[0] - p2[0]) *  (p3[0] - p2[0]) + (p3[1] - p2[1]) *  (p3[1] - p2[1]) ;
            dist4 = (p2[0] - p4[0]) *  (p2[0] - p4[0]) + (p2[1] - p4[1]) *  (p2[1] - p4[1]) ;
            dist5 = (p4[0] - p3[0]) *  (p4[0] - p3[0]) + (p3[1] - p4[1]) *  (p3[1] - p4[1]) ;
            if(dist = dis3 && (dist == dis1 * 2 || dis1 == dist * 2) && dist4 == dis1 && dist5 == dis1) {
                return true;
            }
        } else if(dis1 == dis3) {
            dist = (p4[0] - p2[0]) *  (p4[0] - p2[0]) + (p4[1] - p2[1]) *  (p4[1] - p2[1]) ;
            dist4 = (p3[0] - p2[0]) *  (p3[0] - p2[0]) + (p3[1] - p2[1]) *  (p3[1] - p2[1]) ;
            dist5 = (p4[0] - p3[0]) *  (p4[0] - p3[0]) + (p3[1] - p4[1]) *  (p3[1] - p4[1]) ;
            if(dist = dis2 && (dist == dis1 * 2 || dis1 == dist * 2)  && dist4 == dis1 && dist5 == dis1) {
                return true;
            }
        } else if(dis2 == dis3) {
            dist = (p3[0] - p4[0]) *  (p3[0] - p4[0]) + (p3[1] - p4[1]) *  (p3[1] - p4[1]) ;
            dist4 = (p3[0] - p2[0]) *  (p3[0] - p2[0]) + (p3[1] - p2[1]) *  (p3[1] - p2[1]) ;
            dist5 = (p4[0] - p3[0]) *  (p4[0] - p3[0]) + (p3[1] - p4[1]) *  (p3[1] - p4[1]) ;
            if(dist = dis1 && (dist == dis2 * 2 || dis2 == dist * 2)  && dist4 == dis2 && dist5 == dis1) {
                return true;
            }
        } else {
            return false;
        }
        return false;
    }
};
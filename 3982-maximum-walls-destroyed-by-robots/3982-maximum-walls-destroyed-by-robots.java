import java.util.*;

public class Solution {
    private static class Seg {
        int mi, ma, cnt;
        Seg left, right;
        Seg(int[] A, int l, int r) {
            this.mi = A[l];
            this.ma = A[r];
            this.cnt = r - l + 1;
            if (l < r) {
                int m = l + (r - l) / 2;
                left  = new Seg(A, l,   m);
                right = new Seg(A, m+1, r);
            }
        }
        int query(int l, int r) {
            if (l > r) return 0;
            if (l <= mi && ma <= r) return cnt;
            if (r < mi || l > ma) return 0;
            return left.query(l, r) + right.query(l, r);
        }
    }

    public int maxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.length;
        int m = walls.length;
        int[][] sortedRobots = new int[n][2];
        for (int i = 0; i < n; i++) {
            sortedRobots[i][0] = robots[i];
            sortedRobots[i][1] = distance[i];
        }
        Arrays.sort(sortedRobots, Comparator.comparingInt(a -> a[0]));
        Arrays.sort(walls);
        Seg seg = new Seg(walls, 0, m - 1);
        int dpLeft = 0, dpRight = 0;
        for (int i = 0; i < n; i++) {
            int at  = sortedRobots[i][0];
            int dis = sortedRobots[i][1];
            int leftUntil  = at - dis;
            int rightUntil = at + dis;
            if (i + 1 < n) {
                rightUntil = Math.min(rightUntil, sortedRobots[i+1][0] - 1);
            }
            if (i > 0) {
                leftUntil  = Math.max(leftUntil,  sortedRobots[i-1][0] + 1);
            }
            int leftMax  = 0;
            int rightMax = 0;
            leftMax = Math.max(leftMax, dpLeft + seg.query(leftUntil, at));
            if (i > 0) {
                int prevAt  = sortedRobots[i-1][0];
                int prevDis = sortedRobots[i-1][1];
                int start = Math.max(leftUntil, Math.min(at, prevAt + prevDis + 1));
                leftMax = Math.max(leftMax, dpRight + seg.query(start, at));
            }
            rightMax = Math.max(rightMax, dpLeft  + seg.query(at, rightUntil));
            rightMax = Math.max(rightMax, dpRight + seg.query(at, rightUntil));
            dpLeft  = leftMax;
            dpRight = rightMax;
        }
        return Math.max(dpLeft, dpRight);
    }
}
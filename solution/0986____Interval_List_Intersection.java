package leetcode.solution;

import java.util.ArrayList;
import java.util.List;

class Solution {
    // perf: 99.56%, 5.02%
    public int[][] intervalIntersection(int[][] aList, int[][] bList) {
        List<int[]> intersection = new ArrayList<int[]>();
        int aIndex = 0, bIndex = 0;
        while (true) {
            // if there is no interval to compare, break
            if (aIndex >= aList.length
                    || bIndex >= bList.length) {
                break;
            }
            int a = aList[aIndex][0];
            int aa = aList[aIndex][1];
            int b = bList[bIndex][0];
            int bb = bList[bIndex][1];
            if (aa < b || a > bb) { // no intersection

            } else {// there is intersection
                intersection.add(new int[] { java.lang.Math.max(a, b), java.lang.Math.min(aa, bb) });
            }
            if (aa > bb) {
                bIndex++;
            } else if (aa < bb) {
                aIndex++;
            } else {
                aIndex++;
                bIndex++;
            }
        }
        int[][] intersectionArray = intersection.toArray(new int[intersection.size()][]);
        return intersectionArray;
    }
}
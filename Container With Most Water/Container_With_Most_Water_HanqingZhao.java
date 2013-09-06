/**
 * Created with IntelliJ IDEA.
 * User: Hanqing
 * Date: 9/4/13
 * Time: 7:49 PM
 * To change this template use File | Settings | File Templates.
 */
public class Solution {
    public int maxArea(int[] height) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int Len=height.length;
        int maxH=0;
        int maxi=0;
        int lind=0;
        int rind=Len-1;

        while (lind<rind) {
            int water=(rind-lind)*(Math.min(height[lind],height[rind]));
            maxi=Math.max(maxi,water);
            if (height[lind]<height[rind]) {
                lind++;
            }
            else {
                rind--;
            }
        }
        return maxi;
    }
}
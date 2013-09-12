public class Solution {
    public int divide(int div1, int div2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int count = 0;
        Long dividend = (long) div1;
        Long divisor  = (long) div2;
        ArrayList<Long> base = new ArrayList<Long>();
        ArrayList<Long> resultBase = new ArrayList<Long>();
        boolean positive = true;
        if (dividend < 0) {
            dividend = 0 - dividend;
            positive = !positive;
        }
        if (divisor < 0) {
            divisor = 0 - divisor;
            positive = !positive;
        }
        base.add(divisor);
        resultBase.add(1L);
        while((divisor + divisor) <= dividend) {
            Long laseElement = resultBase.get(resultBase.size() - 1);
            resultBase.add(laseElement + laseElement);
            base.add(divisor += divisor);
        }
        for (int i = base.size() - 1; i >= 0; i--) {
            long toSub = base.get(i);
            if (dividend >= toSub) {
                dividend -= toSub;
                count += resultBase.get(i);
            }
        }
        if (!positive) count = 0 - count;
        return count;
    }
}
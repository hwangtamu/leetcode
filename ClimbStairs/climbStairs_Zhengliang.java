package climb.stairs;

public class climbStairs {
	public int climbRecur(int n) {
		if (n == 1) return 1;
		else if (n == 2) return 2;
		else return climbRecur(n-1)+climbRecur(n-2);
	}
    public int climb(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 1) return 1;
        int[] methods = new int[n];
        methods[0] = 1;
        methods[1] = 2;
        for (int i = 2; i < n; i++) {
            methods[i] = methods[i-1] + methods[i-2];
        }
        return methods[n-1];
    }
}

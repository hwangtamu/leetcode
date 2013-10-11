package unique.path;

public class uniquePath {
	public static void main(String[] args) {
		System.out.println(uniquePathsTwo(23, 3));
	}

	public static int uniquePaths(int m, int n) {
		if (m == 1 || n == 1) return 1;
		else return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
    }
	
	public static int uniquePathsTwo(int m, int n) {
		int[][] result = new int[m][n];
		for (int i = 0; i < m; i++) {
			result[i][0] = 1;
		}
		for (int j = 0; j < n; j++) {
			result[0][j] = 1;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				result[i][j] = result[i - 1][j] + result[i][j - 1];
			}
		}
		return result[m-1][n-1];
    }
}

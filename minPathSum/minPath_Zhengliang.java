package minimun.path.sum;

public class minPath {
	public static void main(String[] args) {
		// System.out.println(uniquePathsTwo(23, 3));
	}

	public static int minPathSum(int [][] grid) {
		int m = grid.length;
		int n = grid[0].length;
		int[][] result = new int[m][n];
		result[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) {
			result[i][0] = grid[i][0] + result[i-1][0];
		}
		for (int j = 1; j < n; j++) {
			result[0][j] = grid[0][j] + result[0][j-1];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				result[i][j] = grid[i][j] + (result[i-1][j] < result[i][j-1]? result[i-1][j] : result[i][j-1]);
			}
		}
		return result[m-1][n-1];
	}
}

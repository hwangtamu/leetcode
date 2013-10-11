package unique.path.two;

public class uniquePath {
	public static void main(String[] args) {
		// System.out.println(uniquePathsTwo(23, 3));
		int[][] a = new int[3][3];
		a[0][0] = 0;
		a[1][0] = 0;
		a[2][0] = 0;
		a[0][1] = 0;
		a[1][1] = 1;
		a[1][2] = 0;
		a[0][2] = 0;
		a[1][2] = 0;
		a[2][2] = 0;
		System.out.println(uniquePathsWithObstacles(a));
	}

	public static int uniquePathsWithObstacles(int[][] obstacleGrid) {
		int m = obstacleGrid.length;
		int n = obstacleGrid[0].length;
		int[][] result = new int[m][n];
		boolean vertical = true;
		boolean horizontal = true;
		for (int i = 0; i < m; i++) {
			if (vertical && (obstacleGrid[i][0] == 0)) {
				result[i][0] = 1;
			} else {
				result[i][0] = 0;
				vertical = false;
			}
		}
		for (int j = 0; j < n; j++) {
			if (horizontal && (obstacleGrid[0][j] == 0)) {
				result[0][j] = 1;
			} else {
				result[0][j] = 0;
				horizontal = false;
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					result[i][j] = 0;
				} else {
					result[i][j] = result[i - 1][j] + result[i][j - 1];
				}
			}
		}
		return result[m-1][n-1];
	}
}

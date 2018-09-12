class Solution {
	public static int binaryGap(int N) {
		if (N == 0 || ((N & (N - 1)) == 0)) {
			return 0;
		}
		String num = Integer.toBinaryString(N);
		char[] nums = num.toCharArray();
		int distance = Integer.MIN_VALUE;
		int[] distances = new int[nums.length];
		for (int i = 0; i < nums.length; i++) {
			distances[i] = Integer.MIN_VALUE;
		}
		int index = 0;
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == '1') {
				distances[index++] = i;
			}
		}
		for (int i = distances.length - 1; i > 0; i--) {
			if (distances[i] >= 0 && distances[i - 1] >= 0) {
				if (distances[i] - distances[i - 1] >= distance) {
					distance = distances[i] - distances[i - 1];
				}
			}
		}
		return distance;
	}
}
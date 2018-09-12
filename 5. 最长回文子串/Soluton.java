class Solution {
	public char[] manacherString(String str) {
		char[] charArr = str.toCharArray();
		char[] res = new char[str.length() * 2 + 1];
		int index = 0;
		for (int i = 0; i < res.length; i++) {
			res[i] = (i & 1) == 0 ? '#' : charArr[index++];
		}
		return res;
	}

	public String longestPalindrome(String s) {
		if (s == null || s.length() == 0) {
			return "";
		}
		char[] charArr = manacherString(s);
		int[] pArr = new int[charArr.length];
		int index = -1, max_index = 0;
		int pR = -1;
		int max = Integer.MIN_VALUE;
		for (int i = 0; i != charArr.length; i++) {
			pArr[i] = pR > i ? Math.min(pArr[2 * index - i], pR - i) : 1;
			while (i + pArr[i] < charArr.length && i - pArr[i] > -1) {
				if (charArr[i + pArr[i]] == charArr[i - pArr[i]]) {
					pArr[i]++;
				} else {
					break;
				}
			}
			if (i + pArr[i] > pR) {
				pR = i + pArr[i];
				index = i;
			}
			if (pArr[i] > max) {
				max = pArr[i];
				max_index = i;
			}
		}
		char[] temp = new char[2 * max - 1];
		int temp_index = 0;
		for (int i = max_index - max + 1; i <= max_index + (max - 1); i++) {
			temp[temp_index++] = charArr[i];
		}
		return new String(temp).replaceAll("#", "");
	}
}
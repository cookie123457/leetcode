class Solution {
    public boolean rotateString(String A, String B) {
    	boolean flag = false;
    	char[] string_a = A.toCharArray();
    	char[] string_b = B.toCharArray();
    	if (A.length() != B.length()) {
    		return false;
    	}
        if (A.length() == 0 && B.length() == 0) {
            return true;
        }
    	for (int i = 1; i < string_a.length; i++) {
    		if (check(string_a, string_b, i)) {
    			return true;
    		}
    	}
        return false;
    }

    public static boolean check (char[] string_a, char[] string_b, int offset) {
    	for (int i = 0; i< string_a.length; i++) {
    		if (string_a[(i + offset) % string_a.length] != string_b[i]) {
    			return false;
    		}
    	}
    	return true;
    }
}
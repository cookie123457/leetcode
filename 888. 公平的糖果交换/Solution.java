class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int sumA = 0;
        int sumB = 0;
        for (int num: A) {
            sumA += num;
        }
        for (int num: B) {
            sumB += num;
        }
        
        int delta = (sumA - sumB) / 2;
        Set<Integer> set = new HashSet();
        for (int num: A) {
            set.add(num);
        }
        
        for (int num: B) {
            if (set.contains(num + delta)) {
                return new int[]{num + delta, num};
        }
        return new int[]{-1, -1};
    }
}
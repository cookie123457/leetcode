public class Solution {
    List<List<Integer>> result;
    public void find (int n,int remains,List<Integer> temp,int index){
        if (remains == 0) {
            List<Integer> t = new ArrayList<Integer>();
            t.addAll(temp);
            result.add(t);
            return ;
        }
        for (int i = index; i <= n && i + remains - 1 <= n; i++){
            temp.add(i);
            find(n,remains-1,temp,i+1);
            temp.remove(temp.size()-1);
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        result = new ArrayList<List<Integer>>();
        find(n,k,new ArrayList<Integer>(),1);
        return result;
    }
    public static void main (String[] args) {
    	int n = 4, k = 2;
    	combine(n, k);
    }
}
public class Solution {
    List<List<Integer>> result;
    public void find(int n,int remains,List<Integer> tmp,int index){
        if(remains==0){
            List<Integer> t= new ArrayList<Integer>();
            t.addAll(tmp);
            result.add(t);
            return ;
        }
        for(int i=index;i<=n && i+remains-1<=n;i++){
            tmp.add(i);
            find(n,remains-1,tmp,i+1);
            tmp.remove(tmp.size()-1);
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        result=new ArrayList<List<Integer>>();
        find(n,k,new ArrayList<Integer>(),1);
        return result;
    }
    public static void main (String[] args) {
    	int n = 4, k = 2;
    	combine(n, k);
    }
}
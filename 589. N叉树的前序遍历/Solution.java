/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<Integer> preorder(Node root) {    	
        List<Integer> result = new ArrayList<Integer>();
        if (root == null)
        	return result;
        result.add(root.val);
        for (Node child : root.children) {
        	List<Integer> temp = new ArrayList<Integer>();
            temp = preorder(child);
            for (Integer num : temp) {
                result.add(num);
            }
        }
        return result;
    }
}
import java.util.ArrayList;
import java.util.Stack;

public class Solution {
    public static ArrayList<Integer> findSpans(ArrayList<Integer> A) {
        // Write your code here.
        int n = A.size();
        ArrayList<Integer> res = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            res.add(1);
        }
        Stack<Integer> s = new Stack<>();

        for(int i = 0; i < A.size(); i++) {
            while(s.size() > 0 && A.get(s.peek()) <= A.get(i)) {
                res.set(i, 1 + res.get(s.pop()));
            }
            s.push(i);
        }

        return res;
    }

    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>();
        A.add(4);
        A.add(2);
        A.add(3);
        A.add(3);
        A.add(6);
        ArrayList<Integer> res = findSpans(A);
        for(int i = 0; i < res.size(); i++) {
            System.out.print(res.get(i) + " ");
        }
    }
} 

// Write any import statements here

import java.util.Arrays;

class Solution {
  
  public long getMaxAdditionalDinersCount(long N, long K, int M, long[] S) {
    // Write your code here
    Arrays.sort(S);
    long res = 0;

    // count left
    long cur = S[0] - K - 1;
    while(cur >= 1) {
      res++;
      System.out.print(cur + "<- ");
      cur = cur - K - 1;
      System.out.println(cur + "<- ");
    }
    
    // count middle
    for(int i = 0; i < M-1; i++) {
      long next = S[i] + K + 1;
      while(next <= S[i+1] - K - 1) {
        //System.out.println(next + " ");
        res++;
        next = next + K + 1;
      }
    }
    
    // count right
    cur = S[M-1] + K + 1;
    while(cur <= N) {
      //System.out.println(cur + " ");
      res++;
      cur = cur + K + 1;
    }
    
    return res;
  }

}

class Main {
    public static void main(String[] args) {
        Solution ob = new Solution();
        long[] A = {11,6,14};
        long res = ob.getMaxAdditionalDinersCount(15, 2, 3, A);
        System.out.println("\n"+ res);

    }
}


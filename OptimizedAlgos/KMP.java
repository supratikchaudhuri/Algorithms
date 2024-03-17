package OptimizedAlgos;

public class KMP {

    private static void computeLPSArray(String pattern, int[] lps) {
        int len = 0;
        int i = 1;
        lps[0] = 0;

        while(i < pattern.length()) {
            if(pattern.charAt(i) == pattern.charAt(len)) {
                lps[i] = len + 1;
                len++;
                i++;
            } else {
                if(len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    private static int KMPSearch(String text, String pattern, int[] lps) {
        int i = 0;
        int j = 0;

        while(i < text.length()) {
            if(text.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;
            }

            if(j == pattern.length()) {
                return i - j;
            }

            if(i < text.length() && text.charAt(i) != pattern.charAt(j)) {
                if(j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        String text = "onionionionspl";
        String pattern = "onions";
        int[] lps = new int[pattern.length()];

        computeLPSArray(pattern, lps);

        System.out.println(KMPSearch(text, pattern, lps));
    }
}

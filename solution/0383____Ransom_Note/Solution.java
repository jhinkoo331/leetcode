import java.util.Arrays;

public class Solution {
    // perf: 4ms, 5.0%
    // time complexity: log_n(max(ransomNote, magazine)), sort the array is the most expensive process.
    // memory complexity: in-place.
    public boolean canConstruct(String ransomNote, String magazine) {
        char[] ransom=ransomNote.toCharArray();
        char[] maga=magazine.toCharArray();
        Arrays.sort(ransom);
        Arrays.sort(maga);
        int magaIndex = 0;
        for (char c:ransom){
            while(magaIndex<maga.length&&maga[magaIndex]!=c){
                magaIndex++;
            }
            if (magaIndex>=maga.length){
                return false;
            }
            magaIndex++;
        }
        return true;
    }
    public static void main(String[] args) {
        Solution sln=new Solution();
        System.out.println(sln.canConstruct("a", "b"));
        System.out.println(sln.canConstruct("aa", "ab"));
        System.out.println(sln.canConstruct("aa", "aab"));
    }
}

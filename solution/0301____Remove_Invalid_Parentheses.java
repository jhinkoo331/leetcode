import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.HashSet;

// perf: [21, 25], 3 passes.
class Solution {
    // This is a inner enum Class with name `CharType`
    private static enum CharType {
        LEFT_PARENTHESE, // public static final CharType LEFT_PARENTHESE;
        RIGHT_PARENTHESE,
        LETTER,
        UNKNOWN;
    }

    private HashSet<String> ans;
    private int maxLen;
    private int leftParenthesesCount;
    private ArrayList<Character> currentChars;

    Solution() {
        this.currentChars = new ArrayList<Character>();
        this.ans = new HashSet<String>();
        this.ans.add("");
    }

    private String getString() {
        StringBuilder sb = new StringBuilder(this.currentChars.size());
        for (Character c : this.currentChars) {
            sb.append(c);
        }
        return sb.toString();
    }

    private CharType charType(char c) {
        CharType type;
        switch (c) {
            case '(':
                type = CharType.LEFT_PARENTHESE;
                break;
            case ')':
                type = CharType.RIGHT_PARENTHESE;
                break;
            default:
                type = CharType.LETTER;
                break;
        }
        return type;
    }

    // lc invokes this function
    public List<String> removeInvalidParentheses(String s) {
        char[] chars = s.toCharArray();
        search(chars, 0);
        var ansArr = this.ans.toArray(new String[this.ans.size()]);
        return Arrays.asList(ansArr);
    }

    private void check() {
        if (leftParenthesesCount > 0) { // invalid string
            return;
        }
        if (currentChars.size() == maxLen && maxLen > 0) { // add new string with same length
            ans.add(this.getString());
        } else if (currentChars.size() > maxLen) { // new string with longer length
            maxLen = currentChars.size();
            ans.clear();
            ans.add(this.getString());
        }
    }

    private void search(char[] str, int curIndex) {
        this.check();
        if (curIndex >= str.length) {
            return;
        }
        var c = str[curIndex];
        // `switch` works for only primitive types, String and other primitive wrapper
        // types, such as Integer, Charactor and so on.
        switch (this.charType(c)) {
            case LEFT_PARENTHESE:
                // use this char, and search deeper
                currentChars.add(c);
                leftParenthesesCount++;
                search(str, curIndex + 1);
                currentChars.remove(currentChars.size() - 1);
                leftParenthesesCount--;
                // don't use it, search deeper
                search(str, curIndex + 1);
                break;
            case RIGHT_PARENTHESE:
                if (this.leftParenthesesCount > 0) {
                    // use it
                    currentChars.add(c);
                    leftParenthesesCount--;
                    search(str, curIndex + 1);
                    currentChars.remove(currentChars.size() - 1);
                    leftParenthesesCount++;
                }
                // don't use it
                search(str, curIndex + 1);
                break;
            case LETTER:
                // use it, make the string longer
                currentChars.add(c);
                search(str, curIndex + 1);
                currentChars.remove(currentChars.size() - 1);
                break;
            default:
                System.err.println("error");
                break;
        }
    }

    public static void main(String[] args) {
        var sln = new Solution();
        // sln.removeInvalidParentheses("()())()");
        sln.removeInvalidParentheses("(a)())()");
        for (String s : sln.ans) {
            System.out.println(s);
        }
    }
}

public class Solution {
    private Map<Character, Character> pairs = new HashMap<Character, Character>();
    public boolean isValid(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        pairs.put(')', '(');
        pairs.put(']', '[');
        pairs.put('}', '{');
        Stack<Character> brackets = new Stack<Character>();
        for(char c : s.toCharArray()) {
            Character character = Character.valueOf(c);
            if (pairs.values().contains(character)) {
                brackets.push(character);
            }
            Character value = pairs.get(character);
            if (value != null) {
                if (brackets.empty() || (value.compareTo(brackets.pop()) != 0)) return false;
            }
        }
        return brackets.empty();
    }
}
public class Solution {
    public static void addToList(List<String> retVal, String curString, int level, List<String> components) {
    	if (level == 0) {
			retVal.add(curString);
		} else {
			level -= 1;
			for (char word : ((String) components.toArray()[level]).toCharArray()) {
				addToList(retVal, String.valueOf(word) + curString, level, components);
			}
		}
	}
    public ArrayList<String> letterCombinations(String digits) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Map<String, String> m_map = new HashMap<String, String>();
    	m_map.put("2", "abc");
		m_map.put("3", "def");
		m_map.put("4", "ghi");
		m_map.put("5", "jkl");
		m_map.put("6", "mno");
		m_map.put("7", "pqrs");
		m_map.put("8", "tuv");
		m_map.put("9", "wxyz");
		m_map.put("0", " ");
		ArrayList<String> retVal = new ArrayList<String> ();
		List<String> components = new ArrayList<String>();
		for (char word : digits.toCharArray()) {
			components.add(m_map.get(String.valueOf(word)));
		}
		addToList(retVal, "", components.size(), components);
		return retVal;
    }
}

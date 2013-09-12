public class Solution {
    public static void gogogo(ArrayList<Integer> ret, ArrayList<String> list,
                              int subLen, int start, String S) {
    	if (list.isEmpty()) {
			ret.add(start);
			return;
		} else if (list.size() * subLen > S.length()) {
			return;
		} 
		ArrayList<String> newlist = new ArrayList<String>(list);
		if (!newlist.remove(S.substring(0, subLen))) return;
		gogogo(ret, newlist, subLen, start, S.substring(subLen));
    }
    
    public ArrayList<Integer> findSubstring(String S, String[] L) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	ArrayList<Integer> ret = new ArrayList<Integer>();
		ArrayList<String> list = new ArrayList<String>();
		for (String l : L)  list.add(l);
		if (list.isEmpty())	return null;
		int subLen = L[0].length();
		int ttlLen = S.length();
		for (int i = 0; i <= ttlLen - subLen; i++) gogogo(ret, list, subLen, i, S.substring(i));
		return ret;
    }
}
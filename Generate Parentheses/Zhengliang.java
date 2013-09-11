public class Solution {
    public ArrayList<String> generateParenthesis(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
    	int jiDiZaiZaoDeBing = n;
		int taXiaMeiSiDeBing = 0;
		ArrayList<String> chuBingQingKuang = new ArrayList<String>();
		chuBing(jiDiZaiZaoDeBing, taXiaMeiSiDeBing, "", chuBingQingKuang);
		return chuBingQingKuang;
    }
    public static void chuBing(int jiDiZaiZaoDeBing, int taXiaMeiSiDeBing, String dangQianQingKuang, ArrayList<String> shaQingKuang) {
		if ((jiDiZaiZaoDeBing == 0) && (taXiaMeiSiDeBing == 0)) {
			shaQingKuang.add(dangQianQingKuang);
		} else if (jiDiZaiZaoDeBing > 0) {
			chuBing(jiDiZaiZaoDeBing - 1, taXiaMeiSiDeBing + 1, dangQianQingKuang + "(", shaQingKuang);
		}
		if(taXiaMeiSiDeBing > 0) {
			chuBing(jiDiZaiZaoDeBing, taXiaMeiSiDeBing - 1, dangQianQingKuang + ")", shaQingKuang);
		}
	}
}
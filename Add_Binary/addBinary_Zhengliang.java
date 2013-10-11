package add.binary;

public class addBinaryString {
	public static void main(String[] args) {
		 System.out.println(addBinary("1", "10001"));
	}
	
	public static String addBinary(String a, String b) {
		int length = 0;
		if (a.length() > b.length()) {
			length = a.length();
			for (int i = b.length(); i < a.length(); i++) b = "0" + b;
		} else {
			length = b.length();
			for (int i = a.length(); i < b.length(); i++) a = "0" + a;
		}
		String result = "";
		int step = 0;
		for (int i = 1; i <= length; i++) {
			if (a.charAt(length - i) == '1' && b.charAt(length - i) == '1' && step == 1) {
				result = "1" + result;
			} else if (a.charAt(length - i) == '1' && b.charAt(length - i) == '1' && step == 0) {
				result = "0" + result;
				step = 1;
			} else if (a.charAt(length - i) == '0' && b.charAt(length - i) == '0' && step == 1) {
				result = "1" + result;
				step = 0;
			} else if (a.charAt(length - i) == '0' && b.charAt(length - i) == '0' && step == 0) {
				result = "0" + result;
			} else if (step == 0) {
				result = "1" + result;
			} else {
				result = "0" + result;
			}
		}
		if (step == 1) {
			result = "1" + result;
		}
		return result;
	}
}

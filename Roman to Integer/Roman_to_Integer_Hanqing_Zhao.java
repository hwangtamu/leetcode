import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int romanToInt(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function

        Map RomanInt=new HashMap();
        RomanInt.put('M',1000);
        RomanInt.put('D',500);
        RomanInt.put('C',100);
        RomanInt.put('L',50);
        RomanInt.put('X',10);
        RomanInt.put('V',5);
        RomanInt.put('I',1);


        int num=0;
        int ind=0;
        while (ind<s.length()) {
            if ((ind<s.length()-1)&&(Integer)RomanInt.get(s.charAt(ind))<(Integer)RomanInt.get(s.charAt(ind+1))) {
                num+=(Integer)RomanInt.get(s.charAt(ind+1))-(Integer)RomanInt.get(s.charAt(ind));
                ind++;
            }
            else {
                num+=(Integer)RomanInt.get(s.charAt(ind));
            }
            ind++;
        }
        return num;
    }
}

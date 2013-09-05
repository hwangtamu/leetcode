public class Solution {
    public static String intToRoman(int num) {
        // Start typing your Java solution below
        // DO NOT write main() function

        char[] RomanChar={'M','D','C','L','X','V','I'};
        int[] divArray={1000,500,100,50,10,5,1};
        String Roman=new String();
        int ind=0;
        int flag=2;

        do {
            int divNum=num/divArray[ind];
            while (divNum>0) {
                Roman=Roman+RomanChar[ind];
                divNum--;
                num-=divArray[ind];
            }
            if (ind+flag<RomanChar.length) {
                if (num>=divArray[ind]-divArray[ind+flag]) {
                    Roman=Roman+RomanChar[ind+flag]+RomanChar[ind];
                    num-=divArray[ind]-divArray[ind+flag];
                }
                if (flag==2) {
                    flag=1;
                }
                else {
                    flag=2;
                }
            }
            ind++;
        }
        while (ind<RomanChar.length);
        return Roman;

    }
    public static void main(String[] args) {
        int num=4;
        System.out.println(intToRoman(num));
    }
}

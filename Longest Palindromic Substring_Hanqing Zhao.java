public class Solution {
    public static String longestPalindrome(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int Len=s.length();
        int lb,rb;
        int[] boundaries=new int[2];
        int[] maxboundaries=new int[2];
        int maxLen=0;

        for (int pos=0;pos<Len;pos++) {
            int sit=coreDet(s,pos);

            if (sit==1&&pos>0&&pos<Len-1) {
                lb=pos-1;
                rb=pos+1;
                boundaries=expandP(s,lb,rb);
                int currLen=boundaries[1]-boundaries[0]+1;
                if (currLen>maxLen) {
                    maxboundaries=boundaries;
                    maxLen=currLen;
                }
            }
            if (sit==2&&pos<Len-1) {
                lb=pos;
                rb=pos+1;
                boundaries=expandP(s,lb,rb);
                int currLen=boundaries[1]-boundaries[0]+1;
                if (currLen>maxLen) {
                    maxboundaries=boundaries;
                    maxLen=currLen;
                }
            }
            if (sit==3&&pos>0&&pos<Len-1) {
                lb=pos-1;
                rb=pos+1;
                boundaries=expandP(s,lb,rb);
                int currLen=boundaries[1]-boundaries[0]+1;
                if (currLen>maxLen) {
                    maxboundaries=boundaries;
                    maxLen=currLen;
                }

                lb=pos;
                rb=pos+1;
                boundaries=expandP(s,lb,rb);
                currLen=boundaries[1]-boundaries[0]+1;
                if (currLen>maxLen) {
                    maxboundaries=boundaries;
                    maxLen=currLen;
                }
            }
        }
        return s.substring(maxboundaries[0],maxboundaries[1]+1);
    }

    public static int coreDet(String s, int pos) {
        int coreType=0;
        if (pos<s.length()-1) {
            if (s.charAt(pos)==s.charAt(pos+1)) {
                coreType=2;
            }

            if (pos>0) {
                if (s.charAt(pos-1)==s.charAt(pos+1)) {
                    if (coreType==2) {
                        coreType=3;
                    }
                    else {
                        coreType=1;
                    }
                }
            }
        }
        return coreType;
    }

    public static int[] expandP(String s,int lb,int rb) {
        if (lb==0||rb==s.length()-1) {
            int[] finalBound=new int[2];
            finalBound[0]=lb;
            finalBound[1]=rb;
            return finalBound;
        }
        else {
            int lbn=lb-1;
            int rbn=rb+1;
            if (s.charAt(lbn)==s.charAt(rbn)) {
                return expandP(s,lbn,rbn);
            }
            else {
                int[] finalBound=new int[2];
                finalBound[0]=lb;
                finalBound[1]=rb;
                return finalBound;
            }
        }
    }

    public static void main(String[] args) {
        String s="ababa";
        System.out.println(longestPalindrome(s));
    }
}

class Solution {
    public int getLucky(String s, int k) {
        int j,i;
        int sum1=0,sum2=0;
        int[] temp =new int[100*10]
        char[] str = new char[25];
        for(i =0;i<25;i++){
            str[i]= 'a' + i;
        }

        for( j=0;j<s.length();j++){
            for(i =0;i<25;i++){
                if(s[j]==str[i]){
                    temp[i]=i+1;
                }
        }
        for(i =0;i<temp.length;i++){
            int num = temp[i];
            int rem;
            while(num>0){
                rem=num%10;
                num=num/10;
                sum2=sum2+rem;
            }
            sum1=sum1+sum2;
        }
        System.outprintln("transformation 1 :" + sum1);
     }
    }
}
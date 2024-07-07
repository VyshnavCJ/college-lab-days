import java.util.*;



class count
        {
                public static void main(String args[])
                {

                        System.out.println("Enter the string");
                        Scanner s= new Scanner(System.in);
                        String str=s.nextLine();
                        System.out.println("Enter the character:");
                        char c=s.nextLine().charAt(0);
                        int count=0;
                        for(int i=0;i<str.length();i++)
                        {
                                if(c==str.charAt(i))
                                {
                                        count++;
                                }
                        }
                System.out.println("Frequeny is "+count);
                }
        }



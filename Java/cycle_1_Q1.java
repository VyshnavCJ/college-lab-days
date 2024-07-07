import java.util.*;

class Palind{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		System.out.println("Enter the string: ");
		String str=in.nextLine();
        in.close();
		int i,len=str.length()-1;
		for(i=0;i<str.length()/2;i++){
			if(str.charAt(i)!=str.charAt(len)){
				System.out.println("The string is not palindrome");
				break;
			}
			len-=1;
		}
		if(i==str.length()/2){
			System.out.println("The string is palindrome");
	}
    }
}

import java.util.*;
class Sumtoken{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the Integers in a sequence");
		String digit = sc.nextLine();
		StringTokenizer token = new StringTokenizer(digit);
		int dig =0,sum = 0;
		System.out.println("Entered Integer is: ");
		while(token.hasMoreTokens()){
			String s = token.nextToken();
			dig = Integer.parseInt(s);
			System.out.println(dig);
			sum+=dig;
		}
		System.out.println("");
		System.out.println("The sum of the integer is "+sum);
	}

}

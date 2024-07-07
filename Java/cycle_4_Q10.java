import java.io.*;
import java.util.*;
class Th
{
	 void divide(int a,int b) throws ArithmeticException 
	{
		if(b==0)
		throw new ArithmeticException(" cannot be divided by 0 ");
		else
		System.out.println("Ans = "+(a/b));
	}
}
class Main{
	public static void main(String[] args)
	{
		PrintWriter os = null;
		try{
			os = new PrintWriter(new FileOutputStream("Out.txt"));
		}
		catch(FileNotFoundException e )
		{
			System.out.println(" File Not Found ");
			System.exit(0);
		}
		int count;
		for(count=1;count<=3;count++)
		{
			os.println(count+"abc");
		}
		os.close();
		System.out.println("....Written in File....");
		try
		{
			FileInputStream fin = new FileInputStream("Out.txt");
			int i =fin.read();
			while(i!=-1)
			{
				System.out.print((char)i);
				i = fin.read();
			}
			fin.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		try
		{
			System.out.println(" Enter two numbers to add ");
			int a,b;
			Scanner sc = new Scanner(System.in);
			a = sc.nextInt();
			b = sc.nextInt();
			Th th = new Th();
			th.divide(a,b);
			sc.close();
		}
		catch(ArithmeticException e )
		{
			System.out.println(e);
		}
		finally
		{
			System.out.println(" Program Ended ");
		} 
		
	}

}


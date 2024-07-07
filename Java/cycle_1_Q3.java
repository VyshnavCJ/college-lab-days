import java.util.*;

class Matrix{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int r1,c1,r2,c2;
		System.out.print("Enter the order of the matrix: ");
		r1=in.nextInt();
		c1=in.nextInt();
		int a[][]=new int[r1][c1];
		System.out.println("Enter the matrix");
		for(int i=0;i<r1;i++){
			for(int j=0;j<c1;j++){
				a[i][j]=in.nextInt();
			}
		}
		System.out.print("Enter the order of the matrix: ");
		r2=in.nextInt();
		c2=in.nextInt();
		int b[][]=new int[r2][c2];
		System.out.println("Enter the matrix");
		for(int i=0;i<r2;i++){
			for(int j=0;j<c2;j++){
				b[i][j]=in.nextInt();
			}
		}
		if(c1!=r2){
			System.out.println("Matrix cannot be multiplied");
		}else{
			int c[][]=new int[r1][c2];
			for(int i=0;i<r1;i++){
				for(int j=0;j<c2;j++){
					c[i][j]=0;
					for(int k=0;k<c1;k++){
						c[i][j]+=a[i][k]*b[k][j];
					}
				System.out.print(c[i][j]+"\t");
				}
			System.out.println();
			}
		}
        in.close();
    }
}

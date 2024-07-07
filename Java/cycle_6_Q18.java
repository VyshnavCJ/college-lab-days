import java.util.*;

class Binary{

	static int binarySearch(int[] arr, int l,int h,int item){
		int mid=l+(h-l)/2;
		if(l>h){
			return -1;
		}
		if(arr[mid]==item){
			return mid;
		}
		if(arr[mid]<item){
			return binarySearch(arr,mid+1,h,item);
		}
		if(arr[mid]>item){
			return binarySearch(arr,l,mid-1,item);
		}
		return -1;
	}

	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int n;
		System.out.println("Enter the length of the array: ");
		n=in.nextInt();
		int[] a=new int[n];
		System.out.println("Enter the array: ");
		for(int i =0;i<n;i++){
			a[i]=in.nextInt();
		}
		System.out.println("Enter the item to be searched: ");
		int item=in.nextInt();
		int index=binarySearch(a,0,n-1,item);
		if(index==-1){
			System.out.println("The element is not found in the array");
		}else{
			index+=1;
			System.out.println("The element is found at "+ index);
	 	}
        in.close();
	}

}

import java.util.*;
class Doublylinked{
	Scanner sc = new Scanner(System.in);
	class Node{
		int data;
        	Node Llink = null;
        	Node Rlink = null;
		Node(int data){
			this.data = data;	
		}
	}
	Node Head;
	void CreateNode(int n){
                Head = new Node(0);
                Node ptr1;
                ptr1 = Head;
                for(int i=0; i<n;i++){
                        System.out.print("Enter the element: ");
                        int data = sc.nextInt();
			Node ptr2 = new Node(data);
                        ptr2.Rlink = null;
                        ptr2.Llink = ptr1;
                        ptr1.Rlink  = ptr2;
                        ptr1=ptr1.Rlink;
                }
        }

	void TraverseNode(){
                if(Head.Rlink==null){
                        System.out.println("Empty set");
                }
                else{
                        Node ptr = Head.Rlink;
                        System.out.println("The element are: ");
                        while(ptr!=null){
                                System.out.print(ptr.data + "\t");
                                ptr = ptr.Rlink;
                        }
                }
                System.out.println("");
        }
	void DeleteNodeFirst(){
                Node ptr1 = Head.Rlink;
                Node ptr2;
                ptr2=ptr1.Rlink;
                if(ptr2!=null)
                        ptr2.Llink = Head;
                Head.Rlink = ptr2;
                }
        void DeleteNodeEnd(){
                Node ptr1 = Head;
                while(ptr1.Rlink!=null)
                        ptr1=ptr1.Rlink;
                Node ptr2 = ptr1.Llink;
                ptr2.Rlink = null;

        }
	void DeleteNode(int key){
                Node ptr1 = Head;
                Node ptr2;
                int postion=0;
                while(ptr1.data!=key && ptr1.Rlink!=null){
                        ptr1=ptr1.Rlink;
                        postion++;
                }
                if(ptr1.data==key){
                        if(ptr1.Rlink==null){
                                DeleteNodeEnd();
                        }
                        else if(postion==1){
                                DeleteNodeFirst();
                        }
                        else{
                                ptr2 = ptr1.Llink;
                                ptr2.Rlink = ptr1.Rlink;
                                ptr1.Rlink.Llink=ptr2;
                        }
                }
                else{
                        System.out.println("Element not present in the list");
                }
        }
}


class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of nodes you want in the linked list: ");
                int x = sc.nextInt();
		Doublylinked DB = new Doublylinked();
                DB.CreateNode(x);
                DB.TraverseNode();
                int y;
                char c;
                int option;
                System.out.print("Operations\n1 - Deletion from the front\n2 - Deletion from the end\n3 - Deletion from any position\n4 - Traversal\n");
                do
                {
                        System.out.print("Enter(\t1\t2\t3\t4) :");
                        option = sc.nextInt();
                        switch (option)
                        {
                                case 1:
                                        DB.DeleteNodeFirst();
                                        break;
                                case 2:
                                        DB.DeleteNodeEnd();
                                        break;
                                case 3:
					System.out.print("Enter key :");
                                        y = sc.nextInt();
                                        DB.DeleteNode(y);
                                        break;
				case 4:
					DB.TraverseNode();
					break;
				default:
					System.out.println("Wrong option");
                                        break;
			}
			System.out.print("Do want to perform more operations ?(y/n) :");
                        c =  sc.next().charAt(0);
                } while (c == 'y' || c == 'Y');
                sc.close();
        }
        
}

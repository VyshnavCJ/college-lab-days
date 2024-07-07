import java.io.*;
class FileDemo{
public static void main(String[] args)
{
    PrintWriter os = null;
    try{
            os = new PrintWriter(new FileOutputStream("out.txt"));
        }
            catch(FileNotFoundException e){
            System.out.println("File not found.");
            System.exit(0);
        }
    int count;
    for(count =1;count<=3;count++){
        os.println(count+" + " +count +" = " + 2*count );
    }
    os.close();
    System.out.println("...written in file...");
    try{
        FileInputStream fin=new FileInputStream("out.txt");
        int i=fin.read();
        while(i!=-1){
        System.out.print((char)i);
        i=fin.read();
    }
    fin.close();
    }catch(Exception e){System.out.println(e);}
}
}


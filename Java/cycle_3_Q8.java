
import java.io.*;
import java.util.*;
class ReadFile{
        public static void main(String[] args) throws IOException, FileNotFoundException{
                try{
                        File obj = new File("MyFile.txt");
                        Scanner myreader= new Scanner(obj);
                        while(myreader.hasNextLine()){
                                String data = myreader.nextLine();
                                System.out.println(data);
                        }
                        myreader.close();
                }
                catch(FileNotFoundException e){
                        System.out.println("File not present\nCreating new file");
                        String str = "Filehandling in java using" + "FileWriter and FileReader";
                        FileWriter fw = new FileWriter("output.txt");
                        for(int i=0;i<str.length();i++)
                        fw.write(str.charAt(i));
                        System.out.println("Writing successful");
                        fw.close();
                }finally{
                        System.out.println("Program Ended");
                }
        }
}


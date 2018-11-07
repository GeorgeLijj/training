import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class Translate {
    public static void main(String[] args)throws IOException {
        Scanner scanner=new Scanner(System.in);
        String input=scanner.nextLine();
        if(input.length()>3){
            System.out.println(EngToNum.translate(input));
        }else{
            int num=Integer.parseInt(input);
            System.out.println( NumToEng.translate(num));
        }
    }

}

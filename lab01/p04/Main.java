import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while(scanner.hasNextLine()){
            String line = scanner.nextLine();

            StringBuilder buff = new StringBuilder();
            for(char c : line.toCharArray()){
                if(Character.isLetter(c)){
                    buff.append(Character.toLowerCase(c));
                }
            }

            StringBuilder temp = buff; //reference semantics 
            //StringBuilder temp = new StringBuilder(buff);
            temp.reverse();
            
            System.out.println(buff.toString().equals(temp.toString()) ? "palindrome" : "not a palindrome");
        }
    }
}



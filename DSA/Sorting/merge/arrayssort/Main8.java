import java.util.*;
//sorting an array list in ascending order
public class Main8{
    public static void main(String[] args){
        ArrayList<String> al = new ArrayList<String>(); 
        al.add("Geeks For Geeks"); 
        al.add("Friends"); 
        al.add("Dear"); 
        al.add("Is"); 
        al.add("Superb"); 

        Collections.sort(al);

        System.out.println(al);
    }
}

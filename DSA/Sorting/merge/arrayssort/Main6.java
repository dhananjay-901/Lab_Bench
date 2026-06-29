import java.util.*;
class Student implements Comparable<Student>{
    int id;
    String name;

    Student(int id, String name){
        this.id = id;
        this.name = name;
    }

    @Override
    public int compareTo(Student other){
        if(other==null){
            throw new NullPointerException("cannot comapre with null");
        }
        return Integer.compare(this.id, other.id);
    }

    @Override
    public String toString(){
        return id + "-" + name;
    }
}
public class Main6{
    public static void main(String[] args){
        List<Student> students = new ArrayList<>();
        students.add(new Student(3, "alice"));
        students.add(new Student(1, "bob"));
        students.add(new Student(2, "charlie"));

        Collections.sort(students);
        System.out.println(students);
    }
}

/*explanation

*/
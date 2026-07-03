
import java.util.Arrays;


class Student implements Comparable<Student>{
    int r;
    String n;
    String a;

    public Student(int r, String n, String a){
        this.r = r;
        this.n = n;
        this.a = a; 
    }

    public int compareTo(Student o){
        return this.n.compareTo(o.n);
    }

    public String toString(){
        return this.r + this.n + this.a;
    }
}

public class Main5{
    public static void main(String[] args){
        Student[] s = {
            new Student(1,"ram", "up"),
            new Student(2,"shyam", "mp"),
            new Student(3,"hari", "delhi")
        };
        Arrays.sort(s);
        for(Student student : s){
            System.out.println(student);
        }
    }
}
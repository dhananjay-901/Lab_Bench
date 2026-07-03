import java.util.*;
public class Main4{
    static class Student{
        int roll;
        String name;
        String address;
        Student(int roll, String name, String address){
            this.roll = roll;
            this.name = name;
            this.address = address;
        }

        public String toString(){
            return roll + " " + name + " " + address;
        }
    }

    static class sortbyroll implements Comparator<Student>{
        public int compare(Student s1, Student s2){
            return Integer.compare(s1.roll, s2.roll);
        }
    }
    public static void main(String[] args) {
        Student[] students = {
            new Student(1,"ram", "mp"),
            new Student(2, "shyam", "up"),
            new Student(3, "hari", "delhi")
        };

        Arrays.sort(students, new sortbyroll());

        for(Student s : students){
            System.out.println(s);
        }
    }
}
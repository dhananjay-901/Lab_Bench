import java.util.*;
class Student implements Comparable<Student>{
    String name;
    int marks;
    Student(String name, int marks){
        this.name = name;
        this.marks = marks;
    }

    @Override
    public int compareTo(Student other){
        return Integer.compare(this.marks, other.marks);
    }

    @Override
    public String toString(){
        return name + " " + marks;
    }
}

public class Main7 {
    public static void main(String[] args){
        List<Student> students = new ArrayList<>();
        students.add(new Student("Alice", 85));
        students.add(new Student("Bob", 92));
        students.add(new Student("Charlie", 78));

        Collections.sort(students);
        for(Student s: students){
            System.out.println(s);
        }
    }
}

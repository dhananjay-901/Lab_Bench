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

/*sorting my marks 
- defines natural order by marks using compareTo
- collections.sort() automatically arranges elements in ascending order
- the toString method is used to print objects in a readable format.

advantages of comparable interface
- defines the natural ordedring of objects automatically
- eliminates the need for a seperate comparator class for simple sorting
- makes sorting custome objects easier and more efficient
- provides consistent ordering in collections like treeset and treemap
- improves code maintainability by keeping sorting logic inside the class
*/

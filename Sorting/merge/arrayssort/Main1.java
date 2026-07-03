import java.util.Arrays;

public class Main1{
public static void main(String[] args) {
        int[] arr1 = {2,-1,3,4};
        char[] arr2 = {'b', 'a', 'c', 'b'};
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        System.out.println(Arrays.toString(arr1));
        System.out.println(Arrays.toString(arr2));
    }
}

/*the arrays.sort() method in java is used to arrange array elements in ascending order. it works with different data types like integers, characters, strings and more making sorting simple and efficient 
arra.sort() does not remove duplicates it only reorders elements
primitive types cannot use custom comparators sorting is in natural [ascending] order.
*/
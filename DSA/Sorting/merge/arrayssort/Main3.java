import java.util.Arrays;
import java.util.Collections;

public class Main3{
    public static void main(String[] args) {
        Integer[] arr = {2,-1,3,4};
        Arrays.sort(arr, Collections.reverseOrder());
        System.out.println(Arrays.toString(arr));

        String[] str = {"hi", "vishnu", "chauhan"};
        Arrays.sort(str, Collections.reverseOrder());
        System.out.println(Arrays.toString(str));
    }
}
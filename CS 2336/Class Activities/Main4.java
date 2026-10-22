/* This program creates an ArrayList and a LinkedList, adds and removes values
and then searches, replaces, and outputs the values in both lists. */
import java.util.ArrayList;
import java.util.LinkedList;

public class Main4 {
    public static void main(String[] args) {
        // Creates an ArrayList and a LinkedList to store integer values
        ArrayList<Integer> arrayList = new ArrayList<>();
        LinkedList<Integer> linkedList = new LinkedList<>();

        // Adds multiples of 11 from 11 through 99 to both lists
        for (int i = 11; i <= 99; i+= 11) {
            arrayList.add(i);
            linkedList.add(i);
        }

        // Adds 40 at index 4 in both lists
        arrayList.add(4, 40);
        linkedList.add(4, 40);

        // Adds 67 at index 5 in both lists
        arrayList.add(5, 67);
        linkedList.add(5, 67);

        // Removes the value at index 7 from both lists
        arrayList.remove(7);
        linkedList.remove(7);

        // Outputs the index of 55 in both lists
        System.out.println("ArrayList index of 55: " + arrayList.indexOf(55));
        System.out.println("LinkedList index of 55: " + linkedList.indexOf(55));

        // Outputs the index of 3 in both lists
        System.out.println("ArrayList index of 3: " + arrayList.indexOf(3));
        System.out.println("LinkedList index of 3: " + linkedList.indexOf(3));

        // Replaces the value at index 5 with 100 in both lists
        arrayList.set(5, 100);
        linkedList.set(5, 100);

        // Outputs the final values in both lists
        System.out.println("ArrayList: " + arrayList);
        System.out.println("LinkedList: " + linkedList);
    }
}

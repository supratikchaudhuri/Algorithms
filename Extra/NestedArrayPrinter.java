package Extra;

public class NestedArrayPrinter {

    public static Object[] nestedArray = new Object[]{"1", "2", "3", new Object[]{"blue", "yellow", "red"}, "5", new Object[]{"helicopter", "blimp", new Object[]{"biplane", "seaplane", new Object[]{"B-52", "F-35", "A-12"}}}, "7"};

    public static void main(String[] args) {
        printNestedArray(nestedArray, "");
    }

    public static void printNestedArray(Object[] array, String indexPrefix) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] instanceof Object[]) {
                printNestedArray((Object[]) array[i], indexPrefix + i + ".");
            } else {
                System.out.println(indexPrefix + i + ": " + array[i]);
            }
        }
    }
}

// In this problem you have a nested array of strings.
//      Lists of strings can be nested to an arbitrary depth.
//      Print each element contained in the list, including all elements in nested lists.
//      Each element should be printed on a new line with the element's index at the beginning of the line.

// 	input: 
// 	 public static Object[] nestedArray = new Object[]{"1", "2", "3", new Object[]{"blue", "yellow", "red"}, "5", new Object[]{"helicoptor", "blimp",new Object[]{"biplane", "seaplane", new Object[]{"B-52", "F-35", "A-12"}}},"7"};

// 	output: 
// 	    0: 1
//      1: 2
//      2: 3
//      3.0: blue
//      3.1: yellow
//      3.2: red
//      4: 5
//      5.0: helicoptor
//      5.1: blimp
//      5.2.0 : biplane
//      5.2.1 : seaplane
//      5.2.2.0 : B-52
//      5.2.2.1 : F-35
//      5.2.2.2 : A-12
//      6: 7
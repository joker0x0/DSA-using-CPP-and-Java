public class LinearArray {

    int itemCount;
    int array[];

    public LinearArray(int size) {
        itemCount = 0;
        array = new int[size];
    }

    public void insertLast(int x) {
        if (itemCount < array.length) {
            array[itemCount++] = x;
        } else {
            System.out.println("Array is full");
        }
    }

    public void insertFirst(int x) {
        if (itemCount < array.length) {
            for (int i = itemCount; i > 0; i--) {
                array[i] = array[i - 1];
            }
            array[0] = x;
            itemCount++;
        } else {
            System.out.println("Array is full");
        }
    }

    public int linearSearch(int x) {
        for (int i = 0; i < itemCount; i++) {
            if (array[i] == x) {
                return i;
            }
        }
        return -1;
    }

    public void delete(int x) {
        int pos = this.linearSearch(x);
        if(pos != -1) {
            for(int i = pos; i < itemCount; i++) {
                array[i] = array[i + 1];
            }
            itemCount--;
        }
    }

    public void display() {
        for(int i = 0; i < itemCount; i++) {
            System.out.print(array[i] + " ");
        }
    }

    public static void main(String[] args) {
        LinearArray obj = new LinearArray(10);
        obj.insertLast(5);
        obj.insertLast(6);
        obj.insertLast(1);
        obj.insertLast(2);
        obj.insertLast(9);
        obj.insertLast(4);
        obj.insertLast(3);
        System.out.print("Array after insertion: ");
        obj.display();
        System.out.println("");
        obj.insertFirst(0);
        System.out.print("Array after insert first: ");
        obj.display();
        System.out.println("");
        obj.delete(9);
        System.out.print("Array after deletion: ");
        obj.display();
        System.out.print("Find non existing item: ");
        System.out.println(obj.linearSearch(9));
        System.out.print("Find existing item: ");
        System.out.println(obj.linearSearch(3));


    }
}
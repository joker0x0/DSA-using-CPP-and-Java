public class LinearSortedArray {
    int itemCount;
    int array[];

    public LinearSortedArray(int maxSize){
        array = new int[maxSize];
    }

    public void orderedInsert(int x) {
        if(itemCount < array.length) {
            int insertPos = 0;
            while(insertPos < itemCount && array[insertPos] < x) {
                insertPos++;
            }

            for(int k = itemCount; k > insertPos; k--) {
                array[k] = array[k-1];
            }
            array[insertPos] = x;
            itemCount++;
        }
        else {
            System.out.println("Array is full");
        }
    }

    public void display() {
        for(int i = 0; i < itemCount; i++) {
            System.out.print(array[i] + " ");
        }
    }

    public static void main(String [] args) {
        LinearSortedArray array = new LinearSortedArray(5);
        array.orderedInsert(6);
        array.orderedInsert(5);
        array.orderedInsert(8);
        array.orderedInsert(1);

        array.display();
    }

}
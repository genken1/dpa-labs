package com.company;


public class MyHashSet {
    private ProductData array[];
    private int capacity;

    public MyHashSet(int capacity) {
        this.capacity = capacity;
        array = new ProductData[capacity];
        for (int i = 0; i < capacity; i++)
            array[i] = null;
    }


    public boolean add(ProductData e) {
        int hCode = e.hashCode() % capacity;
        if (array[hCode]!= null && array[hCode].equals(e))
            return false;
        else {
            array[hCode] = e;
            return true;
        }
    }


    public boolean contains(ProductData e) {
        int hCode = e.hashCode() % capacity;
        return array[hCode].equals(e);

    }

    public boolean remove(ProductData e) {
        int hCode = e.hashCode() % capacity;
        if (!array[hCode].equals(e))
            return false;
        else {
            array = removeTheElement(array, hCode);
            capacity--;
            return true;
        }
    }


    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < capacity; i++) {
            res.append(i).append(":").append(array[i]).append("\n");
        }
        return res.toString();
    }

    private ProductData[] removeTheElement(ProductData[] arr, int index) {
        if (arr == null | index < 0 || index >= arr.length) {
            return arr;
        }

        ProductData[] anotherArray = new ProductData[arr.length - 1];

        for (int i = 0, k = 0; i < arr.length; i++) {
            if (i == index) {
                continue;
            }
            anotherArray[k++] = arr[i];
        }
        return anotherArray;
    }
}
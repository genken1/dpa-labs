package com.company;


public class Main {
    public static void main(String[] args) {
        final int SIZE = 10;
        MyHashSet set = new MyHashSet(SIZE);
        for(int i=0; i<SIZE; i++){
            int id = (int) (Math.random()*100000);
            set.add(new ProductData("Product"+i, id));
        }
        System.out.println(set.contains(new ProductData("Product"+1, 1)));
        System.out.println(set);
        set.remove(new ProductData("Product"+1, 1));
        System.out.println(set);
    }
}

package com.company.Exercice1;

import java.util.TreeSet;

public class PriorityQueue<T>{

    private TreeSet<T> tree;

    public PriorityQueue() {
        tree = new TreeSet<>();
    }

    public void offer(T o) {
        tree.add(o);
    }

    public void poll() {
        if(!tree.isEmpty()) tree.pollFirst();
    }

    public T peek() {
        return tree.first();
    }

    public boolean isEmpty() {
        return tree.isEmpty();
    }

    public int Size(){
        return tree.size();
    }
}

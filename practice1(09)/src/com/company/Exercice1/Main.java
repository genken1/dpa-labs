package com.company.Exercice1;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        ArrayList<Node> list = new ArrayList<>();
        Node node1 = new Node("M", 12, 1);
        Node node2 = new Node("K", 13, 2);
        Node node3 = new Node("P", 14, 3);
        Node node4 = new Node("M", 15, 4);
        Node node5 = new Node("M", 16, 5);
        PriorityQueue<Node> queue = new PriorityQueue<Node>();

        queue.offer(node1);
        queue.offer(node2);
        queue.offer(node3);
        queue.offer(node4);
        queue.offer(node5);

        printInfo(queue);
    }

    public static void printInfo(PriorityQueue<Node> prQueue) {
        int mTime=0, kTime=0, pTime=0;
        int size = prQueue.Size();

        for (int i = 0; i < size; i++) {
            System.out.println(prQueue.peek());
            Node n = prQueue.peek();
            if (n.getCategory() == "M") {
                mTime += n.getTime();
            }
            else if (n.getCategory() == "P") {
                pTime += n.getTime();
            }
            else if (n.getCategory() == "K") {
                kTime += n.getTime();
            }
            prQueue.poll();
        }
        System.out.println("Time Manager = " + mTime);
        System.out.println("Time Controller = " + kTime);
        System.out.println("Time Worker = " + pTime);
    }
}

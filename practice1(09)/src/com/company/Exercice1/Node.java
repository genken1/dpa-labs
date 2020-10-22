package com.company.Exercice1;

public class Node implements Comparable<Node>{
    private String category;
    private int time, number, priority;

    public Node(String category, int time, int number) {
        this.category = category;
        this.time = time;
        this.number = number;
        if(category.equals("M"))
            this.priority = 1;
        else if (category.equals("K"))
            this.priority = 2;
        else if(category.equals("P"))
            this.priority = 3;
    }


    @Override
    public int compareTo(Node o) {
        if(priority == o.priority) return 1;
        return priority - o.priority;
    }

    @Override
    public String toString() {
        return "Node{" +
                "category='" + category + '\'' +
                ", time=" + time +
                ", number=" + number +
                '}';
    }

    public String getCategory() {
        return category;
    }

    public int getTime() {
        return time;
    }
}

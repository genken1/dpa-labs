package com.company;

public class AVLTree {
    private Node node;

    private class Node {
        int key;
        byte height; // разница высот левого и правого поддерева
        Node left;
        Node right;

        public Node(int key) {
            this.key = key;
            left = null;
            right = null;
            height = 1;
        }
    }

    private int height(Node node) {
        return node != null ? node.height : 0;
    }

    private int bFactor(Node node) { //поиск разница высот левого и правого поддерева
        return height(node.right) - height(node.left);
    }

    private void fixHeight(Node node) { //восстанавливает корректное значение поля height
        int hl = height(node.left);
        int hr = height(node.right);
        node.height = (byte) ((Math.max(hl, hr))+1);
    }

    private Node rotateRight(Node p) // правый поворот вокруг p
    {
        Node q = p.left;
        p.left = q.right;
        q.right = p;
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    private Node rotateLeft(Node q) // левый поворот вокруг q
    {
        Node p = q.right;
        q.right = p.left;
        p.left = q;
        fixHeight(q);
        fixHeight(p);
        return p;
    }

    private Node balance(Node p) // балансировка узла p
    {
        fixHeight(p);
        if (bFactor(p) == 2) {
            if (bFactor(p.right) < 0)
                p.right = rotateRight(p.right);
            return rotateLeft(p);
        }
        if (bFactor(p) == -2) {
            if (bFactor(p.left) > 0)
                p.left = rotateLeft(p.left);
            return rotateRight(p);
        }
        return p; // балансировка не нужна
    }

    private Node insert(Node p, int k) // вставка ключа k в дерево с корнем p
    {
        if (p == null) return new Node(k);
        if (k < p.key)
            p.left = insert(p.left, k);
        else
            p.right = insert(p.right, k);
        return balance(p);
    }

    private Node findMin(Node p) // поиск узла с минимальным ключом в дереве p
    {
        return p.left != null ? findMin(p.left) : p;
    }

    private Node removeMin(Node p) // удаление узла с минимальным ключом из дерева p
    {
        if (p.left == null)
            return p.right;
        p.left = removeMin(p.left);
        return balance(p);
    }

    private Node remove(Node p, int k) // удаление ключа k из дерева p
    {
        if (p == null) return null;
        if (k < p.key)
            p.left = remove(p.left, k);
        else if (k > p.key)
            p.right = remove(p.right, k);
        else //  k == p->key
        {
            Node q = p.left;
            Node r = p.right;
            // delete p;
            if (r == null) return q;
            Node min = findMin(r);
            min.right = removeMin(r);
            min.left = q;
            return balance(min);
        }
        return balance(p);
    }

    public void add(int k){
        if(node == null) node = new Node(k);
        else node = insert(node, k);
    }

    public void remove(int k){
        if(node != null) node = remove(node, k);
    }

    public void print(){
        printBinaryTree(node, 0);
    }

    public void printBinaryTree(Node node, int level) {
        if (node != null) {
            printBinaryTree(node.left, level + 1);
            for (int i = 0; i < level; i++)
                System.out.print("   ");//чем ниже уровень, тем отступ больше
            System.out.println(node.key);
            printBinaryTree(node.right, level + 1);
        }
    }
}

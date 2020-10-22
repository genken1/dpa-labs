package com.company;

public class ProductData {
    private String name;
    private int number;

    public ProductData(String name, int number) {
        this.name = name;
        this.number = number;
    }

    @Override
    public String toString() {
        return "ProductData{" +
                "name='" + name + '\'' +
                ", number=" + number +
                '}';
    }

    public boolean equals(ProductData obj) {
        return name.equals(obj.name) && number==obj.number;
    }

    @Override
    public int hashCode() {
        return number;
    }
}

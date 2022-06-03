package com.company;

public class StaticClass {
    public static int id = 0;

    public static void StaticMethod() {
        id++;
        System.out.println("Static Method, static instance variable id= " + id);
    }
}

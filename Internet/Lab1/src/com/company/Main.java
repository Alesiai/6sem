package com.company;

public class Main {

    public static void main(String[] args) {

        int a1, b1 = 3;
        float a2 = 4, b2 = 5;
        double a3 = 7, b3 = 8;

        a1=1;


        char a = 'a', b='b';
        System.out.println(
                "a1^2 - b1^2= " + (Math.pow(a1,2) - Math.pow(b1,2)) +
                "\na2^3 - b2^3= " + (Math.pow(a2,3) - Math.pow(b2,3)) +
                "\na3^4 - b3^4= " + (Math.pow(a3,4) - Math.pow(b3,4)) +
                "\na+b= "+ (a+b) +
                "\na-b= "+ (a-b));
    }
}

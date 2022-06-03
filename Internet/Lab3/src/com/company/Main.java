package com.company;

public class Main {

    public static void main(String[] args) {
        CCC ccc = new CCC();
        System.out.println("Empty designer: "+ ccc.x + " " + ccc.getY());
        ccc.x = 1;
        ccc.setY(2);
        System.out.println("Setting data: "+ ccc.x + " " + ccc.getY()+
                "\nSum: " + ccc.sum() +
                "\nDifference: " + CCC.ssub(ccc.x, ccc.getY()));

        CCC ccc2 = new CCC(1, 3);
        System.out.println("Fully designer: "+ ccc2.x + " " + ccc2.getY()+
                "\nSum: " + ccc2.sum()+
                "\nDifference: " + CCC.ssub(ccc2.x, ccc2.getY()));

        System.out.println("\nWork with DDD class\n");

        DDD ddd = new DDD();
        System.out.println("Empty designer: " + ddd.x + " " + ddd.getY());
        ddd.x = 4;
        ddd.setY(5);
        System.out.println("Setting data: "+ ddd.x + " " + ddd.getY()+
                "\nSum: " + ddd.sum(ddd.x, ddd.getY())+
                "\nCalc: " + ddd.calc(ddd.x, ddd.getY()));

        DDD ddd2 = new DDD(3, 5);
        System.out.println("Fully designer: "+ ddd2.x + " " + ddd2.getY() +
                "\nCalc: " + ddd2.calc(ddd2.x, ddd2.getY()));
    }
}
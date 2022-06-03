package com.company;

public class Main {

    public static void main(String[] args) {
        String s01 = new String();
        System.out.println("s01.length = " + s01.length());

        char[] cs = { '0', '1', '2', '3', '4', '5', '6', '7'};
        String s02 = new String(cs);
        System.out.println("s02.length = " + s02.length() + "\t s02 = " + s02);

        String s03 = new String(cs, 3, 5);
        System.out.println("s03.length = " + s03.length() + "\t s03 = " + s03);

        String s04 = "01234567";
        System.out.println("s04.length = " + s04.length() + "\t s04 = " + s04);

        String s05 =new String("01234567");
        System.out.println("s05.length = " + s05.length() + "\t s05 = " + s05);
        System.out.println();

        ////////////////////////////////////
        System.out.println("\"01234567\".length = " + "01234567".length());

        String s06 = new String("01234567");
        for (int i = 0; i<s06.length(); i++){
            System.out.print(s06.charAt(i) + ((i<s06.length()-1) ? "-" : ""));
        }

        System.out.println("");
        char[] cs1 = new char[4];
        s06.getChars(2, 6, cs1, 0);
        for(int i = 0; i<cs1.length; i++){
            System.out.print(cs1[i] + ((i < cs1.length - 1) ? "-" : ""));
        }
        System.out.println("\n");

        ////////////////////////
        String s07 = new String("01234567");
        String s08 = new String("01234567");
        System.out.println("(s07==s08) = " + (s07==s08));
        System.out.println("(s07==\"01234567\") = " + (s07=="01234567"));
        System.out.println("s07.equals(s08) = " + s07.equals(s08));
        String s09 = s08;
        System.out.println("(s08==s09) = " + (s08==s09));

        System.out.println();
        ////////////////////////////////////////
        String s10 = new String("hello world!");
        System.out.println(s10.indexOf('h'));
        System.out.println(s10.indexOf('o'));
        System.out.println(s10.lastIndexOf('o'));
        System.out.println(s10.indexOf('o', 5));
        System.out.println(s10.lastIndexOf('o', 10));
        System.out.println(s10.lastIndexOf('o', 5));

        System.out.println();
        //////////////////////////////////////////////////

        System.out.println(s10.substring(5));
        System.out.println(s10.substring(4, 8));

        System.out.println();
        /////////////////////////////////

        System.out.println(s10.replace('!', '?'));
        System.out.println(s10.toUpperCase());
        System.out.println(s10.toLowerCase());

        System.out.println();
        /////////////////////////////////////

        StringBuffer s15 = new StringBuffer(100);
        s15.append("Hello world!");
        System.out.println("s15.length() = " + s15.length());
        System.out.println("s15.capacity() = " + s15.capacity());
        s15.insert(5, " beautiful");
        System.out.println(s15);
        System.out.println("s15.length() = " + s15.length());
        System.out.println("s15.capacity() = " + s15.capacity());
        s15.delete(5,14);
        System.out.println(s15);
        s15.ensureCapacity(200);
        System.out.println("s15.capacity() = " + s15.capacity());
        String s16 = s15.toString();

        System.out.println();
        //////////////////////////////////////////

        Byte x1 = 3;
        Short x2 = 256;
        Integer x3 = 1000;
        Float x4 = 3.14f;
        Double x5 = 2.9e10;
        Long x6 = 200000000L;
        Character x7 = 'f';
        Boolean x8 = true;
        System.out.println(x1+"\t "+ x1.getClass()
                +"\n"+x2 +"\t "+ x2.getClass()
                +"\n"+x3+"\t "+ x3.getClass()
                +"\n"+x4+"\t "+ x4.getClass()
                +"\n"+x5+"\t "+ x5.getClass()
                +"\n"+x6 +"\t "+ x6.getClass()
                +"\n"+x7+"\t "+ x7.getClass()
                +"\n"+x8+"\t "+ x8.getClass());
        System.out.println();

        Planet planet = Planet.MARS;

        switch (planet){
            case MARS:
                System.out.println("MARS");
                break;
            case JUPITER:
                System.out.println("JUPITER");
                break;
            default:
                System.out.println("default");
        }
        System.out.println();

        Planet1 planet1 = Planet1.NEPTUNE;
        System.out.println(planet1.gravity);
        System.out.println(planet1.mass);
        System.out.println(planet1.radius);

        Muffin cherry = Muffin.Cherry;
        System.out.println(cherry.cost+" "+cherry.weight+" "+ cherry.structure);
        Muffin chocolate = Muffin.Chocolate;
        System.out.println(chocolate.cost+" "+chocolate.weight+" "+ chocolate.structure);
    }

    public enum Planet{
        MERCURY,
        VENUS,
        EARTH,
        MARS,
        JUPITER,
        SATURN,
        URANUS,
        NEPTUNE;
    }

    public enum Planet1{
        MERCURY(3.302e+23, 2.439e+06),
        NEPTUNE(1.024e+26, 2.477e+07);
        private final double mass;
        private final double radius;
        private final double gravity;
        private static final double G = 6.673000e-11;
        Planet1(double mass, double radius){
            this.mass = mass;
            this.radius = radius;
            this.gravity = G*mass/(radius*radius);
        }
    }

    public enum Muffin{
        Cherry(4000, "Cherry and chocolate"),
        Chocolate(5000, "Only chocolate");
        private final double cost;
        private final String structure;
        private final double weight;
        Muffin(double cost, String structure){
            this.cost = cost;
            this.structure = structure;
            this.weight = 4*cost;
        }
    }
}


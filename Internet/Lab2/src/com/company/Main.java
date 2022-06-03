package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println("Ex1 Array");
        int[] array = new int[10];
        String arrayResultString = "";

        for(int i=0; i<array.length; i++){
            array[i] = i;
            arrayResultString += Integer.toString(array[i]);
        }
        System.out.println(arrayResultString);

        System.out.println("\nEx2 Matrix");
        int[][] matrix = new int[5][5];
        for(int i=0; i< matrix.length; i++){
            String resultString = "";
            for(int j=0; j< matrix.length; j++){
                matrix[i][j] = i+j;
                resultString += Integer.toString(matrix[i][j]) + " ";
            }
            System.out.println(resultString);
        }

       System.out.println("\nEx3 >>>, <<=, ^= ,  & ,  ~.  Operations\n");
        int a1 = 2; //010
        int b1 = 4;//101
        System.out.println("a1=2(010) b1=5(101) " +
                "\na1&b1 = " + (a1&b1)+
                "\na1>>>b1 = " + (a1>>>b1) + //сдвиг вправо с заполнением нулями
                "\na1<<=b1 = " + (a1<<=b1) + //сдвиг влево с присваиванием
                "\na1^=b1 = " + (a1 ^= b1)+ //исключающее или(XOR)
                "\n~a1 = " + (~a1));     // отрицание

        System.out.println("\n Ex4");
        boolean result1 = false||true,
                result2 = false&&true,
                result3 = -5 < 0 ? true : false;

        System.out.println("false||true = "+ result1 + "\nfalse&&true = " + result2 + "\n-5 < 0 ? true : false = " + result3);
        System.out.println("\n Ex5");

        if(result1){
            for(int i=0; i<array.length; i++){
                arrayResultString += Integer.toString(array[i]);
            }
            System.out.println(arrayResultString);

            int i=1;
            while (i <= 3){
                System.out.println((i));
                i++;
            }

            do{
                System.out.println("do");
            }while(i==3);


            switch (i){
                case (1): System.out.println("case 1"); break;
                case (2): System.out.println("case 2"); break;
                case (3): System.out.println("case 3"); break;
                case (4): System.out.println("case 4"); break;
                default: System.out.println("default"); break;
            }
        }
        else{
            System.out.println("it's else");
        }

        System.out.println("Ex 6");
        StaticClass.StaticMethod();
        StaticClass.StaticMethod();
        StaticClass.StaticMethod();
    }
}


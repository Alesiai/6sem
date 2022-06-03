import A.*;
import A.AA.*;
import A.AA.AAA.AAAA.*;

public class Main {

    public static void main(String[] args) {
        Class1lv1 class1lv1 = new Class1lv1(1);

        Class1lv2 class1lv2 = new Class1lv2(2);
        Class2lv2 class2lv2 = new Class2lv2(2);

        Class1lv4 class1lv4 = new Class1lv4(4);
        Class2lv4 class2lv4 = new Class2lv4(4);

        System.out.println(class1lv1.toString());
        System.out.println(class1lv2.toString() + " " + class2lv2.toString());
        System.out.println(class1lv4.toString() + " " + class2lv4.toString());

        B.BClass1lv1 bClass1lv1 = new B.BClass1lv1(1);
        B.BB.BClass1lv2 bClass1lv2 = new B.BB.BClass1lv2(2);
        B.BB.BClass2lv2 bClass2lv2 = new B.BB.BClass2lv2(2);
        B.BB.BBB.BBBB.BClass1lv4 bClass1lv4 = new B.BB.BBB.BBBB.BClass1lv4(4);
        B.BB.BBB.BBBB.BClass2lv4 bClass2lv4 = new B.BB.BBB.BBBB.BClass2lv4(4);

        System.out.println();
        System.out.println(bClass1lv1.toString());
        System.out.println(bClass1lv2.toString() + " " + bClass1lv4.toString());
        System.out.println(bClass1lv4.toString() + " " + bClass2lv4.toString());

        System.out.println();
        B.BClass1lv1A bClass1lv11 = new B.BClass1lv1A(23333);

        System.out.println();
        A.ClassMotherB classMotherB = new A.ClassMotherB(9999999);
        classMotherB.print();
    }
}

import lvOne.ClassLv1;
import lvOne.lvTwo.ClassLv2;
import lvOne.lvTwo.lvThree.ClassLv3;
import lvOne.lvTwo.lvThree.lvFour.ClassLv4;

public class MMM {

    public void main(){
        System.out.println("MAIN METHOD MMM's CLASS");
    }

    public static void main(String[] args) {
        ClassLv4 classLv4 = new ClassLv4();
        ClassLv3 classLv3 = new ClassLv3();
        ClassLv2 classLv2 = new ClassLv2();
        ClassLv1 classLv1 = new ClassLv1();
        AAA aaa = new AAA();
        MMM mmm = new MMM();
        mmm.main();
    }
}
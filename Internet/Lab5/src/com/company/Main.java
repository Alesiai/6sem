package com.company;
import com.company.Person.Student.Class.AAA;
import java.util.Date;

public class Main {
    public static void main(String[] args) {
        AAA aaa = new AAA();
        aaa.setBirthday(2002, 00, 13);
        aaa.setFatherName("Boby");
        aaa.setName("Bob");
        aaa.setSurname("Jonson");
        aaa.setUniversity("BSTU");
        aaa.setFirstDate(new Date(2020,00,01));
        System.out.println("Birthday: " + aaa.getBirthday() + "\n" +
                "Name: "   + aaa.getName() + "\n" +
                "Surname: "  + aaa.getSurname() + "\n" +
                "Father Name: "   + aaa.getFatherName() + "\n" +
                "First date: "  + aaa.getFirstDate() + "\n" +
                "University: "  + aaa.getUniversity());
    }
}


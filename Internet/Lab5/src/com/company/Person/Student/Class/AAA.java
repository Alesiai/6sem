package com.company.Person.Student.Class;
import com.company.Person.Student.student;
import java.util.Date;

public class AAA implements student {
    private String Name;
    private String Surname;
    private String FatherName;
    private Date Birthday;
    private Date FirstDate;
    private String University;

    @Override
    public void setFirstDate(Date d) {
        d.setYear(d.getYear() - 1900);
        this.FirstDate = d;
    }

    @Override
    public void setUniversity(String university) {
        this.University = university;
    }

    @Override
    public void setSurname(String surname) {
        this.Surname = surname;
    }

    @Override
    public void setName(String name) {
        this.Name = name;
    }

    @Override
    public void setFatherName(String fatherName) {
        this.FatherName = fatherName;
    }

    @Override
    public void setBirthday(int yyyy, int mm, int dd) {
        this.Birthday = (yyyy>LimitBirthDay? new Date(yyyy-1900,mm,dd):null);
    }

    @Override
    public String getUniversity() {
        return University;
    }

    @Override
    public Date getFirstDate() {return FirstDate; }

    @Override
    public String getSurname() {
        return Surname;
    }

    @Override
    public String getName() {
        return Name;
    }

    @Override
    public String getFatherName() {
        return FatherName;
    }

    @Override
    public Date getBirthday() {
        return Birthday;
    }
}

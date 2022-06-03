package com.company.Person;
import java.util.Date;

public interface person {
    public int LimitBirthDay = 1900;
    public void setSurname(String surname);
    public void setName(String name);
    public void setFatherName(String fatherName);
    public void setBirthday(int yyyy, int mm, int dd);
    public String getSurname();
    public String getName();
    public String getFatherName();
    public Date getBirthday();
}


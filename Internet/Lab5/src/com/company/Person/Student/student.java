package com.company.Person.Student;

import com.company.Person.person;

import java.util.Date;

public interface student extends person {
    int LimitUniversityLength = 50;
    void setFirstDate(Date d);
    Date getFirstDate();
    void setUniversity(String university);
    String getUniversity();
}



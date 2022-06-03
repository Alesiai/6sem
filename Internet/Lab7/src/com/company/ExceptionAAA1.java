package com.company;

public class ExceptionAAA1 extends Exception {
    public ExceptionAAA1() {
    }

    @Override
    public String getMessage() {
        return "\nparameter is NULL " ;
    }

    @Override
    public void printStackTrace() {
        this.printStackTrace();
    }

    @Override
    public String toString() {
        return "\nMy string " + super.toString();
    }
}

package com.company;

public class ExceptionAAA2 extends Exception {

    public ExceptionAAA2() {
    }

    @Override
    public String getMessage() {
        return "\nparameter is 0 ";
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

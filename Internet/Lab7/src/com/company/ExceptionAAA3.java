package com.company;

public class ExceptionAAA3 extends Exception {

    public ExceptionAAA3() {
    }

    @Override
    public String getMessage() {
        return "\nparameter < 0 \n";
    }

    @Override
    public void printStackTrace() {
        this.printStackTrace();
    }

    @Override
    public String toString() {
        return "\nException string: " + super.toString();
    }
}

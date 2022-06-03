package com.company;

class DDD extends CCC {
    public int x;
    private int y;

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public DDD() {
        super();
        this.x = 1;
        this.y =1;
    }

    public DDD(int x, int y) {
        super(x, y);
        this.x = x;
        this.y = y;
    }

    public int sum(int x, int y) {
        return super.sum() + x + y;
    }

    public int calc(int x, int y) {
        return x * y + super.x * super.getY();
    }
}

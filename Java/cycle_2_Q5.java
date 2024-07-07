class Shape{
    void numberOfSides(){}
}

class Rectangle extends Shape{
    void numberOfSides(){
        System.out.println("The number of sides in Rectangle is 4");
    }
}

class Triangle extends Shape{
    void numberOfSides(){
        System.out.println("The number of sides in Triangle is 3");
    }
}

class Hexagon extends Shape{
    void numberOfSides(){
        System.out.println("The number of sides in Hexagon is 6");
    }
}

class ShapeDemo{
    public static void main(String[] args){
        Rectangle rc = new Rectangle();
        Triangle tr = new Triangle();
        Hexagon hc = new Hexagon();
        rc.numberOfSides();
        hc.numberOfSides();
        tr.numberOfSides();
    }
}

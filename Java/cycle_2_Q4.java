class Employee{
    String name;
    int age;
    long  phonenum;
    String address;
    double salary;
    void print_Salary(){
        System.out.println("The salary of the employee is " + salary);

    } 
}

class Officer extends Employee{
    String specialization;
    
}
class Manager extends Employee{
    String department;
    
}

class OfficeDemo{
    public static void main(String args[]){
        Officer of = new Officer();
        of.name = "Vyshnav";
        of.age = 20;
        of.address = "Kochi";
        of.salary = 1000000000;
        of.phonenum = 9846050605l;
        of.specialization = "marketing";
        Manager ma = new Manager();
        ma.name = "CJ";
        ma.age = 20;
        ma.address = "Maradu";
        ma.phonenum = 8589813520l;
        ma.salary = 100000000;
        ma.department = "cyber security";
        System.out.println("Officer");
        System.out.println();
        System.out.println("Name " + of.name);
        System.out.println("Age " + of.age);
        System.out.println("PhoneNumber " + of.phonenum);
        System.out.println("Address " + of.address);
        of.print_Salary();
        System.out.println("Specialization " + of.specialization);
        System.out.println();
        System.out.println("Manager ");
        System.out.println();
        System.out.println("Name " + ma.name);
        System.out.println("Age " + ma.age);
        System.out.println("PhoneNumber " + of.phonenum);
        System.out.println("Address " + ma.address);
        ma.print_Salary();
        System.out.println("Department " + ma.department);
        
    }
}
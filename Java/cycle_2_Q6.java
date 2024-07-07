class Student {
    Student() {
        System.out.println("\nHello Student");
    }
}

class Garbage {
    public static void main(String[] args) {
        int no_of_students = 5;
        Student obj;
        for (int i = 0; i < no_of_students; i++) {
            obj = new Student();
            System.out.println(obj);
        }
    }
}
/* This program uses an abstract employee class and different employee types
to calculate and output each employee's salary. */
abstract class Employee {
    // Defines the salary method that each employee type must use
    abstract double salary();
}

class PartTime extends Employee {
    int hours;

    // Calculates the salary based on the number of hours worked
    double salary() {
        return hours * 20;
    }
}

class FullTime extends Employee {
    // Returns the fixed salary for a full-time employee
    double salary() {
        return 8000;
    }
}

class Contract extends Employee {
    // Returns the fixed salary for a contract employee
    double salary() {
        return 6000;
    }
}

public class Main2 {
    public static void main(String[] args) {
        // Creates a part-time employee and sets the number of hours worked
        PartTime p1 = new PartTime();
        p1.hours = 100;

        // Creates a full-time employee and a contract employee
        FullTime f1 = new FullTime();
        Contract c1 = new Contract();

        // Outputs the salary for each employee
        System.out.println("Part time salary: " + p1.salary());
        System.out.println("Full time salary: " + f1.salary());
        System.out.println("Contract salary: " + c1.salary());
    }
}

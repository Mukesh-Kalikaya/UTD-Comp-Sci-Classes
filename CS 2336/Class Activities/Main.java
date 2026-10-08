/* This program uses inheritance to create different types of employees and
then calculates and outputs the salary for each type of employee. */
class Employees {
    // Returns the default employee salary
    double salary() {
        return 0;
    }
}

class PartTime extends Employees {
    double hours;

    // Calculates the salary based on the number of hours worked
    double salary() {
        return hours * 20;
    }
}

class FullTime extends Employees {
    // Returns the fixed salary for a full-time employee
    double salary() {
        return 80000;
    }
}

class Contract extends Employees {
    // Returns the fixed salary for a contract employee
    double salary() {
        return 60000;
    }
}

public class Main {
    public static void main(String[] args) {
        // Creates a part-time employee and sets the number of hours worked
        PartTime p1 = new PartTime();
        p1.hours = 20;

        // Creates a full-time employee and a contract employee
        FullTime f1 = new FullTime();
        Contract c1 = new Contract();

        // Outputs the salary for each employee
        System.out.println(p1.salary());
        System.out.println(f1.salary());
        System.out.println(c1.salary());
    }
}
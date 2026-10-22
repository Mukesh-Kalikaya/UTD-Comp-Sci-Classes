/* This program uses inheritance, an abstract employee class, and an interface
to calculate and output the salary and bonus for different types of employees. */
abstract class Employee {
    // Stores the employee's name, ID, and department
    String name;
    int id;
    String department;

    // Initializes the employee's information
    Employee(String name, int id, String department) {
        this.name = name;
        this.id = id;
        this.department = department;
    }

    // Defines the salary method that each employee type must use
    abstract double calculateSalary();

    // Outputs the employee's information
    void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.print("Department: " + department);
    }
}

interface Bonus {
    // Defines the method that an employee with a bonus must use
    double calculateBonus();
}

class FullTimeEmployee extends Employee implements Bonus {
    // Stores the full-time employee's monthly salary
    double monthlySalary;

    // Initializes the full-time employee's information and salary
    FullTimeEmployee(String name, int id, String department, double monthlySalary) {
        super(name, id, department);
        this.monthlySalary = monthlySalary;
    }

    // Returns the full-time employee's monthly salary
    double calculateSalary() {
        return monthlySalary;
    }

    // Calculates the full-time employee's bonus
    public double calculateBonus() {
        return calculateSalary() * 0.10;
    }
}

class PartTimeEmployee extends Employee implements Bonus {
    // Stores the part-time employee's hourly rate and hours worked
    double hourlyRate;
    int hoursWorked;

    // Initializes the part-time employee's information and work details
    PartTimeEmployee(String name, int id, String department, double hourlyRate, int hoursWorked) {
        super(name, id, department);
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    // Calculates the part-time employee's salary
    double calculateSalary() {
        return hourlyRate * hoursWorked;
    }

    // Calculates the part-time employee's bonus
    public double calculateBonus() {
        return calculateSalary() * 0.10;
    }
}

class Manager extends FullTimeEmployee {
    // Stores the manager's allowance
    double allowance;

    // Initializes the manager's information, salary, and allowance
    Manager(String name, int id, String department, double monthlySalary, double allowance) {
        super(name, id, department, monthlySalary);
        this.allowance = allowance;
    }

    // Calculates the manager's salary including the allowance
    double calculateSalary() {
        return monthlySalary + allowance;
    }
}


public class EmployeeTest {
    public static void main(String[] args) {
        // Creates a full-time employee, a part-time employee, and a manager
        FullTimeEmployee emp1 = new FullTimeEmployee("Alice", 101, "IT", 5000);
        PartTimeEmployee emp2 = new PartTimeEmployee("Bob", 102, "HR", 20, 80);
        Manager emp3 = new Manager("Charlie", 103, "Finance", 7000, 1500);

        // Outputs the full-time employee's details, salary, and bonus
        emp1.displayDetails();
        System.out.println("Salary: $" + emp1.calculateSalary());
        System.out.println("Bonus: $" + emp1.calculateBonus());

        System.out.println();

        // Outputs the part-time employee's details, salary, and bonus
        emp2.displayDetails();
        System.out.println("Salary: $" + emp2.calculateSalary());
        System.out.println("Bonus: $" + emp2.calculateBonus());

        // Outputs the manager's details, salary, and bonus
        emp3.displayDetails();
        System.out.println("Salary: $" + emp3.calculateSalary());
        System.out.println("Bonus: $" + emp3.calculateBonus());
    }   
}

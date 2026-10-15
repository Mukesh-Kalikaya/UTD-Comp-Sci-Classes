/* This program uses an abstract employee class and an interface to create
different types of university employees and then outputs their work. */
interface Teachable {
    // Defines the method that a teachable employee must use
    void teach();
}

abstract class Employee {
    // Stores the employee's name and email
    protected String name;
    protected String email;

    // Initializes the employee's name and email
    public Employee(String name, String email) {
        this.name = name;
        this.email = email;
    }

    // Defines the work method that each employee type must use
    abstract void work();
}

class Professor extends Employee implements Teachable {
    // Initializes a professor's name and email
    public Professor(String name, String email) {
        super(name, email);
    }

    // Outputs the work performed by the professor
    public void work() {
        System.out.println(name + " is teaching classses.");
    }

    // Outputs what the professor teaches
    public void teach() {
        System.out.println(name + " teaches students.");
    }
}

class Staff extends Employee {
    // Initializes a staff member's name and email
    public Staff(String name, String email) {
        super(name, email);
    }

    // Outputs the work performed by the staff member
    public void work() {
        System.out.println(name + " is doing university office work.");
    }
}

class StudentAssistant extends Employee {
    // Initializes a student assistant's name and email
    public StudentAssistant(String name, String email) {
        super(name, email);
    }

    // Outputs the work performed by the student assistant
    public void work() {
        System.out.println(name + " is assisting with university work.");
    }
}

public class Main3 {
    public static void main(String[] args) {
        // Creates a professor, a staff member, and a student assistant
        Professor p = new Professor("Alice", "alice@utd.edu");
        Staff s = new Staff("Bob", "bob@utd.edu");
        StudentAssistant sa = new StudentAssistant("Chris", "chris@utd.edu");
        
        // Outputs the work performed by the professor and what the professor teaches
        p.work();
        p.teach();

        // Outputs the work performed by the staff member
        s.work();

        // Outputs the work performed by the student assistant
        sa.work();
    }
}
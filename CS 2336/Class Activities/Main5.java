/* This program checks if an age is valid and outputs an error message
if the age is outside the valid range. */
class InvalidAgeException extends Exception {
    // Creates an exception with an error message
    public InvalidAgeException(String message) {
        super(message);
    }
}

public class Main5 {
    // Checks if the age is between 0 and 120
    public static void validate(int age) throws InvalidAgeException {
        if (age < 0 || age > 120) {
            throw new InvalidAgeException("Age must be between 0 and 120");
        }
    }

    public static void main(String[] args) {
        try {
            // Checks the age
            validate(150);
        } catch (InvalidAgeException e) {
            // Outputs the error message
            System.out.println(e.getMessage());
        }
    }
}

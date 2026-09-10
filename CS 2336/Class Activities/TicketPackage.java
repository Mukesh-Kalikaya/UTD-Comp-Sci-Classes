/* This program takes the age, height, and preferred parking zone and then using that,
it then determines the ticket package that the user is eligible for and the final price 
of that package.*/
import java.util.Scanner;

public class TicketPackage 
{
    public static void main(String[] args) 
    {
        // Define variables
        Scanner input = new Scanner(System.in);
        int age, height, price;
        char zone;
        String ticketType;

        // Get the age
        System.out.print("Enter age: ");
        age = input.nextInt();

        // Get the height
        System.out.print("Enter height (in inches): ");
        height = input.nextInt();

        // Get the park zone
        System.out.print("Enter park zone (A, W, F, T): ");
        zone = input.next().charAt(0);

        // Logic to handle all cases and match them with their respective prices
        if (age >= 16 && height >= 54 && (zone == 'T' || zone == 't')) 
        {
            ticketType = "Thrill Seeker Package";
            price = 75;
        } 
        else if (zone == 'W' || zone == 'w') 
        {
            ticketType = "Water Explorer Package";
            price = 55;
        } 
        else if (age <= 12 || zone == 'F' || zone == 'f') 
        {
            ticketType = "Family Fun Package";
            price = 40;
        } else 
        {
            ticketType = "General Admission";
            price = 50;
        }

        // Output the ticket type and the final cost to the user
        System.out.println("\nTicket Type: " + ticketType);
        System.out.println("Final Ticket Cost: $" + price);
    }
}

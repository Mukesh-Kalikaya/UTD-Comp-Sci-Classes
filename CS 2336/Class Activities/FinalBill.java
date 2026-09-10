/* This program gets the meal cost from the user and then uses the values for tips and tax (variable)
to calculate the total bill and outputs all of those values (meal cost entered, tax, tip and total cost)
to the user. */
import java.util.Scanner;

public class FinalBill 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);

        // Gets the meal cost from the user
        System.out.print("Enter the meal cost: $");
        double mealCost = input.nextDouble();

        // Sets the percentages for the tax and the tip
        double tax = 8.25 / 100;
        double tip = 18.00 / 100;

        // Calculates the total bill
        double totalBill = mealCost + (mealCost * tax) + (mealCost * tip);

        // Outputs the values to the user (the meal cost, the tax, the tip and the
        // final total bill.)
        System.out.println("Meal Cost: $" + mealCost);
        System.out.println("Tax: $" + tax);
        System.out.println("Tip: $" + tip);
        System.out.println("Total Bill: $" + totalBill);
    }
}

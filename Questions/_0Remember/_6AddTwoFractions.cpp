#include <iostream>
using namespace std;

// Function to calculate the Greatest Common Divisor (GCD) using the Euclidean algorithm
int calculateGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return calculateGCD(b, a % b);
    }
}

// Function to add two fractions and print the result in simplified form
void addFraction(int num1, int den1, int num2, int den2)
{
    int numResult, denResult;

    // Calculate the numerator and denominator of the result
    numResult = (num1 * den2) + (num2 * den1);
    denResult = den1 * den2;

    // Calculate the GCD of the result to simplify the fraction
    int gcd = calculateGCD(numResult, denResult);

    // Simplify the fraction by dividing the numerator and denominator by the GCD
    numResult /= gcd;
    denResult /= gcd;

    // Print the simplified fraction
    cout << numResult << "/" << denResult << endl;
}

// Main function to take input from user and call the addFraction function
int main()
{
    int num1, den1, num2, den2;

    // Taking input for the first fraction
    cin >> num1 >> den1;

    // Taking input for the second fraction
    cin >> num2 >> den2;

    // Add the fractions and print the result
    addFraction(num1, den1, num2, den2);

    return 0;
}

/*
 * Time Complexity:
 * - The time complexity of the `calculateGCD` function is O(log(min(a, b))) due to the Euclidean algorithm.
 * - The time complexity of the `addFraction` function is dominated by the `calculateGCD` call, so it is also O(log(min(numResult, denResult))).
 *
 * Space Complexity:
 * - The space complexity is O(1) because we are using a fixed amount of extra space for variables.
 */

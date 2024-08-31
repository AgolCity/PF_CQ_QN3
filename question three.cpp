#include <iostream>
using namespace std;

// (a) Function to compute the sum of all integers from 'first' to 'last' inclusive
int sum_from_to(int first, int last) {
    int sum = 0;
    
    // Ensure 'first' is less than or equal to 'last'
    if (first > last) {
        swap(first, last);  // Swap values if 'first' is greater than 'last'
    }

    for (int i = first; i <= last; i++) {
        sum += i;  // Add each number from 'first' to 'last' to 'sum'
    }
    
    return sum;
}

// Helper function to compute the greatest common divisor (GCD) using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// (b) Function to reduce a fraction by dividing numerator and denominator by their GCD
int reduce(int &num, int &denom) {
    // Return 0 if either number is non-positive
    if (num <= 0 || denom <= 0) {
        return 0;
    }
    
    int commonDivisor = gcd(num, denom);  // Find the GCD of 'num' and 'denom'
    
    // Reduce the fraction by dividing by the GCD
    num /= commonDivisor;
    denom /= commonDivisor;
    
    return 1;  // Return 1 to indicate successful reduction
}

int main() {
    // Example usage of sum_from_to function
    int first = 3, last = 7;
    cout << "Sum from " << first << " to " << last << " is: " << sum_from_to(first, last) << endl;

    // Example usage of reduce function
    int numerator = 8, denominator = 12;
    int result = reduce(numerator, denominator);
    if (result == 1) {
        cout << "Reduced fraction: " << numerator << "/" << denominator << endl;
    } else {
        cout << "Failed to reduce the fraction." << endl;
    }

    return 0;
}


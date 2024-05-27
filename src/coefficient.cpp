#include <iostream>
#include <cmath>

// Function to calculate the binomial coefficient "n choose k"
long long binomialCoefficient(int n, int k) {
    long long result = 1;
    if (k > n - k) {
        k = n - k;
    }
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

// Function to calculate the coefficient of x^k in (x + a)^n
long long coefficientOfX(int n, int k, int a) {
    if (k > n) {
        return 0; // No such term in the expansion
    }
    return binomialCoefficient(n, k) * pow(a, n - k);
}

int main() {
    int n1, a1, n2, a2, k, xMultiplier;
    std::cout << "Enter the exponent n for (x + a)^n in the first term: ";
    std::cin >> n1;
    std::cout << "Enter the constant a for (x + a)^n in the first term: ";
    std::cin >> a1;
    std::cout << "Enter the exponent n for (x + a)^n in the second term: ";
    std::cin >> n2;
    std::cout << "Enter the constant a for (x + a)^n in the second term: ";
    std::cin >> a2;
    std::cout << "Enter the exponent of x that multiplies the second term (enter 0 if none): ";
    std::cin >> xMultiplier;
    std::cout << "Enter the power k of x for which you want the coefficient: ";
    std::cin >> k;

    long long coefficient = 0;

    // Coefficient of x^k in (x + a1)^n1
    coefficient += coefficientOfX(n1, k, a1);

    // Adjust k for the x^multiplier in the second term
    int adjustedK = k - xMultiplier;

    // Coefficient of x^adjustedK in (x + a2)^n2
    coefficient += coefficientOfX(n2, adjustedK, a2);

    std::cout << "The coefficient of x^" << k << " in the expansion is: " << coefficient << std::endl;
    return 0;
}

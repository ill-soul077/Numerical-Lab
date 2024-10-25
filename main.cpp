
#include<bits/stdc++.h>
using namespace std;

// Function prototypes for Linear Equations methods
void jacobiMethod();
void gaussSeidelMethod();
void gaussElimination();
void gaussJordanElimination();
void luFactorization();

// Function prototypes for Non-linear Equations methods
void bisectionMethod();
void falsePositionMethod();
void secantMethod();
void newtonRaphsonMethod();

// Function prototype for Differential Equations
void rungeKuttaMethod();

// Function prototype for Matrix Inversion
void matrixInversion();

int main() {
    int mainChoice, subChoice;

    while (true) {
        cout << "\n--- Application for Solving Equations and Inverting Matrices ---\n";
        cout << "Select the type of problem:\n";
        cout << "1. Solution of Linear Equations\n";
        cout << "2. Solution of Non-linear Equations\n";
        cout << "3. Solution of Differential Equations\n";
        cout << "4. Matrix Inversion\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                cout << "\n--- Linear Equations Methods ---\n";
                cout << "1. Jacobi Iterative Method\n";
                cout << "2. Gauss-Seidel Iterative Method\n";
                cout << "3. Gauss Elimination\n";
                cout << "4. Gauss-Jordan Elimination\n";
                cout << "5. LU Factorization\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                switch (subChoice) {
                    case 1: jacobiMethod(); break;
                    case 2: gaussSeidelMethod(); break;
                    case 3: gaussElimination(); break;
                    case 4: gaussJordanElimination(); break;
                    case 5: luFactorization(); break;
                    default: cout << "Invalid choice for Linear Equations.\n"; break;
                }
                break;

            case 2:
                cout << "\n--- Non-linear Equations Methods ---\n";
                cout << "1. Bisection Method\n";
                cout << "2. False Position Method\n";
                cout << "3. Secant Method\n";
                cout << "4. Newton-Raphson Method\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                switch (subChoice) {
                    case 1: bisectionMethod(); break;
                    case 2: falsePositionMethod(); break;
                    case 3: secantMethod(); break;
                    case 4: newtonRaphsonMethod(); break;
                    default: cout << "Invalid choice for Non-linear Equations.\n"; break;
                }
                break;

            case 3:
                cout << "\n--- Differential Equations Methods ---\n";
                cout << "1. Runge-Kutta Method\n";
                cout << "Enter your choice: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    rungeKuttaMethod();
                } else {
                    cout << "Invalid choice for Differential Equations.\n";
                }
                break;

            case 4:
                cout << "\n--- Matrix Inversion ---\n";
                matrixInversion();
                break;

            case 5:
                cout << "Exiting the application.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

// Placeholder function definitions

void jacobiMethod() { cout << "Jacobi Iterative Method selected.\n"; }
void gaussSeidelMethod() { cout << "Gauss-Seidel Iterative Method selected.\n"; }
void gaussElimination() { cout << "Gauss Elimination selected.\n"; }
void gaussJordanElimination() { cout << "Gauss-Jordan Elimination selected.\n"; }
void luFactorization() { cout << "LU Factorization selected.\n"; }

void bisectionMethod() { cout << "Bisection Method selected.\n"; }
void falsePositionMethod() { cout << "False Position Method selected.\n"; }
void secantMethod() { cout << "Secant Method selected.\n"; }
void newtonRaphsonMethod() { cout << "Newton-Raphson Method selected.\n"; }

void rungeKuttaMethod() { cout << "Runge-Kutta Method selected.\n"; }

void matrixInversion() { cout << "Matrix Inversion selected.\n"; }

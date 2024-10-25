#include <bits/stdc++.h>
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

int main()
{
    int mainChoice, subChoice;

    while (true)
    {
        cout << "\n--- Application for Solving Equations and Inverting Matrices ---\n";
        cout << "Select the type of problem:\n";
        cout << "1. Solution of Linear Equations\n";
        cout << "2. Solution of Non-linear Equations\n";
        cout << "3. Solution of Differential Equations\n";
        cout << "4. Matrix Inversion\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
            cout << "\n--- Linear Equations Methods ---\n";
            cout << "1. Jacobi Iterative Method\n";
            cout << "2. Gauss-Seidel Iterative Method\n";
            cout << "3. Gauss Elimination\n";
            cout << "4. Gauss-Jordan Elimination\n";
            cout << "5. LU Factorization\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            switch (subChoice)
            {
            case 1:
                jacobiMethod();
                break;
            case 2:
                gaussSeidelMethod();
                break;
            case 3:
                gaussElimination();
                break;
            case 4:
                gaussJordanElimination();
                break;
            case 5:
                luFactorization();
                break;
            default:
                cout << "Invalid choice for Linear Equations.\n";
                break;
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

            switch (subChoice)
            {
            case 1:
                bisectionMethod();
                break;
            case 2:
                falsePositionMethod();
                break;
            case 3:
                secantMethod();
                break;
            case 4:
                newtonRaphsonMethod();
                break;
            default:
                cout << "Invalid choice for Non-linear Equations.\n";
                break;
            }
            break;

        case 3:
            cout << "\n--- Differential Equations Methods ---\n";
            cout << "1. Runge-Kutta Method\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
            {
                rungeKuttaMethod();
            }
            else
            {
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
void gaussSeidelMethod()
{
    double epsilon = 0.001;
    int n = 20;
    double aug[n][n + 1], solution[n] = {0};
    int m, it;
    cout << "Enter the number of equations/variables: ";
    cin >> m;
    cout << "Enter the maximum number of iterations: ";
    cin >> it;

    cout << "Enter the coefficients and constant terms for each equation:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cin >> aug[i][j];
        }
    }

    double new_solution[m] = {0};
    for (int i = 0; i < it; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double sum = 0;
            for (int k = 0; k < m; k++)
            {
                if (j != k)
                    sum += aug[j][k] * new_solution[k];
            }
            new_solution[j] = (aug[j][m] - sum) / aug[j][j];
        }

        bool converged = true;
        for (int j = 0; j < m; j++)
        {
            if (abs(solution[j] - new_solution[j]) > epsilon)
            {
                converged = false;
                break;
            }
        }

        cout << "Iteration " << i + 1 << ": ";
        for (int j = 0; j < m; j++)
        {
            cout << "[" << j + 1 << "]: " << new_solution[j] << "  ";
        }
        cout << endl;

        if (converged)
        {
            cout << "\nConverged Solution:\n";
            for (int j = 0; j < m; j++)
            {
                cout << "x" << j + 1 << " = " << new_solution[j] << endl;
            }
            return ;
        }

        for (int j = 0; j < m; j++)
        {
            solution[j] = new_solution[j];
        }
    }

    cout << "\nFinal Solution after max iterations:\n";
    for (int j = 0; j < m; j++)
    {
        cout << "x" << j + 1 << " = " << new_solution[j] << endl;
    }
}
void gaussElimination()
{

    int n;
    cout << "Give number of variables" << endl;
    cin >> n;

    vector<vector<double>> m(n, vector<double>(n + 1));

    cout << "Enter the augmented matrix (coefficients and constants) for" << n << " variables:" << endl;
    for (auto &x : m)
    {
        for (auto &gg : x)
        {
            cin >> gg;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int k = i + 1; k < n; ++k)
        {
            if (abs(m[k][i]) > abs(m[i][i]))
            {
                swap(m[i], m[k]);
            }
        }

        for (int j = i + 1; j < n; ++j)
        {
            double f = m[j][i] / m[i][i];
            for (int k = i; k <= n; ++k)
            {
                m[j][k] -= f * m[i][k];
            }
        }
    }

    vector<double> s(n);
    for (int i = n - 1; i >= 0; --i)
    {
        s[i] = m[i][n] / m[i][i];
        for (int j = i + 1; j < n; ++j)
        {
            s[i] -= (m[i][j] / m[i][i]) * s[j];
        }
    }
    cout << fixed << setprecision(6);
    cout << "The solutions are:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " = " << s[i] << endl;
    }
}
void gaussJordanElimination()
{
    int n;
    cout << "Enter the variable numbers : " << endl;
    cin >> n;
    vector<vector<double>> m(n, vector<double>(n + 1));
    cout << "Enter the augmented matrix : " << endl;
    for (auto &x : m)
        for (auto &ja : x)
            cin >> ja;

    for (int i = 0; i < n; ++i)
    {
        double p = m[i][i];
        for (int j = 0; j <= n; ++j)
            m[i][j] /= p;
        for (int k = 0; k < n; ++k)
        {
            if (k != i)
            {
                double f = m[k][i];
                for (int j = 0; j <= n; ++j)
                    m[k][j] -= f * m[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << "x" << i + 1 << " = " << m[i][n] << endl;
}
void luFactorization() { cout << "LU Factorization selected.\n"; }

void bisectionMethod() { cout << "Bisection Method selected.\n"; }
void falsePositionMethod() { cout << "False Position Method selected.\n"; }
void secantMethod() { cout << "Secant Method selected.\n"; }
void newtonRaphsonMethod() { cout << "Newton-Raphson Method selected.\n"; }

void rungeKuttaMethod() { cout << "Runge-Kutta Method selected.\n"; }

void matrixInversion() { cout << "Matrix Inversion selected.\n"; }

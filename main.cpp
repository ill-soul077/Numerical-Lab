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

void jacobiMethod()
{

    int n;
    cout << "Enter the number of variables (2 to 5): ";
    cin >> n;

    vector<vector<float>> a(n, vector<float>(n));
    vector<float> d(n);
    vector<float> x(n, 0);
    vector<float> x_prev(n, 0);
    float tol;

    cout << "Enter the tolerance: ";
    cin >> tol;

    cout << "Enter coefficients and constants for each equation :\n";
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        cin >> d[i];
    }

    int iter = 0;
    bool conv;

    do
    {
        conv = true;

        for (int i = 0; i < n; i++)
        {
            float sum = d[i];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    sum -= a[i][j] * x_prev[j];
            }
            x[i] = sum / a[i][i];
        }

        iter++;
        cout << "Iteration " << iter << ": ";
        for (int i = 0; i < n; i++)
        {
            cout << "x" << i + 1 << " = " << fixed << setprecision(4) << x[i] << "  ";
        }
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            if (abs(x[i] - x_prev[i]) > tol)
            {
                conv = false;
            }
        }

        x_prev = x;

    } while (!conv);

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << x[i] << endl;
    }

    //cout << "Jacobi Iterative Method selected.\n";
}
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
            return;
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
void luFactorization()
{

    const int N = 5;
    double a[N][N + 1], l[N][N] = {0}, u[N][N] = {0}, sol[N] = {0};

    int m;
    cout << "Enter the number of equations: ";
    cin >> m;

    cout << "Enter the coefficients and constants:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
        l[i][i] = 1.0;

    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            double s = 0;
            for (int k = 0; k < i; k++)
                s += u[k][j] * l[i][k];
            u[i][j] = a[i][j] - s;
        }
        for (int j = i + 1; j < m; j++)
        {
            double s = 0;
            for (int k = 0; k < i; k++)
                s += u[k][i] * l[j][k];
            l[j][i] = (a[j][i] - s) / u[i][i];
        }
    }

    double v[N] = {0};
    for (int i = 0; i < m; i++)
    {
        double s = 0;
        for (int j = 0; j < i; j++)
            s += l[i][j] * v[j];
        v[i] = a[i][m] - s;
    }

    for (int i = m - 1; i >= 0; i--)
    {
        double s = 0;
        for (int j = i + 1; j < m; j++)
            s += u[i][j] * sol[j];
        sol[i] = (v[i] - s) / u[i][i];
    }

    // cout << "Solution:\n";
    // cout<< fixed << setprecision(6);
    // for (int i = 0; i < m; i++)
    // {
    //     cout << "x" << i + 1 << " = "  << sol[i] << endl;
    // }

    // cout << "\nUpper Matrix:\n";
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << setw(10) << setprecision(4) << u[i][j];
    //     }
    //     cout << endl;
    // }

    // cout << "\nLower Matrix:\n";
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << setw(10) << setprecision(4) << l[i][j];5
    //     }
    //     cout << endl;
    // }
}
const double tol = 0.000001;
double f(double x, double p, double q, double r, double s)
{

    return p * x * x * x + q * x * x + r * x + s;
}
double f_prime(double x, double p, double q, double r, double s)
{
    return 3 * p * x * x + 2 * q * x + r;
}
void bisectionMethod()
{
    cout << "Bisection Method selected.\n";

    cout << "Bisection Method selected.\n";
    double p, q, r, s, a, b;
    cout << "Enter coefficients of equation: " << endl;
    cin >> p >> q >> r >> s;
    cout << "Enter Interval: " << endl;
    cin >> a >> b;

    if (f(a, p, q, r, s) * f(b, p, q, r, s) >= 0)
    {
        cout << "Invalid interval. Function values at the boundaries must have opposite signs." << endl;
        return;
    }
    double c = a;
    while ((b - a) >= tol)
    {
        c = (a + b) / 2;
        if (f(c, p, q, r, s) == 0.0)
            break;
        if (f(c, p, q, r, s) * f(a, p, q, r, s) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    cout << "The root is approximately: " << c << endl;
}
void falsePositionMethod()
{
    cout << "False Position Method selected.\n";
    cout << "False Position Method selected.\n";

    double p, q, r, s, a, b;
    cout << "Enter coefficients of equation: " << endl;
    cin >> p >> q >> r >> s;
    cout << "Enter Interval: " << endl;
    cin >> a >> b;
    if (f(a, p, q, r, s) * f(b, p, q, r, s) >= 0)
    {
        cout << "Invalid interval. Function values at the boundaries must have opposite signs." << endl;
        return;
    }
    double c = a;
    while ((b - a) >= tol)
    {
        c = (a * f(b, p, q, r, s) - b * f(a, p, q, r, s)) / (f(b, p, q, r, s) - f(a, p, q, r, s));
        if (f(c, p, q, r, s) == 0.0)
            break;
        if (f(c, p, q, r, s) * f(a, p, q, r, s) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    cout << "The root is approximately: " << c << endl;
}
void secantMethod()
{ // cout << "Secant Method selected.\n";
    cout << "Secant Method selected.\n";
    double x_prev, x_curr, x_next, p, q, r, s, max_iter;

    cout << "Enter coefficients of equation: " << endl;
    cin >> p >> q >> r >> s;
    cout << "Enter two initial guesses: " << endl;
    cin >> x_prev >> x_curr;
    cout << "Enter Max Iterations: " << endl;
    cin >> max_iter;

    for (int i = 0; i < max_iter; i++)
    {
        double f_prev = f(x_prev, p, q, r, s);
        double f_curr = f(x_curr, p, q, r, s);

        if (fabs(f_curr - f_prev) < 1e-10)
        {
            cout << "Division by a very small number, method fails." << endl;
            return;
        }

        x_next = x_curr - f_curr * (x_curr - x_prev) / (f_curr - f_prev);

        if (fabs(x_next - x_curr) < tol)
        {
            cout << "The root is approximately: " << x_next << endl;
            return;
        }

        x_prev = x_curr;
        x_curr = x_next;
    }

    cout << "Method did not converge within the maximum number of iterations." << endl;
}
void newtonRaphsonMethod()
{ // cout << "Newton-Raphson Method selected.\n";
    cout << "Newton-Raphson Method selected.\n";

    double x, p, q, r, s, max_iter;
    cout << "Enter coefficients of equation: " << endl;
    cin >> p >> q >> r >> s;
    cout << "Enter Initial Guess: " << endl;
    cin >> x;
    cout << "Enter Max Iterations: " << endl;
    cin >> max_iter;
    for (int i = 0; i < max_iter; i++)
    {
        double fx = f(x, p, q, r, s);
        double fx_prime = f_prime(x, p, q, r, s);

        if (fabs(fx_prime) < 1e-10)
        {
            cout << "Derivative is too small, method fails." << endl;
            return;
        }

        double x_next = x - fx / fx_prime;

        if (fabs(x_next - x) < tol)
        {
            cout << "The root is approximately: " << x_next << endl;
            return;
        }

        x = x_next;
    }

    cout << "Method did not converge within the maximum number of iterations." << endl;
}

void rungeKuttaMethod()
{
    // dy/dx=x+y
    auto f = [](double x, double y)
    {
        return x + y;
    };
    double y0;
    double x0;
    double h;
    int steps;
    cout << "y0=";
    cin >> y0;
    cout << "x0=";
    cin >> x0;
    cout << "h=";
    cin >> h;
    cout << "Enter number of steps:";
    cin >> steps;
    double y = y0;
    double x = x0;
    for (int i = 0; i < steps; ++i)
    {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += h;
    }
    cout << "Result of RK method:" << y << endl;
}

void matrixInversion()
{

    int n;
    cout << "Enter the size of matrix: ";
    cin >> n;
    cout << endl;
    vector<vector<double>> A(n, vector<double>(n, 0)); // Initialize A with given size
    cout << "Enter the elements of matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    //    int n = A.size();
    vector<vector<double>> inv(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i)
    {
        inv[i][i] = 1.0;
    }

    for (int i = 0; i < n; ++i)
    {
        // Check for zero pivot and try to swap rows if necessary
        if (fabs(A[i][i]) < 1e-9)
        {
            bool swapped = false;
            for (int j = i + 1; j < n; ++j)
            {
                if (fabs(A[j][i]) > 1e-9)
                {
                    swap(A[i], A[j]);
                    swap(inv[i], inv[j]);
                    swapped = true;
                    break;
                }
            }
            if (!swapped)
            {
                cout << "Matrix is singular and cannot be inverted.\n";
                return;
            }
        }

        double pivot = A[i][i];
        for (int j = 0; j < n; ++j)
        {
            A[i][j] /= pivot;
            inv[i][j] /= pivot;
        }

        for (int k = 0; k < n; ++k)
        {
            if (i != k)
            {
                double factor = A[k][i];
                for (int j = 0; j < n; ++j)
                {
                    A[k][j] -= factor * A[i][j];
                    inv[k][j] -= factor * inv[i][j];
                }
            }
        }
    }

    cout << "Inverted Matrix:\n";
    cout << fixed << setprecision(4); // Set output precision
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << inv[i][j] << " ";
        cout << "\n";
    }
}

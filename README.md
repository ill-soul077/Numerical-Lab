# Console Application Development Using Numerical Methods

# Solution of Linear Equation

This part of the project was solved by **Hassan Mohammed Naquibul Hoque(2107077)**. 
In this part I imlemented these Five mthods to solve linear equations.

1. **Jacobi Iterative Method**
2. **Gauss-Seidel Iterative Method**
3. **Gauss Elimination Method**
4. **Gauss-Jordan Elimination Method**
5. **LU Factorization Method**

Each of them has a different approach on the matter of the iteration or reduction of matrices in order to solve the variables. In detail, all the algorithms will be described here with the use of parameters and variables. Advantages and disadvantages were also discussed here.

---
## Jacobi Iterative Method

### Description
The Jacobi method provides a systematic way of iteration to solve a system of linear equations. It makes a guess for each variable, refining the solutions based on the relative values of neighboring variables. Initial guessing is important sometimes.

### Key Steps
1. Zero initialization of variables or initialization with a guess value.
2. For every variable, new estimation based on constant and other variable values previously calculated.
3. Check for convergence by comparing the change in variable values to a given tolerance.
4. Repeat until all variables converge within the tolerance.

### Advantages
- Easy to implement and understand.
- Useful for large, sparse matrices.
- Suitable for parallel computing.
- convergence under certain conditions

### Disadvantages
- Convergence not guaranteed; it works only in the case of strictly diagonally dominant matrices.
- Often requires more iterations as compared to Gauss-Seidel.
- limited practical use

 There a lot of scope in this part of the code. Due to lack of time it had some issues in big number of variables


---
## Gauss-Seidel Iterative Method

### Description
The Gauss-Seidel method is similar in concept to the Jacobi method but enhances convergence by utilizing updated values immediately after computation, rather than after a full iteration.

### Key Steps
1. Make an initial guess for each variable.
2. For each variable, directly compute its new value and for the rest of the calculations in the same iteration make use of the values that have just been calculated.
3. Convergence: difference between new and old value of each variable should be less than a given tolerance.
4. Repeat until convergence is reached, or some maximum number of iterations has been performed.

### Advantages
- Usually converges faster than Jacobi.
- Suitable for large sparse matrices.
- More eﬃcient for systems whose matrices are strongly diagonally dominant.
- Useful for Small Systems
- Accurary Improved

### Disadvantages
- Needs a sequential update of variables, making it more challenging to parallelize.
- Convergence is not guaranteed without special matrix properties
- Initial guesses sensitive
- difficult in certain type of systems

There is some scope for improvement and increasing accuracy in order to solve 5 variable equations. If anyone is interested let me know.

---
## Gauss Elimination Method

### Description
Gauss elimination is a method through which the system of equations is reduced to an upper triangular matrix, through which back substitution can be easily done to determine the values of the variables.

### Key Steps
1. **Formulate the Augmented Matrix**:
   - Reduce the system of equations to an augmented matrix form \([A | B]\), where \(A\) is the coefficient matrix and \(B\) is the constants matrix.

2. **Forward Elimination**:
- **Pivot Selection**: Find the leftmost column that does not have all zeros in its column and label this the pivot column.
- **Row Operations**: Perform elementary row operations to insert zeros below the pivot element along the column that the pivot element is in.
- Repeat this for each column until the whole matrix is in upper triangular form.

3. **Back Substitution**:
- In upper triangular form solve the variables from the bottom and work up, substituting into previous equations to find all variable values.

### Advantages
- It is a direct method that involves a finite number of steps.
- Any system with unique solution can be solved
- It is good for dense matrices
- Basis for other methods such as Gauss Jordan Elimination

### Disadvantages
- Computationally expensive for big systems.
- Large matrices require huge amount of memory.
- Suffers from round off Errors due to floating point arithmetic.
- It may have round off Errors.

---
## Gauss-Jordan Elimination Method

### Description
Gauss-Jordan method is an extension to the Gaussian Elimination by obtaining a complete diagonal matrix, which gives a solution directly without any further step from a single step. The resulting matrix is in reduced row echelon form (RREF).
## Key Steps

1. **Formulate the Augmented Matrix**:
- The system of equations can be expressed as an augmented matrix \([A | B]\), where \(A\) represents the coefficient matrix and \(B\) is the constants matrix.

2. **Row Operations**:
   - Perform elementary row operations to transform the matrix. Three forms of operation may be applied:
   - **Row Swapping:** Two rows are interchanged.
   - **Row Scaling**: Multiply any row by a non-zero constant.
   - **Row Addition**: Add a multiple of one row to another row.

3. **Convert into Reduced Row Echelon Form**:
  - Achieve RREF such that:
  - Every leading entry in a row is 1.
  - Each leading 1 is the sole nonzero entry in its column.
  - The leading 1's float to the right down the rows.

4. **Identify Solutions**:
   - In RREF, the solutions of the system can be directly interpreted with each variable corresponding to a leading 1 in that row.

 

### Advantages
- Gives solutions directly and does not require back-substitution.
- Can be applied to yield matrix inverses.
- Suitable for systems where all the unknowns need to be solved simultaneously.
- It can also be used for an inverse matrix calculation and Rank.
Disadvantages
- More computational compared to Gauss elimination.
- Higher chance of round-off errors in the arithmetic of floating-point.
- Cannot be used on very large matrices due to memory issues.
---
## LU Factorization Method

### Description
LU Factorization breaks the coefficient matrix down into two matrices, `L` (lower triangular) and `U` (upper triangular), with which to solve the system.

## Key Steps

1. **Create an Augmented Matrix**:
	- Begin with a square matrix \(A\) to be factored. 

2. **Carry Out Gaussian Elimination:
Use Gaussian Elimination to transform A to an upper triangular matrix U. Be certain during this process to list the multipliers used in eliminating entries below the pivot elements.

3. **Form Lower Triangular Matrix**:
- As you perform row operations to introduce zeros below the pivots in, write down the corresponding multiplier in a lower triangular matrix. Entries on the diagonal of are often set to be 1.
4. **Combine Results**:
   - Once you have both matrices, represent your original matrix as.
5. **Verification**:
- Multiply matrices \(L\) and \(U\) to check whether the product is equal to the original matrix \(A\).
 
### Advantages
- Suitable for systems with multiple right-hand sides.
- Computationally cost-effective since the decompositions `L` and `U` are used several times.
- Solutions can be computed in a stable way if a decomposition is well-conditioned.
-
### Disadvantages
- Computationally expensive decomposition of big-sized matrices.
- Solutions may be sensitive for round-off errors if a matrix is ill-conditioned.
- More ineffective if only one solution is to be found.
special conditions
Complexity increases with the increase in row

---


# Solution of Non Linear Equations

This part of the project was implemented by **Rysul Aman Nirob(2107092)**


1. **Bisection Method**
2. **False Position Method (Regula Falsi)**
3. **Secant Method**
4. **Newton-Raphson Method**

The unique characteristics of each technique make them suitable for different problem types. The following is the list of each algorithm with their commonly associated advantages and disadvantages.

---

## 1. Bisection Method

### Working Details
The Bisection method is an elementary root-finding algorithm. It repeats the division of an interval in half, selecting that subinterval in which the root lies.

1. In this method, two initial guesses are given: `a` and `b`, such that \( f(a) \) and \( f(b) \) have opposite signs, meaning there will always be at least one root in between.
2. The midpoint \ ( c = \frac{a + b}{2} \) is found.
3. If \( f(c) = 0 \), the process stops since the root is found.
4. Otherwise, the interval `[a, b]` is updated according to the sign of \( f(c) \), and the process repeats until the interval is sufficiently small.

### Advantages
- **Guaranteed Convergence**: So long as the function is continuous and the assumptions hold, the method will always converge to a solution.
- **Simplicity**: It is easy to learn and use the Bisection method.
- **Global Method**: It does not require a good initial guess, but only the interval over which the function changes sign.

### Disadvantages
- Slow convergence: The method converges slowly with linear convergence; hence, it becomes inefficient when high precision is required.
- Requires an Interval: It requires a valid interval where the function changes signs, which reduces its applicability in some cases.

---

## 2. False Position Method (Regula Falsi)

### Job Details
The False Position method also requires an interval `[a, b]` with opposite signs at the boundaries, much like the Bisection method. Instead of taking the midpoint to calculate the next approximation, linear interpolation between `a` and `b` is used:.

1. Compute \( c = a -frac{f\(a) \cdot (b - a)}{f(b) - f(a)} \).
2. Update the interval `[a, b]` depending on the sign of \( f(c) \).
3. Repeat until convergence is achieved or the interval is sufficiently small.

### Pros
• Faster Convergence: It converges generally faster than the Bisection method because it makes use of the shape of the function.
- **Global Method**: It does not require an initial guess, only an interval where the function changes sign.

### Disadvantages
• **Convergence Problems**: If one of the function values at the interval endpoints is closer to the root, then the method may converge slowly.
- **Requires a Valid Interval**: Like Bisection, it requires an interval where the function changes sign, which again limits its use.

---

## 3. Secant Method

### Working Details
The Secant method is an iterative root-finding algorithm that doesn’t require the derivative of the function. It uses two initial guesses `x0` and `x1`, and the next approximation is calculated by fitting a secant line through these points.

1. Compute \( x_{n+1} = x_n - \frac{f(x_n) \cdot (x_n - x_{n-1})}{f(x_n) - f(x_{n-1})} \).
2. Repeat until the change in `x` is smaller than a predefined tolerance.

### Advantages
- **No Derivative Required**: It does not require computation of the derivative of the function like the Newton-Raphson method.
- Faster than Bisection: Typically has a faster convergence than Bisection and False Position for well-behaved functions.

### Disadvantages

- **Convergence is Not Guaranteed**: Might not converge if initial guesses are bad or if the function does not behave well.

- **Requires Two Initial Guesses**: It may not always be easy to find two good initial guesses.

---

## 4. Newton-Raphson Method

### Working Details

The Newton-Raphson method is an iterative algorithm, using the derivative of the function for fast convergence. From an initial guess, x0, the next approximation, x(n+1), can be found as follows:

1. \( x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)} \).

2. Repeat until the difference between successive approximations falls below a prescribed tolerance.

### Advantages

• **Fast Convergence**: Assuming quadratic convergence, it is one of the fastest methods for root finding when it works. 
- **Efficiency**: Fewer iterations are usually needed compared to other techniques, so it is efficient for large computations. 
### Disadvantages 
- **Needs Derivative**: It requires the derivative of the function, which may be complicated or time-consuming to calculate.
- **Sensitive to Initial Guess**: Unless the initial guess is very close to the root, the method may diverge or converge to a spurious root.
- **Not Global**: Unlike the Bisection or False Position methods, Newton-Raphson is sensitive to the initial guess and might not work globally.

--- 

# Runge-Kutta Method (RK4) for Ordinary Differential Equations

This part project implements by **Tajnoor Sultana(2107108)** on **4th Order Runge-Kutta Method (RK4)**, one of the most popular numerical methods to solve ordinary differential equations of the kind \(\frac{dy}{dx} = f(x, y)\).

The following code computes the approximate value of y at a given x using small step sizes h and starting from the initial condition (x0, y0).

## Code Details
The resulting differential equation in this example is:
\[
\frac{dy}{dx} = x + y
\]

The `rungeKuttaMethod` function prompts the user to enter:
- `y0`: Value of `y` at `x0`
- `x0`: Initial value of `x`
- `h`: Step size
- `steps`: Number of steps to perform

Given the number of steps, use RK4 to find the approximate value of `y`.

## Working Details of the Runge-Kutta Method (4th Order)

The Runge-Kutta method improves accuracy by calculating four different slopes at each interval:
1. **k1**: Slope at the start of the interval.
2. **k2**: Slope at the midpoint of the interval using `k1`.
3. k3: Another midpoint slope using k2.
4. **k4**: Slope at the end of the interval using `k3`.

The new value of `y` is then computed by taking a weighted average of these slopes:
\left[
y_{next} = y + \frac{k1 + 2 \cdot k2 + 2 \cdot k3 + k4}{6}
\]

## Advantages of the 4th Order Runge-Kutta Method

- **High Accuracy**: RK4 has high accuracy with fewer steps compared to the lower-order methods, which is the reason it's one of the most implemented approaches in numerical ODE solutions.
Stability: The method itself is numerically stable for a large class of problems.
- **Efficiency**: Balances computational cost with accuracy, making it efficient for many engineering and scientific applications.

## Disadvantages of the 4th Order Runge-Kutta Method

• Fixed Step Size: Standard RK4 has a fixed step size, which can be quite inefficient in cases where the function's values change rapidly in their domain. It is, therefore, wise to use adaptive step-size RK4 methods.

• **Computational Overhead**: It involves four function evaluations per step, which may be prohibitively expensive if the function is elaborate, or if the dimension is high.

• Limited flexibility: Because of the fixed order of RK4, it may not adapt to problems where the precision requirement changes dynamically as well as variable-order methods do. 

---


# Matrix Inversion using Gauss-Jordan Elimination

This part of the project implemented by **Tajnoor Sultana(2107108)**  a function to invert a square matrix using the **Gauss-Jordan elimination** method. The matrix inversion is crucial in various fields, including linear algebra, engineering, and computer graphics.

## Working Details

The `matrixInversion` function performs the following steps:

1. **Input Matrix Size**: The user is prompted to enter the size of the square matrix \( n \).
2. **Matrix Input**: The user is asked to input the elements of the \( n \times n \) matrix \( A \).
3. **Initialize Inverted Matrix**: An identity matrix of the same size is initialized to hold the inverted matrix.
4. **Pivoting**:
   - For each row, check if the diagonal element (pivot) is close to zero. If it is, attempt to swap it with a lower row that has a non-zero value.
   - If no such row exists, the matrix is singular, and the inversion is not possible.
5. **Normalization**:
   - Normalize the pivot row by dividing all elements in the row by the pivot value.
6. **Row Reduction**:
   - For each other row, eliminate the values in the current pivot column by subtracting appropriate multiples of the pivot row from the other rows.
7. **Output Result**: After processing all rows, the inverted matrix is printed with a precision of four decimal places.

## Advantages

- **Direct Method**: The Gauss-Jordan elimination method provides a direct way to compute the inverse of a matrix, making it conceptually straightforward.
- **General Applicability**: This method works for any square matrix, provided it is non-singular (invertible).
- **Precision Control**: The function allows for precise output formatting, enabling easier interpretation of results.

## Disadvantages

- **Computational Complexity**: The time complexity is \( O(n^3) \), which can be inefficient for large matrices.
- **Numerical Stability**: The method can suffer from numerical instability, particularly for ill-conditioned matrices, leading to inaccurate results.
- **Memory Usage**: The approach requires additional space to store the inverted matrix, which can be a drawback for very large matrices.
- **Pivoting Requirement**: The need for row swapping can complicate the algorithm, especially in cases where the matrix is close to singular.

---

### Requirements
- C++ compiler



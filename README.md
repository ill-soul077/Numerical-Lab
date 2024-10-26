# Numerical-Lab

# Console Application Development Using Numerical Methods


first part of the problem was solved by Hassan Mohammed Naquibul Hoque(2107077). 
In this part I implemented Five mthods to solve linear equations.


1. **Jacobi Iterative Method**
2. **Gauss-Seidel Iterative Method**
3. **Gauss Elimination Method**
4. **Gauss-Jordan Elimination Method**
5. **LU Factorization Method**

Each method has a unique approach to iterating or reducing matrices to solve for the variables. Below is a detailed explanation of each algorithm, including the parameters and variables they use.

---

## Jacobi Iterative Method

### Description
The Jacobi method is an iterative algorithm for solving a system of linear equations. It starts with an initial guess for each variable and refines the solutions based on the relative values of neighboring variables.

### Key Steps
1. Initialize all variables to zero or a guess value.
2. For each variable, calculate the new value based on the constants and previously calculated values of other variables.
3. Check for convergence by comparing the change in variable values to a given tolerance.
4. Repeat until all variables converge within the tolerance.

### Advantages
- Simple to implement and understand.
- Useful for large, sparse matrices.
- Suitable for parallel computing.

### Disadvantages
- Convergence is not guaranteed; works only with strictly diagonally dominant matrices.
- Often requires more iterations compared to Gauss-Seidel.

---

## Gauss-Seidel Iterative Method

### Description
The Gauss-Seidel method is similar to the Jacobi method but improves convergence by using updated values as soon as they are computed, rather than waiting for an entire iteration.

### Key Steps
1. Set up an initial guess for each variable.
2. For each variable, compute the new value immediately and use it in subsequent calculations within the same iteration.
3. Check for convergence by comparing the difference between the new and old values with a tolerance.
4. Iterate until convergence or until a maximum number of iterations is reached.

---

## Gauss Elimination Method

### Description
Gauss elimination is a method that transforms the system of equations into an upper triangular matrix, allowing easy back-substitution to find variable values.

### Key Steps
1. Use row operations to create zeros below the pivot (diagonal) elements.
2. Swap rows to handle zero or small pivot values for numerical stability.
3. After forming the upper triangular matrix, solve for each variable starting from the last row (back-substitution).

---

## Gauss-Jordan Elimination Method

### Description
The Gauss-Jordan method extends Gaussian elimination by making the entire matrix diagonal, yielding the solution directly in a single step.

### Key Steps
1. Normalize each pivot row by dividing by the pivot element.
2. Use row operations to make all elements above and below the pivot zero, resulting in a diagonal matrix.
3. The matrix now shows each variable’s value in the corresponding row.

---

## LU Factorization Method

### Description
LU Factorization decomposes the coefficient matrix into two matrices, `L` (lower triangular) and `U` (upper triangular), which are used to solve the system.

### Key Steps
1. Decompose the matrix into `L` and `U`.
2. Solve for an intermediate vector using `L`.
3. Use `U` to solve for the final solution vector.
4. This method is useful for systems requiring multiple solutions with different constant vectors.

---


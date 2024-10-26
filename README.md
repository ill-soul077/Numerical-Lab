# Console Application Development Using Numerical Methods


first part of the problem was solved by Hassan Mohammed Naquibul Hoque(2107077). 
In this part I implemented these Five mthods to solve linear equations.


1. **Jacobi Iterative Method**
2. **Gauss-Seidel Iterative Method**
3. **Gauss Elimination Method**
4. **Gauss-Jordan Elimination Method**
5. **LU Factorization Method**

Each method has a unique approach to iterating or reducing matrices to solve for the variables. Below is a detailed explanation of each algorithm, including the parameters and variables they use.Advantages and disadvantages was also discussed here

---

## Jacobi Iterative Method

### Description
The Jacobi method is an iterative algorithm for solving a system of linear equations. It starts with an initial guess for each variable and refines the solutions based on the relative values of neighboring variables. Initial guessing is sometimes important.

### Key Steps
1. Initialize all variables to zero or a guess value.
2. For each variable, calculate the new value based on the constants and previously calculated values of other variables.
3. Check for convergence by comparing the change in variable values to a given tolerance.
4. Repeat until all variables converge within the tolerance.

### Advantages
- Simple to implement and understand.
- Useful for large, sparse matrices.
- Suitable for parallel computing.
- convergence under certain conditions

### Disadvantages
- Convergence is not guaranteed; works only with strictly diagonally dominant matrices.
- Often requires more iterations compared to Gauss-Seidel.
- limited practical use

There a lot of scope in this part of the code. Due to lack of time it had some issues in big number of variables
---

## Gauss-Seidel Iterative Method

### Description
The Gauss-Seidel method is similar to the Jacobi method but improves convergence by using updated values as soon as they are computed, rather than waiting for an entire iteration.

### Key Steps
1. Set up an initial guess for each variable.
2. For each variable, compute the new value immediately and use it in subsequent calculations within the same iteration.
3. Check for convergence by comparing the difference between the new and old values with a tolerance.
4. Iterate until convergence or until a maximum number of iterations is reached.

### Advantages
- Typically converges faster than Jacobi.
- Suitable for large, sparse matrices.
- More efficient for systems with strongly diagonally dominant matrices.
- Effective for Small Systems
- Improved Accuracy

### Disadvantages
- Requires a sequential update of variables, making it harder to parallelize.
- Convergence is not guaranteed without specific matrix properties.
- Sensitive to initial guesses
- difficult with certain type of systems

There is a some scope for improvement and increasing accurecy to solve 5 variable equations. If any one is interested let me know.

---

## Gauss Elimination Method

### Description
Gauss elimination is a method that transforms the system of equations into an upper triangular matrix, allowing easy back-substitution to find variable values.

### Key Steps
1. **Formulate the Augmented Matrix**:
   - Convert the system of equations into an augmented matrix form \([A | B]\), where \(A\) is the coefficient matrix and \(B\) is the constants matrix.

2. **Forward Elimination**:
   - **Select Pivot**: Identify the leftmost non-zero column as the pivot column.
   - **Row Operations**: Use elementary row operations (swapping rows, scaling rows, and adding multiples of rows) to create zeros below the pivot element in its column.
   - Repeat this process for each column until the matrix is in upper triangular form.

3. **Back Substitution**:
   - Once in upper triangular form, solve for the variables starting from the last row and substituting back into previous equations to find all variable values.

### Advantages
- Direct method with a finite number of steps.
- Can solve any system with a unique solution.
- Effective for dense matrices.
- foundation for other methods like Gauss Jordan Elimination

### Disadvantages
- Computationally expensive for large systems.
- Requires significant memory for large matrices.
- Prone to rounding errors in floating-point arithmetic.
- it can have round off Errors.

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


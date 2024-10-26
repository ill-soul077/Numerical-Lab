# Console Application Development Using Numerical Methods

1st part of the problem was solved by Hassan Mohammed Naquibul Hoque(2107077). 
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
   - Reduce the system of equations to an augmented matrix form \\\\([A | B]\\\\), where \\\\(A\\\\) is the coefficient matrix and \\\\(B\\\\) is the constants matrix.

2. **Forward Elimination**:
• **Pivot Selection**: Find the leftmost column that does not have all zeros in its column and label this the pivot column.
 • **Row Operations**: Perform elementary row operations to insert zeros below the pivot element along the column that the pivot element is in.
 • Repeat this for each column until the whole matrix is in upper triangular form.

3. **Back Substitution**:
-In upper triangular form solve the variables from the bottom and work up, substituting into previous equations to find all variable values.

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
- The system of equations can be expressed as an augmented matrix \\([A | B]\\), where \\(A\\) represents the coefficient matrix and \\(B\\) is the constants matrix.

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


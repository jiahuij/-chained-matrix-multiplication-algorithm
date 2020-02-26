a program in VS C++ 2017 to implement the algorithm for the chained matrix	   

multiplication problem shown in class. Your program should first prompt the user for the total

number of matrices to be multiplied. It then asks the user to enter the dimension for each of the

matrices. Your program then determines how the matrices should be parenthesized and displays

the results to the screen (i.e. the M matrix, the P matrix, and the parenthesization of the

matrices). The following shows a scenario of running a sample program, where user's inputs are

represented in boldface. You may assume all inputs entered are valid and the matrices to be

multiplied are compatible. You may also assume the total number of matrices to be multiplied is

10 or less.

> Enter the total number of matrices to be multiplied: 4

> Enter the dimension for the first matrix: 5 2

> Enter the dimension for the second matrix: 2 3

> Enter the dimension for the third matrix: 3 4

> Enter the dimension for the fourth matrix: 4 6

The following shows the M matrix and the P matrix computed, respectively.

0 30 64 132

0 24 72

0 72

 0
 
1 1 1

2 3

3

The following shows the optimal parenthesization of the matrices.

(𝑀1((𝑀2𝑀3) 𝑀4))

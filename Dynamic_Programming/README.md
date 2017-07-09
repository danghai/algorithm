# Dynamic Programming:

Dynamic programming is a method for solving a complex problem by breaking it 
down into simpler subproblems, solving each of those subproblems just once,
and storing their solutions in an array (usually). 

Everytime the same sub-problem occurs, instead of recomputing its solution,
the previously calculated solutions are used, thereby saving computation time at
the expense of storage space.

Dynamic programming can be implemented in two ways
	* Memoization
	* Tabulation

1. Memoization: Memoization uses the top-down technique to solve the problem. 
It begin with original problem then breaks it into sub-problems and solve these
sub-problems in the same way. 

In this approach, you assume that you have alread computed all subproblems. You
typically perform a recursive call (or some iterative equivalent) from the main problem.
You ensure that the recursive call never recomputes a subproblem because you cache 
the results, and thus duplicate sub-problem are not recomputed.

2. Tabulation: Tabulation is the typical Dynamic Programming approach. Tabulation uses
the bottom up approach to solve the problem by solving all related sub-problem first, 
typically by storing the results in an array. Based on the results stored in the array,
the solution to the `top` original problem is then computed.

Memoization and tabulation are both storage techniques applied to avoid recomputation of 
a subproblem

### Applicability of dynamic programming:

The idea behind dynamic programming, in general, is to solve a given problem, by solving
different parts of the problem (subproblems), then using the cached solutions of the
subproblems to reach an overall solution

The problems that can be solved by usiing Dynamic Programming has the following two main
properties

1. Overlapping sub-problems

Overlapping subproblems is a property in which a problem can be broken down into subproblems
which are used multiple times.

Dynamic programming is mainly used when solutions of same subproblems are needed again and 
again. In dynamic programming, computed solutions to subproblems are stored in a array so
that these do not have to recomputed. So Dynamic Programming is no useful when there are no 
overlapping subproblems because there is no point storing the solutions if they are not 
needed again

2. Optimal Substructure

Optimal substructure is a property in which an optimal solution of the original problem
can be constructed efficiently from the optimal solutions of its sub-problems

### Steps to follow for solving a Dynamic Programming problem:

1. Express a solution mathematically
2. Express a solution recursively
3. Either develop a bottom up algorithm or top-down memoized algorithm

### List of Dynamic Programming problem and solutions:


# Sliding-Puzzle-Solver
### Implementation of A-star, IDA-star and BFS Algorithms to solve a NxN Sliding Puzzle Problem
</br>
<p align="center">
  <img width="460" height="460" src="https://miro.medium.com/max/1050/1*W7jg4GmEjGBypd9WPktasQ.gif">
</p>
<br />

---------------------
#### [**solver_state.h**](https://github.com/ash04-creater/Sliding-Puzzle-Solver/blob/main/solver_state.h)

The header file describes the game state at any instant in the search space. It implements the creation and allocation of the **nodes** in the search space, the **heuristic** functions(misplaced tiles and **manhattan**) and printing the **optimal path** leading to the solution.

-----------------
#### [**solvability.h**](https://github.com/ash04-creater/Sliding-Puzzle-Solver/blob/main/solvability.h)

The header file contains the function which **mathematically** checks whether the given input scramble can be solved or not.

----------------

#### [**solver.h**](https://github.com/ash04-creater/Sliding-Puzzle-Solver/blob/main/solver.h)

The header file implements **A-star** and **BFS(Breadth First Search)** graph algorithms which traverse on the search space to get the optimal number of moves leading to the solution.

-------------

#### [**main.cpp**](https://github.com/ash04-creater/Sliding-Puzzle-Solver/blob/main/main.cpp)

The file executes the **main()** function which takes the size of the grid and the grid itself as a input and calls the functions included in the **solver.h** header file to find the solution to the puzzle.

------------

#### [**IDA_star.cpp**](https://github.com/ash04-creater/Sliding-Puzzle-Solver/blob/main/IDA_star.cpp)

This file contains tha **IDA-star**(Iterative Deepening A-star) implementation of the solver. The algorithm is **recursively** implemented on the input scramble using the **manhattan** heuristic and gets the optimal path to the solution elegantly.

------------

### Example of Input :

3 &nbsp; &nbsp; &nbsp; <---Size of grid(N) </br>
1 8 7  <---The NxN grid </br>
3 0 5  </br>
4 6 2  </br>

### Output :

1 8 7 <--- Input Grid  </br>
3 0 5 </br>
4 6 2 </br>
   
1 0 7   
3 8 5   
4 6 2   
  
1 7 0   
3 8 5  
4 6 2   

1 7 5   
3 8 0   
4 6 2   

1 7 5   
3 8 2   
4 6 0   

1 7 5   
3 8 2   
4 0 6   

1 7 5   
3 0 2   
4 8 6   

1 0 5   
3 7 2   
4 8 6   

1 5 0   
3 7 2   
4 8 6   

1 5 2   
3 7 0   
4 8 6   

1 5 2   
3 7 6   
4 8 0   

1 5 2   
3 7 6   
4 0 8   

1 5 2   
3 0 6   
4 7 8   

1 5 2   
0 3 6   
4 7 8   

1 5 2   
4 3 6   
0 7 8  

1 5 2   
4 3 6   
7 0 8   

1 5 2   
4 3 6   
7 8 0   

1 5 2   
4 3 0   
7 8 6   

1 5 2   
4 0 3   
7 8 6   

1 0 2    
4 5 3   
7 8 6   

1 2 0   
4 5 3   
7 8 6   

1 2 3   
4 5 0   
7 8 6   

1 2 3 <--- Solution Grid   
4 5 6   
7 8 0   
  
### **Benchmarks :**
All the three algorithms A-star , IDA-star and BFS took **22** steps **(moves)** to find the solution to the puzzle . IDA-star took **0.021 secs** , A-star took **0.071 secs** and BFS took **1.252 secs** to solve the grid. Thus , **IDA-star** works most optimally here.








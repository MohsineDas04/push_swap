# **Push\_swap 42**

## **🗣️ About**

**Push\_swap** is a rigorous algorithmic project from the 42 curriculum. The challenge involves sorting a stack of integers using a second auxiliary stack and a limited set of operations (push, swap, rotate).

The core difficulty lies not just in sorting, but in **optimization**. The goal is to sort the data with the absolute minimum number of operations possible. This requires implementing complex sorting algorithms and carefully managing computational complexity.

This project implements a **Hybrid Turk Algorithm**, optimized for efficiency and low move counts.

## **🛠️ The Rules**

You have two stacks, **Stack A** and **Stack B**.

* **Stack A**: Contains a random amount of negative and/or positive numbers which cannot be duplicated.  
* **Stack B**: Initially empty.

The goal is to sort the numbers in **Stack A** in ascending order using the following operations:

| Command | Description |
| :---- | :---- |
| **sa** | Swap the first 2 elements at the top of stack A. |
| **sb** | Swap the first 2 elements at the top of stack B. |
| **ss** | sa and sb at the same time. |
| **pa** | Push the first element of stack B to the top of stack A. |
| **pb** | Push the first element of stack A to the top of stack B. |
| **ra** | Shift up all elements of stack A by 1\. First element becomes the last. |
| **rb** | Shift up all elements of stack B by 1\. First element becomes the last. |
| **rr** | ra and rb at the same time. |
| **rra** | Shift down all elements of stack A by 1\. Last element becomes the first. |
| **rrb** | Shift down all elements of stack B by 1\. Last element becomes the first. |
| **rrr** | rra and rrb at the same time. |

## **🧠 The Algorithm**

This project uses a variation of the **Turk Algorithm**, refined with an **Average Split** strategy for pre-sorting.

### **Phase 1: The Partitioning (A → B)**

Instead of pushing everything to Stack B blindly, we perform a smart pre-sort:

1. We calculate the **average value** of the current Stack A.  
2. We iterate through Stack A. If a number is **below the average**, we push it to Stack B (pb).  
3. **Optimization**: If the pushed number is significantly smaller than the others in B, we rotate B (rb) to place it at the bottom, creating a rough descending order (V-shape) in Stack B.  
4. We repeat this process until only 3 numbers remain in Stack A.  
5. The final 3 numbers in Stack A are sorted using a hardcoded, constant-time logic (ft\_sort\_three).

### **Phase 2: The Greedy Sort (B → A)**

Now we have a roughly sorted Stack B and a sorted mini-Stack A. We move elements back to A using a "Cheapest Move" cost analysis:

1. For **every single node** in Stack B, we calculate the cost (number of operations) required to move it to its correct position in Stack A.  
   * This calculation accounts for double rotations (rr and rrr) to save moves.  
2. We identify the node with the **lowest total cost**.  
3. We execute the optimized sequence of moves to push that specific node to Stack A.  
4. This repeats until Stack B is empty.

### **Phase 3: Final Alignment**

The stack is now sorted, but the smallest number might not be at the top. We simply rotate Stack A (ra or rra) until the minimum value is at index 0\.

## **📊 Performance & Complexity**

The algorithm is designed to handle standard 42 benchmarks with ease:

| Input Size | Target Moves | My Average | Complexity |
| :---- | :---- | :---- | :---- |
| **3 numbers** | \< 3 | 0-2 | O(1) |
| **5 numbers** | \< 12 | 7-10 | O(1) |
| **100 numbers** | \< 700 | \~600 | O(N log N) |
| **500 numbers** | \< 5500 | \~4500 | O(N log N) |

## **💻 Installation**

Clone the repository and compile the project:

git clone [\[https://github.com/your-username/push\_swap.git\](https://github.com/your-username/push\_swap.git)  
cd push\_swap](https://github.com/MohsineDas04/push_swap.git)  
make

To compile the bonus (checker):

make bonus

## **🕹️ Usage**

### **Running Push\_swap**

Run the program with a list of integers as arguments. It will output the operations needed to sort the list.

./push\_swap 2 1 3 6 5 8

### **Running the Checker (Bonus)**

The bonus part is a custom program that validates the output of push\_swap. It takes the same arguments, reads operations from stdin, and outputs OK or KO.

ARG="4 67 3 87 23"; ./push\_swap $ARG | ./checker $ARG

If the sorting fails or the input is invalid, it prints Error.

## **🧪 Testing**

### **Simple Manual Test**

\# Define a list of numbers  
ARG="1 5 2 4 3"

\# Run push\_swap to see instructions  
./push\_swap $ARG

\# Pipe to checker to verify  
./push\_swap $ARG | ./checker $ARG

### **Random Number Test**

You can use shuf (Linux) or ruby scripts to generate random numbers.

**Test with 100 random numbers:**

ARG=$(seq 1 100 | shuf | tr '\\n' ' '); ./push\_swap $ARG | ./checker $ARG

*Expected output: OK*

**Check move count:**

ARG=$(seq 1 500 | shuf | tr '\\n' ' '); ./push\_swap $ARG | wc \-l

## **📂 Project Structure**

* push\_swap.c: Main entry point and logic controller.  
* checker.c: Bonus program entry point.  
* ft\_sort\_\*.c: Core sorting algorithms (hundred, five, three).  
* ft\_execute.c: executing moves based on calculated costs.  
* ft\_cheapest\_move.c: Logic to find the most efficient element to move.  
* ft\_ll\_utils.c: Linked list utility functions.  
* src/operations/: Contains the actual sa, pb, rra, etc. functions.  
* libft/: My custom C library (extended).  
* printf/: My custom printf implementation.

## **🎓 What I Learned**

* **Complexity Analysis**: Understanding the difference between O(n^2) and O(n log n) in a practical, constrained environment.  
* **Sorting Algorithms**: Deep dive into QuickSort, MergeSort, and creating hybrid algorithms like the Turk Sort.  
* **Stack Manipulation**: visualising data structures and manipulating pointers effectively.  
* **Optimization**: How to shave off every single instruction to meet strict move-count limits.  
* **Makefile**: Creating robust build systems that handle multiple binaries and library dependencies without relinking.

## **👨‍💻 Author**

**mlakhlil**

* 42 Profile: [mlakhlil](https://profile-v3.intra.42.fr/)

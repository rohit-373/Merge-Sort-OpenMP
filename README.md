Parallel merge sort with OpenMP:
Explore how OpenMP, a powerful API supporting parallel processing in languages like C, C++, and Python, can make merge sort more efficient.
- Implements parallel merge sort: Uses OpenMP to split sorting tasks.
- Sequential merge sort base case: Switches to this for smaller subarrays.
- Merge function: Combines two sorted subarrays.
- Reads input: Fetches numbers from "numbers.txt".
- Prints execution time: Displays time for parallel sort.
- OpenMP parallel sections: Divides and sorts concurrently.
- Threshold for sequential sort: Prevents excessive overhead.
- Efficiency: Beats sequential sort for large datasets on multi-core systems.

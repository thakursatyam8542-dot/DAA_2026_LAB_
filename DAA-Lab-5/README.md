# DAA Lab-5

This repository contains the solutions for **Design and Analysis of Algorithms (DAA) Lab-5**.

## Problems

1. Find the median of N numbers **without sorting the complete list** using Quickselect.
2. Find the K-th smallest element without sorting the complete list using Quickselect.
3. Implement Quick Sort for N randomly generated elements stored in a file.
4. Implement Heap Sort for N randomly generated elements stored in a file.

## Repository Structure

```text
DAA-Lab-5/
├── README.md
├── .gitignore
├── 01_median_quickselect.c
├── 02_kth_smallest_quickselect.c
├── 03_quick_sort_file.c
└── 04_heap_sort_file.c
```

## How to Compile

Using GCC:

```bash
gcc 01_median_quickselect.c -o median
gcc 02_kth_smallest_quickselect.c -o kth_smallest
gcc 03_quick_sort_file.c -o quick_sort
gcc 04_heap_sort_file.c -o heap_sort
```

Run:

```bash
./median
./kth_smallest
./quick_sort
./heap_sort
```

On Windows with MinGW, use:

```bash
median.exe
kth_smallest.exe
quick_sort.exe
heap_sort.exe
```

## Complexity Analysis

| Algorithm | Best | Average | Worst |
|---|---:|---:|---:|
| Quickselect | O(N) | O(N) | O(N²) |
| Quick Sort | O(N log N) | O(N log N) | O(N²) |
| Heap Sort | O(N log N) | O(N log N) | O(N log N) |

### Key Concepts

- **Quickselect:** Uses partitioning and searches only the side containing the required element.
- **Quick Sort:** Uses partitioning and recursively sorts both sides.
- **Heap Sort:** Builds a Max Heap and repeatedly moves the maximum element to the end.
- **Max Heap:** Every parent node is greater than or equal to its children.

## Quickselect Dry Run

For:

```text
Array = [7, 2, 10, 4, 3]
```

Using `3` as pivot:

```text
[7, 2, 10, 4, 3]
          pivot=3

After partition:

[2, 3, 10, 4, 7]
    ^
 pivot index = 1
```

If the required index is `2`, Quickselect searches only the right side:

```text
[10, 4, 7]
```

Partitioning around `7` gives:

```text
[4, 7, 10]
```

Therefore the required element is `7`.

## Heap Sort Dry Run

For:

```text
[4, 10, 3, 5, 1]
```

Build Max Heap:

```text
[10, 5, 3, 4, 1]
```

Move maximum to the end and heapify repeatedly:

```text
[5, 4, 3, 1, 10]
[4, 1, 3, 5, 10]
[3, 1, 4, 5, 10]
[1, 3, 4, 5, 10]
```

Final sorted array:

```text
[1, 3, 4, 5, 10]
```

## Submitted By

**DAA Lab-5 Assignment**

Add your name, roll number, branch, section, and semester before submitting if required by your instructor.


## Graphs / Diagrams

The following diagrams are included for easier understanding and GitHub submission.

### 1. Quickselect Flow

```mermaid
flowchart TD
    A[Start] --> B[Input Array and K]
    B --> C[Choose Pivot]
    C --> D[Partition Array]
    D --> E{Pivot index == K?}
    E -- Yes --> F[Return Element]
    E -- No --> G{K < Pivot Index?}
    G -- Yes --> H[Search Left Part]
    G -- No --> I[Search Right Part]
    H --> C
    I --> C
```

### 2. Quick Sort Flow

```mermaid
flowchart TD
    A[Start] --> B[Choose Pivot]
    B --> C[Partition Array]
    C --> D[Quick Sort Left Part]
    C --> E[Quick Sort Right Part]
    D --> F{Subarray has one element?}
    E --> F
    F -- No --> B
    F -- Yes --> G[Sorted Array]
```

### 3. Heap Sort Flow

```mermaid
flowchart TD
    A[Start] --> B[Build Max Heap]
    B --> C[Swap Root with Last Element]
    C --> D[Reduce Heap Size]
    D --> E[Heapify Root]
    E --> F{Heap Size > 1?}
    F -- Yes --> C
    F -- No --> G[Sorted Array]
```

### 4. Max Heap Structure

For example:

```text
              10
             /  \
            5    3
           / \
          4   1
```

Array representation:

```text
Index:   0   1   2   3   4
Value:  10   5   3   4   1
```

For a node at index `i`:

```text
Left Child  = 2*i + 1
Right Child = 2*i + 2
Parent      = (i - 1) / 2
```

### 5. Quickselect vs Quick Sort

```mermaid
flowchart LR
    A[Partition] --> B[Quickselect]
    A --> C[Quick Sort]
    B --> D[Search Only Required Side]
    C --> E[Sort Both Sides]
    D --> F[Find K-th Element / Median]
    E --> G[Complete Sorted Array]
```

These diagrams are written in **Mermaid**, so GitHub can render them directly inside `README.md`.


# Algorithms and Graphs

## 1. Algorithm: Median Using Quickselect

**Input:** Array `A` of `N` elements.

**Algorithm:**
1. If `N` is odd, set `K = N/2`.
2. If `N` is even, find elements at indices `N/2 - 1` and `N/2`.
3. Choose the last element as the pivot.
4. Partition the array so elements smaller than or equal to the pivot are placed on the left.
5. Get the final position of the pivot.
6. If the pivot position is `K`, return the pivot.
7. If `K` is smaller than the pivot position, repeat Quickselect on the left part.
8. Otherwise, repeat Quickselect on the right part.
9. For an even-sized array, average the two middle elements.

**Pseudocode:**

```text
QUICKSELECT(A, low, high, K)
    if low == high
        return A[low]

    p = PARTITION(A, low, high)

    if p == K
        return A[p]

    if K < p
        return QUICKSELECT(A, low, p-1, K)

    return QUICKSELECT(A, p+1, high, K)
```

### Graph / Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Read N elements]
    B --> C{N is odd?}
    C -- Yes --> D[K = N/2]
    C -- No --> E[Find N/2-1 and N/2]
    D --> F[Choose Pivot]
    E --> F
    F --> G[Partition Array]
    G --> H{Pivot position = K?}
    H -- Yes --> I[Return Element]
    H -- No --> J{K < Pivot Position?}
    J -- Yes --> K[Quickselect Left Part]
    J -- No --> L[Quickselect Right Part]
    K --> F
    L --> F
    I --> M[Median]
```

---

## 2. Algorithm: K-th Smallest Using Quickselect

**Input:** Array `A` of `N` elements and integer `K`.

**Algorithm:**
1. Check that `1 <= K <= N`.
2. Convert K-th position to zero-based index: `K = K - 1`.
3. Choose the last element as pivot.
4. Partition the array.
5. Find the pivot's final position `P`.
6. If `P == K`, the pivot is the answer.
7. If `K < P`, search the left part.
8. If `K > P`, search the right part.
9. Stop when the required element is found.

**Pseudocode:**

```text
QUICKSELECT(A, low, high, K)
    if low == high
        return A[low]

    P = PARTITION(A, low, high)

    if P == K
        return A[P]

    if K < P
        return QUICKSELECT(A, low, P-1, K)

    return QUICKSELECT(A, P+1, high, K)
```

### Graph / Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Read Array and K]
    B --> C[Set K = K-1]
    C --> D[Choose Pivot]
    D --> E[Partition Array]
    E --> F{Pivot Position = K?}
    F -- Yes --> G[Return A[K]]
    F -- No --> H{K < Pivot Position?}
    H -- Yes --> I[Search Left Part]
    H -- No --> J[Search Right Part]
    I --> D
    J --> D
    G --> K[End]
```

---

## 3. Algorithm: Quick Sort

**Input:** Array `A` containing `N` elements.

**Algorithm:**
1. If `low >= high`, stop because the subarray has at most one element.
2. Choose the last element as pivot.
3. Partition the array around the pivot.
4. The pivot reaches its correct position.
5. Recursively apply Quick Sort to the left subarray.
6. Recursively apply Quick Sort to the right subarray.
7. Continue until all subarrays contain at most one element.

**Pseudocode:**

```text
QUICKSORT(A, low, high)
    if low < high
        P = PARTITION(A, low, high)

        QUICKSORT(A, low, P-1)
        QUICKSORT(A, P+1, high)
```

### Graph / Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Read Array]
    B --> C{low < high?}
    C -- No --> D[Return]
    C -- Yes --> E[Choose Pivot]
    E --> F[Partition Array]
    F --> G[Quick Sort Left Part]
    F --> H[Quick Sort Right Part]
    G --> I{Subarray size <= 1?}
    H --> I
    I -- No --> E
    I -- Yes --> J[Sorted Array]
```

### Quick Sort Partition Graph

For:

```text
[7, 2, 10, 4, 3]
```

Pivot = `3`

```text
             3
           /   \
        2       7,10,4
```

After partition:

```text
[2, 3, 10, 4, 7]
```

Then Quick Sort recursively sorts:

```text
Left  = [2]
Right = [10,4,7]
```

---

## 4. Algorithm: Heap Sort

**Input:** Array `A` containing `N` elements.

**Algorithm:**
1. Start with the input array.
2. Build a Max Heap.
3. The largest element is now at the root (`A[0]`).
4. Swap the root with the last element.
5. Reduce the heap size by one.
6. Heapify the root to restore the Max Heap.
7. Repeat steps 3–6 until only one element remains.
8. The array is sorted in ascending order.

**Pseudocode:**

```text
HEAPSORT(A, N)

    for i = N/2 - 1 down to 0
        HEAPIFY(A, N, i)

    for i = N-1 down to 1
        swap(A[0], A[i])
        HEAPIFY(A, i, 0)
```

### Heapify Pseudocode

```text
HEAPIFY(A, N, i)

    largest = i
    left = 2*i + 1
    right = 2*i + 2

    if left < N and A[left] > A[largest]
        largest = left

    if right < N and A[right] > A[largest]
        largest = right

    if largest != i
        swap(A[i], A[largest])
        HEAPIFY(A, N, largest)
```

### Graph / Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Read Array]
    B --> C[Build Max Heap]
    C --> D[Swap Root with Last Element]
    D --> E[Reduce Heap Size]
    E --> F[Heapify Root]
    F --> G{Heap Size > 1?}
    G -- Yes --> D
    G -- No --> H[Sorted Array]
    H --> I[End]
```

### Max Heap Graph

For:

```text
[10, 5, 3, 4, 1]
```

the tree is:

```text
              10
             /  \
            5    3
           / \
          4   1
```

Array representation:

```text
Index:   0   1   2   3   4
Value:  10   5   3   4   1
```

Relations:

```text
Left Child  = 2*i + 1
Right Child = 2*i + 2
Parent      = (i - 1) / 2
```

---

## 5. Overall Lab-5 Algorithm Graph

```mermaid
flowchart TD
    A[DAA LAB-5] --> B[Problem 1]
    A --> C[Problem 2]
    A --> D[Problem 3]
    A --> E[Problem 4]

    B --> B1[Median]
    B1 --> B2[Quickselect]

    C --> C1[K-th Smallest]
    C1 --> C2[Quickselect]

    D --> D1[Random Elements]
    D1 --> D2[Store in File]
    D2 --> D3[Read from File]
    D3 --> D4[Quick Sort]
    D4 --> D5[Sorted Array]

    E --> E1[Random Elements]
    E1 --> E2[Store in File]
    E2 --> E3[Read from File]
    E3 --> E4[Build Max Heap]
    E4 --> E5[Heap Sort]
    E5 --> E6[Sorted Array]
```

## Algorithm Comparison

| Problem | Technique | Main Idea |
|---|---|---|
| Median | Quickselect | Find middle element without complete sorting |
| K-th Smallest | Quickselect | Find required order statistic |
| Quick Sort | Divide and Conquer | Partition and recursively sort both sides |
| Heap Sort | Heap | Build Max Heap and repeatedly extract maximum |


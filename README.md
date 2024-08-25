# Container Reordering Task

For application which operates on various sequence STL containers with elements of type:
```
struct Data {
    std::uint8_t x;
    double y;
};
```
* Let container elements with x bigger than given threshold ```x_threshold``` be subset A.
* Let container elements with x smaller or equal to given threshold ```x_threshold``` be subset B.

Implement library with function which:
1. Reorders the container in such a way, that subset A preceeds subset B.
2. Reorders elements of subset B in such a way, that given number ```n``` of elements has smallest value of y and this n elements are in ascending order of y. Let this ```n``` elements be subset C.
3. Accepts callback as a parameter and applies it to elements of subset C. Callback takes ```Data&``` as parameter and returns no result.

Non-functional requirements:
* Source code should be stored in git repository
* Create unit tests for the library

# Info About Implementation

Code is implemented for sequence STL containers. We have five sequence STL containers(vector, array, deque, forward_list, list).

Functions calls should follow the sequence present in a test.cpp. Because without forming subsetA and subsetB we can not form subsetC, also without forming subsetC we can't apply callback on each element of subsetC.

Implemented dedicated functions(reorderSubsetAB, formSubsetC, callbackOnSubsetC) for above mentioned three subtasks.

Added test cases in test.cpp file and given comment for every testcase starting as "test_case:" in file. Performed testcases:
* all the sequence container tested at once
* passing n for subsetC length more then subsetB length
* didn't keep x value for any element less x_throshold so, subsetB itself not able to form
* didn't keep x value for any element greater then x_throshold so, subsetA itself not able to form

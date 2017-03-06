# FacebookDominatingSet

This catalogues two methods with which to determine a dominating set or set cover approximation. The first, a Greedy Algorithm whose definition can be found <a href="http://webpages.ursinus.edu/nscoville/sensornets14.pdf"> here.</a> This is a completely original implementation, (despite the pseudocode used as a reference) mistakes and all :)

The next, a modification of the code for a set cover algorithm found <a href="http://www.geeksforgeeks.org/vertex-cover-problem-set-1-introduction-approximate-algorithm-2/"> here.</a> The determination method used is identical to that found in the source, with input changes. Changes are: the ability to use an adjacency matrix to determine what edges to add and tracking which edges have been added so as to prevent duplicates caused by the symmetry of the adjacency matrix.

The adjacency matrix is what is used to generate the dominating sets.

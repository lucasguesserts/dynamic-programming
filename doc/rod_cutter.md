# Rod Cutter

## Problem

Given a rod of length `n`, and an array that contains the prices of all the pieces smaller than `n`, determine the maximum profit you could obtain from cutting up the rod and selling its pieces.

## Problem in Mathematical Terms

### Input

- the rod size $n \in \N$
  - define a domain set $D = \{1, ..., n\}$
- piece price function $f: D \rightarrow \R_+^*, \quad f(0) = 0$

Obs: the natural numbers here do not include $0$.

### Goal

Let $p \in \N^1 \cup \dots \cup \N^n$ and $l = length(p)$:

Maximize $\displaystyle\sum\limits_{j = 1}^{l} f(p_j)$

Subjected to $\displaystyle\sum\limits_{j = 1}^{l} p_j \leq n$

## Analysis

Does this problem has the two required characteristics: optimal substructure and overlapping subproblems?

### Optimal Substructure

> problem exhibits optimal substructure if an optimal solution to the problem contains within it optimal solutions to subproblems

Consider an optimal solution $p = \left<p_1, \dots, p_l\right>$ for the problem. Consider now solving the same problem for a rod of size $p_1$.

As a first guess, one could say that the solution is $\left<p_1\right>$, but is really it? I mean, is it possible to have a better solution?

The answer is no, it is not possible. If there was a better solution $p'$, then one could replace $p_1$ by all values in $p'$ in order to get a better solution. Since one assumend that $p$ is optimal, then there is no solution better than $\left<p_1\right>$

The same is valid for any value of $p$. It is also valid for the sum of values in $p$. e.g. the solution for a rod of length $p_1 + p_2$ is $\left<p_1, p_2\right>$.

One can see that the problem ideed exhibits optimal substructure.

### Overlapping Subproblems

> When a recursive algorithm revisits the same problem repeatedly, we say that the optimization problem has overlapping subproblems.

It is unfortunate that the definition requires an algorithm... But one can get the idea of why the problem has overlapping subproblems: solving for any $n$ will require evaluating the solution for $n = 1$, $n = 2$, ...

### Conclusion

Dynamic Programming is appliable!

## References

- Cormen, Thomas H., et al. Introduction to algorithms. MIT press, 2022.
- [udemy](https://www.udemy.com/course/dynamic-programming-i/learn/lecture/10879632?start=0#overview)
- [educative.io](https://www.educative.io/edpresso/the-rod-cutting-problem)

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

## References

- [udemy](https://www.udemy.com/course/dynamic-programming-i/learn/lecture/10879632?start=0#overview)
- [educative.io](https://www.educative.io/edpresso/the-rod-cutting-problem)

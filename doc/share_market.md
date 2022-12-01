# Share Market

## Problem

You are given an array in which the $i$th element is the price of a given stock on the day $i$. You are permitted to complete at most 1 transaction (i.e. buy once and sell once). What is the maximum profit you can gain?

Notice that you cannot sell a stock before buying it.

### Input

* An array of prices $p = \langle p_{0}, \dots, p_{n-1} \rangle \in \R^n_+ \land n \in \N \land n \geqslant 2$

### Intermediate Result

An array of ordered pairs $r = \langle \langle b_{0}, s_{0} \rangle, \dots, \langle b_{m-1}, s_{m-1} \rangle \rangle,  m \in \N$.

Satisfying:

* $b_{i}, s_{i} \in \{0, \dots, n-1\}, \forall i \in \{0, \dots, m-1\}$
* $b_{i} < s_{i}, \forall i \in \{0, \dots, m-1\}$
* $s_{i} < b_{i+1}, \forall i \in \{0, \dots, m-2\}$

$b$ represents a _buy_ operation and $s$ a _sell_ one.

### Output

A value $z = \displaystyle\sum\limits_{i=0}^{m-1} p_{s_{i}} - p_{b_{i}} \in \R_+$.

### Goal

maximize $z$.

## Solution - Dynamic Programming

Given that you buy on a day $i$, while the value does not decrease, you keep it. If it will drop the next day, you sell it.

### Initial State

Find the first pair $\langle b, s \rangle$ for which the price increases, i.e. the first pair of consecutive indices for which $p_s - p_b > 0$.

### Optimal Substructure

Let:

* $\langle b_l, s_l \rangle$ be the last operation;
* $p_{s_l}$ be the price of the last sell;
* $i$ the index of the current day;
* $p_i$ the stock price of the current day;
* $p_{i-1}$ the stock price of the previous day;

Cases:

1. if $(s_l == i-1) \land (p_{s_l} \leqslant p_i)$
    1. replace $\langle b_l, s_l \rangle$ by $\langle b_l, i \rangle$
    2. rationale: if the stock price is increasing, you keep it;
2. if $(s_l < i-1) \land (p_{i-1} \leqslant p_i)$
    1. add $\langle i-1, i \rangle$
    2. rationale: if you have no stock and it will increase, you buy and sell it;
3. the others are cases in which the stock price drops, and there is nothing to do;

Complexity: $\mathcal{O}(n)$

## Solution - Simple

Pseudocode:

1. $ \Delta p = \left[ \langle p_{i+1} - p_i \rangle \ for \ i \in \{0, \dots, n-2\}\right]$
2. $\Delta p_> = filter(\Delta p, (>=0))$
3. $r = sum(\Delta p_>)$
4. return $r$

The filter takes care of removing the drops on the price, while the sum of the differences computes the gains.

Complexity: $\mathcal{O}(n)$

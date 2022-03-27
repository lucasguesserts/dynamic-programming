# Factorial

```pseudocode
factorial(0) = 1
factorial(n) = n * factorial(n - 1)
```

|       n      | 0 | 1 | 2 | 3 |  4 |   5 |   6 |    7 |     8 |      9 |
|-------------:|--:|--:|--:|--:|---:|----:|----:|-----:|------:|-------:|
| factorial(n) | 1 | 1 | 2 | 6 | 24 | 120 | 720 | 5040 | 40320 | 362880 |

## Fast Computation Strategy

The naive implementation is to make a recursive implementation. That would be bad. A not that better one is to use a for loop (you save some function calls). Then one can improve it quite a lot by using memoization. That is not the best though.

Since factorial grows very fast and there is a limited number of inputs for which one can compute a factorial value that fits the memory, one can simply implement a lookup table.

## References

- [Factorial](https://en.wikipedia.org/wiki/Factorial)
- [Fastest factorial implementation with 64-bit result in assembly](https://stackoverflow.com/questions/3207094/fastest-factorial-implementation-with-64-bit-result-in-assembly)

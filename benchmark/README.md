# Benchmark

## Many of the benchmarks provided here are meaningless

Take the benchmarks for the problem 'on the way home', which in my computer display the following result:

```plain
============ ./benchmark/BM_onTheWayHome ============
2022-04-04T20:44:09-03:00
Running ./benchmark/BM_onTheWayHome
----------------------------------------------------------------
Benchmark                      Time             CPU   Iterations
----------------------------------------------------------------
BM_onTheWayHome_opt          342 ns          342 ns      2026025
BM_onTheWayHome_class        412 ns          412 ns      1685007
BM_onTheWayHome_naive     111018 ns       110846 ns         6281
```

Now change the last problem instances to:

```cpp
{120, 50},
{50, 120},
```

And run it again. In my machine I get:

```plain
============ ./benchmark/BM_onTheWayHome ============
2022-04-04T20:44:09-03:00
Running ./benchmark/BM_onTheWayHome
----------------------------------------------------------------
Benchmark                      Time             CPU   Iterations
----------------------------------------------------------------
BM_onTheWayHome_opt          344 ns          344 ns      1958756
BM_onTheWayHome_class        424 ns          423 ns      1618929
```

(I removed the naive implementation for obvious reasons...)

How come one gets the same results?!?!?! Well, it is actually quite simple, it computes once and then it retrieves the same values over and over again. It is always falling in the case "the value is available, simply retrieve it". Since the number of runs is high, the time tends to be the time required for retrieving the entry of the matrix. And then, the benchmark becomes useless...

What it should do instead is to reinitialize the vector of values every time it runs, because what we want to measure is the time it requires for getting the solution of a big problem provided it has never run.

That is going to happen in every solution which uses memoization, i.e. all solutions we care about... (Damn it!).

import functools
import itertools
import random
import time


def generate_random_sequence() -> list:
    SEQUENCE_SIZE = 22
    MINIMUM_VALUE = 1
    MAXIMUM_VALUE = 20
    sequence = [
        random.randint(MINIMUM_VALUE, MAXIMUM_VALUE) for i in range(SEQUENCE_SIZE)
    ]
    return sequence


def flat_map(array):
    return functools.reduce(list.__add__, array)


def is_increasing_sequence(sequence: list) -> bool:
    for i in range(len(sequence) - 1):
        if sequence[i] >= sequence[i + 1]:
            return False
    return True


def generate_all_subsequences(sequence: list) -> list:
    x = flat_map(
        [list(itertools.combinations(sequence, l)) for l in range(1, len(sequence) + 1)]
    )
    print(f"Sequence: {sequence}")
    # print(f"all subsequences: {x}")
    print("")
    return x


def arg_max(func: callable, l: list) -> list:
    return max(l, key=func)


def naive_algorithm(sequence: list) -> list:
    all_subsequences = generate_all_subsequences(sequence)
    increasing_subsequences = list(filter(is_increasing_sequence, all_subsequences))
    solution = arg_max(len, increasing_subsequences)
    return solution


# if __name__ == "__main__":
#     sequence = [9, 8, 5, 2, 9, 10, 7, 3, 7, 9]
#     naive_solution = naive_algorithm(sequence)
#     opt_solution = opt_algorithm_1(sequence)
#     print(f"Sequence: {sequence}")
#     print(f"Naive solution: {naive_solution}")
#     print(f"Opt   solution: {opt_solution}")
#     print(
#         f"Solutions are equivalent: {are_solutions_equivalent(len, naive_solution, opt_solution)}"
#     )

def execute_algorithm(algorithm, sequence):
    start_time = time.process_time()
    solution = algorithm(sequence)
    finish_time = time.process_time()
    duration = finish_time - start_time
    return (duration, solution)


if __name__ == "__main__":
    list_of_random_sequences = [generate_random_sequence() for i in range(1)]
    algorithms = [naive_algorithm]
    processing_time = [0 for _ in algorithms]
    for sequence in list_of_random_sequences:
        executions_output = execute_algorithm(naive_algorithm, sequence)
        print(f"list: {sequence}")
        print(f"solution: {executions_output[1]}")
        print(f"solution length: {len(executions_output[1])}")
        print(f"execution time: {executions_output[0]}")
        print("")

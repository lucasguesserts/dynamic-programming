import itertools
import random
import sys


def flat_map(f: callable, xs: list) -> list:
    # https://dev.to/turbaszek/flat-map-in-python-3g98
    ys = []
    for x in xs:
        ys.extend(f(x))
    return ys


def generate_sequence_set_with_defined_size(valid_steps: list[int], sequence_size: int) -> list[list[int]]:
    return list(itertools.product(valid_steps, repeat=sequence_size))


def generate_sequence_set(number_of_steps: int, step_limit: int) -> list[list[int]]:
    valid_steps = range(1, step_limit + 1)
    all_sequences = flat_map(
        lambda sequence_size: generate_sequence_set_with_defined_size(
            valid_steps, sequence_size
        ),
        range(1, number_of_steps + 1),
    )
    valid_sequences = list(filter(lambda s: sum(s) == number_of_steps, all_sequences))
    return valid_sequences


def compute_sequence_cost(sequence: list[int], fees: list[float]) -> float:
    acc: float = fees[0]
    for i in range(1, len(sequence)):
        current_step = sum(sequence[:i])
        acc += fees[current_step]
    return acc


def arg_min(f: callable, l: list):
    if len(l) == 0:
        raise ValueError("list must have at least one element")
    minimum_value = f(l[0])
    minimum_index = 0
    for index in range(1, len(l)):
        value = f(l[index])
        if value < minimum_value:
            minimum_value = value
            minimum_index = index
    return l[minimum_index]


def naive_algorithm(number_of_steps: int, step_limit: int, fees: list[float]) -> tuple[list[int], float]:
    sequence_set: list[list[int]] = generate_sequence_set(number_of_steps, step_limit)
    optimal_sequence = arg_min(
        lambda s: compute_sequence_cost(s, fees),
        sequence_set
    )
    cost_of_optimal_sequence = compute_sequence_cost(optimal_sequence, fees)
    return (optimal_sequence, cost_of_optimal_sequence)


def run_case_verbose(number_of_steps: int, step_limit: int, fees: list[float] = None, case_name: str = "") -> None:
    if fees == None:
        fees = [random.randint(1, 10) for i in range(number_of_steps)]
    sequence_set: list[list[int]] = generate_sequence_set(number_of_steps, step_limit)
    optimal_sequence, cost_of_optimal_sequence = naive_algorithm(number_of_steps, step_limit, fees)
    print("")
    if len(case_name) > 0:
        print(f"===== {case_name} =====")
    else:
        print("=====")
    print(f"number_of_steps = {number_of_steps}")
    print(f"step_limit = {step_limit}")
    print(f"fees = {fees}")
    print("sequences and costs:")
    for s in sequence_set:
        print(f"\tcost = {compute_sequence_cost(s, fees)}, sequence = {s}")
    print(f"optimal cost sequence: {optimal_sequence}")
    print(f"cost of optimal sequence: {cost_of_optimal_sequence}")
    print("")
    return


if __name__ == "__main__":
    run_case_verbose(number_of_steps=3, step_limit=3, fees=[2, 3, 4], case_name="Example 1")
    run_case_verbose(number_of_steps=4, step_limit=3, fees=[1, 1, 1, 3], case_name="Example 2")
    run_case_verbose(number_of_steps=6, step_limit=3, case_name="random case")

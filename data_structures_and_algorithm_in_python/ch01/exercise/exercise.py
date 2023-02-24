from random import *


# Reinforcement
def is_multiple(n, m):
    """
    R-1.1
    """
    return True if n % m == 0 else False


def is_even(k):
    """
    R-1.2
    """
    return True if k % 2 == 0 else False


def minmax(data):
    """
    R-1.3
    """
    min_val, max_val = 99999, -1
    for d in data:
        if min_val > d:
            min_val = d

        if max_val < d:
            max_val = d

    return min_val, max_val


def sum_squares_smaller_than(n):
    """
    R-1.4
    """
    total = 0
    for i in range(1, n):
        total += i * i

    return total


def sum_squares_smaller_than_compact(n):
    """
    R-1.5
    """
    return sum([k * k for k in range(1, n)])


def sum_odd_squares_smaller_than(n):
    """
    R-1.6
    """
    total = 0
    for i in range(1, n):
        if i % 2 != 0:
            total += i * i

    return total


"""
R-1.7
"""
n = 10
print(sum([k * k for k in range(1, n) if k % 2 != 0]))


"""
R-1.8
equivalent index j is k + n
"""


"""
R-1.9
range(50, 81, 10)
"""


"""
R-1.10
range(8, -9, -2)
"""


"""
R-1.11
"""
r_11 = [pow(2, i) for i in range(9)]


def my_choice(data):
    """
    R-1.12
    """
    return data[randrange(0, len(data))]


# Creativity
def reverse_data(data):
    """
    C-1.13
    """
    return iter([i for i in data[::-1]])


def find_pairs_odd_product(data):
    """
    C-1.14
    """
    pairs = []
    for i in range(len(data) - 1):
        for j in range(i + 1, len(data)):
            if i * j % 2 != 0:
                pairs.append((i, j))

    return pairs


def check_distinct_sequence(data):
    """
    C-1.15
    """
    d = {}
    for i in range(len(data)):
        if d.get(data[i]) is None:
            d[data[i]] = 1
        else:
            return False

    return True


"""
C-1.16
Yes
"""


"""
C-1.17
It does not change value of data
"""


"""
C-1.18
"""
c_18 = [i ** 2 - i for i in range(1, 11)]


# C-1.19
words = [chr(w) for w in range(97, 123)]


# C-1.20
from random import randrange, randint  # noqa


def shuffle(data):
    n = len(data)
    for i in range(n - 1, 0, -1):
        j = randint(0, i - 1)
        data[i], data[j] = data[j], data[i]


data = [1, 2, 3, 4]
shuffle(data)
data


# C-1.21
def print_reverse_input():
    input_strs = []
    while True:
        try:
            line = input()
        except EOFError:
            break
        input_strs.append(line)
    for line in reversed(input_strs):
        print(line)


print_reverse_input()


# C-1.23
index = input()
value = input()
a = [1, 2, 3, 4]
try:
    a[index] = value
except IndexError:
    print("Don't try buffer overflow attacks in Python!")


# C-1.24
def count_vowels(sequence):
    vowels = ["u", "e", "o", "a", "i"]
    count = 0
    for char in sequence:
        if char in vowels:
            count += 1

    return count


# C-1.25
def remove_punctuation(sentence):
    removed = [
        char
        for char in sentence
        if char >= "a" and char <= "z" or char >= "A" and char <= "Z" or char == " "
    ]
    print(removed)
    return "".join(removed)


remove_punctuation("Let s try, Mike.")

#%% C-1.27
def factors(n):  # generator that computes factors
    k = 1
    larger_factors = []
    while k * k < n:  # while k < sqrt(n)
        if n % k == 0:
            yield k
            larger_factors.append(n // k)
        k += 1
    if k * k == n:  # special case if n is perfect square
        yield k
    for factor in reversed(larger_factors):
        yield factor


for i in factors(9):
    print(i)

#%% C-1.28
def norm(vector, p=2):
    return sum(v ** p for v in vector) ** (1 / p)


print(norm([4, 3, 4], 3))

#%% P-1.30

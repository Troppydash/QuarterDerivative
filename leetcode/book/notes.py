from typing import TypeVar


T = TypeVar("T")


def subsets(arr: list[T], subset: list[T]):
    if len(arr) == 0:
        ...  # process subset
        return

    subsets(arr[1:], subset)
    subsets(arr[1:], [*subset, arr[0]])

    # subsets([1, 2, 3], [])  returns the subsets of {1,2,3}


def permutations(arr: list[T], perm: list[T], chosen: list[bool]):
    if len(perm) == len(arr):
        ...  # process permutation
        print(perm)
        return

    for i, e in enumerate(arr):
        if chosen[i]:
            continue

        chosen[i] = True
        permutations(arr, [*perm, e], chosen)
        chosen[i] = False

    # permutations([1, 2, 3], [], [False] * 3)  returns the permutation of {1,2,3}


def queens(n: int):
    cols = [False] * n
    diag1 = [False] * (2 * n - 1)  # represents the x+y diag (top right to bottom left)
    diag2 = [False] * (
        2 * n - 1
    )  # represents the x+n-y-1 diag (bottom left to top right)

    def recursion(y: int):
        if y == n:
            # then we've placed y queens
            return 1

        counts = 0
        for x in range(n):
            # can't place queen
            if cols[x] or diag1[x + y] or diag2[x + n - y - 1]:
                continue

            cols[x] = diag1[x + y] = diag2[x + n - y - 1] = True
            counts += recursion(y + 1)
            cols[x] = diag1[x + y] = diag2[x + n - y - 1] = False
        return counts

    return recursion(0)


def subarray(arr):
    if len(arr) == 0:
        return 0

    overall = trailing = 0
    for i in range(len(arr)):
        trailing = max(arr[i], trailing + arr[i])
        overall = max(trailing, overall)

    return overall


print(subarray([-1]))

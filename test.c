import numpy as np
from scipy.linalg import solve
from copy import deepcopy


f = open("test.txt")
length = int(f.readline())
A = []
B = []
print(length)
for _ in range(length):
    row = f.readline().split()
    A1 = []
    for j in range(len(row) - 1):
        A1.append(int(row[j]))

    B.append(int(row[-1]))
    A.append(A1)

A_test = np.array(A[:][:])
B_test = np.array(B[:])


def determinant(matrix: list[list[int]]) -> int:
    det = 0
    match len(matrix):
        case 1:
            return matrix[0][0]
        case 2:
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
        case _:
            for k in range(len(matrix)):
                det += matrix[0][k] * (-1) ** k * determinant(
                    [matrix[i][:k] + matrix[i][k + 1:] for i in range(1, len(matrix))])
    return det


def kramer(a, b):
    det = determinant(a)
    if det == 0:
        print("определитель равен 0")
        return
    print("Метод Крамера:")
    for i in range(len(a)):
        new_a = deepcopy(a)
        for j in range(len(a)):
            new_a[j][i] = b[j]
        print(f"x{i} = {determinant(new_a) / det}")


def second_helper(a, b):
    x0 = [0 for _ in range(len(a))]  # Значения переменных предыдущей итерации
    x = [1 for _ in range(len(a))]  # Значения переменных текущей итерации
    de = [1 for _ in range(len(a))]  # Погрешность
    e = 10 ** -15  # Заданная точность
    n = len(a)

    while max(de) > e:
        for i in range(n):
            s = b[i]
            for j in range(n):
                if j != i:
                    s -= a[i][j] * x0[j]
            s /= a[i][i]

            s = float('{:.15f}'.format(s))
            de[i] = float('{:.15f}'.format(abs(s - x0[i])))
            x[i] = s

        for i in range(n):
            x0[i] = x[i]

    print("\nМетод простых итераций")
    for i in range(n):
        print(f"x{i} = {x[i]}")


def second(a, b):
    a0 = deepcopy(a)
    flag = True
    for i in range(len(a)):
        for j in range(len(a)):
            a[i][j] = abs(a[i][j])

    for i in range(len(a)):
        if sum(a[i]) - 2 * a[i][i] >= 0:
            flag = False
            print("Диагональное преобладание не соблюдается")
            break
    if flag:
        second_helper(a0, b)


kramer(A, B)
second(A, B)


ans = solve(A_test, B_test)

print("\nРешение системы уравнений из библиотеки:", *ans, sep="\n")

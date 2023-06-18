import csv
import numpy as np
import sympy as sym

file = "input.csv"

N = 8
EPS = 1e-4

class Func:

    def __init__(self, x, y, B, C, D, replace = False):
        self.size = np.size(x)

        self.x = x
        self.y = y
        self.B = B.flatten()
        self.C = C.flatten()
        self.D = D.flatten()

        self.replace = replace

    def getIndex(self, x0):

        if x0 < self.x[0]:
            return 0

        for i in range(1, self.size - 1):
            if self.x[i - 1] < x0 < self.x[i + 1]: return i

        return self.size - 2

    def calculate(self, x0):

        ind = self.getIndex(x0)

        ans = self.y[ind] + self.B[ind] * (x0 - self.x[ind]) + self.C[ind] * (x0 - self.x[ind]) ** 2 + self.D[ind] * (x0 - self.x[ind]) ** 3

        if self.replace: return sym.exp(ans)
        else: return ans

def readFromFile(file):
    Table = []

    with open(file) as f:
        reader = csv.DictReader(f)

        for row in reader:
            Table.append(np.array(list(map(float, [*row.values()]))))

    return Table

def generate():
    x = np.linspace(0, 1.2, 13)
    y = np.linspace(0, 1.2, 13)

    Table = np.ones((13, 15))
    Table[:, 0] = x
    Table[:, 1] = y

    # 2x + 3y + 3 = 0

    for i in range(13):
        for j in range(13):
            Table[i, j + 2] = 2 * Table[i, 0] + 3 * Table[j, 1] + 3

    return Table





def quadratureFormula(n: int):
    if n % 2 == 0: return 2 / (n + 1) 
    else: return 0

def getLegendrePoly(num: int):

    x = sym.symbols("x")
    func = f"(x**2-1)**{num} / (2 ** {num})"
    func = sym.sympify(func)
    func = func / sym.factorial(num)

    return sym.Derivative(func, (x, num)).doit()

def solveSystem(polyZeros):

    matrix = np.array([polyZeros ** i for i in range(N)], dtype = "float")
    matrix.reshape((N, N))

    BCoefs = np.array([quadratureFormula(i) for i in range(N)], dtype = "float")
    BCoefs.reshape((N, 1))

    return np.linalg.solve(matrix, BCoefs)

def Gauss(a, b, f: Func, ACoefs, polyZeros):

    xValues = (b + a) / 2 + (b - a) * polyZeros / 2

    funcValues = np.array([f.calculate(x) for x in xValues])

    return (b - a) * np.sum(ACoefs * funcValues) / 2

def Simpson(a, b, f: Func):
    amount = 16

    h = (b - a) / amount
    edge = int(amount / 2)
    xValues = np.linspace(a, b, amount + 1)

    return h * np.sum([f.calculate(xValues[2 * i]) + 4 * f.calculate(xValues[2 * i + 1]) + f.calculate(xValues[2 * i + 2]) for i in range(edge)]) / 3

def spline(x, y):

    size = np.size(x)

    deltaX = np.diff(x)
    deltaY = np.diff(y)

    # A * C = b

    A = np.zeros((size, size))
    b = np.zeros((size, 1))
    A[0, 0] = 1
    A[-1, -1] = 1

    for i in range(1, size - 1):
        A[i, i - 1] = deltaX[i - 1]
        A[i, i + 1] = deltaX[i]
        A[i,i] = 2*(deltaX[i-1] + deltaX[i])

        b[i,0] = 3*(deltaY[i] / deltaX[i] - deltaY[i - 1] / deltaX[i - 1])

    C = np.linalg.solve(A, b)

    D = np.zeros((size - 1, 1))
    B = np.zeros((size - 1, 1))

    for i in range(0, size - 1):
        D[i] = (C[i + 1] - C[i]) / (3 * deltaX[i])
        B[i] = (deltaY[i] / deltaX[i]) - (deltaX[i] / 3)*(2 * C[i] + C[i + 1])

    return B, C, D



def solutionWithoutReplace(Table, ACoefs, polyZeros):

    integrals = []
    x = Table[:, 0]
    size = np.shape(Table)[1]

    for i in range(2, size):

        z = Table[:, i]
        B, C, D = spline(x, z)

        f = Func(x, z, B, C, D)

        integrals.append(Gauss(0, 1 - x[i - 2], f, ACoefs, polyZeros))

    integrals = np.array(integrals, dtype = "float")

    y = Table[:, 1]
    B, C, D = spline(y, integrals)

    f = Func(y, integrals, B, C, D)

    return Simpson(0, 1, f)

def solutionWithReplace(Table, ACoefs, polyZeros):

    integrals = []
    x = Table[:, 0]
    size = np.shape(Table)[1]

    for i in range(2, size):

        z = np.log(Table[:, i])
        B, C, D = spline(x, z)

        f = Func(x, z, B, C, D, True)

        integrals.append(Gauss(0, 1 - x[i - 2], f, ACoefs, polyZeros))

    integrals = np.array(integrals, dtype = "float")

    y = Table[:, 1]
    B, C, D = spline(y, integrals)

    f = Func(y, integrals, B, C, D)

    return Simpson(0, 1, f)

poly = getLegendrePoly(N)
polyZeros = np.array(sym.solve(poly.doit(), sym.Symbol('x')))
polyZeros = np.sort(polyZeros)

# polyZeros - zeros of legendre polynomials
# ACoefs - coefficients for A

ACoefs = solveSystem(polyZeros)
print(ACoefs)

Table = np.array(readFromFile(file))
# Table = generate()

ans = solutionWithoutReplace(Table, ACoefs, polyZeros)
print(f"Integral without replacement: {ans:.6f}")
ans = solutionWithReplace(Table, ACoefs, polyZeros)
print(f"Integral with replacement: {ans:.6f}")

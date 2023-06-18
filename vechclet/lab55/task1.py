import sympy as sym
import numpy as np
from scipy.linalg import solve

N = 3
eps = 1e-3

def Newton(F, Jacobian):
    
    curValues = np.array([0.5, 0.5, 0.5], dtype="float")

    FCur = F(*curValues)
    JacobianCur = Jacobian(*curValues)

    delta = solve(JacobianCur, FCur).reshape((N, ))
    curValues += delta
    
    while np.linalg.norm(delta) > eps:
        
        curValues -= delta

        FCur = F(*curValues)
        JacobianCur = Jacobian(*curValues)

        delta = solve(JacobianCur, FCur).reshape((N, ))

    return curValues

vars = ['x', 'y', 'z']
funcs = ['x ** 2 + y ** 2 + z ** 2 - 1',
         '2 * x ** 2 + y ** 2 - 4 * z',
         '3 * x ** 2 - 4 * y + z ** 2']

F = sym.Matrix(funcs)
Jacobian = sym.Matrix(funcs).jacobian(vars)

Jacobian = sym.lambdify(sym.symbols(vars), Jacobian)
F = sym.lambdify(sym.symbols(vars), F)

values = Newton(F, Jacobian)
space = ' '

print(f"Answer is x: {values[0]:.5f}\n{space:>10}y: {values[1]:.5f}\n{space:>10}z: {values[2]:.5f}\n")

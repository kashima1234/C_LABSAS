import numpy as np
import prettytable as pt

N = 6

def formatOut(num):
    return f"{num:.5f}"

def leftDiffDer(yValue, step, index):
    if index > 0:
        return formatOut((yValue[index] - yValue[index - 1]) / step)
    else:
        return '*'

def centerDiffDer(yValue, step, index):
    if index > 0 and index < N - 1:
        return formatOut((yValue[index + 1] - yValue[index - 1]) / (2 * step))
    else:
        return '*'

def secondRunge(yValue, step, index):
    if  not (1 < index < N - 2):
        return '*'

    f1 = (yValue[index + 1] - yValue[index - 1]) / (2 * step)
    f2 = (yValue[index + 2] - yValue[index - 2]) / (4 * step)

    return formatOut(f1 + (f1 - f2) / 3)

def aligVars(yValue, xValue, index):
    if index > N - 2:
        return '*'

    d = (1 / yValue[index + 1] - 1 / yValue[index]) / \
        (1 / xValue[index + 1] - 1 / xValue[index])

    return formatOut(d * yValue[index] ** 2 / xValue[index] ** 2)

def secondDiffDer(yValue, step, index):
    if index > 0 and index < N - 1:
        return formatOut((yValue[index - 1] - 2 * yValue[index] + yValue[index + 1]) / step ** 2)
    else:
        return ' *'

xArr = [1, 2, 3, 4, 5, 6]
yArr = [0.571, 0.889, 1.091, 1.231, 1.333, 1.412]
    
step = (xArr[-1] - xArr[0]) / (len(xArr) - 1)

methods = [leftDiffDer, centerDiffDer, 
           secondRunge, aligVars, 
           secondDiffDer]

table = pt.PrettyTable()
filedNames = ["X", "Y", "1", "2", "3", "4", "5"]

table.add_column(filedNames[0], xArr)
table.add_column(filedNames[1], yArr)

for i in range(len(methods)):
    if i == 3:
        table.add_column(filedNames[i + 2], [methods[i](yArr, xArr, j) for j in range(N)])
    else:    
        table.add_column(filedNames[i + 2], [methods[i](yArr, step, j) for j in range(N)])

print(table)

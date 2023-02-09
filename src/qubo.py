from amplify import Solver, BinaryPoly, BinaryQuadraticModel, gen_symbols, decode_solution
from amplify.constraint import equal_to, less_equal
from amplify.client import FixstarsClient
import math

def print_chess(queens):
    dim = len(queens)
    for i in range(dim):
        line = ""
        for j in range(dim):
            if queens[i][j] == 0:
                line += "."
            else:
                line += "Q"
        print(line)

n = int(input("Enter N: "))
q = gen_symbols(BinaryPoly, n, n)

# each row only has one queen
row_constraints = [
    equal_to(sum([q[i][j] for i in range(n)]), 1) 
    for j in range(n)
]

# each column only has one queen
col_constraints = [
    equal_to(sum([q[i][j] for j in range(n)]), 1) 
    for i in range(n)
]

# each bottom left to top right diagonal has at most one queen
left_diag_constraints = [None] * (n * 2 - 1)
for s in range(n*2-1):
    left_sum = BinaryPoly(0)
    for i in range(max(s-n+1, 0), min(s+1, n)):
        left_sum += q[i][s-i]
    left_diag_constraints[s] = less_equal(left_sum, 1)

# each top left to bottom right diagonal has at most one queen
right_diag_constraints = [None] * (n * 2 - 1)
for s in range(1-n, n):
    right_sum = BinaryPoly(0)
    for i in range(max(-s, 0), min(n-s, n)):
        right_sum += q[i][s+i]
    right_diag_constraints[s] = less_equal(right_sum, 1)

# all constraints
constraints = (
    sum(row_constraints)
    + sum(col_constraints)
    + sum(left_diag_constraints)
    + sum(right_diag_constraints)
)

# show all constraints, only for debug
# for i in range(len(constraints)):
#     print(constraints[i])

client = FixstarsClient()
client.parameters.timeout = 5000
client.token = "GzX1Y1Y7Jwv83tgEHD3c7FTpmmW0MH98"

solver = Solver(client)

model = BinaryQuadraticModel(constraints)
result = solver.solve(model)
result_data = solver.client_result
sol_time = result_data.timing.time_stamps
if len(result) == 0:
    print("Unsatisfiable N queens problem at N =", n)
    exit()

values = result[0].values
q_values = decode_solution(q, values)
print_chess(q_values)
print(len(result), "result(s) in:", sol_time, "ms")

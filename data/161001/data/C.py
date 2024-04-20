import math

line = input()
(N, K) = line.split(" ")
N = int(N)
K = int(K)

if K >= math.ceil(math.log(N, 2)):
  print("Your wish is granted!")
else:
  print("You will become a flying monkey!")

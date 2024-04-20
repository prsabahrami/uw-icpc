#!/usr/bin/python

import sys

print "Running with ",str(sys.argv)
eps = 0.0001

jname = sys.argv[0][:-3]+"diff"
print jname
judge = open(sys.argv[0][:-3]+"diff")
#team = open(sys.argv[2])

## Read a sequence of pairs
for jline in judge:
  #j = float(judge.readline())
  j = float(jline)
  #t = float(team.readline())
  t = float(raw_input())

  print "Judge/Team: ", j, t


  if (abs(j-t) > eps):
    print("not within eps")
    sys.exit(2)

print("CORRECT!")
sys.exit(0)

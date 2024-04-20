#!/bin/bash

# Wrapper around checkers extracted from Polygon.
#
# 1) copy this file into contest directory (where the .dat and .diff files are)
# 2) put the Polygon checker binary there too, with filename A.polygon.checker,
#    where A is the problem letter
# 3) for i in A.*.dat; do ln -s polygon_checker_wrapper ${i/dat/cmd}; done

NAME=`basename $0`
#PROB=`echo ${NAME:0:1} | tr A-Z a-z`
PROB=`echo ${NAME:0:1}`
echo Problem $PROB
cat > output.$$
$HOME/data/$PROB.polygon.checker ${0/cmd/dat} output.$$ ${0/cmd/diff} 2>&1
RVAL=$?
# Polygon uses 1 for WA, but we use 1 for Format Error and 2 for Wrong Answer
if [ $RVAL == 1 ]; then
  exit 2;
fi
exit $RVAL

#!/bin/bash
echo "compile "
make all
echo "this is lifetime use register"
./reg
echo "this is lifetime not use regitster"
./unreg
echo "clean all"
make clean

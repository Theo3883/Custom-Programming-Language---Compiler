#!/bin/bash
# filepath: compile.sh

echo "compiling $1"
rm -f lex.yy.c
rm -f $1.tab.c
rm -f $1
bison -d $1.y -Wcounterexamples
flex $1.l
g++ AST.cpp SymTable.cpp lex.yy.c $1.tab.c -o $1 -w
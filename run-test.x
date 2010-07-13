#!/usr/bin/gdb -x

file ./gdb-test
set breakpoint pending on
display/i $pc
break fxn
run .libs/libplugin.so.0.0.0

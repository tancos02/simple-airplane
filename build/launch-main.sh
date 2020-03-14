#!/bin/sh
bindir=$(pwd)
cd /home/paulus/Tugas/GrafKom/simple-airplane/src/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/paulus/Tugas/GrafKom/simple-airplane/build/main 
	else
		"/home/paulus/Tugas/GrafKom/simple-airplane/build/main"  
	fi
else
	"/home/paulus/Tugas/GrafKom/simple-airplane/build/main"  
fi

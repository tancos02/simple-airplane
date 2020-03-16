#!/bin/sh
bindir=$(pwd)
cd /home/hanif/ITB/Education/Semester6/simple-airplane/src/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "xYES" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		/usr/bin/gdb -batch -command=$bindir/gdbscript --return-child-result /home/hanif/ITB/Education/Semester6/simple-airplane/build/main 
	else
		"/home/hanif/ITB/Education/Semester6/simple-airplane/build/main"  
	fi
else
	"/home/hanif/ITB/Education/Semester6/simple-airplane/build/main"  
fi

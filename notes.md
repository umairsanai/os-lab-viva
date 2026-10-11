# Compilation Flags:
    gcc -o hw hw.c          -o:     to specify the executable name
    gcc -Wall hw.c          -Wall:  gives much better warnings
    gcc -g hw.c             -g:     to enable debugging with gdb
    gcc -O hw.c             -O:     to turn on optimization


# Separate Compilation:
    gcc -Wall -O -c hw.c
    gcc -Wall -O -c helper.c
    gcc -o hw hw.o helper.o -lm


# Compiling an object file using a library
    gcc -o account.o -c -Wall account.c -Iinclude -Ilibs/logger


# Creating a Static Library
    gcc -c my_arithmetic.c my_compare.c
    ar crs libmymath.a my_arithmetic.o my_compare.o



# Creating a Dynamic/Shared Library
    gcc -fPIC -c my_arithmetic.c my_compare.c
    gcc -shared my_arithmetic.o my_compare.o -o libmymath.so


# Linking a Static Library
    gcc main.o -Llibs/math -lmymath -o math.out


# Linking a Library Without the lib Prefix
    gcc main.o -L./libs -l:mmm.a -o try.out

# Running an Executable Linked Against a Dynamic/Shared Library
    LD_LIBRARY_PATH=. ./main.out


# GDB Commands:
    help – list commands

    run (arguments)
    
    list – show lines of source
    
    break [file:line number] 
    break list_given.cpp:80, 
    break List::print
    break 41

    clear [file:line number] - Removes a breakpoint

    list - Shows the next few lines where the program is stopped

    finish - Steps out of a function - 
    Abbrevation: fin
    
    next – execute next line, stepping over function calls
    
    step – execute next line, stepping into function calls
    
    print – print the contents of variables and data structures
    
    frame – select frame number, point to the stack you are interested in
    
    backtrace – display program stack and control flow
    
    command – execute GDB command-list every time breakpoint n is reached
    
    continue – continue the execution of the code
    Abbrevation: cont

    info args

    info locals

    print [variable]
    
    quit – quit the debugger


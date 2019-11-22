# CDDLabs-C00220175

These labs are all done in C++ demonstrating different exercises with multi-threading programming. In each file has Doxygen code for clear documentation. Each file has their own makefile for compiling.

##Make file##

You can compile each lab by typing in to the terminal in the working directory, 'make -k'. This will compile the code and create and executable.

If you type 'make CLEAN' in to the terminal, the make file will remove all of the object files in the folder.

##To run##

After the executable is created, type "./" + the executable file name to run the program.

##Create Doxygen##

First you need to open the Doxyfile and edit OUTPUT_DIRECTORY to the working directory + "/docs" (i.e /home/user/Desktop)

and then INPUT to the working directory (i.e /home/user/Desktop)

If you type 'make DOC' in a terminal in the working directory, the make file will compile the Doxygen code and it will display the Doxygen via Mozilla Firefox.

------------------------

Lab 1 - The Toolchain
Executable file = helloThreads

------------------------

Lab 2 - Signalling with Semaphores
Executable file = Semaphore

------------------------

Lab 3 - Rendezvous
Executable file = rendezvous

------------------------

Lab 4 - Mutual Exclusion
Executable file = mutex

------------------------

Lab 5 - Reusable Barrier Class
Executable file = Barrier

------------------------

Lab 6 - Producers and Consumers
Executable file = Barrier

------------------------


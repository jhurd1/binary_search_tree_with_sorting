###############################################################
# Program:
#     Assignment 11, Sorts
#     Brother Kirby, CS235
# Author:
#     Daniel Perez, Jamie Hurd, Benjamin Dyas
# Summary:
#     This program contains the implementation of...
# Time:
#     Pair programming: 06 hours
#     Daniel:           06 hours
#     Benjamin:         06 hours
#		Jamie:            06 hours
# The most difficult part:
#     Daniel:   The most difficult part was the heap sort
#					 because the pseudocode was not correct and 
#					 we had to make several important modifications.
#					 we also had a very hard to debug "stack smash"
#					 error which was resolved by dynamically
#               allocating the array in the constructor.
#	   Benjamin: The most difficult part was working through the
#               heap sort. we were having issues with the array
#               in the constructor not being correctly
#               initilized. We were running into the heap crash
#               error. This was solved by allocating the memory
#               correctly in the constructor.
#	   Jamie:    The most difficult part was following the de-
#					 bugging of the psuedocode from the textbook,
#					 which so often proved incorrect for our code.
#					Template arguments became somewhat hairy for me 
#					through some debugging scenarios.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment11.o
	g++ -o a.out assignment11.o -g
	tar -cf assignment11.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment11.o     : the driver program
##############################################################
assignment11.o: assignment11.cpp sortValue.h \
		sortBinary.h sortInsertion.h sortHeap.h sortBubble.h \
		sortSelection.h sortMerge.h sortQuick.h
	g++ -c assignment11.cpp -g


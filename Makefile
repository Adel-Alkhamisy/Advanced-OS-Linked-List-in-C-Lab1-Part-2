# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Adel Alkhamisy>
list: list.c main.c
	gcc list.c main.c -o list

clean:
	rm -f list

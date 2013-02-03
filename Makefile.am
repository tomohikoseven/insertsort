AM_CPPFLAGS = -Wall -g -I. -I/usr/local/include

bin_PROGRAMS=main
main_SOURCES=main.c insertSort.c insertSort.h

check_PROGRAMS=test_insertSort
test_insertSort_SOURCES=test_insertSort.c insertSort.c insertSort.h
test_insertSort_CFLAGS=-D__UT -fmudflap
test_insertSort_LDFLAGS=-L. -L/usr/local/lib
test_insertSort_LDADD= -lcunit -lmudflap

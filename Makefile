CFLAGS = -g
GCC = gcc
.c.o :
	$(GCC) -c $(CFLAGS) $*.c
EXES = test_tree
all : $(EXES)
TEST_TREEOBJS =  test_tree.o scaled_kdtree.o
test_tree : $(TEST_TREEOBJS) 
	gcc $(CFLAGS) -o test_tree $(TEST_TREEOBJS) -lm 

#============================================================================
#  list makefile
#
#  Notes:
#
#===========================================================================

GXX           = g++
#INCLUDE_OPT   = -I. -I-
INCLUDE_OPT   = -iquote .
DOPT          = -a
#VG_OPT        = -q --leak-check=full

COMPILE_OPT   = -g -O -Wall -W -Wunused -Wuninitialized -Wshadow 
#COMPILE_OPT   = -g -O -Wall -W -Wunused -Wuninitialized -Wshadow -Wreorder -Weffc++ -pedantic 

LIST_O = list.o
LIST_H = list.h
#DEF = -DSTD_LIST   # Don't need, use target std_list

#-------------------------------------------------------------------------------
TEST_PROG_01 = test_front_push_front
TEST_PROG_02 = test_pop_front
TEST_PROG_03 = test_size
TEST_PROG_04 = test_back_push_back
TEST_PROG_05 = test_pop_back
TEST_PROG_06 = test_empty
TEST_PROG_07 = test_iterator_deref
TEST_PROG_08 = test_iterator_compare
TEST_PROG_09 = test_iterator_inc
TEST_PROG_10 = test_iterator_loop
TEST_PROG_11 = test_iterator_loop2
TEST_PROG_12 = test_iterator_dec
TEST_PROG_13 = test_copy_ctor
TEST_PROG_14 = test_assignment
TEST_PROG_15 = test_large
TEST_PROG_16 = test_insert
TEST_PROG_17 = test_splice

#-------------------------------------------------------------------------------
TEST_PROG_DIR   = ../../cs61003_instructor/List/Test_Progs/
DRIVER_PROG_DIR = ../../cs61003_instructor/List/Drivers/

#===========================================================================
msg:
	@echo 'Targets for compiling test programs:'
	@echo '   t1  or ${TEST_PROG_01}'
	@echo '   t2  or ${TEST_PROG_02}'
	@echo '   t3  or ${TEST_PROG_03}'
	@echo '   t4  or ${TEST_PROG_04}'
	@echo '   t5  or ${TEST_PROG_05}'
	@echo '   t6  or ${TEST_PROG_06}'
	@echo '   t7  or ${TEST_PROG_07}'
	@echo '   t8  or ${TEST_PROG_08}'
	@echo '   t9  or ${TEST_PROG_09}'
	@echo '   t10 or ${TEST_PROG_10}'
	@echo '   t11 or ${TEST_PROG_11}'
	@echo '   t12 or ${TEST_PROG_12}'
	@echo '   t13 or ${TEST_PROG_13}'
	@echo '   t14 or ${TEST_PROG_14}'
	@echo '   t15 or ${TEST_PROG_15}'
	@echo '   t16 or ${TEST_PROG_16}'
	@echo '   t17 or ${TEST_PROG_17}'
	@echo '   tests  - runs t1, t2, ...'
	@echo 'Note: each test depends on the previous tests.'
	@echo 'Targets for compiling individual test programs:'
	@echo '   p1, p2, etc.'
	@echo '   progs'
	@echo 'Other Targets:'
	@echo '   driver      - Compile current directory file driver.cpp'
	@echo '   tm1 tm2 ... - Individual memory error, leak tests'
	@echo '   testall     - Runs t1, t2, ... and all memory error, leak tests'
	@echo '   clean'
	@echo 'Note: To have make ignore errors use the options "-ik", ex:'
	@echo '   make -ik t6'

#===========================================================================
# Compile using std::list
# If std::list is used the local list.cpp is compiled but not used.
# This is because in the test_% rule LIST_O is replaced when the file is
# parsed, I couldn't see an easy to eliminate this dependency.
std_list: DEF = -DSTD_LIST
std_list: LIST_O = 
std_list: LIST_H = 
std_list: list.o progs t17
	@echo 'std::list used.'

#===========================================================================
# Compile list.o
list.o:	list.h  list.cpp
	${CXX} ${COMPILE_OPT} ${CXX_FLAGS} ${INCLUDE_OPT} -c list.cpp 

#===========================================================================
# Compile local driver file
driver.o:	list.h  driver.cpp
	${GXX} ${COMPILE_OPT} ${DEF} ${INCLUDE_OPT} -c driver.cpp

driver:	driver.o  list.o
	${GXX} ${COMPILE_OPT} ${DEF} ${INCLUDE_OPT} driver.o list.o -o driver

#===========================================================================
# Compile test programs

#----------------------------------------------------------------------------
test_%: ${LIST_O} test_%.o
	${CXX} ${COMPILE_OPT} ${LIST_O} test_$*.o -o test_$*

test_%.o:	${LIST_H}  ${TEST_PROG_DIR}test_%.cpp
	${CXX} ${COMPILE_OPT} ${CXX_FLAGS} ${DEF} ${INCLUDE_OPT} -c ${TEST_PROG_DIR}test_$*.cpp 

#===========================================================================
.PRECIOUS: test_%.o driver_%.o

#===========================================================================
# Compile test programs

p1:  ${TEST_PROG_01}
p2:  ${TEST_PROG_02}
p3:  ${TEST_PROG_03}
p4:  ${TEST_PROG_04}
p5:  ${TEST_PROG_05}
p6:  ${TEST_PROG_06}
p7:  ${TEST_PROG_07}
p8:  ${TEST_PROG_08}
p9:  ${TEST_PROG_09}
p10: ${TEST_PROG_10}
p11: ${TEST_PROG_11}
p12: ${TEST_PROG_12}
p13: ${TEST_PROG_13}
p14: ${TEST_PROG_14}
p15: ${TEST_PROG_15}
p16: ${TEST_PROG_16}
p17: ${TEST_PROG_17}

progs: p17 p16 p15 p14 p13 p12 p11 p10 p9 p8 p7 p6 p5 p4 p3 p2 p1 
	@echo 'Done compiling.'

#===========================================================================
# Run test programs

testall: progs tests test_leaks
	@echo "All test programs done running."

tests: progs    t1  t2  t3  t4  t5  t6  t7  t8  t9  t10  \
                t11 t12 t13 t14 t15 t16 t17
	@echo "Main test programs done running."

t0: 
	@echo "Test programs running ..."

t1: p1 ${TEST_PROG_01}
	./${TEST_PROG_01}

t2: p2 t1
	./${TEST_PROG_02}

t3: p3 t2
	./${TEST_PROG_03}

t4: p4 t3
	./${TEST_PROG_04}

t5: p5 t4
	./${TEST_PROG_05}

t6: p6 t5
	./${TEST_PROG_06}

t7: p7 t6
	./${TEST_PROG_07}

t8: p8 t7
	./${TEST_PROG_08}

t9: p9 t8
	./${TEST_PROG_09}

t10: p10 t9
	./${TEST_PROG_10}

t11: p11 t10
	./${TEST_PROG_11}

t12: p12 t11
	./${TEST_PROG_12}

t13: p13 t12
	./${TEST_PROG_13}

t14: p14 t13
	./${TEST_PROG_14}

t15: p15 t14
	./${TEST_PROG_15}

t16: p16 t15
	./${TEST_PROG_16}

t17: p17 t16
	./${TEST_PROG_17}

#============================================================================
# Test for memory leaks
test_leaks: progs  tm1  tm2  tm3  tm4  tm5  tm6  tm7  tm8  tm9  tm10  \
                   tm11 tm12 tm13 tm14 tm15 tm16 tm17
	@echo "Memory leak test programs done running."

tm1:  t1
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_01}

tm2:  t2
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_02}

tm3:  t3
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_03}

tm4:  t4
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_04}

tm5:  t5
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_05}

tm6:  t6
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_06}

tm7:  t7
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_07}

tm8:  t8
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_08}

tm9:  t9
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_09}

tm10:  t10
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_10}

tm11:  t11
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_11}

tm12:  t12
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_12}

tm13:  t13
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_13}

tm14:  t14
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_14}

tm15:  t15
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_15}

tm16:  t16
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_16}

tm17:  t17
	/usr/bin/valgrind ${VG_OPT} ./${TEST_PROG_17}

tma: tm1 tm2 tm3 tm4 tm5 tm6 tm7 tm8 tm9 tm10 tm11 tm12 tm13 tm14 tm15 tm16 tm17
	@echo 'Memory leak tests done.'

#============================================================================
clean:
	rm -f test_*
	rm -f driver
	rm -f *.o a.out
	rm -f core*

veryclean: clean
	rm -f *out.txt


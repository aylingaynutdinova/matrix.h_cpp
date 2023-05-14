CC = gcc -lstdc++ -std=c++17 -g -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage
SOURSES = *.cc
OBJECT = $(patsubst %*.cc, %*.o,  ${SOURSES})
TEST_FLAGS =-lgtest -lgmock -pthread

all: clean s21_matrix_oop.a

s21_matrix_oop.a:$(SOURSES)
	$(CC) -c $(SOURSES)
	@ar rcs s21_matrix_oop.a $(OBJECT)

test: s21_matrix_oop.a
	@$(CC) -lstdc++ -std=c++17 -pedantic -Wall -Werror -Wextra -lgtest s21_matrix_oop.a tests.cc -o unit_test
	@./unit_test

gcov_report: clean
	$(CC) --coverage *.cc -o test -lgtest 
	chmod +x *
	./test
	lcov -t "test" -o test.info --no-external -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

clean:
	@rm -rf ./*.o ./*.a ./a.out ./GcovReport ./*.gcno ./*.gcda ./report ./*.info ./decimal_o ./*.dSYM ./unit_test ./CPPLINT*



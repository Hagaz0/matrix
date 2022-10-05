CC=gcc

all: test s21_matrix_oop.a

test: build
	cd tests; make
	cd tests; ./final
build:
	rm -rf tests
	mkdir tests
	cd tests; cmake ../

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf tests

objs:
	$(CC) -c S21Matrix.cc

s21_matrix_oop.a: objs
	ar rc s21_matrix_oop.a S21Matrix.o
	ranlib s21_matrix_oop.a
	rm -rf *.o


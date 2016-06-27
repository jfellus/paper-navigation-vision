
ALGOS_SRC:=$(shell find src/algos -name "*.c")
ALGOS:=$(ALGOS_SRC:src/algos/%.c=build/%)

all: $(ALGOS)

build/%: bin/algos/%.o bin/main.o bin/utils/V4LIn.o
	mkdir -p build
	g++ -pthread -o $@ $^ -ljpeg 

bin/%.o: src/%.c src/*.h src/utils/*.h
	mkdir -p `dirname $@`
	g++ -o $@ -c $<


clean:
	rm -rf bin build

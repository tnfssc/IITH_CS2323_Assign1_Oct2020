Assembler: Assembler.o tables/addr_gen.o
	mkdir -p bin
	g++ Assembler.o tables/addr_gen.o -o bin/Assembler

Assembler.o: Assembler.cpp
	g++ -c Assembler.cpp -o Assembler.o

addr_gen.o: tables/addr_gen.cpp tables/addr_gen.hpp
	g++ -c tables/addr_gen.cpp -o tables/addr_gen.o

clean:
	rm -f -rf *.o bin
	rm -f -rf tables/*.o

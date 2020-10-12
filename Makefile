Assembler: Assembler.o tables/addr_gen.o
	mkdir -p bin
	g++ Assembler.o tables/opcode_gen.o tables/addr_gen.o -o bin/Assembler

ConvertAssembly: ConvertAssembly.o
	mkdir -p bin
	g++ ConvertAssembly.o -o bin/ConvertAssembly

main: Assembler.cpp ConvertAssembly.cpp
	g++ -c ConvertAssembly.cpp -o ConvertAssembly.o
	g++ -c Assembler.cpp -o Assembler.o

functions: functions/opcode_type.cpp functions/opcode_type.hpp
	g++ -c functions/opcode_type.cpp -o functions/opcode_type.o

tables: tables/addr_gen.cpp tables/addr_gen.hpp tables/opcode_gen.cpp tables/opcode_gen.hpp
	g++ -c tables/addr_gen.cpp -o tables/addr_gen.o
	g++ -c tables/opcode_gen.cpp -o tables/opcode_gen.o

clean:
	rm -f -rf *.o bin
	rm -f -rf tables/*.o
	rm -f -rf functions/*.o

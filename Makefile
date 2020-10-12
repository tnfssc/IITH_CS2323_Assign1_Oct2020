Assembler: Assembler.o tables/addr_gen.o
	mkdir -p bin
	g++ common/*.o Assembler/*.o -o bin/Assembler

ConvertAssembly: ConvertAssembly.o
	mkdir -p bin
	g++ common/*.o ConvertAssembly/*.o -o bin/ConvertAssembly

main:
	g++ -c tables/addr_gen.cpp -o Assembler/addr_gen.o
	g++ -c tables/opcode_gen.cpp -o Assembler/opcode_gen.o

	g++ -c functions/split_string.cpp -o common/split_string.o
	g++ -c functions/opcode_type.cpp -o Assembler/opcode_type.o

	g++ -c Assembler.cpp -o Assembler/Assembler.o
	g++ -c ConvertAssembly.cpp -o ConvertAssembly/ConvertAssembly.o

clean:
	rm -f -rf *.o bin
	rm -f -rf */*.o
	rm -f -rf */*.o

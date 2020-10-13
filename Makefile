Assembler: Assembler.o tables/addr_gen.o
	mkdir -p bin
	g++ common/*.o Assembler/*.o -o bin/Assembler

ConvertAssembly: ConvertAssembly.o
	mkdir -p bin
	g++ common/*.o ConvertAssembly/*.o -o bin/ConvertAssembly

main:
	mkdir -p Assembler
	mkdir -p common
	mkdir -p ConvertAssembly
	mkdir -p output

	g++ -c tables/addr_gen.cpp -o common/addr_gen.o
	g++ -c tables/opcode_gen.cpp -o common/opcode_gen.o
	g++ -c tables/format_gen.cpp -o common/format_gen.o
	g++ -c tables/funct_gen.cpp -o common/funct_gen.o

	g++ -c functions/split_string.cpp -o common/split_string.o
	g++ -c functions/opcode_type.cpp -o common/opcode_type.o
	g++ -c functions/funct_type.cpp -o common/funct_type.o
	g++ -c functions/format_type.cpp -o common/format_type.o
	g++ -c functions/addr_type.cpp -o common/addr_type.o

	g++ -c Assembler.cpp -o Assembler/Assembler.o
	g++ -c ConvertAssembly.cpp -o ConvertAssembly/ConvertAssembly.o

clean:
	rm -f -rf *.o bin Assembler ConvertAssembly common output
	rm -f -rf */*.o
	rm -f -rf */*.o

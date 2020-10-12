make main

make Assembler

echo 
echo 
./bin/Assembler sample_data/prog1.asm
echo 
echo 

make ConvertAssembly

echo 
echo 
./bin/ConvertAssembly output/prog1bin.txt
echo 
echo 

make clean

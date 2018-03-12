output: matrixMain.cpp determinant.cpp readMatrix.cpp
	g++ matrixMain.cpp determinant.cpp readMatrix.cpp -o output

matrixMain.o: matrixMain.cpp
	g++ -c matrixMain.cpp
determinant.o: determinant.cpp determinant.h
	g++ -c determinant.cpp
readMatrix.o: readMatrix.cpp readMatrix.h
	g++ -c readMatrix.cpp 
clean: 
	rm *.o output

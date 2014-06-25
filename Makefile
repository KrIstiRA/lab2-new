all: main.cpp largeClass.cpp largeNum.cpp
	g++ -c -fPIC largeClass.cpp largeNum.cpp
	g++ -shared -o liblargeClass.so largeClass.o largeNum.o
	LD_LIBRARY_PATH=./ g++ main.cpp -llargeClass -I. -Wl,-rpath,. -L. -o TCHMK_2
	rm *.o
	
windows: main.cpp largeClass.cpp largeNum.cpp
	g++ -c largeClass.cpp largeNum.cpp
	g++ -shared -o largeClass.dll largeClass.o largeNum.o
	g++ main.cpp largeClass.dll -I. -Wl,-rpath,. -L. -o TCHMK_2.exe 
	del *.o
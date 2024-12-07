
.SILENT: lab1 lab2 lab4 lab5
lab1:
	echo "=====" complex "====="
	cd lab_1 && g++ complex.cc -o main && ./main
	echo "=====" swap "====="
	cd lab_1 && g++ swap.cc -o main && ./main

lab2:
	echo "=====" stack "====="
	cd lab_2 && g++ stack.cc -o main && ./main
lab3:
	echo "=====" string "====="
	cd lab_3 && g++ str.cc -o main && ./main

lab4:
	echo "=====" graphics "====="
	cd lab_4 && g++ -o main main.cc -lSDL_bgi -lSDL2 && ./main

lab5:
	echo "=====" graphics "(colored)" "====="
	cd lab_5 && g++ -o main draw.cc -lSDL_bgi -lSDL2 && ./main
	echo "=====" class inheritance "====="
	cd lab_5 && g++ -o main inherit.cc && ./main
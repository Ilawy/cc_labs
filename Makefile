
.SILENT: lab1 lab2
lab1:
	echo "=====" complex "====="
	cd lab_1 && g++ complex.cc -o main && ./main
	echo "=====" swap "====="
	cd lab_1 && g++ swap.cc -o main && ./main


lab2:
	echo "=====" stack "====="
	cd lab_2 && g++ stack.cc -o main && ./main

.SILENT: lab1
lab1:
	echo "=====" complex "====="
	cd lab_1 && g++ complex.cc -o main && ./main
	echo "=====" swap "====="
	cd lab_1 && g++ swap.cc -o main && ./main
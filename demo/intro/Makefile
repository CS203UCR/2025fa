
EXECS = madd_A madd_B arraySort bitonic quicksort simple

CFLAGS=


all: $(EXECS)


madd_A: madd_A.c
	gcc -O3 madd_A.c -o madd_A

madd_B: madd_B.c
	gcc -O3 madd_B.c -o madd_B


arraySort: arraySort.cpp calculate_sum.c
	gcc calculate_sum.c -c 
	g++ -O0 arraySort.cpp calculate_sum.o -o arraySort

arraySortO3: arraySort.cpp calculate_sum.c
	gcc calculate_sum.c -c 
	g++ -O3 arraySort.cpp calculate_sum.o -o arraySort
    
bitonic: bitonic.cu
	/usr/local/cuda/bin/nvcc -O3 $(CFLAGS) bitonic.cu -o bitonic
        
quicksort: quicksort.cu 
	/usr/local/cuda/bin/nvcc -O3 $(CFLAGS) quicksort.cu -o quicksort

clean:
		rm -f $(EXECS)
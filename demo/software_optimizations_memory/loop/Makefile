all: loop_A loop_B

EXTRA_CFLAGS = -DHAVE_LINUX_PERF_EVENT_H -g -O3 

loop_A: loop.c perfstats.c
	gcc $(EXTRA_CFLAGS) -DA perfstats.c loop.c -o loop_A
	
loop_B: loop.c perfstats.c
	gcc $(EXTRA_CFLAGS) perfstats.c loop.c -o loop_B

clean:
		rm -f loop_A loop_B

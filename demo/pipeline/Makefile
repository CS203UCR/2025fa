all:  arithmetics_A arithmetics_B swap flip_array linked_list linked_list.s arithmetics_2_A arithmetics_2


#arraySort

EXTRA_CFLAGS = -DHAVE_LINUX_PERF_EVENT_H
CFLAGS = -O3
OPTS = -O0

arithmetics_A: arithmetics.c perfstats.c 
	$(CC) -DA  $(EXTRA_CFLAGS) $(OPTS) perfstats.c arithmetics.c -o arithmetics_A
	$(CC) -DA  $(EXTRA_CFLAGS) $(OPTS) -S arithmetics.c -o A.s

arithmetics_B: arithmetics.c perfstats.c 
	$(CC) -DB  $(EXTRA_CFLAGS) $(OPTS) perfstats.c arithmetics.c -o arithmetics_B
	$(CC) -DB  $(EXTRA_CFLAGS) $(OPTS) -S arithmetics.c -o B.s

arithmetics_2_A: arithmetics_2.c 
	$(CC) -O0 -DA $(EXTRA_CFLAGS) arithmetics_2.c -o arithmetics_2_A
	$(CC) -O0 -DA $(EXTRA_CFLAGS) -S arithmetics_2.c 
	cp arithmetics_2.s arithmetics_2_A.s

arithmetics_2: arithmetics_2.c 
	$(CC) -O0 $(EXTRA_CFLAGS) arithmetics_2.c -o arithmetics_2
	$(CC) -O0 $(EXTRA_CFLAGS) -S arithmetics_2.c 

swap: swap.c
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) swap.c -o swap

flip_array: flip_array.c
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) flip_array.c -o flip_array
	$(CC) -S -O2 $(EXTRA_CFLAGS) flip_array.c -o flip_array.s

linked_list: linked_list.c perfstats.c 
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) perfstats.c  linked_list.c -o linked_list

linked_list.s: linked_list.c perfstats.c 
	$(CC) -S $(CFLAGS) $(EXTRA_CFLAGS) linked_list.c -o linked_list.s
	
clean:
		rm -f arithmetics arithmetics_A arithmetics_B linked_list flip_array swap *.s *~ arithmetics_2_A arithmetics_2

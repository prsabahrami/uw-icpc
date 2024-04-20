CC=gcc -ansi -Wall -g
LDFLAGS= -lm
CCC=g++ -ansi -D__USE_BSD -Wall -O2

.c:
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

.cc:
	$(CCC) $< -o $@ $(LDFLAGS)
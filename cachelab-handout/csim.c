#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void printInfo();

int main(int argc, char* argv[]) {
	int opt;
	int s, E, b = 0;
	char * trace_file = NULL;
	while(opt = getopt(argc, argv, "hvs:E:b:t:") != -1) {
		switch(opt) {
			case 'h':
				printf("Help:\n
						\t-h: see help\n
						\t-v: display traces info\n
						\t-s: number of sets\n
						\t-E: number of lines in a set\n
						\t-b: number of bytes in a line\n
						\t-t: trace file to test\n");
				break;
			case 'v':
				printInfo();
				break;	
			case 's':
				s = atoi(optarg);
				break;
			case 'E':
				E = atoi(optarg);
				break;
			case 'b':
				b = atoi(optarg);
				break;
			case 't':
				trace_file = optarg;	
		}
	}
    printSummary(0, 0, 0);
    return 0;
}

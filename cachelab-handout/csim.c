#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int info_flag = 0;
int opt = 0;
int s = 0;
int E = 0; 
int b = 0;
char* trace_file = NULL;

void read_command() {
	while(opt = getopt(argc, argv, "hvs:E:b:t:") != -1) {
		switch(opt) {
			case 'h':
				printf("Help:\n\t-h: see help\n\t-v: display traces info\n\t-s: number of sets\n\t-E: number of lines in a set\n\t-b: number of bytes in a line\n\t-t: trace file to test\n");
				break;
			case 'v':
				info_flag = 1;	
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
				break;
			default:
				printf("Bad command line ;(\n");
				break;
		}
	}
}

void read_trace(FILE* fp) {
	char action = '\0';
	int address = 0x0;
	int size;
	int miss, hit, evic;
	miss = hit = evic = 0;
	if (info_flag) {
		// TODO:-v 
	} else {

	}
	while (fscanf(fp, "%c %X %d", &action, &address, &size) != EOF) {
		if (action == 'I')
			continue;
		// TODO: cal miss and hit times	
	}

    printSummary(miss, hit, evic);
}

int cache_init() {
	// TODO:  init cache, allocate memory region
}
int main(int argc, char* argv[]) {
	read_command();  // read command line from shell

	// read trace file
	FILE* fp = NULL;
	fp = fopen(trace_file, "r");
	read_trace(fp);

	int* cache = NULL;	// cache memory region pointer
	if (cache_init(cache) == -1) {
		printf("Memory alloc failed! :(");
		return 0;
	}

    return 0;
}

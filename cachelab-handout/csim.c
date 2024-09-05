#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	int opt;
	while(opt = getopt())
    printSummary(0, 0, 0);
    return 0;
}

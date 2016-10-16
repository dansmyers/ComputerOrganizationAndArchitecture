// Processing input arguments with getopt
// DSM, 2016

#include <stdio.h>
#include <unistd.h>  // getopt

int main(int argc, char *argv[]) {
    char c;
    
    // getopt parses the command line arguments in argv
    //
    // The third argument to getopt is a string specifying the flags that it
    // should search for in the argv list.
    //
    // Here, getopt is told to search for "-i" and "-o" flags. The : after each
    // letter indicates that each flag is followed by a parameter value (for
    // example, the name of an input file might follow the -i flag).
    //
    // The flags can occur in any order. When getopt finds a flag, it returns
    // the flag letter as a char and the second argument, if it exists, in
    // the special variable optarg.
    
    while ((c = getopt (argc, argv, "i:o:")) != -1) {
        switch(c) {
            case 'i':
                printf("i argument = %s\n", optarg);
                break;
                
            case 'o':
                printf("o argument = %s\n", optarg);
                break;
        }
    }
    
    return 0;
}
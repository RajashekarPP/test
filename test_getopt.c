#include <unistd.h>
       #include <stdlib.h>
       #include <stdio.h>

       int
       main(int argc, char *argv[])
       {
           int flags, opt;
           int nsecs, tfnd;

           nsecs = 0;
           tfnd = 0;
           flags = 0;
           while ((opt = getopt(argc, argv, "nt:")) != -1) {
               switch (opt) {
		putchar(opt);
               case 'n':
                   flags = 1;
                putchar(opt);   break;
               case 't':
                   nsecs = atoi(optarg);
                   tfnd = 1;
                putchar(opt);   break;
               default: /* '?' */putchar(opt);
                   fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                           argv[0]);
                   exit(EXIT_FAILURE);
               }
           }

           printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n",
                   flags, tfnd, nsecs, optind);

           if (optind >= argc) {
               fprintf(stderr, "Expected argument after options\n");
               exit(EXIT_FAILURE);
           }

           printf("name argument = %s\n", argv[optind]);

           /* Other code omitted */

           exit(EXIT_SUCCESS);
       }


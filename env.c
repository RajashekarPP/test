#include"cheaders.h"

main (int argc, char **argv, char **envp)
{

  char *ptr;
  char a[50], b[200];
  ptr = getenv ("PATH");
  fputs (ptr, stdout);
  puts ("\nenter the path to be added");
  gets (a);
  strcpy (b, ptr);
  strcat (b, a);
  setenv ("PATH", b, 1);
  puts ("\n new process is executing\n");
  int i;
  for (i=1; i<argc; i++)
    {
    puts("looop");
      if (fork()==0)
	{
	  system(argv[i]);
	  exit(0);
	}
 }
exit(0);
}


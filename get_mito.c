// Author: whc2
// Date: 20181212
// Discription: This program is used to get mitochondrion sequence from a assemblied contig sequence. We first use nucmer to align mitocondrion sequence with contig, and then get the maximam alignment length. Using this coordination, we cut original sequence to get the assemblied mitocondrion sequence. In this study, the maximam alignment appears between 1 to 13949. So, if you want to use this program the postion must be changed as you need.
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int ch;
	FILE * fp;
	FILE * op;	// outfile name
	char fname[50];
	char oname[50];

	printf ("Enter contig name: ");
	scanf ("%s", fname);
	printf ("Enter output mitochondrion name: ");
	scanf ("%s", oname);

	op = fopen (oname, "w");
	fp = fopen (fname, "r");
	if (fp == NULL)
	{
		printf ("Fail to open %s\n", fname);
		exit (1);
	}

	long n = 0;
	while ((ch = getc (fp)) != EOF)
	{
		if (ch == '>')
		{
			putc (ch, op);
			while ((ch = getc (fp)) != '\n')
			{
				putc (ch, op);
			}
			putc ('\n', op);
		}
		else 
		{
			putc (ch, op);
			++n;
			while (((ch = getc (fp)) != EOF) && (n < 13949))
			{
				putc (ch, op);
				++n;
			}
			putc ('\n', op);
			exit (0);
		}
	}
	fclose (fp);
	fclose (op);

	return 0;
}

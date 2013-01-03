/* Bin2C (Binary To C Source Converter) - v0.1
   By 360trev
    
   Trivial program to translate any binary file into C Source-code that
   can subsequently be included into another program by a C Compiler.

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
   AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
   OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int c,i=0;
	FILE *fp_in, *fp_out;

	printf("Bin2C 0.1 (Binary To C Source Converter)\n"); 
	printf("Last Built: %s, Time: %s\n",__DATE__, __TIME__);
	printf("By 360trev [BSD Licensed Open Source]\n\n");

	if(argc < 4) {
		printf("Usage: %s <array_name> <in_file> <out_file>\n",argv[0]); return 0;
	}
	printf("þ Attempting to opening output file \"%s\"...",argv[3]);
	if((fp_out = fopen(argv[3], "wb"))) {
		printf("Done\n");
		printf("þ Attempting to opening input file \"%s\"...",argv[2]);
		if((fp_in = fopen(argv[2], "rb"))) {
			printf("Done\n\n");
			printf("þ Generating C Source-Code...\n");
			fprintf(fp_out,"\nunsigned char %s[] =\n{\n\t",argv[1]);
			while ((c = fgetc(fp_in)) != EOF) {
				if(i==40) {
					printf("#");
					fprintf(fp_out,"\n\t");
					i=0;
				}
				fprintf(fp_out,"0x%-2.2x,",c);
				i++;
			}
			fprintf(fp_out,"\n};\n");
			printf("\nAll Done\n");
			if(fp_in != 0) fclose(fp_in);
		}	else {
			fprintf(stderr,"Can't open infile %s\n", argv[2]);
		}
		if(fp_out != 0)	{
			fclose(fp_out);
		}
	} else {
		fprintf(stderr,"Can't open outfile %s\n", argv[3]);
		return 1;
	}
	return 0;
}

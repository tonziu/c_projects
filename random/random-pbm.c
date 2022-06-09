/*
	This module tests the random function by creating bitmap random images
	with a specified fill ratio.
	
	Inspired by: Rouben Rostamian
	Written by: Tony De Corso
*/
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

static int my_random(int n);
static int fetch_int(char **argv, int pos);
static double fetch_double(char **argv, int pos);
static int **make_random_matrix(int m, int n, double f);
static int write_pbm(int **M, int m, int n, char *outfile);

int main(int argc, char **argv)
{
	int m, n, s;
	double f;
	char *outfile;
	
	if (argc != 6)
	{
		printf("Must be 6 arguments.\n");
		return 1;
	}
	
	m = fetch_int(argv, 1);
	n = fetch_int(argv, 2);
	s = fetch_int(argv, 3);
	f = fetch_double(argv, 4);

	if (f > 1) 
	{
		printf("Fill ratio must be smaller than 1.\n");
	}
	outfile = argv[5];
	
	srand(s);
	
	int **M = make_random_matrix(m, n, f);

	/* for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", M[i][j]);
		}
		printf("\n");
	} */
	
	int done = write_pbm(M, m, n, outfile);
	
	free_matrix(M);

	return 0;
}

static int my_random(int n)
{
	return random()/(RAND_MAX/n + 1);
}

static int fetch_int(char **argv, int pos)
{
	char *endptr;
	int n = strtol(argv[pos], &endptr, 10);
	if (*endptr == '\0') return n;
}

static double fetch_double(char **argv, int pos)
{
	char *endptr;
	double n = strtod(argv[pos], &endptr);
	if (*endptr == '\0') return n;
}

static int **make_random_matrix(int m, int n, double f)
{
	int **M;
	int i, j;
	make_matrix(M, m, n);
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			M[i][j] = 0;
		}
	}
	
	int k = 0;
	while (k <  m * n * f)
	{
		i = my_random(m);
		j = my_random(n);
		if (M[i][j] == 0) 
		{
			M[i][j] = 1;
			k++;
		}
	}
	
	return M;
}

static int write_pbm(int **M, int m, int n, char *outfile)
{
	FILE *stream = fopen(outfile, "w+");
	if (stream == NULL)
	{
		printf("Error opening the file.\n");
		return 0;
	}
	
	fprintf(stream, "%s %d %d\n", "P1", m, n);
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fprintf(stream, "%d\t", M[i][j]);
		}
		fprintf(stream, "\n");
	}
	
	fflush(stream);
	fclose(stream);
	
	return 1;
}
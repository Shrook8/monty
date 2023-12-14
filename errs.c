nclude "mo.h"

/**
 * err - prints appropiate error message determined by their error code.
 * @error_code" the error code are the following:
 * (1) => the user dose not give any file or more than one file to the program.
 * (2) => the file provided is not a file that can be opended or read.
 * (3) => the file provided contains an invalid instruction.
 * (4) => when the program is unable to malloc more memory.
 * (5) => when the parameter passed to the instruction "push" is not an int.
 * (6) => when the stack it empty for pint.
 * (7) => when the stack it empty for pop.
 * (8) => when the stack too short for operation.
*/

void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "error: can not open file %s\n",
					va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unkown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push int\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}



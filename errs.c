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

/**
 * more_err - handles errors
 * @error_code: the error codes are the following:
 * (6) => when the stack it empty for pint.
 * (7) => when the stack it empty for pop
 * (8) => when stack is too shrot for opeartation.
 * (9) => division by zero
*/

void mor_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can not pint, stack empty\n", va_arg(ag, int));
			break;
		case 7:
			fprinyf(stderr, "L%d: can not pop an empty stack\n", va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errs
 * @error_code: ther error code is the following:
 * (10) ~> the num inside a node is outside ASCII bounds
 * (11) ~> the stack is empty
*/

void string_err(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can not pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can not pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

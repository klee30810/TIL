#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int result;

	char *expCopy = (char *)malloc(len + 1);
	strcpy(expCopy, exp);

	ConvToRPNExp(expCopy);
	result = EvalRPNExp(expCopy);

	free(expCopy);
	return result;
}

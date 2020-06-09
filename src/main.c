#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <tice.h>
#include <fileioc.h>

int main(int argc, char **argv)
{
	
	uint16_t PTRSIZE;
	short LOOPSIZE;
	char *fname;
	size_t fnameLen;
	char c;

	/* Pointer */
	//uint16_t array[PTRSIZE];
	uint16_t *p;
	uint16_t ptrNum;
	uint16_t *tempPtr;

	//uint16_t loop[4096] = {0};
	uint16_t *l;
	uint16_t *tempLoop;
	uint16_t *ol;

	/* FILE IO */
	ti_var_t f;

	/* TI Setup */
	os_ClrHome();
	ti_CloseAll();

	/* Variable Instantiations */
	//fname = "OP";
	fnameLen = 15;
	fname = malloc(fnameLen+1);
	os_GetStringInput("Brainfuck program to open:", fname, fnameLen);
	boot_NewLine();	

	PTRSIZE = 256;
	LOOPSIZE = 32;

	p = malloc(sizeof(uint16_t)*PTRSIZE);
	ptrNum = 0;
	tempPtr = p;
	memset(p, 0x00, PTRSIZE);

	l = malloc(sizeof(uint16_t)*LOOPSIZE);
	tempLoop = l;
	
	f = ti_OpenVar(fname, "r", 5);
	free(fname);

	if(!f){
		os_PutStrFull("Program Not Found!");
		while(!os_GetCSC());
		return 1;
	}
	
	/* Compile Loop */
	while((c = ti_GetC(f)) != EOF)
	{
		switch(c)
		{
			case 17:
				if(ptrNum + 1 < PTRSIZE)
				{
					++p;
					++ptrNum;
				}
				break;
			case 16:
				if(ptrNum != 0)
				{
					--p;
					--ptrNum;
				}
				break;
			case 112:
				++*p;
				break;
			case 113:
				if(*p <= 0)
					*p = 0;
				else
					--*p;
				break;
			case 58:
				{
				char op[2];
				op[1] = 0x00;
				op[0] = *p;
				if(*p != 10)
					os_PutStrFull(op);
				else
					boot_NewLine();
				break;
				 }
			case 43:
				*p = os_GetCSC();
				break;
			case 6:
				++l;
				*l = ti_Tell(f);
				
				break;
			case 7:
				if(*p == 0)
				{	
					*l = 0;
					--l;
				}else{
					ti_Seek(*l, SEEK_SET, f);
				}
				break;
		}
		
	}
	/* Close Files */
	ti_Close(f);
	free(l);
	free(p);
	
	while(!os_GetCSC());


}	

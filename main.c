#include <stdio.h>

#define	RESET			"\x1b[0m"
#define	COLOR_RED		"\x1b[38;5;196m"
#define	COLOR_GREEN	"\x1b[38;5;82m"

void	header(void)
{
	printf("\x1b[38;5;46m	 _______ _______ _______        _______ _______ _______ ___ 		\n"RESET);
	printf("\x1b[38;5;47m	|   _   |   _   |   _   |______|       |   _   |   _   |   |    \n"RESET);
	printf("\x1b[38;5;48m	|   1___|   1___|.  1   |______|.|   | |.  |   |.  |   |.  |    \n"RESET);
	printf("\x1b[38;5;48m	|____   |____   |.  _   |      `-|.  |-|.  |   |.  |   |.  |___ \n"RESET);
	printf("\x1b[38;5;49m	|:  1   |:  1   |:  |   |        |:  | |:  1   |:  1   |:  1   |\n"RESET);
	printf("\x1b[38;5;50m	|::.. . |::.. . |::.|:. |        |::.| |::.. . |::.. . |::.. . |\n"RESET);
	printf("\x1b[38;5;51m	`-------`-------`--- ---'        `---' `-------`-------`-------'\n"RESET);
	printf("\n\n");
	printf("\x1b[38;5;47m	• SSA Analyzer for Empire Earth by 0x7c00\n"RESET);
	printf("\x1b[38;5;50m	• Version: 0.1\n"RESET);
	return ;
}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc < 2)
	{
		printf(COLOR_RED "Missing arguments.\n" RESET);
		printf("ex: ./program " COLOR_GREEN " file.ssa" RESET"\n");
		return (0);
	}
	header();
	return (0);
}

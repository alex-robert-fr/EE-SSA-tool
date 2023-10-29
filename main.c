#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	bool	unsigned char
#define	true	1
#define	false	0

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
	printf("\n\n");
	return ;
}

const char *get_filename_extension(const char* filename)
{
	const char *dot = strchr(filename, '.');
	if (!dot || dot == filename)
		return (NULL);
	return (dot + 1);
}

bool	check_file(char *path)
{
	// file begin rass
	
	// Check extension
	const char *ext = get_filename_extension(path);
	if(!ext) {
		printf(COLOR_RED" * Bad extension.\n"RESET);
		printf(COLOR_RED" Quit program !\n"RESET);
		return (false);
	}
	if (ext[0] != 's' || ext[1] != 's' || ext[2] != 'a')
	{
		printf(COLOR_RED" * Bad extension.\n"RESET);
		printf(COLOR_RED" Quit program !\n"RESET);
		return (false);
	}

	// Check path
	FILE	*file = fopen(path, "r");
	if (!file)
	{
		printf(COLOR_RED" * Error opening file.\n"RESET);
		printf(COLOR_RED" Quit program !\n"RESET);
		return (false);
	}

	printf("\x1b[38;5;47mOpen file\n"RESET);
	char	buffer[5];
	fgets(buffer, 5, file);
	if (buffer[0] != 'r' || buffer[1] != 'a' || buffer[2] != 's' || buffer[3] != 's')
	{
		fclose(file);
		printf(COLOR_RED" * The file syntax is wrong.\n"RESET);
		printf(COLOR_RED" Quit program !\n"RESET);
		return (false);
	}
	fclose(file);
	return (true);
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
	check_file(argv[1]);
	
	return (0);
}

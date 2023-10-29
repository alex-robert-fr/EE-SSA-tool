#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ssa-too.h"

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

	// The file starts with "rass".
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

void	read_bytes(FILE *fd, int num, int *dest)
{
	int		c;

	for (int i = 0; i < num; i++) {
		c = fgetc(fd);
		dest[i] = c;
	}
}

void	pint_to_pchar(int *tab, int size, char *dest)
{
	for (int i = 0; i < size; i++) {
		dest[i] = tab[i];
	}
	dest[4] = '\0';
}

int	binary_to_int(int *tab)
{
	int	value = 0;
	for (int i = 0; i < 4; i++) {
		value |= tab[i] << (i * 8);
	}
	return (value);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf(COLOR_RED "Missing arguments.\n" RESET);
		printf("ex: ./program " COLOR_GREEN " file.ssa" RESET"\n");
		return (0);
	}
	header();
	check_file(argv[1]);

	printf("\x1b[38;5;51m INFO:\n" RESET);
	
	FILE	*file = fopen(argv[1], "rb");
	ssa_info	info;
	info.magic = calloc(sizeof(char), 5);

	int	magic[4];
	read_bytes(file, 4, magic);
	pint_to_pchar(magic, 4,info.magic);
	printf("\x1b[38;5;51m	* Magic: b'%s'\n" RESET, info.magic);

	int major[4];
	read_bytes(file, 4, major);
	info.major_version = (short)binary_to_int(major);
	int	minor[4];
	read_bytes(file, 4, minor);
	info.minor_version = (short)binary_to_int(minor);

	printf("\x1b[38;5;51m	* SSA Version: %d.%d\n" RESET, info.major_version, info.minor_version);
	
	free(info.magic);
	fclose(file);

	return (0);
}

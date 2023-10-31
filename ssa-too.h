#pragma once

typedef struct {
	char	*magic;
	short	major_version;
	short	minor_version;
	int		start_offset;
	int		lenght_data;
	int		offset;
}	ssa_info;

typedef struct {
	short	lenght_path;
	char	*path;
	int		start;
	int		end;
	int		size;
} data_info;

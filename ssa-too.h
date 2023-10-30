#pragma once

typedef struct {
	char	*magic;
	short	major_version;
	short	minor_version;
	int		start_offset;
	int		lenght_data;
}	ssa_info;

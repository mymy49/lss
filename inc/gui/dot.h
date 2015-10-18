#ifndef LSS_GUI_DOT__H_
#define LSS_GUI_DOT__H_

struct DotType
{
	unsigned blue : 5;
	unsigned green : 6;
	unsigned red : 5;
}__attribute__((packed));

union Dot
{
	DotType rgb;
	unsigned short data;
}__attribute__((packed));

struct Pos
{
	unsigned short x;
	unsigned short y;
}__attribute__((packed));

#endif
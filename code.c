#include "spider.h"
#include "print.h"

int uvl_entry()
{
	print("\fHello World!", 0x00000000, 0x00555555);
	print("\vHello World!", 0x00000000, COLOR_TRANS);
	print("\nHello World2", 0x000000FF, COLOR_TRANS);
	print("\nHello World3", 0x000000FF, COLOR_TRANS);
	printint(0xDEADBEEF, 0x0000FFFF, COLOR_TRANS);
}

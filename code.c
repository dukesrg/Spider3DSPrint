#include "spider.h"
#include "print.h"

int uvl_entry()
{
  print("\vtest string\r\n\t");
	print(0xDEADBEEF, 0x00FF7F00, COLOR_TRANS);
}

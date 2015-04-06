#include "spider.h"

#define VRAM_LOC	0x1F000000
#define BYTES_PER_PIXEL	3
#define BOTTOM_FB0_LOC	(void*)(VRAM_LOC + 0x0048F000)
#define BOTTOM_FB1_LOC	(void*)(VRAM_LOC + 0x004C7800)
#define BOTTOM_X_RES	320
#define BOTTOM_Y_RES	240
#define BOTTOM_FB_SIZE	BOTTOM_X_RES * BOTTOM_Y_RES * BYTES_PER_PIXEL
#define TOP_L_FB0_LOC	(void*)(VRAM_LOC + 0x001E6000)
#define TOP_L_FB1_LOC	(void*)(VRAM_LOC + 0x0022C800)
#define TOP_R_FB0_LOC	(void*)(VRAM_LOC + 0x00273000)
#define TOP_R_FB1_LOC	(void*)(VRAM_LOC + 0x002B9800)
#define TOP_FB0_LOC	TOP_L_FB0_LOC
#define TOP_FB1_LOC	TOP_L_FB1_LOC
#define BOTTOM_X_RES	400
#define BOTTOM_Y_RES	240
#define BOTTOM_FB_SIZE	TOP_X_RES * TOP_Y_RES * BYTES_PER_PIXEL
#define MEM_STRIPE_SIZE 16
#define CHAR_WIDTH	8
#define CHAR_HEIGHT	8
#define TOP_COLS	TOP_X_RES / CHAR_WIDTH
#define TOP_ROWS	TOP_Y_RES / CHAR_HEIGHT
#define BOTTOM_COLS	BOTTOM_X_RES / CHAR_WIDTH
#define BOTTOM_ROWS	BOTTOM_Y_RES / CHAR_HEIGHT
#define BUFFER_LOC	(void*)0x18410000
#define FONT_START	32
#define COLOR_FG_DEF	0x00FFFFFF
#define COLOR_BG_DEF	0x00000000
#define COLOR_TRANS	0xFF000000

void CopyMem(void *src, void *dst, unsigned size);
void print(char *value, unsigned fgcolor, unsigned bgcolor);
void print(char *value);
void print(unsigned value, unsigned fgcolor, unsigned bgcolor);
void print(unsigned value);

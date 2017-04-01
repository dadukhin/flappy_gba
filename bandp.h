/*
 * Exported with nin10kit v1.4
 * Invocation command was nin10kit -mode=sprites -bpp=4 -for_bitmap=1 -transparent=FF00FF bandp bird2.png pipe2.png pipe3.png 
 * Time-stamp: Saturday 04/01/2017, 16:21:33
 * 
 * Image Information
 * -----------------
 * bird2.png 32@32
 * pipe2.png 64@64
 * pipe3.png 64@64
 * Transparent color: (255, 0, 255)
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * 
 * All bug reports / feature requests are to be sent to Brandon (bwhitehead0308@gmail.com)
 */

#ifndef BANDP_H
#define BANDP_H

#define BANDP_TRANSPARENT 0x00

#define BANDP_PALETTE_TYPE (0 << 13)
#define BANDP_DIMENSION_TYPE (1 << 6)

extern const unsigned short bandp_palette[256];
#define BANDP_PALETTE_SIZE 256

extern const unsigned short bandp[2304];
#define BANDP_SIZE 2304

#define BIRD2_PALETTE (0 << 12)
#define BIRD2_SPRITE_SHAPE (0 << 14)
#define BIRD2_SPRITE_SIZE (2 << 14)
#define BIRD2_ID 512

#define PIPE2_PALETTE (1 << 12)
#define PIPE2_SPRITE_SHAPE (0 << 14)
#define PIPE2_SPRITE_SIZE (3 << 14)
#define PIPE2_ID 528

#define PIPE3_PALETTE (1 << 12)
#define PIPE3_SPRITE_SHAPE (0 << 14)
#define PIPE3_SPRITE_SIZE (3 << 14)
#define PIPE3_ID 592

#endif


/*
 * Exported with nin10kit v1.4
 * Invocation command was nin10kit -mode=sprites -bpp=4 -for_bitmap=1 -transparent=FF00FF bandp bird2.png pipe2.png pipe3.png 
 * Time-stamp: Friday 03/31/2017, 14:35:53
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

#include "bandp.h"

const unsigned short bandp_palette[256] =
{
	0x7c1f,0x1c88,0x4070,0x6419,0x34ce,0x290b,0x1cf0,0x1d2c,
	0x2179,0x31ef,0x55b7,0x4a13,0x1e76,0x171c,0x139d,0x737c,
	0x7c1f,0x24ca,0x20ea,0x11a9,0x11c9,0x0dea,0x0e0a,0x16ac,
	0x16cd,0x1ace,0x170d,0x134e,0x2b93,0x2f93,0x37b6,0x3bb8,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7c1f,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
};

const unsigned short bandp[2304] =
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0xa000,0x1111,0xbba0,0x9777,0xc954,0xeddd,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x0071,0xb557,0x0bb9,0xf55c,0x4bff,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x9900,0xb000,0x71fa,0x5200,0x1151,
	0xfbaa,0xbbbb,0xff9b,0xffff,0xff5b,0xffff,0xff5b,0xffff,
	0xd99b,0xeeee,0xeddd,0x9eee,0xeedc,0x7eee,0xeec7,0x7eee,
	0xdc9b,0x7eee,0xd7bf,0x7eee,0xcbff,0xceec,0xbfff,0xeed1,
	0xfbbc,0x9bff,0xfffb,0xffff,0xfff5,0xbfff,0xfff5,0x5bff,
	0xfff5,0x5bff,0xfff5,0x5bff,0xffb9,0xbbff,0xf57d,0xffff,
	0x000b,0x0000,0x009b,0x0000,0x0bbb,0x0000,0x45ff,0x0000,
	0x45ff,0x0000,0x45ff,0x0000,0x45ff,0x0000,0x45ff,0x0000,
	0xfc5b,0xffff,0xdd9f,0xffff,0xc400,0xdddd,0xc000,0xeeed,
	0xb000,0xccc9,0x0000,0x1512,0x0000,0xcc72,0x0000,0xcd95,
	0x9cff,0xeed1,0xceff,0xeed1,0xcccd,0xeeed,0xc7ce,0xeeee,
	0xdccc,0xcdee,0xddc5,0x7ddd,0xdddc,0xcddd,0xdddc,0xdddd,
	0xbcce,0xbbbb,0x1dee,0x5551,0x89cd,0x8888,0x867c,0x8888,
	0x6889,0x6666,0x5884,0x5555,0x866c,0x8888,0x867c,0x8888,
	0x45bb,0x0002,0x5555,0x0025,0x8888,0x2268,0x8888,0x9988,
	0x6666,0xaaa8,0x5555,0x0047,0x8888,0x0027,0x8888,0x00a9,
	0x0000,0x77f0,0x0000,0x9900,0x0000,0xff00,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0xedc7,0xeddd,0xccc9,0xcccc,0x77ba,0x7777,0x3300,0x3333,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x7cdd,0x6666,0x2ccc,0x9999,0x0977,0xfffa,0x0333,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0xb666,0x000a,0x4999,0x0000,0x0aff,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2200,0x0000,0xb200,0x0000,0xa200,0x0000,0xa200,
	0x0000,0xa200,0x0000,0xa200,0x0000,0xa200,0x0000,0xa200,
	0x2222,0x2222,0xffff,0xffff,0xcddf,0x888f,0xcddf,0x888f,
	0xcddf,0x888f,0xcddf,0x888f,0xcddf,0x888f,0xcddf,0x888f,
	0x2222,0x2222,0xffff,0xffff,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x2222,0x2222,0xffff,0xffff,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x2222,0x2222,0xafff,0xaaec,0x4888,0x5486,0x5888,0x5486,
	0x5888,0x5486,0x5888,0x5486,0x5888,0x5486,0x5888,0x5486,
	0x0022,0x0000,0x002b,0x0000,0x0026,0x0000,0x0026,0x0000,
	0x0026,0x0000,0x0026,0x0000,0x0026,0x0000,0x0026,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0xa200,0x0000,0xa200,0x0000,0xa200,0x0000,0xa200,
	0x0000,0xa200,0x0000,0x8200,0x0000,0x4200,0x0000,0x2100,
	0xcddf,0x888f,0xcddf,0x888f,0xcddf,0x888f,0xcddf,0x888f,
	0xcddf,0x888f,0x99de,0x779e,0x3333,0x3333,0x2222,0x2222,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x7777,0x7777,0x3333,0x3333,0x2222,0x2222,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x7777,0x7777,0x3333,0x3333,0x2222,0x2222,
	0x5888,0x5486,0x5888,0x5486,0x5888,0x5486,0x5888,0x5486,
	0x5888,0x5486,0x5777,0x5476,0x3333,0x3333,0x2222,0x2222,
	0x0026,0x0000,0x0026,0x0000,0x0026,0x0000,0x0026,0x0000,
	0x0026,0x0000,0x0026,0x0000,0x0024,0x0000,0x0012,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x5554,0x5555,0xeffa,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0x4445,0x4444,0xaaaf,0xaaaa,0x888f,0x8888,0x888f,0x8888,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x4444,0x4444,0xaaaa,0xaaaa,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x4544,0x5554,0x557a,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,0xdfe8,0xeddd,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,0x888f,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,0x5578,0x5548,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,0x0000,0x2000,
	0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,0x8455,0x8755,
	0x8455,0x8755,0x8455,0x8755,0x8455,0xa755,0x4555,0x4454,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0xaaaa,0xaaaa,0x4444,0x4444,
	0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,0x8888,0xf888,
	0x8888,0xf888,0x8888,0xf888,0xaaaa,0xfaaa,0x4444,0x5444,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,0xddde,0x8efd,
	0xddde,0x8efd,0xddde,0x8efd,0xddde,0xaffe,0x5555,0x4555,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,0x0002,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x2100,0x0000,0x4200,0x0000,0x6200,0x0000,0x6200,
	0x0000,0x6200,0x0000,0x6200,0x0000,0x6200,0x0000,0x6200,
	0x2222,0x2222,0x3333,0x3333,0x6745,0x7775,0x6845,0x8885,
	0x6845,0x8885,0x6845,0x8885,0x6845,0x8885,0x6845,0x8885,
	0x2222,0x2222,0x3333,0x3333,0x7777,0x7777,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x2222,0x2222,0x3333,0x3333,0x7777,0x7777,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x2222,0x2222,0x3333,0x3333,0xe977,0xed99,0xf888,0xfddc,
	0xf888,0xfddc,0xf888,0xfddc,0xf888,0xfddc,0xf888,0xfddc,
	0x0012,0x0000,0x0024,0x0000,0x0028,0x0000,0x002a,0x0000,
	0x002a,0x0000,0x002a,0x0000,0x002a,0x0000,0x002a,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x6200,0x0000,0x6200,0x0000,0x6200,0x0000,0x6200,
	0x0000,0x6200,0x0000,0x6200,0x0000,0xb200,0x0000,0x2200,
	0x6845,0x8885,0x6845,0x8885,0x6845,0x8885,0x6845,0x8885,
	0x6845,0x8885,0x6845,0x8884,0xceaa,0xfffa,0x2222,0x2222,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0xffff,0xffff,0x2222,0x2222,
	0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888,
	0x8888,0x8888,0x8888,0x8888,0xffff,0xffff,0x2222,0x2222,
	0xf888,0xfddc,0xf888,0xfddc,0xf888,0xfddc,0xf888,0xfddc,
	0xf888,0xfddc,0xf888,0xfddc,0xffff,0xffff,0x2222,0x2222,
	0x002a,0x0000,0x002a,0x0000,0x002a,0x0000,0x002a,0x0000,
	0x002a,0x0000,0x002a,0x0000,0x002b,0x0000,0x0022,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
};


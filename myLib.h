typedef unsigned int u32;
typedef unsigned short u16;
#define REG_DISPCTL *(unsigned short *)0x4000000
#define OBJ_ENABLE 0x1000
#define MODE3 3
#define MODE1D (1<<6)
#define BG2_ENABLE (1<<10)

extern unsigned short *videoBuffer;
typedef enum{
    START,
    START_NODRAW,
    PLAY,
    GAMEOVER,
} GBAState;

#define COLOR(r, g, b) ((r) | (g)<<5 | (b)<<10)
#define WHITE COLOR(31,31,31)
#define RED COLOR(31,0,0)
#define GREEN COLOR(0,31,0)
#define BLUE COLOR(0,0,31)
#define MAGENTA COLOR(31, 0, 31)
#define CYAN COLOR(0, 31, 31)
#define YELLOW COLOR(31, 31, 0)
#define BLACK 0


#define NUMPIPES 3
#define BIRDWIDTH 27 
#define BIRDHEIGHT (20) //10 is size of magenta
#define PIPEWIDTH 28
#define PIPEHEIGHT 64
#define JUMPVEL 9
#define OFFSET(r,c,rowlen) ((r)*(rowlen) + (c))
#define OAMMEM  ((OamEntry*)0x7000000)



// Buttons

#define BUTTON_A		(1<<0)
#define BUTTON_B		(1<<1)
#define BUTTON_SELECT	(1<<2)
#define BUTTON_START	(1<<3)
#define BUTTON_RIGHT	(1<<4)
#define BUTTON_LEFT		(1<<5)
#define BUTTON_UP		(1<<6)
#define BUTTON_DOWN		(1<<7)
#define BUTTON_R		(1<<8)
#define BUTTON_L		(1<<9)

#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)

#define BUTTONS *(volatile unsigned int *)0x4000130

#define SCANLINECOUNTER *(volatile short *)0x4000006

/* DMA */

#define REG_DMA0SAD         *(const volatile u32*)0x40000B0 // source address
#define REG_DMA0DAD         *(volatile u32*)0x40000B4       // destination address
#define REG_DMA0CNT         *(volatile u32*)0x40000B8       // control register

// DMA channel 1 register definitions
#define REG_DMA1SAD         *(const volatile u32*)0x40000BC // source address
#define REG_DMA1DAD         *(volatile u32*)0x40000C0       // destination address
#define REG_DMA1CNT         *(volatile u32*)0x40000C4       // control register

// DMA channel 2 register definitions
#define REG_DMA2SAD         *(const volatile u32*)0x40000C8 // source address
#define REG_DMA2DAD         *(volatile u32*)0x40000CC       // destination address
#define REG_DMA2CNT         *(volatile u32*)0x40000D0       // control register

// DMA channel 3 register definitions
#define REG_DMA3SAD         *(const volatile u32*)0x40000D4 // source address
#define REG_DMA3DAD         *(volatile u32*)0x40000D8       // destination address
#define REG_DMA3CNT         *(volatile u32*)0x40000DC       // control register

typedef struct
{
	const volatile void *src;
	void *dst;
	unsigned int cnt;
} DMA_CONTROLLER;

#define DMA ((volatile DMA_CONTROLLER *) 0x040000B0)

//SPRITE STUFF

#define SPRITEPAL  ((u16 *)0x5000200)
typedef struct { u16 tileimg[8192]; } charblock;
#define CHARBLOCKBASE ((charblock*)0x6000000)
//define object attribute memory state address
#define SpriteMem ((unsigned short*)0x7000000) //OAM
//define object attribute memory image address
#define SpriteData ((unsigned short*)0x6010000)



// Bits 8-9 flags Object Mode controls what type of sprite it is, and whether to draw or not (1 and 3 is used for affine sprites)
#define ATTR0_REG (0<<8) // Default
#define ATTR0_HIDE (2<<8) // If set the sprite is hidden, by default all sprites are SHOWN

// Bits A-B control Rendering modes.  Alpha blending can be enabled by setting these two bits to 01.

// C controls Mosaic effect if set the sprite will appear pixelated.
#define ATTR0_MOSAIC (1<<12)

// D Palette Mode
#define ATTR0_4BPP 0          // 16 colors (16 Palette Banks)
#define ATTR0_8BPP (1<<13)    // 256 colors (1 Palette of 256 Colors)

// E-F Sprite Shape
#define ATTR0_SQUARE 0
#define ATTR0_WIDE (1<<14)
#define ATTR0_TALL (2<<14)


// Flip flags
#define ATTR1_NOFLIP 0
#define ATTR1_HFLIP (1<<12)
#define ATTR1_VFLIP (1<<13)

// Sprite size.  Combined with attribute 0’s shape flag determines the dimensions of the sprite given.
#define ATTR1_SIZE8 0
#define ATTR1_SIZE16 (1<<14)
#define ATTR1_SIZE32 (2<<14)
#define ATTR1_SIZE64 (3<<14)


// Defines
#define DMA_CHANNEL_0 0
#define DMA_CHANNEL_1 1
#define DMA_CHANNEL_2 2
#define DMA_CHANNEL_3 3

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)


#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)



// Prototype
void setPixel(int , int , unsigned short );
void drawRect(int row, int col, int height, int width, unsigned short color);
void drawImage3(int x, int y, int width, int height, const unsigned short *image);
void drawFragment(int x, int y, int width, int height, const unsigned short *image, int parallax);
void drawFragmentMoved(int x, int y, int x2, int y2, int width, int height, const unsigned short *image);
void drawRectImage(int x, int y, int width, int height, const unsigned short *image);
void drawBird(int x, int y, int *starts, int *widths, const unsigned short *image);
void birdSetup(int *starts, int *widths, const unsigned short *image);
void initGraphics();
void initSprites();
void setupOBJS();
void keyInput(GBAState state);
void render();
void moveBird();
void hideSprites();
void movePipes();
void renderSprites();
void resetVars();
void delay(int);
void bgRedraw();
void waitForVblank();

#ifndef FRAMES_
#define FRAMES_

//https://stackoverflow.com/questions/4130434/c-undefined-reference-to-defined-function
#ifdef __cplusplus
extern "C" {
#endif
#include <time.h>

extern char led_grid[20];
extern void draw_frame(void);
extern void all_on(void);
extern void grid_off(void);
extern char led_grid[20];

void caution_lights();
void caution_lights2();
void snowflakes();
void snake_coil();
void snake_coil_uncoil();
void snake_coil_uncoil_fade();
// void A_(char brightness);
// void B_(char brightness);
// void C_(char brightness);
// void D_(char brightness);
// void E_(char brightness);
// void Y_(char brightness);
void abbey();
void snake_loading();
void snake_loading_2();
void wave();
void wave_continous();

void alphabet();
void alphabet_switch();
void happy();
void amongus();
void christmas();
void snake_slither();
void snake_slither0();
void DVD_Logo();
void bug_random();
void bug_random_slow();
void visualizer();

#ifdef __cplusplus
}
#endif

#endif
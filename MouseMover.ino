/* -*- mode:c++ -*- */
/**
 * @file 
 *
 * This program continuously moves the mouse in some way to prevent a
 * screensaver from activating. 
 *
 * See https://github.com/motlib/MouseMover.
 * 
 * @author Motlib <andreas@a-netz.de>
 */

#include "Mouse.h"
#include "math.h"

/** Select movement type. Define either cross or circle. */
#define MOVE_CIRCLE
#undef MOVE_CROSS

/** Mouse movement distance. */
#define MOUSE_DIST 10


/**
 * Initializations.
 */
void setup(void)
{
    Mouse.begin();
}


#ifdef MOVE_CROSS
/**
 * Moves the mouse in a cross style at one position of the screen. 
 */
static void do_move(void)
{
    static uint8_t dir = 0;
    int8_t x, y;

    x = ((-1) + (2 * (dir & 0x01))) * MOUSE_DIST;
    y = ((-1) + (dir & 0x02)) * MOUSE_DIST;
    
    Mouse.move(x, y);

    ++dir;
    dir &= 0x3u;

    for(uint8_t i = 0; i < 1; ++i)
    {
        delay(1000);
    }    
}
#endif /* MOVE_CROSS */


#ifdef MOVE_CIRCLE
/**
 * Moves the mouse in a big circle on the screen. 
 */
static void do_move(void)
{
    static double angle = 0;
    int8_t x, y;

    angle += 0.05;
    if(angle > 2 * 3.1415927)
    {
        angle = 0.0;
    }

    x = (int8_t)(sin(angle) * MOUSE_DIST);
    y = (int8_t)(cos(angle) * MOUSE_DIST);

    Mouse.move(x, y);

    delay(100);
}
#endif /* MOVE_CIRCLE */

/**
 * Normal program execution. 
 */
void loop(void)
{
    do_move();
}

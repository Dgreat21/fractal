
#include "fractol.h"
#include "keys.h"

static int	key_press(int key, void *param)
{
	t_all	*fract;

	fract = (t_all *)param;
	if (key == kVK_Escape)
		exit(0);
	else if (key == kVK_ANSI_B)
		fract->key = BSHP;
	else if (key == kVK_ANSI_J)
		fract->key = JULIA;
	else if (key == kVK_ANSI_M)
		fract->key = MANDELBROT;
//	else if (key == kVK_ANSI_KeypadPlus || key == kVK_ANSI_KeypadMinus ||
//			 key == kVK_ANSI_Minus || key == kVK_ANSI_Equal)
//		change_iteration(fract, key);
//	else if (key >= kVK_LeftArrow && key <= kVK_UpArrow)
//		arrow_control(fract, key);
//	else if (key == K_MEN || key == K_BOL)
//		change_move_speed(fract, key);
//	else if (key == K_BACKSPCE)
//		back_pls(fract);
	draw(fract);
	return (0);
}

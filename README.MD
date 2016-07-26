## Installation

under mac environment
"make re"

under linux environment
you have to change the minilibx and use one that is valid under linux
make re PLATFORM=Linux
(May not be working perfectly under linux)

## Usage

"./fractol" give you the list of fractals that are builtin
example "./fractol mandelbrot" will launch you the first fractal

## Inputs
<Space> go to the next builtin fractal
<MouseScroll_[UP|DOWN] | KEYPAD_[PLUS|MINUS]> Zoom in and out of the fractal
<C> Change the color of the fractal
<H> position the fractal relative to your mouse position
<V> enable or disable mouse variation on dynamic fractals like Julia
<R> Reset current fractal
<Q> Remove one iteration of calcul
<W> Add one iteration of calcul
<[LEFT|RIGHT|UP|DOWN]_ARROW> Move to the direction of the key
<E> Epileptic mode, change color automatically after a certain time
<Enable only when epileptic mode>
	<Alpha1> Slow down epileptic mode
	<Alpha2> Speed up epileptic mode
</Enable only when epileptic mode>
<Escape> Quit the program

## Authors

Béranger "Rakiah" Kabbas

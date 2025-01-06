mlx_init() - Establishes a connection to the X Window System (X11) server.
This connection allows MLX to create and manage windows, handle input events
and draw graphics.

The function sets up internal data structures that MLX uses to manage:
Windows
Images
Input events (keyboard, mouse)
Other graphical resources
It essencially prepares everything required for rendering graphics.

Return value:
It returns a void * pointer that serves as a handle to the MLX instance.
This pointer is required for all subsequent MLX functions (e.g., creating
windows, images, etc), as it links them to the initialized graphical
environment.


mlx_new_window() - Function sends a request to the X server to create a new
window. 
X server responds witha window ID, which MLX wraps in a void * pointer for you
to use.
The function sets the window's dimensions (width and height) and assigns the
window a title.
MLX allocates memory and resources to manage the window, such as buffers for 
rendering and structures for handling events.
The function uses the voit * pointer returned by mlx_init() to associate the
new window with the inialized MLX context. This allows that the window is 
managed within the same graphical environment.


mlx_new_image() - Creates a new, off-screen image (not directly displayed in
the window). Returns a void * pointer that represents the image.
Internally, MLX allocates memory for an image buffer that matcher the specified
dimensions. The buffer is stored in a format compatible with MLX's rendering
pipeline.
The new image is associated with the mlx instance, enableing you to manipulate
and display it.


mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)
Provides direct access to the pixel data of the image
buffer created by mlx_new_image. Parameters:
img_ptr = The pointer to the image created by mlx_new_image.
bits_per_pixel = A pointer to an integer that will store the number of bits per
pixel (e.g., 32 for 4 bytes per pixel).
size_line = A pointer to an integer that will store the number of bytes per
row of pixels in memory (including padding).
endian = A pointer to an integer that will store the endianness of the image data
(0 for little-endian, 1 for big-endian).
Internally: the function calculates the starting address of the pixel data in the 
image buffer and returns it as a char *.

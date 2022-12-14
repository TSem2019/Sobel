# Sobel

v1

Sobel operator for edge detection in gray scale images.

Mode **replicate** is used ('replicate' - input array values outside the bounds of the array are assumed to equal the nearest array border value).





Input arguments of function:

***src** - pointer to gray scale image;

**width** - width of gray scale image;

**height** - height of gray scale image.



Return:

**int*** - pointer to result.



Example:

Input image

<img src="examples/Lena_test.png" alt="Input" style="width: 300px;"/>

Result:

<img src="examples/Lena_Sobel.png" alt="Input" style="width: 300px;"/>
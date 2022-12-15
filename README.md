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

# Arguments (Windows PowerShell)

```
.\Sobel_Test input_file.png output_file.png
```

The **input_file.png** and **output_file.png** arguments are, the file for which the contour should be calculated and the file with that calculated contour, respectively.

//sudo apt-get install libjpeg-dev in linux. this opens and edits the colour data of a jpeg. to resize it. I made the resize algorithm and mapped the colour data using linear interpolation.
//but the extraction of resolution data and creation of new jped image file was from chatgpt. I edited it to fit my program. 


#include <stdio.h>
#include <jpeglib.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

Pixel** read_jpeg_file(const char* filename, int* width, int* height) {
    //surfs through header to get information and reach where pixel data is stored
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        printf("ERROR wrong/invalid file path %s\n", filename);
        exit(0);
        return 0;
    }
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);
    *width = cinfo.output_width;
    *height = cinfo.output_height;
    //initialises 2d array of pixel structure to store colour information
    Pixel** image = (Pixel**)malloc(cinfo.output_height * sizeof(Pixel*));
    for (int i = 0; i < cinfo.output_height; i++) {
        image[i] = (Pixel*)malloc(cinfo.output_width * sizeof(Pixel));
    }

    JSAMPARRAY buffer = (*cinfo.mem->alloc_sarray)
        ((j_common_ptr) &cinfo, JPOOL_IMAGE, cinfo.output_width * cinfo.output_components, 1);
    //loads colour data
    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, buffer, 1);
        for (int x = 0; x < cinfo.output_width; x++) {
            image[cinfo.output_scanline-1][x].r = buffer[0][x * cinfo.output_components];
            image[cinfo.output_scanline-1][x].g = buffer[0][x * cinfo.output_components + 1];
            image[cinfo.output_scanline-1][x].b = buffer[0][x * cinfo.output_components + 2];
        }
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);

    return image;
}
void write_file(const char* filename, Pixel** image, int width, int height){
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    //writes data to header about image
    FILE *output = fopen(filename, "wb");
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, output);
    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_start_compress(&cinfo, TRUE);

    JSAMPROW row_pointer;
    int row_stride = width * 3; // RGB channels
    //writes colour
    while (cinfo.next_scanline < cinfo.image_height) {
        row_pointer = (JSAMPROW) &image[cinfo.next_scanline][0];
        jpeg_write_scanlines(&cinfo, &row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(output);
    jpeg_destroy_compress(&cinfo);

}

    int main() {
    char filename[100]; // Allocate memory for filename
    int x, y, ox, oy, owidth, oheight, nwidth, nheight;
    float scaleh, scalew;

    // Getting file path of the image
    printf("Enter the file path of the image: ");
    scanf("%s", filename);

    Pixel** image = read_jpeg_file(filename, &owidth, &oheight);

    // Getting dimensions of the new image
    printf("Enter the dimensions of the new image (height width): ");
    scanf("%d %d", &nheight , &nwidth);

    scaleh = (float) oheight / nheight;
    scalew = (float) owidth / nwidth;

    printf("%f %f\n", scaleh, scalew);

    // Allocate memory for new_image
    Pixel** new_image = (Pixel**) malloc(nheight * sizeof(Pixel*));
    for (int i = 0; i < nheight; i++) {
        new_image[i] = (Pixel*) malloc(nwidth * sizeof(Pixel));
    }

    float oxf, oyf; // Used to check if we need to interpolate
    f	for (int y = 0; y < nheight; y++) {
    	for (int x = 0; x < nwidth; x++) {
        	oxf = scalew * x;
        	oyf = scaleh * y;
        	int ox = (int)oxf;
        	int oy = (int)oyf;
        	float fx = oxf - ox;
        	float fy = oyf - oy;

        	if (ox >= owidth - 1) ox = owidth - 2;
        	if (oy >= oheight - 1) oy = oheight - 2;

        	Pixel p1 = image[oy][ox];
        	Pixel p2 = image[oy][ox + 1];
        	Pixel p3 = image[oy + 1][ox];
        	Pixel p4 = image[oy + 1][ox + 1];

        	new_image[y][x].r = (unsigned char)((1 - fx) * (1 - fy) * p1.r + fx * (1 - fy) * p2.r + (1 - fx) * fy * p3.r + fx * fy * p4.r);
        	new_image[y][x].g = (unsigned char)((1 - fx) * (1 - fy) * p1.g + fx * (1 - fy) * p2.g + (1 - fx) * fy * p3.g + fx * fy * p4.g);
        	new_image[y][x].b = (unsigned char)((1 - fx) * (1 - fy) * p1.b + fx * (1 - fy) * p2.b + (1 - fx) * fy * p3.b + fx * fy * p4.b);
    	}
	}

    // Write the scaled image to a new file
    write_file("scaled.jpg", new_image, nwidth, nheight);

    // Free memory allocated for both image and new_image
    for (int i = 0; i < oheight; i++) {
        free(image[i]);
    }
    free(image);

    for (int i = 0; i < nheight; i++) {
        free(new_image[i]);
    }
    free(new_image);

    return 0;
}

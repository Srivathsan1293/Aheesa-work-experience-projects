This program requires the Libjpeg library to installed in order extract the data from an image.
Give the complete file path when asked and enter the new desired resolution. 

I employed a division function to scale back the new pixel coordinates 
to where they would be in the source image. This method was incomplete as most 
scaled back values were not exact pixel coordinates, so pixel scaling algorithms
were researched and linear interpolation was employed to decide the colour of 
intermediate pixels in the new image. To copy colour data from an image we need 
to store its data in an array, this became a major hurdle as I tried to analyse 
where colour data is stored in the jpeg format. Following online advice I decided 
to use the libjpeg library to parse through the header of a jpeg image and extract
the necessary information. The 2 part nature of both pixel coordinates and complex 
numbers allowed pixel coordinates to also be manipulated using the same library, 
reflecting how properties of mathematical concepts can be used to infer algorithms even in unrelated topics. 

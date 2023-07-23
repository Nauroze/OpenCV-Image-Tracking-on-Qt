# OpenCV Image Tracking on Qt
<b>Real-time multi object tracking</b>

In this program objects in a live camera feed are detected and tracked. As frames are passed through the camera feed, their RGB attributes are converted into the HSV type. This provides better depth so the algorithm can understand all the different colors and their hues in the image. Through that, the min/max HSV attributes are altered until the resulting threshold image has the object of interest isolated, thereby providing a quick and responsive object tracking mechanism.

The program also allows tracking multiple objects by storing their attributes in a container. Each object that is to be added is given a name of the user's choice and their corresponding HSV attributes are collected in a struct. The next time the object appears, it is tracked and the tag appears along with it.

Development was done in C++ on the Qt Framework.

For a tutorial on covering the fundamentals of color detection through thresholding, check out : http://opencv-srf.blogspot.ca/2010/09/object-detection-using-color-seperation.html

For information on how to install OpenCV libraries, check out this step-by-step guide : https://medium.com/@sourabhjigjinni/install-opencv-4-0-0-for-c-windows-7-10-code-blocks-tdm-gcc-64-dff65addf162

Video Demo: https://www.youtube.com/watch?v=SmeCGUqQ3qY

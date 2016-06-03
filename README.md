# OpenCV Image Tracking on Qt
<b>Real-time multi object tracking</b>

In this program objects in a live camera feed are detected and tracked. As frames are passed on through the camera feed, their RGB attributes are converted into the HSV type. This provides better depth so the algorithm can understand all the different colors and their hues in the image. Through that, the min/max HSV attributes are altered until the resulting threshold image has the object of interest isolated, thereby providing a quick and responsive object tracking. system.

The program also allows tracking multiple objects. Each object is defined by a struct consisting all the HSV values. Each object that is to be added is given a name of the user's choice. The next time the object appears, it is tracked and the tag appears along with it.

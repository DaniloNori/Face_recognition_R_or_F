This program demonstrates how to perform face detection using OpenCV library. The program takes an input image as a command line argument, applies face detection using a Haar Cascade classifier, and then draws rectangles around the detected faces.

Prerequisites.
OpenCV library
A Haar Cascade classifier file (such as haarcascade_frontalface_alt.xml) for face detection.

How to Use.

./face_detection <input image>

How it works.

The program checks whether an input image file path has been provided as an argument on the command line.
It loads the Haar Cascade classifier for face detection. If the classifier file is not found, the program terminates with an error message.
Reads the input grayscale image using the cv::imread() function.
The face detection algorithm is applied to the input image using the detectMultiScale() function. The function detects faces and returns the bounding box coordinates as a cv::Rect vector.
Next, the program draws rectangles around the detected faces using the cv::rectangle() function.
Finally, the output image with the detected faces is displayed using the cv::imshow() and cv::waitKey() functions.

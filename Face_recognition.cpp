#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input image>\n";
        return EXIT_FAILURE;
    }

    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("haarcascade_frontalface_alt.xml")) {
        std::cerr << "Error loading face cascade.\n";
        return EXIT_FAILURE;
    }

    cv::Mat img = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << "Error loading input image.\n";
        return EXIT_FAILURE;
    }

    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale(img, faces, 1.1, 2, 0, cv::Size(30, 30));

    for (const auto& face : faces) {
        cv::rectangle(img, face, cv::Scalar(255, 255, 255), 2);
    }

    cv::imshow("Face detection", img);
    cv::waitKey(0);

    return EXIT_SUCCESS;
}
#include <iostream>
/*
#include <opencv2/core.hpp>				// core functionality
#include <opencv2/imgcodecs.hpp>		// img file reading/writing (imread, imwrite)
#include <opencv2/highgui.hpp>			// GUI functions (imshow, waitKey)
*/

#include <opencv2/opencv.hpp>			// catches all the above and more includes
#include <chrono>

using namespace cv;

int main(int argc, char** argv) 
{
	if (argc != 3) {
		std::cout << "usage: ./feature_detection img1 img2" << std::endl;
		return 1;
	}

	Mat img1 = imread(argv[1], IMREAD_GRAYSCALE);
	Mat img2 = imread(argv[2], IMREAD_GRAYSCALE);

	if (img1.empty() || img2.empty())
	{
		std::cout << "Could not read images" << std::endl;
		return 1;
	}

	//-- initialization
	std::vector<KeyPoint> keypoints1, keypoints2;
	Mat descriptors1, descriptors2;
	Ptr<FeatureDetector> detector = ORB::create();
	Ptr<DescriptorExtractor> descriptor = ORB::create();
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");

	//-- detect Oriented Fast
	std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
	detector->detect(img1, keypoints1);
	detector->detect(img2, keypoints2);

	//-- compute BRIEF descriptor
	descriptor->compute(img1, keypoints1, descriptors1);
	descriptor->compute(img2, keypoints2, descriptors2);
	std::chrono::steady_clock::time_point t2 =std::chrono::steady_clock::now();
	std::chrono::duration<double> time_used = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);

	std::cout << "extract ORB cost = " << time_used.count() << " seconds. " << std::endl;

	Mat outimg1;
	drawKeypoints(img1, keypoints1, outimg1, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	imshow("ORB features", outimg1);
	waitKey(0);

	return 0;
}

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	system("Color 02"); // black background, green font
	string path = "assets/dog.jpg";
	Mat img = imread(path);
	if (img.empty()) {
		cout << "Can't read the file!\n";
		return -1;
	}

	cout << "Successfully loaded image!\n";
	cout << "Image size: " << img.cols << " x " << img.rows << "\n";

	resize(img, img, Size(), 0.4, 0.4);

	char brightness_to_ascii[] = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	int len = sizeof(brightness_to_ascii) / sizeof(char);

	vector<vector<char>> ascii_picture(img.rows, vector<char>(img.cols));

	cout << "Iterating through pixel brightnesses:\n";
	for (int row = 0; row < img.rows; ++row) {
		for (int col = 0; col < img.cols; ++col) {
			Vec3b pixel = img.at<Vec3b>(row, col);
			int r = (int)pixel[2];
			int g = (int)pixel[1];
			int b = (int)pixel[0];
			int brightness = 0.2126 * r + 0.7152 * g + 0.0722 * b;
			char c = brightness_to_ascii[brightness * len / 256];
			ascii_picture[row][col] = c;
		}
	}

	for (int row = 0; row < img.rows; ++row) {
		for (int col = 0; col < img.cols; ++col) {
			for (int i = 0; i < 3; ++i) cout << ascii_picture[row][col];
		}
		cout << "\n";
	}
}
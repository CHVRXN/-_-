#include <opencv2/core/core.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#define M_PIl 3.141592653589793238462643383279502884L

using namespace cv;
using namespace std;

void DrawWindow ()
{
 int height = 520;
	int width = 840;
	Mat img(height, width, CV_8UC3);
	Point textOrg(100, img.rows / 2);
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
	double fontScale = 2;
	Scalar color(200, 100, 50);
	putText(img, "OpenCV Step By Step", textOrg, fontFace, fontScale, color);
	namedWindow("Âûâîä", 0);
	imshow("Hello world", img);
	waitKey(0);
	
}
int main()
/*
 {
	int height = 520;
	int width = 840;
	Mat img(height, width, CV_8UC3);
	Point textOrg(100, img.rows / 2);
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
	double fontScale = 2;
	Scalar color(200, 100, 50);
	putText(img, "OpenCV Step By Step", textOrg, fontFace, fontScale, color);
	namedWindow("Âûâîä", 0);
	imshow("Hello world", img);
	waitKey(0);
	return 0;
}
DrawWindow ();
*/
/*
{
	setlocale(LC_ALL, "Russian");
	char filename[80]; //road.jpg
	cout << "Ââåäèòå èìÿ ôàéëà, êîòîðûé áóäåò èçìåíåí" << endl;
	cin.getline(filename, 80);
	cout << "Îòêðûòü ôàéë" << endl;

	Mat img = imread("road.jpg", 1);
	const char* source_window = "Èñõîäíîå èçîáðàæåíèå";

	namedWindow(source_window, WINDOW_GUI_EXPANDED);
	imshow(source_window, img);

	Mat scr_gray;
	Mat canny_output;
	cvtColor(img, scr_gray, COLOR_RGB2GRAY); //Ñîçäàíèå ÷á  ôîòî
	imwrite("cvtColor.jpg", scr_gray); //Ñîõðàíåíèå ÷á ôîòî â ïàïêó ñ ïðîãðàììîé
	blur(scr_gray, scr_gray, Size(10, 10)); //Ñîçäàíèå ðàçìûòîãî  ôîòî
	imwrite("blur.jpg", scr_gray); //Ñîõðàíåíèå ðàçìûòîãî ôîòî â ïàïêó ñ ïðîãðàììîé

	double otsu_thresh_val = threshold(scr_gray, img, 0, 255, THRESH_BINARY | THRESH_OTSU);
	double high_thresh_val = otsu_thresh_val, lower_thresh_val = otsu_thresh_val * 0.5;
	cout << otsu_thresh_val;
	Canny(scr_gray, canny_output, lower_thresh_val, high_thresh_val, 3);

	const char* sorce_grey_window = "Ñåðîå èçîáðàæåíèå";
	namedWindow(sorce_grey_window, WINDOW_GUI_EXPANDED);
	imshow(sorce_grey_window, canny_output);
	imwrite("canny_output.jpg", canny_output);

	RNG rng(12345);
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;

	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	vector<Moments>mu(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}

	vector<Point2f>mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}
	
	for (int i = 0; i < contours.size(); i++)
	{
		printf("Êîíòóð ¹ %d: öåíòð ìàññ - x = %.2f y = %.2f; äëèíà - %.2f \n", i, mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00, arcLength(contours[i], true));
	}

	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3); //CV_8UC3 - èçîáðàæåíèå áåç çíàêà ñ 3 êàíàëàìè

	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		circle(drawing, mc[i], 4, color, -1, 5, 0);
	}

	namedWindow("Êîíòóðû", WINDOW_GUI_EXPANDED);
	imshow("Êîíòóðû", drawing);


	waitKey(0);
	return(0);
}*/

{
	//Óñòàíàâëèâàåì ðóññêóþ ëîêàëü äëÿ êîíñîëè
	setlocale(LC_ALL, "Russian");

	char filename[100]; // Figyres.mp4 èëè Figyres_same_color.mp4
	cout << "Ââåäèòå èìÿ ôàéëà, êîòîðûé õîòèòå ïðîàíàëèçèðîâàòü, è íàæìèòå Enter" << endl;
	cin.getline(filename, 100);
	cout << "Îòêðûòü ôàéë";
	cout << filename << endl;

	
	
	VideoCapture cap(filename);
	if (!cap.isOpened()) { cout << "Îøèáêà îòêðûòèÿ ôàéëà"; return -1; }
	Mat im;
	for (; ;)
	{
		Mat mat, frame;
		cap >> frame;
		mat = frame;
		if (mat.empty()) break;

		imshow("Ðàñïîçíàâàíèå", frame);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}

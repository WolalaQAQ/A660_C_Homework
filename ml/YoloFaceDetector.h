//
// Created by wolala on 2023/3/20.
//
#ifndef A660_C_HOMEWORK_YOLOFACEDETECTOR_H
#define A660_C_HOMEWORK_YOLOFACEDETECTOR_H

#include <openvino/c/openvino.h>
#include <opencv2/opencv.hpp>
using namespace cv;

typedef struct {
  float prob;
  Rect rect;
  Point points[5];
} Object;

Mat getCameraFrame();
void parseYolo();
void detect2origin();
void processFrame();

#endif  // A660_C_HOMEWORK_YOLOFACEDETECTOR_H

//
// Created by Adminstrator on 2023/3/21.
//
#include "cap_image.h"

void Cap() {
  CvCapture* capture = cvCreateCameraCapture(1);
  if (!capture) {
    fprintf(stderr, "Error: Cannot open the camera.\n");
    return;
  }

  cvNamedWindow("Camera", CV_WINDOW_AUTOSIZE);

  while (1) {
    IplImage* frame = cvQueryFrame(capture);
    if (!frame) {
      fprintf(stderr, "Error: Cannot read a frame from the camera.\n");
      break;
    }

    cvShowImage("Camera", frame);

    char c = cvWaitKey(33);
    if (c == 27) { // ESC key
      break;
    } else if (c == 'p' || c == 'P') {
      static int counter = 0;
      char filename[64];
      sprintf(filename, "frame_%04d.png", counter++);
      cvSaveImage(filename, frame, 0);
      printf("Saved: %s\n", filename);
    }
  }

  cvReleaseCapture(&capture);
  cvDestroyAllWindows();
}
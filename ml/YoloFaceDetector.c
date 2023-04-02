//
// Created by wolala on 2023/3/20.
//
#include "YoloFaceDetector.h"

Mat getCameraFrame() {
  VideoCapture cap(0);
  Mat frame;
  cap >> frame;
  return frame;
}

void parseYolo() {
  ov_core_t* core = NULL;
  ov_core_create(&core);
  ov_model_t* model = NULL;
  ov_core_read_model(core, "/home/wolala/A660_C_Homework/model/yolov7-lite-s.xml", NULL, &model);
  ov_compiled_model_t* compiled_model = NULL;
  ov_core_compile_model(core, model, "CPU", 0, &compiled_model);
  ov_infer_request_t* infer_request = NULL;
  ov_compiled_model_create_infer_request(compiled_model, &infer_request);
  ov_tensor_t* input_tensor1 = NULL;
  ov_tensor_t* input_tensor2 = NULL;
  void* data = NULL;
  {
    // Get input tensor by index
    ov_infer_request_get_input_tensor_by_index(infer_request, 0, &input_tensor1);
    // Element types, names and layouts are aligned with framework
    ov_tensor_data(input_tensor1, &data);
    // Fill first data ...
  }

  {
    // Get input tensor by tensor name
    ov_infer_request_get_tensor(infer_request, "data2_t", &input_tensor2);
    // Element types, names and layouts are aligned with framework
    ov_tensor_data(input_tensor2, &data);
    // Fill first data ...
  }

  ov_tensor_free(input_tensor1);
  ov_tensor_free(input_tensor2);
  ov_infer_request_infer(infer_request);

  ov_tensor_t* output_tensor = NULL;
  void* out_data = NULL;

  // model has only one output
  ov_infer_request_get_output_tensor(infer_request, &output_tensor);
  // Element types, names and layouts are aligned with framework
  ov_tensor_data(output_tensor, &out_data);
  // process output data

  ov_tensor_free(output_tensor);
}
#pragma once
#include "Utils.h"


int perceptron_learning(Sample point, double* weight_array, int dimension, int class_number);
void perceptron_feed_forwared(Sample point, double* weight_array, int dimension, int class_number, double* net, double* output, double bias);
int perceptron_back_propagation(Sample point, double* weight_array, int dimension, int class_number, double* net, double* output, double bias);
double sgn(double net);

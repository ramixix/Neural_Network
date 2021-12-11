#pragma once
#include "Utils.h"

typedef struct Layer {
	int number_of_neurons;
	int number_of_inputs;
	int weights_length;
	double* weights;
	double* net;
	double* output;
	double* S; // S is a sign that i cant show it by character but basically S = (dk - ok) f`(netk)
	double bias = 1;
	double learning_constant = 0.1;
	int lambda = 1;
}Layer;


typedef struct Neural_Network {
	int number_of_inputs;
	int number_of_outputs;
	int number_of_layers;
	int total_neuron_number;
	Layer* layers;
}Neural_Network;

void create_network(Neural_Network *my_network, int input_num, int hidden_layer_num, int neurons_number_in_each_hidden_layer, int output_num);
void initiate_all_layers(Layer *all_layers, int dimension, int  number_of_hidden_layers, int neurons_number_in_each_hidden_layer, int total_class_number);
double train(Sample point, Neural_Network *my_network, Layer *all_layers);
double SGD_feed_forward(Sample point, Neural_Network* my_network, Layer *all_layers);
void SGD_back_propagation(Sample point, Neural_Network* my_network, Layer* all_layers);
double RMSE(double total_error, int total_points, int total_neurons_number);
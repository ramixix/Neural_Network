#include "Network.h"


void create_network(Neural_Network* my_network, int input_num, int hidden_layers_num, int neurons_number_in_each_hidden_layer, int output_num) {
	int total_layers_num = hidden_layers_num + 1;  // the total layer of network is equal to == number of hidden layers + output layer ===> hidden_layers + 1
	my_network->number_of_inputs = input_num;
	my_network->number_of_layers = total_layers_num;
	my_network->number_of_outputs = output_num;
	my_network->layers = (Layer*)malloc(sizeof(Layer) * total_layers_num);

	// total neurons inside each network is equal to == number of neurons in each hidden layer(in our program number of nerons in each hidden layer is the same) + number of neurons in output layer
	my_network->total_neuron_number = 0;
	for (int i = 0; i < hidden_layers_num; i++) {
		my_network->total_neuron_number += neurons_number_in_each_hidden_layer;
	}
	my_network->total_neuron_number += output_num;
}

//##############################################################################################################################################################################################################

void initiate_all_layers(Layer* all_layers, int input_num, int  hidden_layers_num, int neurons_number_in_each_hidden_layer, int output_num) {
	int total_layers_num = hidden_layers_num + 1;
	
	// set number of inputs for every layers ( for simplifying it, i add bias of each layer to our inputs array)
	all_layers[0].number_of_inputs = input_num + 1; // the first layer's input are always the inputs give by the user (here points on coordinate plane)
	for (int i = 1; i < total_layers_num; i++) {
		all_layers[i].number_of_inputs = neurons_number_in_each_hidden_layer + 1;
	}

	// set number of neurons in each layer (all hidden layers have the same number of neurons, only output layer might have different number of neurons and that is eqal to output_num)
	for(int i = 0; i < hidden_layers_num; i++){
		all_layers[0].number_of_neurons = neurons_number_in_each_hidden_layer;
	}
	all_layers[hidden_layers_num].number_of_neurons = output_num;

	// calculate weight matrix size for every layer ( weight size for each layer = number of neuron in that layer * (number of inputs + 1) )
	// we already add one to inputs_number for each layer so we are good to go
	for (int i = 0; i < total_layers_num; i++) {
		// calculate weight matrix size for each layer and allocate enough memory and then asign random value for initilization.
		all_layers[i].weights_length = all_layers[i].number_of_neurons * all_layers[i].number_of_inputs;
		all_layers[i].weights = (double*)malloc(sizeof(double) * all_layers[i].weights_length);
		set_random_value_to_array(all_layers[i].weights, all_layers[i].weights_length);

		all_layers[i].net = (double*)malloc(sizeof(double) * all_layers[i].number_of_neurons);
		all_layers[i].output = (double*)malloc(sizeof(double) * all_layers[i].number_of_neurons);
		all_layers[i].S = (double*)malloc(sizeof(double) * all_layers[i].number_of_neurons);

		for (int j = 0; j < all_layers[i].number_of_neurons; j++) {
			all_layers[i].net[j] = 0.0;
			all_layers[i].output[j] = 0.0;
			all_layers[i].S[j] = 0.0;
		}
	}
}

//##############################################################################################################################################################################################################

double train(Sample point, Neural_Network* my_network, Layer* all_layers) {
	double total_error = 0;
	SGD_feed_forward(point, my_network, all_layers, total_error);
	total_error = SGD_back_propagation(point, my_network, all_layers);
	return total_error;

}

//##############################################################################################################################################################################################################

// in feed_forward we calculate outputs for all layers in our network
void SGD_feed_forward(Sample point, Neural_Network* my_network, Layer* all_layers, double error) {
	// start form layer 1. calculate net and output;
	for (int i = 0; i < all_layers[0].number_of_neurons; i++) {
		for (int j = 0; j < all_layers[0].number_of_inputs - 1 ; j++) {
			all_layers[0].net[i] += all_layers[0].weights[i * (all_layers[0].number_of_inputs) + j] * point.x_coordinates[j];
		}
		all_layers[0].net[i] += all_layers[0].weights[i * (all_layers[0].number_of_inputs) + (all_layers[0].number_of_inputs - 1 )] * all_layers[0].bias;
	}

	for (int i = 0; i < all_layers[0].number_of_neurons; i++) {
		all_layers[0].output[i] = sigmoid(all_layers[0].net[i], all_layers[0].lambda);
	}

	// middle layers
	int number_of_hidden_layers = my_network->number_of_layers - 1;
	for (int layer_index = 1; layer_index < number_of_hidden_layers; layer_index++) {
		for (int i = 0; i < all_layers[layer_index].number_of_neurons; i++) {
			for (int j = 0; j < all_layers[layer_index].number_of_inputs - 1; j++) {
				all_layers[layer_index].net[i] += all_layers[layer_index].weights[i * (all_layers[layer_index].number_of_inputs) + j] * all_layers[layer_index - 1].output[j];
			}
			all_layers[layer_index].net[i] += all_layers[layer_index].weights[i * (all_layers[layer_index].number_of_inputs) + (all_layers[layer_index].number_of_inputs - 1)] * all_layers[layer_index].bias;
		}

		for (int i = 0; i < all_layers[layer_index].number_of_neurons; i++) {
			all_layers[layer_index].output[i] = sigmoid(all_layers[layer_index].net[i], all_layers[layer_index].lambda);
		}
	}

	// output layer
	int last_layer_index = number_of_hidden_layers;
	double desired_output;
	for (int i = 0; i < all_layers[last_layer_index].number_of_neurons; i++) {
		for (int j = 0; j < (all_layers[last_layer_index].number_of_inputs - 1); j++) {
			all_layers[last_layer_index].net[i] += all_layers[last_layer_index].weights[i * (all_layers[last_layer_index].number_of_inputs) + j] * all_layers[last_layer_index - 1].output[j];
		}
		all_layers[last_layer_index].net[i] += all_layers[last_layer_index].weights[i * (all_layers[last_layer_index].number_of_inputs) + (all_layers[last_layer_index].number_of_inputs - 1)] * all_layers[last_layer_index].bias;
	}

	for (int i = 0; i < all_layers[last_layer_index].number_of_neurons; i++) {
		all_layers[last_layer_index].output[i] = sigmoid(all_layers[last_layer_index].net[i], all_layers[last_layer_index].lambda);

		if (i == point.class_id)
			desired_output = 1;
		else
			desired_output = -1;
		
		error += pow((desired_output - all_layers[last_layer_index].output[i]), 2);
	}
}

//##############################################################################################################################################################################################################

double SGD_back_propagation(Sample point, Neural_Network* my_network, Layer* all_layers) {

}

//##############################################################################################################################################################################################################


//##############################################################################################################################################################################################################

//##############################################################################################################################################################################################################
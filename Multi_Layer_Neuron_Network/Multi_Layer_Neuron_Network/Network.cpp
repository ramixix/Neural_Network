#include "Network.h"


void create_network(Neural_Network* my_network, int input_num, int hidden_layers_num, int neurons_number_in_each_hidden_layer, int output_num, int train_type) {
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

	initiate_all_layers(my_network->layers, input_num, hidden_layers_num, neurons_number_in_each_hidden_layer, output_num, train_type);
}

//##############################################################################################################################################################################################################

void initiate_all_layers(Layer* all_layers, int input_num, int  hidden_layers_num, int neurons_number_in_each_hidden_layer, int output_num, int train_type) {
	int total_layers_num = hidden_layers_num + 1;
	
	// set number of inputs for every layers ( for simplifying it, lets add bias of each layer to our inputs array, so the plus one '+ 1' is because of bias) 
	all_layers[0].number_of_inputs = input_num + 1; // the first layer's input are always the inputs give by the user (here points on coordinate plane)
	for (int i = 1; i < total_layers_num; i++) {
		all_layers[i].number_of_inputs = neurons_number_in_each_hidden_layer + 1;
	}

	// set number of neurons in each layer (all hidden layers have the same number of neurons, only output layer might have different number of neurons and that is eqal to output_num)
	for(int i = 0; i < hidden_layers_num; i++){
		all_layers[i].number_of_neurons = neurons_number_in_each_hidden_layer;
	}
	all_layers[hidden_layers_num].number_of_neurons = output_num;

	// set learning constant for each layer
	all_layers[0].learning_constant = 0.01f;
	for (int i = 1; i < total_layers_num; i++) {
		all_layers[i].learning_constant = all_layers[i - 1].learning_constant + 0.001f;
	}

	// calculate weight matrix size for every layer ( weight size for each layer = number of neuron in that layer * (number of inputs + 1) )
	// we already add one to inputs_number for each layer so we are good to go
	for (int i = 0; i < total_layers_num; i++) {
		// setting bias , lambda (for sigmoid function). 
		all_layers[i].bias = 1;
		all_layers[i].lambda = 1;

		// calculate weight matrix size for each layer and allocate enough memory and then asign random value for initilization.
		all_layers[i].weights_length = all_layers[i].number_of_neurons * all_layers[i].number_of_inputs;
		all_layers[i].weights = (double*)malloc(sizeof(double) * all_layers[i].weights_length);
		set_random_value_to_array(all_layers[i].weights, all_layers[i].weights_length);

		all_layers[i].net = (double*)malloc(sizeof(double) * all_layers[i].number_of_neurons);
		all_layers[i].output = (double*)malloc(sizeof(double) * all_layers[i].number_of_neurons);
		all_layers[i].S = (double*)malloc(sizeof(double) * all_layers[i].number_of_neurons);
		if (train_type == 1) {	// in case when the train type is SGD Momentum
			all_layers[i].moment_weights = (double*)calloc(all_layers[i].weights_length, sizeof(double));
			all_layers[i].moment_rate = Moment_Rate;
		}
	}
}

//##############################################################################################################################################################################################################

double train(Sample point, Neural_Network* my_network, Layer* all_layers, int train_type) {
	double total_error = 0;
	total_error = SGD_feed_forward(point, my_network, all_layers);
	if (train_type == 0)
		SGD_back_propagation(point, my_network, all_layers);
	else
		SGD_Moment_back_propagation(point, my_network, all_layers);
	return total_error;

}

//##############################################################################################################################################################################################################

// in feed_forward we calculate outputs for all layers in our network
double SGD_feed_forward(Sample point, Neural_Network* my_network, Layer* all_layers) {
	double error = 0.0;
	reset_net_values(all_layers, my_network->number_of_layers);
	// start form layer 1. calculate net and output;
	for (int i = 0; i < all_layers[0].number_of_neurons; i++) {
		for (int j = 0; j < all_layers[0].number_of_inputs - 1 ; j++) {
			double neta = all_layers[0].weights[i * (all_layers[0].number_of_inputs) + j] * point.x_coordinates[j];
			all_layers[0].net[i] += all_layers[0].weights[i * (all_layers[0].number_of_inputs) + j] * point.x_coordinates[j];
		}
		double netaa = all_layers[0].weights[i * (all_layers[0].number_of_inputs) + (all_layers[0].number_of_inputs - 1)] * all_layers[0].bias;
		all_layers[0].net[i] += all_layers[0].weights[i * (all_layers[0].number_of_inputs) + (all_layers[0].number_of_inputs - 1 )] * all_layers[0].bias;
		double netaaa = all_layers[0].net[i];
	}

	for (int i = 0; i < all_layers[0].number_of_neurons; i++) {
		double outa = sigmoid(all_layers[0].net[i], all_layers[0].lambda);
		all_layers[0].output[i] = sigmoid(all_layers[0].net[i], all_layers[0].lambda);
	}

	// middle layers ( layers that are between the first hidden layer and output layer)
	int number_of_hidden_layers = my_network->number_of_layers - 1;
	for (int layer_index = 1; layer_index < number_of_hidden_layers; layer_index++) {
		for (int i = 0; i < all_layers[layer_index].number_of_neurons; i++) {
			for (int j = 0; j < all_layers[layer_index].number_of_inputs - 1; j++) {
				double neta = all_layers[layer_index].weights[i * (all_layers[layer_index].number_of_inputs) + j] * all_layers[layer_index - 1].output[j];
				all_layers[layer_index].net[i] += all_layers[layer_index].weights[i * (all_layers[layer_index].number_of_inputs) + j] * all_layers[layer_index - 1].output[j];
			}
			double netaa = all_layers[layer_index].weights[i * (all_layers[layer_index].number_of_inputs) + (all_layers[layer_index].number_of_inputs - 1)] * all_layers[layer_index].bias;
			all_layers[layer_index].net[i] += all_layers[layer_index].weights[i * (all_layers[layer_index].number_of_inputs) + (all_layers[layer_index].number_of_inputs - 1)] * all_layers[layer_index].bias;
		}

		for (int i = 0; i < all_layers[layer_index].number_of_neurons; i++) {
			double outa = sigmoid(all_layers[layer_index].net[i], all_layers[layer_index].lambda);
			all_layers[layer_index].output[i] = sigmoid(all_layers[layer_index].net[i], all_layers[layer_index].lambda);
		}
	}
	double f1 = all_layers[0].output[0];
	double f2 = all_layers[0].output[1];
	double f3 = all_layers[0].output[2];
	
	// output layer
	int last_layer_index = number_of_hidden_layers;
	for (int i = 0; i < all_layers[last_layer_index].number_of_neurons; i++) {
		for (int j = 0; j < (all_layers[last_layer_index].number_of_inputs - 1); j++) {
			double wie = all_layers[last_layer_index].weights[i * (all_layers[last_layer_index].number_of_inputs) + j];
			double in= all_layers[last_layer_index - 1].output[j];
			double re = wie * in;
			all_layers[last_layer_index].net[i] += all_layers[last_layer_index].weights[i * (all_layers[last_layer_index].number_of_inputs) + j] * all_layers[last_layer_index - 1].output[j];
		}
		double netaa= all_layers[last_layer_index].weights[i * (all_layers[last_layer_index].number_of_inputs) + (all_layers[last_layer_index].number_of_inputs - 1)] * all_layers[last_layer_index].bias;
		double reee = all_layers[last_layer_index].net[i] + netaa;
		all_layers[last_layer_index].net[i] += all_layers[last_layer_index].weights[i * (all_layers[last_layer_index].number_of_inputs) + (all_layers[last_layer_index].number_of_inputs - 1)] * all_layers[last_layer_index].bias;
	}
	double ff1 = all_layers[1].net[0];
	double ff2 = all_layers[1].net[1];

	
	for (int i = 0; i < all_layers[last_layer_index].number_of_neurons; i++) {
		double outa = sigmoid(all_layers[last_layer_index].net[i], all_layers[last_layer_index].lambda);
		all_layers[last_layer_index].output[i] = sigmoid(all_layers[last_layer_index].net[i], all_layers[last_layer_index].lambda);

		double desired_output;
		if (i == point.class_id)
			desired_output = 1;
		else
			desired_output = -1;
		
		error += pow((desired_output - all_layers[last_layer_index].output[i]), 2);
	}
	return error;
}

//##############################################################################################################################################################################################################

void SGD_back_propagation(Sample point, Neural_Network* my_network, Layer* all_layers) {
	// start from last layer (output layer)
	int last_layer_index = my_network->number_of_layers - 1;
	// first of all we calculate the back error and put it in S array.
	for (int neuron_index = 0; neuron_index < all_layers[last_layer_index].number_of_neurons; neuron_index++) {
		double desired_output;
		if (point.class_id == neuron_index)
			desired_output = 1;
		else
			desired_output = -1;
		all_layers[last_layer_index].S[neuron_index] = (desired_output - all_layers[last_layer_index].output[neuron_index]) * sigmoidDerivative(all_layers[last_layer_index].net[neuron_index], all_layers[last_layer_index].lambda); // (dk-ok)*f`(netk)

		double learning_constant = all_layers[last_layer_index].learning_constant;
		double error_return = all_layers[last_layer_index].S[neuron_index];
		for (int j = 0; j < all_layers[last_layer_index].number_of_inputs - 1; j++) {
			double outj = all_layers[last_layer_index - 1].output[j];
			double sj = all_layers[last_layer_index].S[neuron_index];//
			double new_we = sj * learning_constant * outj;
			all_layers[last_layer_index].weights[neuron_index * (all_layers[last_layer_index].number_of_inputs) + j] += learning_constant * error_return * all_layers[last_layer_index - 1].output[j];
			double newweight = all_layers[last_layer_index].weights[neuron_index * (all_layers[last_layer_index].number_of_inputs) + j];//
		}
		all_layers[last_layer_index].weights[neuron_index * (all_layers[last_layer_index].number_of_inputs) + (all_layers[last_layer_index].number_of_inputs - 1)] += learning_constant * error_return * all_layers[last_layer_index].bias;
		double newlastweigh = all_layers[last_layer_index].weights[neuron_index * (all_layers[last_layer_index].number_of_inputs) + (all_layers[last_layer_index].number_of_inputs - 1)];//
	}
	double out0 = all_layers[last_layer_index].weights[0];
	double out1 = all_layers[last_layer_index].weights[1];
	double out2 = all_layers[last_layer_index].weights[2];
	double out3 = all_layers[last_layer_index].weights[3];
	double out4 = all_layers[last_layer_index].weights[4];
	double out5 = all_layers[last_layer_index].weights[5];
	double out6 = all_layers[last_layer_index].weights[6];
	double out7 = all_layers[last_layer_index].weights[7];

	// all the hidden layers before the last layer
	// goes from last to first ( except first hidden layer )
	int last_hidden_layer_index = last_layer_index - 1;
	for (int index_layer = last_hidden_layer_index; index_layer > 0; index_layer--) {
		
		for (int neuron_index = 0; neuron_index < all_layers[index_layer].number_of_neurons; neuron_index++) {
			double S_next = 0.0;
			for (int k = 0; k < all_layers[index_layer + 1].number_of_neurons; k++) {
				S_next += all_layers[index_layer + 1].S[k] * all_layers[index_layer+1].weights[k * (all_layers[index_layer+1].number_of_inputs) + neuron_index];
			}

			all_layers[index_layer].S[neuron_index] = S_next * sigmoidDerivative(all_layers[index_layer].net[neuron_index], all_layers[index_layer].lambda);
			
			for (int j = 0; j < all_layers[index_layer].number_of_inputs - 1; j++) {
				all_layers[index_layer].weights[neuron_index * (all_layers[index_layer].number_of_inputs) + j] += all_layers[index_layer].learning_constant * all_layers[index_layer].S[neuron_index] * all_layers[index_layer - 1].output[j];
			}
			all_layers[index_layer].weights[neuron_index * (all_layers[index_layer].number_of_inputs) + (all_layers[index_layer].number_of_inputs - 1)] += all_layers[index_layer].learning_constant * all_layers[index_layer].S[neuron_index] * all_layers[index_layer].bias;
		}
	}

	// the first layer
	for (int neuron_index = 0; neuron_index < all_layers[0].number_of_neurons; neuron_index++) {
		double S_next = 0.0;
		for (int j = 0; j < all_layers[1].number_of_neurons; j++) {
			S_next += all_layers[1].S[j] * all_layers[1].weights[j * (all_layers[1].number_of_inputs) + neuron_index];
			double wi = all_layers[1].weights[j * (all_layers[1].number_of_inputs) + neuron_index];
		}
		all_layers[0].S[neuron_index] = S_next * sigmoidDerivative(all_layers[0].net[neuron_index], all_layers[0].lambda);

		double learning_constant = all_layers[0].learning_constant;
		double error_return = all_layers[0].S[neuron_index];
		for (int k = 0; k < all_layers[0].number_of_inputs - 1; k++) {
			all_layers[0].weights[neuron_index * all_layers[0].number_of_inputs + k] += learning_constant * error_return * point.x_coordinates[k];
			double newweight = all_layers[0].weights[neuron_index * all_layers[0].number_of_inputs + k];//
		}
		all_layers[0].weights[neuron_index * all_layers[0].number_of_inputs + (all_layers[0].number_of_inputs - 1)] += learning_constant * error_return * all_layers[0].bias;
		double newaweight = all_layers[0].weights[neuron_index * all_layers[0].number_of_inputs + (all_layers[0].number_of_inputs - 1)];
	}
}

//##############################################################################################################################################################################################################

void SGD_Moment_back_propagation(Sample point, Neural_Network* my_network, Layer* all_layers) {
	// start from last layer (output layer)
	int last_layer_index = my_network->number_of_layers - 1;
	// first of all we calculate the back error and put it in S array.
	for (int neuron_index = 0; neuron_index < all_layers[last_layer_index].number_of_neurons; neuron_index++) {
		double desired_output;
		if (point.class_id == neuron_index)
			desired_output = 1;
		else
			desired_output = -1;
		all_layers[last_layer_index].S[neuron_index] = (desired_output - all_layers[last_layer_index].output[neuron_index]) * sigmoidDerivative(all_layers[last_layer_index].net[neuron_index], all_layers[last_layer_index].lambda); // (dk-ok)*f`(netk)

		double learning_constant = all_layers[last_layer_index].learning_constant;
		double error_return = all_layers[last_layer_index].S[neuron_index];
		for (int j = 0; j < all_layers[last_layer_index].number_of_inputs - 1; j++) {
			double delta_error = learning_constant * error_return * all_layers[last_layer_index - 1].output[j];
			all_layers[last_layer_index].weights[neuron_index * (all_layers[last_layer_index].number_of_inputs) + j] += delta_error + Moment_Rate * all_layers[last_layer_index].moment_weights[neuron_index * (all_layers[last_layer_index].number_of_inputs) + j];
			all_layers[last_layer_index].moment_weights[neuron_index * (all_layers[last_layer_index].number_of_inputs) + j] = delta_error;
		}
		double delta_error = learning_constant * error_return * all_layers[last_layer_index].bias;
		all_layers[last_layer_index].weights[neuron_index * (all_layers[last_layer_index].number_of_inputs) + (all_layers[last_layer_index].number_of_inputs - 1)] += delta_error + Moment_Rate * all_layers[last_layer_index].moment_weights[neuron_index * (all_layers[last_layer_index].number_of_inputs) + (all_layers[last_layer_index].number_of_inputs - 1)];
		all_layers[last_layer_index].moment_weights[neuron_index * (all_layers[last_layer_index].number_of_inputs) + (all_layers[last_layer_index].number_of_inputs - 1)] = delta_error;
	}
	double out0 = all_layers[last_layer_index].weights[0];
	double out1 = all_layers[last_layer_index].weights[1];
	double out2 = all_layers[last_layer_index].weights[2];
	double out3 = all_layers[last_layer_index].weights[3];
	double out4 = all_layers[last_layer_index].weights[4];
	double out5 = all_layers[last_layer_index].weights[5];
	double out6 = all_layers[last_layer_index].weights[6];
	double out7 = all_layers[last_layer_index].weights[7];

	// all the hidden layers before the last layer
	// goes from last to first ( except first hidden layer )
	int last_hidden_layer_index = last_layer_index - 1;
	for (int index_layer = last_hidden_layer_index; index_layer > 0; index_layer--) {

		for (int neuron_index = 0; neuron_index < all_layers[index_layer].number_of_neurons; neuron_index++) {
			double S_next = 0.0;
			for (int k = 0; k < all_layers[index_layer + 1].number_of_neurons; k++) {
				S_next += all_layers[index_layer + 1].S[k] * all_layers[index_layer + 1].weights[k * (all_layers[index_layer + 1].number_of_inputs) + neuron_index];
			}
			all_layers[index_layer].S[neuron_index] = S_next * sigmoidDerivative(all_layers[index_layer].net[neuron_index], all_layers[index_layer].lambda);

			double learning_constant = all_layers[index_layer].learning_constant;
			double error_return = all_layers[index_layer].S[neuron_index];
			for (int j = 0; j < all_layers[index_layer].number_of_inputs - 1; j++) {
				double delta_error = learning_constant * error_return * all_layers[index_layer - 1].output[j];
				all_layers[index_layer].weights[neuron_index * (all_layers[index_layer].number_of_inputs) + j] += delta_error + Moment_Rate * all_layers[index_layer].moment_weights[neuron_index * (all_layers[index_layer].number_of_inputs) + j];
				all_layers[index_layer].moment_weights[neuron_index * (all_layers[index_layer].number_of_inputs) + j] = delta_error;
			}
			double delta_error = learning_constant * error_return * all_layers[index_layer].bias;
			all_layers[index_layer].weights[neuron_index * (all_layers[index_layer].number_of_inputs) + (all_layers[index_layer].number_of_inputs - 1)] += delta_error + Moment_Rate * all_layers[index_layer].moment_weights[neuron_index * (all_layers[index_layer].number_of_inputs) + (all_layers[index_layer].number_of_inputs - 1)];
			all_layers[index_layer].moment_weights[neuron_index * (all_layers[index_layer].number_of_inputs) + (all_layers[index_layer].number_of_inputs - 1)] = delta_error;
		}
	}

	// the first layer
	for (int neuron_index = 0; neuron_index < all_layers[0].number_of_neurons; neuron_index++) {
		double S_next = 0.0;
		for (int j = 0; j < all_layers[1].number_of_neurons; j++) {
			S_next += all_layers[1].S[j] * all_layers[1].weights[j * (all_layers[1].number_of_inputs) + neuron_index];
			double wi = all_layers[1].weights[j * (all_layers[1].number_of_inputs) + neuron_index];
		}
		all_layers[0].S[neuron_index] = S_next * sigmoidDerivative(all_layers[0].net[neuron_index], all_layers[0].lambda);

		double learning_constant = all_layers[0].learning_constant;
		double error_return = all_layers[0].S[neuron_index];
		for (int k = 0; k < all_layers[0].number_of_inputs - 1; k++) {
			double delta_error = learning_constant * error_return * point.x_coordinates[k];
			all_layers[0].weights[neuron_index * all_layers[0].number_of_inputs + k] += delta_error + Moment_Rate * all_layers[0].moment_weights[neuron_index * all_layers[0].number_of_inputs + k];
			all_layers[0].moment_weights[neuron_index * all_layers[0].number_of_inputs + k] = delta_error;
		}
		double delta_error = learning_constant * error_return * all_layers[0].bias;
		all_layers[0].weights[neuron_index * all_layers[0].number_of_inputs + (all_layers[0].number_of_inputs - 1)] += delta_error + Moment_Rate * all_layers[0].moment_weights[neuron_index * all_layers[0].number_of_inputs + (all_layers[0].number_of_inputs - 1)];
		all_layers[0].moment_weights[neuron_index * all_layers[0].number_of_inputs + (all_layers[0].number_of_inputs - 1)] = delta_error;
	}
}

//##############################################################################################################################################################################################################

double RMSE(double total_error, int total_points, int total_neurons_number) {
	return (double)(sqrt(0.5 * total_error) / (total_points * total_neurons_number));
}

//##############################################################################################################################################################################################################

void reset_net_values(Layer* all_layers, int total_layers) {
	for (int layer_index = 0; layer_index < total_layers; layer_index++) {
		for (int neuron_index = 0; neuron_index < all_layers[layer_index].number_of_neurons; neuron_index++) {
			all_layers[layer_index].net[neuron_index] = 0.0;
		}
	}
}
//##############################################################################################################################################################################################################
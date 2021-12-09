#include "Learning_Rules.h"

// perceptron learning
int perceptron_learning(Sample point, double* weight_array, int dimension, int class_number) {
	double* net_values = new double[class_number];;
	double* output_values = new double[class_number];;
	double bias = 1;
	int is_there_any_error;

	perceptron_feed_forwared(point, weight_array, dimension, class_number, net_values, output_values, bias);
	is_there_any_error = perceptron_back_propagation(point, weight_array, dimension, class_number, net_values, output_values, bias);
	return is_there_any_error;
}

//##############################################################################################################################################################################################################

void perceptron_feed_forwared(Sample point, double *weight_array, int dimension, int class_number, double *net, double *output, double bias) {
	
	// initial net 
	for (int i = 0; i < class_number; i++) {
		net[i] = 0;
	}

	// our dimension is equal to 2 but in weight matrix we add an additional column for bias weights so our column in weight matrix is equal to dimension + 1
	for (int i = 0; i < class_number; i++) {
		for (int j = 0; j < dimension; j++) {
			net[i] += weight_array[i * (dimension + 1) + j] * point.x_coordinates[j];
		}
		net[i] += weight_array[i * (dimension + 1) + dimension] * bias;
	}

	for (int i = 0; i < class_number; i++) {
		output[i] = sgn(net[i]);
	}
}

//##############################################################################################################################################################################################################

int perceptron_back_propagation(Sample point, double* weight_array, int dimension, int class_number, double* net, double* output, double bias) {
	int desired_output;
	double learning_constatn = 0.1f;

	int has_weights_get_updated = 0;
	// run for each class 
	for (int i = 0; i < class_number; i++) {
		
		// set desired output for specific class
		if (point.class_id == i)
			desired_output = 1;
		else
			desired_output = -1;
		
		// update weights if desired output is not equal to output and increase 'has_weights_get_updated' value to specify that weights get updated at that class
		if (output[i] != desired_output) {
			has_weights_get_updated++;
			for (int c = 0; c < dimension; c++) {
				weight_array[i * (dimension + 1) + c] += (learning_constatn * (desired_output - output[i]) * point.x_coordinates[c]);
			}
			weight_array[i * (dimension + 1) + dimension] += (learning_constatn * (desired_output - output[i]) * bias);

		}
	}

	if (has_weights_get_updated == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//##############################################################################################################################################################################################################
//sgn function
double sgn(double net) {
	return (net >= 0.0f) ? 1.0f : (-1.0f);
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
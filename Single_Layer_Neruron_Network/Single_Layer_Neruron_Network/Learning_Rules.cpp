#include "Learning_Rules.h"

// this is made up of two parts, feed_forward and back_propagation.
// First, feed forward part is invoked to find the required outputs and then the back propagation is called to update the weights based on the outputs.
int perceptron_learning(Sample point, double* weight_array, int dimension, int class_number) {
	double* net_values = new double[class_number];;
	double* output_values = new double[class_number];;
	double bias = 1;
	int is_there_any_error;

	perceptron_feed_forward(point, weight_array, dimension, class_number, net_values, output_values, bias);
	is_there_any_error = perceptron_back_propagation(point, weight_array, dimension, class_number, net_values, output_values, bias);

	delete[]net_values;
	delete[]output_values;
	return is_there_any_error;
}

//##############################################################################################################################################################################################################

// feed forward to find outputs in perceptron method
// calculate the sum of the weight matrix multiplied by the input sample matrix, and then give the sum values to ‘sign’ function and calculate the output
void perceptron_feed_forward(Sample point, double *weight_array, int dimension, int class_number, double *net, double *output, double bias) {
	
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

// update the weights for a neuron if the calculated output is not equal to desired output (our sample label ) otherwise there will be no change in weights .
// This function returns 1 if there is any change in weights and return 0 if there is no change in weighs.
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

// Sign function returns 1 if given value is greater than 0, and -1 if the given value is less than 0 (used in perceptron method)
double sgn(double net) {
	return (net >= 0.0f) ? 1.0f : (-1.0f);
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


// Again similar to perceptron_learning rule , the delta_learning rule  also is  made up of two parts, feed_forward and back_propagation. First, 
// feed forward part is invoked to find the required outputs and then the back propagation is called to update the weights based on the outputs.
double delta_learning(Sample point, double* weight_array, int dimension, int class_number) {
	double* net_values = new double[class_number];;
	double* output_values = new double[class_number];;
	double bias = 1;
	int lambda = 1;
	double error;

	delta_feed_forwared(point, weight_array, dimension, class_number, net_values, output_values, bias, lambda);
	error = delta_back_propagation(point, weight_array, dimension, class_number, net_values, output_values, bias, lambda);
	
	delete[]net_values;
	delete[]output_values;
	return error;
	

}

//##############################################################################################################################################################################################################

// outputs are calculated by giving the sum of the weight matrix multiplied by the input sample matrix, to ‘sigmoid’ function.
void delta_feed_forwared(Sample point, double* weight_array, int dimension, int class_number, double* net, double* output, double bias, int lambda){
	for (int i = 0; i < class_number; i++) {
		net[i] = 0;
	}

	for (int i = 0; i < class_number; i++) {
		for (int j = 0; j < dimension; j++) {
			net[i] += weight_array[j + i * (dimension + 1)] * point.x_coordinates[j];
		}
		net[i] += weight_array[i * (dimension + 1) + dimension] * bias;
	}

	for (int i = 0; i < class_number; i++) {
		output[i] = sigmoid(net[i], lambda);
	}
}

//##############################################################################################################################################################################################################

// error is calculated for each point and weights are updated immediately right after. This function returns the calculated error.
double delta_back_propagation(Sample point, double* weight_array, int dimension, int class_number, double* net, double* output, double bias, int lambda) {
	double desired_output;
	double learning_constatn = 0.1f;

	double error = 0;
	for (int i = 0; i < class_number; i++) {
		if (point.class_id == i)
			desired_output = 1;
		else
			desired_output = -1;

		// calculate error
		error += 0.5 * pow(desired_output - output[i], 2);
		// no matter what update the weights
		for (int c = 0; c < dimension; c++) {
			weight_array[i * (dimension + 1) + c] += (learning_constatn * (desired_output - output[i]) * sigmoidDerivative(net[i], lambda) * point.x_coordinates[c]);
		}
		weight_array[i * (dimension + 1) + dimension] += (learning_constatn * (desired_output - output[i]) * sigmoidDerivative(net[i], lambda) * bias);
	}

	return error;
}

//##############################################################################################################################################################################################################

double sigmoid(double net, int lambda) {
	return (2.0 / (1.0 + exp(lambda * (-net)))) - 1;
}

//##############################################################################################################################################################################################################

double sigmoidDerivative(double net, int lambda) {
	return 0.5 * (1 - pow(sigmoid(net, lambda), 2));
}

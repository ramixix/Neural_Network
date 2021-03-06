#include "Utils.h"

// check the user selection in combobox is valid
bool check_combobox_selection(char combobox_value) {
	char valid_values[8] = { '2', '3', '4', '5', '6', '7', '8', '9' };

	for (int i = 0; i < 8; i++) {
		if (combobox_value == valid_values[i])
			return true;

	}
	return false;
}

//#####################################################################################################################################

// realocate the points array and add the new added point
Sample* add_sample_to_points(Sample* points, int total_point, float x1, float x2, int class_id, int dimension) {
	Sample* new_points = new Sample[total_point];
	for (size_t i = 0; i < total_point; i++) {
		new_points[i].x_coordinates = new double[dimension];
	}

	int new_added_point_index = total_point - 1;

	for (int i = 0; i < new_added_point_index; i++) {
		for (int j = 0; j < dimension; j++) {
			new_points[i].x_coordinates[j] = points[i].x_coordinates[j];
		}
		new_points[i].class_id = points[i].class_id;
	}

	new_points[new_added_point_index].x_coordinates[0] = x1;
	new_points[new_added_point_index].x_coordinates[1] = x2;
	new_points[new_added_point_index].class_id = class_id;

	delete[] points;
	return new_points;
}

//#####################################################################################################################################

// find x2 in equation w0*x1 + w1*x2 + w3 = 0
// x2 = (-w3 - w0*x1) / w1
int find_y_point(int x, double w[], int constant) {
	return (int)((double)(-1 * constant * w[2] - w[0] * x) / (double)(w[1]));
}

//#####################################################################################################################################

// set random value as initial weights.
void set_random_value_to_array(double* array, int array_length) {
	srand(time(NULL));
	for (int i = 0; i < array_length; i++) {
		array[i] = (double)rand() / (double)RAND_MAX;
	}

}

//#####################################################################################################################################
// normalized points using z score normalization method (X- Xmean) / Xstd
void z_score_normalization(Sample* points, int total_point) {
	double x1_mean = 0, x2_mean = 0;
	double x1_standard_deviation = 0, x2_standard_deviation = 0;

	for (int i = 0; i < total_point; i++) {
		x1_mean += points[i].x_coordinates[0];
		x2_mean += points[i].x_coordinates[1];
	}

	x1_mean /= total_point;
	x2_mean /= total_point;

	for (int i = 0; i < total_point; i++) {
		x1_standard_deviation += pow((points[i].x_coordinates[0] - x1_mean), 2);
		x2_standard_deviation += pow((points[i].x_coordinates[1] - x2_mean), 2);
	}

	x1_standard_deviation /= (total_point - 1);
	x2_standard_deviation /= (total_point - 1);

	x1_standard_deviation = sqrt(x1_standard_deviation);
	x2_standard_deviation = sqrt(x2_standard_deviation);

	for (int i = 0; i < total_point; i++) {
		points[i].x_coordinates[0] = (points[i].x_coordinates[0] - x1_mean) / x1_standard_deviation;
		points[i].x_coordinates[1] = (points[i].x_coordinates[1] - x2_mean) / x2_standard_deviation;

	}
}
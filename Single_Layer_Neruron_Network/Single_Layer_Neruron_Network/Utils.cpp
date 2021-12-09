#include "Utils.h"



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

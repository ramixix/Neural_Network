#pragma once
#include <cmath>
#include <stdlib.h>
#include <time.h>

struct Sample {
	double* x_coordinates;
	int class_id;
};

bool check_combobox_selection(char combobox_value);
Sample* add_sample_to_points(Sample* points, int total_point, float x1, float x2, int class_id, int dimension);
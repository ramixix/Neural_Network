#include "Utils.h"



bool check_combobox_selection(char combobox_value) {
	char valid_values[8] = { '2', '3', '4', '5', '6', '7', '8', '9' };

	for (int i = 0; i < 8; i++) {
		if (combobox_value == valid_values[i])
			return true;

	}
	return false;
}
#include "../../headers/builder/MaterialBuilder.h"

MaterialBuilder::MaterialBuilder() {
	/*functions.insert(make_pair("Ka", KaBuilder::process));
	functions.insert(make_pair("Kd", KdBuilder::process));
	functions.insert(make_pair("Ks", KsBuilder::process));*/
}

MaterialBuilder::~MaterialBuilder() {}







_function* MaterialBuilder::function(string command) {
	_function* _func = &functions[command];

	if (_func) {
		return _func;
	}

	return NULL;
}

void MaterialBuilder::processLine(string command, stringstream& line) {
	_function* _func = function(command);

	if (_func != NULL) {
		(*_func)(line);
		return;
	}
}
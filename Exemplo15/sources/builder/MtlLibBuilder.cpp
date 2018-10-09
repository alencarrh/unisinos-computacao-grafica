#include "../../headers/builder/MtlLibBuilder.h"


void MtlLibBuilder::process(std::stringstream& line) {
	string name;
	line >> name;

	mtlFile->read(name);
}
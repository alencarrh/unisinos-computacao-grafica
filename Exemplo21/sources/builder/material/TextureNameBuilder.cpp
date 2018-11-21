#include "../../headers/builder/material/TextureNameBuilder.h"

TextureNameBuilder::TextureNameBuilder(MaterialMediator* mediator) {
	this->mediator = mediator;
}
TextureNameBuilder::~TextureNameBuilder() {}
void TextureNameBuilder::process(stringstream& line) {
	string name;
	line >> name;
	while (!line.eof()) {
		string temp;
		line >> temp;
		name += " " + temp;
	}

	this->mediator->callbackTextureName(name);

}

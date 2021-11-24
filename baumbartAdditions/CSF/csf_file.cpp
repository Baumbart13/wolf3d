//
// Created by Baumbart13 on 23.11.2021.
//

#include <fstream>
#include "rapidxml.hpp"

#include "csf_file.h"

using namespace Baumbart13::files::csf;

csf_file csf_file::parse(const std::filesystem::directory_entry &entry) {
	std::ifstream in();
	return {};
}

csf_file csf_file::parseFromXml(const std::filesystem::directory_entry &entry) {
	rapidxml::xml_document<> doc;
	rapidxml::xml_node<> *root_node = nullptr;

	return {};
}

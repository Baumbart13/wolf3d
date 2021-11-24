//
// Created by Baumbart13 on 23.11.2021.
//

#ifndef WOLF_OWN_CSF_FILE_H
#define WOLF_OWN_CSF_FILE_H

#include <string>
#include <cstdint>
#include <filesystem>
#include "csf.h"

namespace Baumbart13::files::csf {

	struct csf_label {
		std::string identifier[4];
		int32_t num_string_pairs = 1;
		int32_t label_name_length;
		std::string label_name;
	};

	struct csf_header {
		char identifier[4];
		int32_t version;
		int32_t num_labels;
		int32_t num_strings;
		csf_tag tag;
		csf_language language;
	};

	class csf_file {
	private:
		csf_header header;
		csf_label *labels;

	public:
		csf_file parse(const std::filesystem::directory_entry &entry);
		csf_file parseFromXml(const std::filesystem::directory_entry &entry);
	};
}

#endif //WOLF_OWN_CSF_FILE_H

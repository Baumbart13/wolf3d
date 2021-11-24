//
// Created by Baumbart13 on 23.11.2021.
//

#ifndef WOLF_OWN_CSF_H
#define WOLF_OWN_CSF_H

namespace Baumbart13::files::csf {
	enum csf_tag {
		nothing
	};

	enum csf_language : int32_t {
		english_us = 0,
		english_uk,
		german,
		french,
		spanish,
		italian,
		japanese,
		jabberwockie,
		korean,
		chinese,
		unknown
	};

	const char CSF_LABEL_IDENTIFIER[4] = {' ', 'L', 'B', 'L'};
	const char CSF_HEADER_IDENTIFIER[4] = {' ', 'F', 'S', 'C'};
}

#endif //WOLF_OWN_CSF_H

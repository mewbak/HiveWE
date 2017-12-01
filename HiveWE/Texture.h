#pragma once

class Texture : public Resource {
public:
	int width;
	int height;
	int channels;
	uint8_t* data;

	Texture(const std::string& path);

	virtual ~Texture() {
		delete[] data;
	}
};
#pragma once

struct TriggerCategory {
	int id;
	std::string name;
	bool is_comment;
};

struct TriggerVariable {
	std::string name;
	std::string type;
	bool is_array;
	int array_size = 0;
	bool is_initialized;
	std::string initial_value;
};

struct TriggerParameter;

struct TriggerSubParameter {
	int type;
	std::string name;
	bool begin_parameters;
	std::vector<TriggerParameter> parameters;
};

struct TriggerParameter {
	int type;
	std::string value;
	TriggerSubParameter sub_parameter;
	bool is_array = false;
	std::vector<TriggerParameter> parameters;
};

struct ECA {
	int type;
	int group;
	std::string name;
	bool enabled;
	std::vector<TriggerParameter> parameters;
	std::vector<ECA> ecas;
};

struct Trigger {
	int id;
	std::string name;
	std::string description;
	bool is_comment;
	bool is_enabled;
	std::string custom_text;
	bool initally_off;
	bool run_on_initialization;
	int category_id;
	std::vector<ECA> lines;
};

class Triggers {
	std::unordered_map<std::string, int> argument_counts;

public:
	std::string global_jass_comment;
	std::string global_jass;
	
	std::vector<TriggerCategory> categories;
	std::vector<TriggerVariable> variables;
	std::vector<Trigger> triggers;

	void load(BinaryReader& reader);
	void load_jass(BinaryReader& reader);

	void save() const;
	void save_jass() const;

	int next_id = 0;
};
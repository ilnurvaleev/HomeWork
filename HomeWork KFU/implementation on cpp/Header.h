#pragma once
bool is_get();
void get_form_data(char*& data);
void str_decode(char*& dec_str, const char* enc_str);
void get_param_value(char*& value, const char* param_name, const char* data);


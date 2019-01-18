#ifndef JDSON_LEPTJSON_H_
#define JDSON_LEPTJSON_H_


typedef enum {LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT} lept_jdson_type;

typedef struct {
    lept_jdson_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SIGULAR
};

int json_parse(lept_value *v, const char* json_str);


lept_jdson_type get_lept_json_type(const lept_value *v);


#endif // MACRO

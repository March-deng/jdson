#include <assert.h>  /* assert() */
#include <stdlib.h>  /* NULL */
#include "mleptjson.h"


typedef struct{
    const char* json_str;
}lept_context;

static int lept_parse_value(lept_value *v, lept_context* c) {
    switch (*c->json_str)
    {
        case 'n': return lept_parse_null(v, c);
        default:
            break;
    }
}

static int lept_parse_null(lept_value *v, lept_context* c) {

}

static int lept_parse_whitespace(lept_context* c) {
    const char* s = c->json_str;
    while(*s == ' '|| *s == '\t' || *s=='\n' || *s == '\r'){
        s++;
        c->json_str = s;
    }
}

int json_parse(lept_value *v, const char* json_str) {
    lept_context c;
    assert(v != NULL);
    c.json_str = json_str;
    v->type = LEPT_NULL;
    lept_parse_whitespace(&c);

    return lept_parse_value(v, &c);
}

lept_jdson_type get_lept_json_type(const lept_value *v) {
    assert(v != NULL);
    return v->type;
}
#include <ini.h>

int handler(void* context, const char* section, const char* name, const char* value) {
  return 1;
}

int main() {
  const char in[] = "; This is an INI file\n"
                    "[section1]  ; section comment\n"
                    "one=This is a test  ; name=value comment\n"
                    "two = 1234\n"
                    "; x=y\n"
                    "\n"
                    "[ section 2 ]\n"
                    "happy  =  4\n"
                    "sad =\n"
                    "\n"
                    "[empty]\n"
                    "; do nothing\n"
                    "\n"
                    "[comment_test]\n"
                    "test1 = 1;2;3 ; only this will be a comment\n"
                    "test2 = 2;3;4;this won't be a comment, needs whitespace before ';'\n"
                    "test;3 = 345 ; key should be \"test;3\"\n"
                    "test4 = 4#5#6 ; '#' only starts a comment at start of line\n"
                    "#test5 = 567 ; entire line commented\n"
                    " # test6 = 678 ; entire line commented, except in MULTILINE mode\n"
                    "test7 = ; blank value, except if inline comments disabled\n"
                    "test8 =; not a comment, needs whitespace before ';'\n"
                    "\n"
                    "[colon_tests]\n"
                    "Content-Type: text/html\n"
                    "foo:bar\n"
                    "adams : 42\n"
                    "funny1 : with = equals\n"
                    "funny2 = with : colons\n"
                    "funny3 = two = equals\n"
                    "funny4 : two : colons";

  return ini_parse_string(in, handler, NULL);
}

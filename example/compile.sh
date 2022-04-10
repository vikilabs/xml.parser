rm test_xml_parser
cd ../src
make
cd ../example
gcc test_xml_parser.c -I../src/ ../lib/xml_parser.a -o test_xml_parser

#ifndef ENTRYPOINT
#define ENTRYPOINT

#include <string>

extern "C" void entrypoint(std::string infile, std::string schema, std::string output_folder);

#endif // ENTRYPOINT
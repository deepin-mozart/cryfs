#include "ProgramOptions.h"
#include <cstring>
#include <messmer/cpp-utils/assert/assert.h>

using namespace cryfs::program_options;
using std::string;
using std::vector;

ProgramOptions::ProgramOptions(const string &baseDir, const string &mountDir, const vector<char*> &fuseOptions)
    :_baseDir(baseDir), _mountDir(new char[mountDir.size()+1]), _fuseOptions(fuseOptions) {
    std::memcpy(_mountDir, mountDir.c_str(), mountDir.size()+1);
    // Fuse needs the mountDir passed as first option (first option = position 1, since 0 is the executable name)
    ASSERT(_fuseOptions.size() >= 1, "There has to be one parameter at least for the executable name");
    _fuseOptions.insert(_fuseOptions.begin()+1, _mountDir);
}

ProgramOptions::~ProgramOptions() {
    delete[] _mountDir;
}

const string &ProgramOptions::baseDir() const {
    return _baseDir;
}

string ProgramOptions::mountDir() const {
    return string(_mountDir);
}

const vector<char *> &ProgramOptions::fuseOptions() const {
    return _fuseOptions;
}

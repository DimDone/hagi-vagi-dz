grep -r "#include <vector>" $(find ~ -name '*.cpp' -type f) | cut -d ':' -f 1

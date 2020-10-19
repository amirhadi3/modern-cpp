#include <iostream>

#ifdef __has_include
#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif
#if __has_include(<windows.h>)
#include <windows.h>
#elif __has_include(<unistd.h>)
#include <unistd.h>
#endif
#endif

int main() {
	fs::path p(R"(c:\)");
	std::cout << __cpp_inline_variables << std::endl;
	std::cout << __cpp_capture_star_this << std::endl;
	return 0;
}
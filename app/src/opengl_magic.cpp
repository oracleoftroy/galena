#include <cstdint>

#ifdef _WIN32

// these magic numbers are used by NVidia and AMD drivers to detect apps that would prefer
// descrete GPUs when creating an OpenGL context when multiple GPU devices are available.
// These must be in the main executable, not a dll.
// https://stackoverflow.com/questions/17458803/amd-equivalent-to-nvoptimusenablement

extern "C"
{
	// http://developer.download.nvidia.com/devzone/devcenter/gamegraphics/files/OptimusRenderingPolicies.pdf
	__declspec(dllexport) uint32_t NvOptimusEnablement = 1;

	// https://gpuopen.com/amdpowerxpressrequesthighperformance/
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

#endif

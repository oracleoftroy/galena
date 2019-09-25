#pragma once

#if !defined(VULKAN_H_)
#error "Please include vulkan/vulkan.h before including this file"
#endif

#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)

// Initialize the vulkan loader
// Requires loading vkGetInstnaceProcAddr via GetProcAddr(), dlsym(), SDL_Vulkan_GetVkGetInstanceProcAddr(), etc
// On completion, the following functions will be available: vkGetInstanceProcAddr, vkCreateInstance, vkEnumerateInstanceExtensionProperties, vkEnumerateInstanceLayerProperties
void vulkan_loader_init(PFN_vkGetInstanceProcAddr get_address);

// Load vulkan instance functions
// On completion, all vulkan functions will be available
void vulkan_load_instance_procs(VkInstance vulkan);

// Load vulkan device functions
// Optional: avoids indirection by loading functions for a specific device
void vulkan_load_device_procs(VkDevice device);

#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

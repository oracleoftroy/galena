#include <vulkan/vulkan.h>
#include <assert.h>

#if VK_HEADER_VERSION != 123
	#error "Vulkan header version does not match"
#endif

#if defined(VK_VERSION_1_0)

// Vulkan core API interface definitions

// Device initialization

static PFN_vkCreateInstance pfn_vkCreateInstance;
VKAPI_ATTR VkResult vkCreateInstance(const VkInstanceCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkInstance * pInstance)
{
	assert(pfn_vkCreateInstance);
	return pfn_vkCreateInstance(pCreateInfo, pAllocator, pInstance);
}

static PFN_vkDestroyInstance pfn_vkDestroyInstance;
VKAPI_ATTR void vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyInstance);
	pfn_vkDestroyInstance(instance, pAllocator);
}

static PFN_vkEnumeratePhysicalDevices pfn_vkEnumeratePhysicalDevices;
VKAPI_ATTR VkResult vkEnumeratePhysicalDevices(VkInstance instance, uint32_t * pPhysicalDeviceCount, VkPhysicalDevice * pPhysicalDevices)
{
	assert(pfn_vkEnumeratePhysicalDevices);
	return pfn_vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
}

static PFN_vkGetPhysicalDeviceFeatures pfn_vkGetPhysicalDeviceFeatures;
VKAPI_ATTR void vkGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures * pFeatures)
{
	assert(pfn_vkGetPhysicalDeviceFeatures);
	pfn_vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
}

static PFN_vkGetPhysicalDeviceFormatProperties pfn_vkGetPhysicalDeviceFormatProperties;
VKAPI_ATTR void vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties * pFormatProperties)
{
	assert(pfn_vkGetPhysicalDeviceFormatProperties);
	pfn_vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
}

static PFN_vkGetPhysicalDeviceImageFormatProperties pfn_vkGetPhysicalDeviceImageFormatProperties;
VKAPI_ATTR VkResult vkGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties * pImageFormatProperties)
{
	assert(pfn_vkGetPhysicalDeviceImageFormatProperties);
	return pfn_vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
}

static PFN_vkGetPhysicalDeviceProperties pfn_vkGetPhysicalDeviceProperties;
VKAPI_ATTR void vkGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceProperties);
	pfn_vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
}

static PFN_vkGetPhysicalDeviceQueueFamilyProperties pfn_vkGetPhysicalDeviceQueueFamilyProperties;
VKAPI_ATTR void vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t * pQueueFamilyPropertyCount, VkQueueFamilyProperties * pQueueFamilyProperties)
{
	assert(pfn_vkGetPhysicalDeviceQueueFamilyProperties);
	pfn_vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

static PFN_vkGetPhysicalDeviceMemoryProperties pfn_vkGetPhysicalDeviceMemoryProperties;
VKAPI_ATTR void vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties * pMemoryProperties)
{
	assert(pfn_vkGetPhysicalDeviceMemoryProperties);
	pfn_vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
}

static PFN_vkGetInstanceProcAddr pfn_vkGetInstanceProcAddr;
VKAPI_ATTR PFN_vkVoidFunction vkGetInstanceProcAddr(VkInstance instance, const char * pName)
{
	assert(pfn_vkGetInstanceProcAddr);
	return pfn_vkGetInstanceProcAddr(instance, pName);
}

static PFN_vkGetDeviceProcAddr pfn_vkGetDeviceProcAddr;
VKAPI_ATTR PFN_vkVoidFunction vkGetDeviceProcAddr(VkDevice device, const char * pName)
{
	assert(pfn_vkGetDeviceProcAddr);
	return pfn_vkGetDeviceProcAddr(device, pName);
}

// Device commands

static PFN_vkCreateDevice pfn_vkCreateDevice;
VKAPI_ATTR VkResult vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDevice * pDevice)
{
	assert(pfn_vkCreateDevice);
	return pfn_vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
}

static PFN_vkDestroyDevice pfn_vkDestroyDevice;
VKAPI_ATTR void vkDestroyDevice(VkDevice device, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyDevice);
	pfn_vkDestroyDevice(device, pAllocator);
}

// Extension discovery commands

static PFN_vkEnumerateInstanceExtensionProperties pfn_vkEnumerateInstanceExtensionProperties;
VKAPI_ATTR VkResult vkEnumerateInstanceExtensionProperties(const char * pLayerName, uint32_t * pPropertyCount, VkExtensionProperties * pProperties)
{
	assert(pfn_vkEnumerateInstanceExtensionProperties);
	return pfn_vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
}

static PFN_vkEnumerateDeviceExtensionProperties pfn_vkEnumerateDeviceExtensionProperties;
VKAPI_ATTR VkResult vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char * pLayerName, uint32_t * pPropertyCount, VkExtensionProperties * pProperties)
{
	assert(pfn_vkEnumerateDeviceExtensionProperties);
	return pfn_vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
}

// Layer discovery commands

static PFN_vkEnumerateInstanceLayerProperties pfn_vkEnumerateInstanceLayerProperties;
VKAPI_ATTR VkResult vkEnumerateInstanceLayerProperties(uint32_t * pPropertyCount, VkLayerProperties * pProperties)
{
	assert(pfn_vkEnumerateInstanceLayerProperties);
	return pfn_vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}

static PFN_vkEnumerateDeviceLayerProperties pfn_vkEnumerateDeviceLayerProperties;
VKAPI_ATTR VkResult vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkLayerProperties * pProperties)
{
	assert(pfn_vkEnumerateDeviceLayerProperties);
	return pfn_vkEnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
}

// queue commands

static PFN_vkGetDeviceQueue pfn_vkGetDeviceQueue;
VKAPI_ATTR void vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue * pQueue)
{
	assert(pfn_vkGetDeviceQueue);
	pfn_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}

static PFN_vkQueueSubmit pfn_vkQueueSubmit;
VKAPI_ATTR VkResult vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo * pSubmits, VkFence fence)
{
	assert(pfn_vkQueueSubmit);
	return pfn_vkQueueSubmit(queue, submitCount, pSubmits, fence);
}

static PFN_vkQueueWaitIdle pfn_vkQueueWaitIdle;
VKAPI_ATTR VkResult vkQueueWaitIdle(VkQueue queue)
{
	assert(pfn_vkQueueWaitIdle);
	return pfn_vkQueueWaitIdle(queue);
}

static PFN_vkDeviceWaitIdle pfn_vkDeviceWaitIdle;
VKAPI_ATTR VkResult vkDeviceWaitIdle(VkDevice device)
{
	assert(pfn_vkDeviceWaitIdle);
	return pfn_vkDeviceWaitIdle(device);
}

// Memory commands

static PFN_vkAllocateMemory pfn_vkAllocateMemory;
VKAPI_ATTR VkResult vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo * pAllocateInfo, const VkAllocationCallbacks * pAllocator, VkDeviceMemory * pMemory)
{
	assert(pfn_vkAllocateMemory);
	return pfn_vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
}

static PFN_vkFreeMemory pfn_vkFreeMemory;
VKAPI_ATTR void vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkFreeMemory);
	pfn_vkFreeMemory(device, memory, pAllocator);
}

static PFN_vkMapMemory pfn_vkMapMemory;
VKAPI_ATTR VkResult vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void ** ppData)
{
	assert(pfn_vkMapMemory);
	return pfn_vkMapMemory(device, memory, offset, size, flags, ppData);
}

static PFN_vkUnmapMemory pfn_vkUnmapMemory;
VKAPI_ATTR void vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
	assert(pfn_vkUnmapMemory);
	pfn_vkUnmapMemory(device, memory);
}

static PFN_vkFlushMappedMemoryRanges pfn_vkFlushMappedMemoryRanges;
VKAPI_ATTR VkResult vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange * pMemoryRanges)
{
	assert(pfn_vkFlushMappedMemoryRanges);
	return pfn_vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}

static PFN_vkInvalidateMappedMemoryRanges pfn_vkInvalidateMappedMemoryRanges;
VKAPI_ATTR VkResult vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange * pMemoryRanges)
{
	assert(pfn_vkInvalidateMappedMemoryRanges);
	return pfn_vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}

static PFN_vkGetDeviceMemoryCommitment pfn_vkGetDeviceMemoryCommitment;
VKAPI_ATTR void vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize * pCommittedMemoryInBytes)
{
	assert(pfn_vkGetDeviceMemoryCommitment);
	pfn_vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
}

// Memory management API commands

static PFN_vkBindBufferMemory pfn_vkBindBufferMemory;
VKAPI_ATTR VkResult vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
	assert(pfn_vkBindBufferMemory);
	return pfn_vkBindBufferMemory(device, buffer, memory, memoryOffset);
}

static PFN_vkBindImageMemory pfn_vkBindImageMemory;
VKAPI_ATTR VkResult vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
	assert(pfn_vkBindImageMemory);
	return pfn_vkBindImageMemory(device, image, memory, memoryOffset);
}

static PFN_vkGetBufferMemoryRequirements pfn_vkGetBufferMemoryRequirements;
VKAPI_ATTR void vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements * pMemoryRequirements)
{
	assert(pfn_vkGetBufferMemoryRequirements);
	pfn_vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
}

static PFN_vkGetImageMemoryRequirements pfn_vkGetImageMemoryRequirements;
VKAPI_ATTR void vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements * pMemoryRequirements)
{
	assert(pfn_vkGetImageMemoryRequirements);
	pfn_vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
}

// Sparse resource memory management API commands

static PFN_vkGetImageSparseMemoryRequirements pfn_vkGetImageSparseMemoryRequirements;
VKAPI_ATTR void vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t * pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements * pSparseMemoryRequirements)
{
	assert(pfn_vkGetImageSparseMemoryRequirements);
	pfn_vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

static PFN_vkGetPhysicalDeviceSparseImageFormatProperties pfn_vkGetPhysicalDeviceSparseImageFormatProperties;
VKAPI_ATTR void vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t * pPropertyCount, VkSparseImageFormatProperties * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceSparseImageFormatProperties);
	pfn_vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}

static PFN_vkQueueBindSparse pfn_vkQueueBindSparse;
VKAPI_ATTR VkResult vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo * pBindInfo, VkFence fence)
{
	assert(pfn_vkQueueBindSparse);
	return pfn_vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
}

// Fence commands

static PFN_vkCreateFence pfn_vkCreateFence;
VKAPI_ATTR VkResult vkCreateFence(VkDevice device, const VkFenceCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkFence * pFence)
{
	assert(pfn_vkCreateFence);
	return pfn_vkCreateFence(device, pCreateInfo, pAllocator, pFence);
}

static PFN_vkDestroyFence pfn_vkDestroyFence;
VKAPI_ATTR void vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyFence);
	pfn_vkDestroyFence(device, fence, pAllocator);
}

static PFN_vkResetFences pfn_vkResetFences;
VKAPI_ATTR VkResult vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence * pFences)
{
	assert(pfn_vkResetFences);
	return pfn_vkResetFences(device, fenceCount, pFences);
}

static PFN_vkGetFenceStatus pfn_vkGetFenceStatus;
VKAPI_ATTR VkResult vkGetFenceStatus(VkDevice device, VkFence fence)
{
	assert(pfn_vkGetFenceStatus);
	return pfn_vkGetFenceStatus(device, fence);
}

static PFN_vkWaitForFences pfn_vkWaitForFences;
VKAPI_ATTR VkResult vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence * pFences, VkBool32 waitAll, uint64_t timeout)
{
	assert(pfn_vkWaitForFences);
	return pfn_vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
}

// Queue semaphore commands

static PFN_vkCreateSemaphore pfn_vkCreateSemaphore;
VKAPI_ATTR VkResult vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSemaphore * pSemaphore)
{
	assert(pfn_vkCreateSemaphore);
	return pfn_vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
}

static PFN_vkDestroySemaphore pfn_vkDestroySemaphore;
VKAPI_ATTR void vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroySemaphore);
	pfn_vkDestroySemaphore(device, semaphore, pAllocator);
}

// Event commands

static PFN_vkCreateEvent pfn_vkCreateEvent;
VKAPI_ATTR VkResult vkCreateEvent(VkDevice device, const VkEventCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkEvent * pEvent)
{
	assert(pfn_vkCreateEvent);
	return pfn_vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
}

static PFN_vkDestroyEvent pfn_vkDestroyEvent;
VKAPI_ATTR void vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyEvent);
	pfn_vkDestroyEvent(device, event, pAllocator);
}

static PFN_vkGetEventStatus pfn_vkGetEventStatus;
VKAPI_ATTR VkResult vkGetEventStatus(VkDevice device, VkEvent event)
{
	assert(pfn_vkGetEventStatus);
	return pfn_vkGetEventStatus(device, event);
}

static PFN_vkSetEvent pfn_vkSetEvent;
VKAPI_ATTR VkResult vkSetEvent(VkDevice device, VkEvent event)
{
	assert(pfn_vkSetEvent);
	return pfn_vkSetEvent(device, event);
}

static PFN_vkResetEvent pfn_vkResetEvent;
VKAPI_ATTR VkResult vkResetEvent(VkDevice device, VkEvent event)
{
	assert(pfn_vkResetEvent);
	return pfn_vkResetEvent(device, event);
}

// Query commands

static PFN_vkCreateQueryPool pfn_vkCreateQueryPool;
VKAPI_ATTR VkResult vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkQueryPool * pQueryPool)
{
	assert(pfn_vkCreateQueryPool);
	return pfn_vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
}

static PFN_vkDestroyQueryPool pfn_vkDestroyQueryPool;
VKAPI_ATTR void vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyQueryPool);
	pfn_vkDestroyQueryPool(device, queryPool, pAllocator);
}

static PFN_vkGetQueryPoolResults pfn_vkGetQueryPoolResults;
VKAPI_ATTR VkResult vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void * pData, VkDeviceSize stride, VkQueryResultFlags flags)
{
	assert(pfn_vkGetQueryPoolResults);
	return pfn_vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
}

// Buffer commands

static PFN_vkCreateBuffer pfn_vkCreateBuffer;
VKAPI_ATTR VkResult vkCreateBuffer(VkDevice device, const VkBufferCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkBuffer * pBuffer)
{
	assert(pfn_vkCreateBuffer);
	return pfn_vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
}

static PFN_vkDestroyBuffer pfn_vkDestroyBuffer;
VKAPI_ATTR void vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyBuffer);
	pfn_vkDestroyBuffer(device, buffer, pAllocator);
}

// Buffer view commands

static PFN_vkCreateBufferView pfn_vkCreateBufferView;
VKAPI_ATTR VkResult vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkBufferView * pView)
{
	assert(pfn_vkCreateBufferView);
	return pfn_vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
}

static PFN_vkDestroyBufferView pfn_vkDestroyBufferView;
VKAPI_ATTR void vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyBufferView);
	pfn_vkDestroyBufferView(device, bufferView, pAllocator);
}

// Image commands

static PFN_vkCreateImage pfn_vkCreateImage;
VKAPI_ATTR VkResult vkCreateImage(VkDevice device, const VkImageCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkImage * pImage)
{
	assert(pfn_vkCreateImage);
	return pfn_vkCreateImage(device, pCreateInfo, pAllocator, pImage);
}

static PFN_vkDestroyImage pfn_vkDestroyImage;
VKAPI_ATTR void vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyImage);
	pfn_vkDestroyImage(device, image, pAllocator);
}

static PFN_vkGetImageSubresourceLayout pfn_vkGetImageSubresourceLayout;
VKAPI_ATTR void vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource * pSubresource, VkSubresourceLayout * pLayout)
{
	assert(pfn_vkGetImageSubresourceLayout);
	pfn_vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
}

// Image view commands

static PFN_vkCreateImageView pfn_vkCreateImageView;
VKAPI_ATTR VkResult vkCreateImageView(VkDevice device, const VkImageViewCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkImageView * pView)
{
	assert(pfn_vkCreateImageView);
	return pfn_vkCreateImageView(device, pCreateInfo, pAllocator, pView);
}

static PFN_vkDestroyImageView pfn_vkDestroyImageView;
VKAPI_ATTR void vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyImageView);
	pfn_vkDestroyImageView(device, imageView, pAllocator);
}

// Shader commands

static PFN_vkCreateShaderModule pfn_vkCreateShaderModule;
VKAPI_ATTR VkResult vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkShaderModule * pShaderModule)
{
	assert(pfn_vkCreateShaderModule);
	return pfn_vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
}

static PFN_vkDestroyShaderModule pfn_vkDestroyShaderModule;
VKAPI_ATTR void vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyShaderModule);
	pfn_vkDestroyShaderModule(device, shaderModule, pAllocator);
}

// Pipeline Cache commands

static PFN_vkCreatePipelineCache pfn_vkCreatePipelineCache;
VKAPI_ATTR VkResult vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkPipelineCache * pPipelineCache)
{
	assert(pfn_vkCreatePipelineCache);
	return pfn_vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
}

static PFN_vkDestroyPipelineCache pfn_vkDestroyPipelineCache;
VKAPI_ATTR void vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyPipelineCache);
	pfn_vkDestroyPipelineCache(device, pipelineCache, pAllocator);
}

static PFN_vkGetPipelineCacheData pfn_vkGetPipelineCacheData;
VKAPI_ATTR VkResult vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t * pDataSize, void * pData)
{
	assert(pfn_vkGetPipelineCacheData);
	return pfn_vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
}

static PFN_vkMergePipelineCaches pfn_vkMergePipelineCaches;
VKAPI_ATTR VkResult vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache * pSrcCaches)
{
	assert(pfn_vkMergePipelineCaches);
	return pfn_vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
}

// Pipeline commands

static PFN_vkCreateGraphicsPipelines pfn_vkCreateGraphicsPipelines;
VKAPI_ATTR VkResult vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo * pCreateInfos, const VkAllocationCallbacks * pAllocator, VkPipeline * pPipelines)
{
	assert(pfn_vkCreateGraphicsPipelines);
	return pfn_vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}

static PFN_vkCreateComputePipelines pfn_vkCreateComputePipelines;
VKAPI_ATTR VkResult vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo * pCreateInfos, const VkAllocationCallbacks * pAllocator, VkPipeline * pPipelines)
{
	assert(pfn_vkCreateComputePipelines);
	return pfn_vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}

static PFN_vkDestroyPipeline pfn_vkDestroyPipeline;
VKAPI_ATTR void vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyPipeline);
	pfn_vkDestroyPipeline(device, pipeline, pAllocator);
}

// Pipeline layout commands

static PFN_vkCreatePipelineLayout pfn_vkCreatePipelineLayout;
VKAPI_ATTR VkResult vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkPipelineLayout * pPipelineLayout)
{
	assert(pfn_vkCreatePipelineLayout);
	return pfn_vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
}

static PFN_vkDestroyPipelineLayout pfn_vkDestroyPipelineLayout;
VKAPI_ATTR void vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyPipelineLayout);
	pfn_vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
}

// Sampler commands

static PFN_vkCreateSampler pfn_vkCreateSampler;
VKAPI_ATTR VkResult vkCreateSampler(VkDevice device, const VkSamplerCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSampler * pSampler)
{
	assert(pfn_vkCreateSampler);
	return pfn_vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
}

static PFN_vkDestroySampler pfn_vkDestroySampler;
VKAPI_ATTR void vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroySampler);
	pfn_vkDestroySampler(device, sampler, pAllocator);
}

// Descriptor set commands

static PFN_vkCreateDescriptorSetLayout pfn_vkCreateDescriptorSetLayout;
VKAPI_ATTR VkResult vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDescriptorSetLayout * pSetLayout)
{
	assert(pfn_vkCreateDescriptorSetLayout);
	return pfn_vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
}

static PFN_vkDestroyDescriptorSetLayout pfn_vkDestroyDescriptorSetLayout;
VKAPI_ATTR void vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyDescriptorSetLayout);
	pfn_vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
}

static PFN_vkCreateDescriptorPool pfn_vkCreateDescriptorPool;
VKAPI_ATTR VkResult vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDescriptorPool * pDescriptorPool)
{
	assert(pfn_vkCreateDescriptorPool);
	return pfn_vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
}

static PFN_vkDestroyDescriptorPool pfn_vkDestroyDescriptorPool;
VKAPI_ATTR void vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyDescriptorPool);
	pfn_vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
}

static PFN_vkResetDescriptorPool pfn_vkResetDescriptorPool;
VKAPI_ATTR VkResult vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags)
{
	assert(pfn_vkResetDescriptorPool);
	return pfn_vkResetDescriptorPool(device, descriptorPool, flags);
}

static PFN_vkAllocateDescriptorSets pfn_vkAllocateDescriptorSets;
VKAPI_ATTR VkResult vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo * pAllocateInfo, VkDescriptorSet * pDescriptorSets)
{
	assert(pfn_vkAllocateDescriptorSets);
	return pfn_vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
}

static PFN_vkFreeDescriptorSets pfn_vkFreeDescriptorSets;
VKAPI_ATTR VkResult vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet * pDescriptorSets)
{
	assert(pfn_vkFreeDescriptorSets);
	return pfn_vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
}

static PFN_vkUpdateDescriptorSets pfn_vkUpdateDescriptorSets;
VKAPI_ATTR void vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet * pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet * pDescriptorCopies)
{
	assert(pfn_vkUpdateDescriptorSets);
	pfn_vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

// Pass commands

static PFN_vkCreateFramebuffer pfn_vkCreateFramebuffer;
VKAPI_ATTR VkResult vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkFramebuffer * pFramebuffer)
{
	assert(pfn_vkCreateFramebuffer);
	return pfn_vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
}

static PFN_vkDestroyFramebuffer pfn_vkDestroyFramebuffer;
VKAPI_ATTR void vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyFramebuffer);
	pfn_vkDestroyFramebuffer(device, framebuffer, pAllocator);
}

static PFN_vkCreateRenderPass pfn_vkCreateRenderPass;
VKAPI_ATTR VkResult vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkRenderPass * pRenderPass)
{
	assert(pfn_vkCreateRenderPass);
	return pfn_vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
}

static PFN_vkDestroyRenderPass pfn_vkDestroyRenderPass;
VKAPI_ATTR void vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyRenderPass);
	pfn_vkDestroyRenderPass(device, renderPass, pAllocator);
}

static PFN_vkGetRenderAreaGranularity pfn_vkGetRenderAreaGranularity;
VKAPI_ATTR void vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D * pGranularity)
{
	assert(pfn_vkGetRenderAreaGranularity);
	pfn_vkGetRenderAreaGranularity(device, renderPass, pGranularity);
}

// Command pool commands

static PFN_vkCreateCommandPool pfn_vkCreateCommandPool;
VKAPI_ATTR VkResult vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkCommandPool * pCommandPool)
{
	assert(pfn_vkCreateCommandPool);
	return pfn_vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
}

static PFN_vkDestroyCommandPool pfn_vkDestroyCommandPool;
VKAPI_ATTR void vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyCommandPool);
	pfn_vkDestroyCommandPool(device, commandPool, pAllocator);
}

static PFN_vkResetCommandPool pfn_vkResetCommandPool;
VKAPI_ATTR VkResult vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags)
{
	assert(pfn_vkResetCommandPool);
	return pfn_vkResetCommandPool(device, commandPool, flags);
}

// Command buffer commands

static PFN_vkAllocateCommandBuffers pfn_vkAllocateCommandBuffers;
VKAPI_ATTR VkResult vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo * pAllocateInfo, VkCommandBuffer * pCommandBuffers)
{
	assert(pfn_vkAllocateCommandBuffers);
	return pfn_vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
}

static PFN_vkFreeCommandBuffers pfn_vkFreeCommandBuffers;
VKAPI_ATTR void vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer * pCommandBuffers)
{
	assert(pfn_vkFreeCommandBuffers);
	pfn_vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
}

static PFN_vkBeginCommandBuffer pfn_vkBeginCommandBuffer;
VKAPI_ATTR VkResult vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo * pBeginInfo)
{
	assert(pfn_vkBeginCommandBuffer);
	return pfn_vkBeginCommandBuffer(commandBuffer, pBeginInfo);
}

static PFN_vkEndCommandBuffer pfn_vkEndCommandBuffer;
VKAPI_ATTR VkResult vkEndCommandBuffer(VkCommandBuffer commandBuffer)
{
	assert(pfn_vkEndCommandBuffer);
	return pfn_vkEndCommandBuffer(commandBuffer);
}

static PFN_vkResetCommandBuffer pfn_vkResetCommandBuffer;
VKAPI_ATTR VkResult vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags)
{
	assert(pfn_vkResetCommandBuffer);
	return pfn_vkResetCommandBuffer(commandBuffer, flags);
}

// Command buffer building commands

static PFN_vkCmdBindPipeline pfn_vkCmdBindPipeline;
VKAPI_ATTR void vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline)
{
	assert(pfn_vkCmdBindPipeline);
	pfn_vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

static PFN_vkCmdSetViewport pfn_vkCmdSetViewport;
VKAPI_ATTR void vkCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport * pViewports)
{
	assert(pfn_vkCmdSetViewport);
	pfn_vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}

static PFN_vkCmdSetScissor pfn_vkCmdSetScissor;
VKAPI_ATTR void vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D * pScissors)
{
	assert(pfn_vkCmdSetScissor);
	pfn_vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}

static PFN_vkCmdSetLineWidth pfn_vkCmdSetLineWidth;
VKAPI_ATTR void vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth)
{
	assert(pfn_vkCmdSetLineWidth);
	pfn_vkCmdSetLineWidth(commandBuffer, lineWidth);
}

static PFN_vkCmdSetDepthBias pfn_vkCmdSetDepthBias;
VKAPI_ATTR void vkCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
{
	assert(pfn_vkCmdSetDepthBias);
	pfn_vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

static PFN_vkCmdSetBlendConstants pfn_vkCmdSetBlendConstants;
VKAPI_ATTR void vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants [4])
{
	assert(pfn_vkCmdSetBlendConstants);
	pfn_vkCmdSetBlendConstants(commandBuffer, blendConstants);
}

static PFN_vkCmdSetDepthBounds pfn_vkCmdSetDepthBounds;
VKAPI_ATTR void vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds)
{
	assert(pfn_vkCmdSetDepthBounds);
	pfn_vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}

static PFN_vkCmdSetStencilCompareMask pfn_vkCmdSetStencilCompareMask;
VKAPI_ATTR void vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask)
{
	assert(pfn_vkCmdSetStencilCompareMask);
	pfn_vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}

static PFN_vkCmdSetStencilWriteMask pfn_vkCmdSetStencilWriteMask;
VKAPI_ATTR void vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask)
{
	assert(pfn_vkCmdSetStencilWriteMask);
	pfn_vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}

static PFN_vkCmdSetStencilReference pfn_vkCmdSetStencilReference;
VKAPI_ATTR void vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference)
{
	assert(pfn_vkCmdSetStencilReference);
	pfn_vkCmdSetStencilReference(commandBuffer, faceMask, reference);
}

static PFN_vkCmdBindDescriptorSets pfn_vkCmdBindDescriptorSets;
VKAPI_ATTR void vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet * pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t * pDynamicOffsets)
{
	assert(pfn_vkCmdBindDescriptorSets);
	pfn_vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

static PFN_vkCmdBindIndexBuffer pfn_vkCmdBindIndexBuffer;
VKAPI_ATTR void vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType)
{
	assert(pfn_vkCmdBindIndexBuffer);
	pfn_vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}

static PFN_vkCmdBindVertexBuffers pfn_vkCmdBindVertexBuffers;
VKAPI_ATTR void vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer * pBuffers, const VkDeviceSize * pOffsets)
{
	assert(pfn_vkCmdBindVertexBuffers);
	pfn_vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

static PFN_vkCmdDraw pfn_vkCmdDraw;
VKAPI_ATTR void vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
{
	assert(pfn_vkCmdDraw);
	pfn_vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

static PFN_vkCmdDrawIndexed pfn_vkCmdDrawIndexed;
VKAPI_ATTR void vkCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance)
{
	assert(pfn_vkCmdDrawIndexed);
	pfn_vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

static PFN_vkCmdDrawIndirect pfn_vkCmdDrawIndirect;
VKAPI_ATTR void vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
	assert(pfn_vkCmdDrawIndirect);
	pfn_vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

static PFN_vkCmdDrawIndexedIndirect pfn_vkCmdDrawIndexedIndirect;
VKAPI_ATTR void vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
	assert(pfn_vkCmdDrawIndexedIndirect);
	pfn_vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}

static PFN_vkCmdDispatch pfn_vkCmdDispatch;
VKAPI_ATTR void vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
	assert(pfn_vkCmdDispatch);
	pfn_vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}

static PFN_vkCmdDispatchIndirect pfn_vkCmdDispatchIndirect;
VKAPI_ATTR void vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset)
{
	assert(pfn_vkCmdDispatchIndirect);
	pfn_vkCmdDispatchIndirect(commandBuffer, buffer, offset);
}

static PFN_vkCmdCopyBuffer pfn_vkCmdCopyBuffer;
VKAPI_ATTR void vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy * pRegions)
{
	assert(pfn_vkCmdCopyBuffer);
	pfn_vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

static PFN_vkCmdCopyImage pfn_vkCmdCopyImage;
VKAPI_ATTR void vkCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy * pRegions)
{
	assert(pfn_vkCmdCopyImage);
	pfn_vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

static PFN_vkCmdBlitImage pfn_vkCmdBlitImage;
VKAPI_ATTR void vkCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit * pRegions, VkFilter filter)
{
	assert(pfn_vkCmdBlitImage);
	pfn_vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

static PFN_vkCmdCopyBufferToImage pfn_vkCmdCopyBufferToImage;
VKAPI_ATTR void vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy * pRegions)
{
	assert(pfn_vkCmdCopyBufferToImage);
	pfn_vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

static PFN_vkCmdCopyImageToBuffer pfn_vkCmdCopyImageToBuffer;
VKAPI_ATTR void vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy * pRegions)
{
	assert(pfn_vkCmdCopyImageToBuffer);
	pfn_vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

static PFN_vkCmdUpdateBuffer pfn_vkCmdUpdateBuffer;
VKAPI_ATTR void vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void * pData)
{
	assert(pfn_vkCmdUpdateBuffer);
	pfn_vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

// transfer support is only available when VK_KHR_maintenance1 is enabled, as documented in valid usage language in the specification
static PFN_vkCmdFillBuffer pfn_vkCmdFillBuffer;
VKAPI_ATTR void vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{
	assert(pfn_vkCmdFillBuffer);
	pfn_vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}

static PFN_vkCmdClearColorImage pfn_vkCmdClearColorImage;
VKAPI_ATTR void vkCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue * pColor, uint32_t rangeCount, const VkImageSubresourceRange * pRanges)
{
	assert(pfn_vkCmdClearColorImage);
	pfn_vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

static PFN_vkCmdClearDepthStencilImage pfn_vkCmdClearDepthStencilImage;
VKAPI_ATTR void vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue * pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange * pRanges)
{
	assert(pfn_vkCmdClearDepthStencilImage);
	pfn_vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

static PFN_vkCmdClearAttachments pfn_vkCmdClearAttachments;
VKAPI_ATTR void vkCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment * pAttachments, uint32_t rectCount, const VkClearRect * pRects)
{
	assert(pfn_vkCmdClearAttachments);
	pfn_vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

static PFN_vkCmdResolveImage pfn_vkCmdResolveImage;
VKAPI_ATTR void vkCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve * pRegions)
{
	assert(pfn_vkCmdResolveImage);
	pfn_vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

static PFN_vkCmdSetEvent pfn_vkCmdSetEvent;
VKAPI_ATTR void vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
	assert(pfn_vkCmdSetEvent);
	pfn_vkCmdSetEvent(commandBuffer, event, stageMask);
}

static PFN_vkCmdResetEvent pfn_vkCmdResetEvent;
VKAPI_ATTR void vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask)
{
	assert(pfn_vkCmdResetEvent);
	pfn_vkCmdResetEvent(commandBuffer, event, stageMask);
}

static PFN_vkCmdWaitEvents pfn_vkCmdWaitEvents;
VKAPI_ATTR void vkCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent * pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier * pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier * pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier * pImageMemoryBarriers)
{
	assert(pfn_vkCmdWaitEvents);
	pfn_vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

static PFN_vkCmdPipelineBarrier pfn_vkCmdPipelineBarrier;
VKAPI_ATTR void vkCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier * pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier * pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier * pImageMemoryBarriers)
{
	assert(pfn_vkCmdPipelineBarrier);
	pfn_vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

static PFN_vkCmdBeginQuery pfn_vkCmdBeginQuery;
VKAPI_ATTR void vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags)
{
	assert(pfn_vkCmdBeginQuery);
	pfn_vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
}

static PFN_vkCmdEndQuery pfn_vkCmdEndQuery;
VKAPI_ATTR void vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query)
{
	assert(pfn_vkCmdEndQuery);
	pfn_vkCmdEndQuery(commandBuffer, queryPool, query);
}

static PFN_vkCmdResetQueryPool pfn_vkCmdResetQueryPool;
VKAPI_ATTR void vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
	assert(pfn_vkCmdResetQueryPool);
	pfn_vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}

static PFN_vkCmdWriteTimestamp pfn_vkCmdWriteTimestamp;
VKAPI_ATTR void vkCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query)
{
	assert(pfn_vkCmdWriteTimestamp);
	pfn_vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}

static PFN_vkCmdCopyQueryPoolResults pfn_vkCmdCopyQueryPoolResults;
VKAPI_ATTR void vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags)
{
	assert(pfn_vkCmdCopyQueryPoolResults);
	pfn_vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

static PFN_vkCmdPushConstants pfn_vkCmdPushConstants;
VKAPI_ATTR void vkCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void * pValues)
{
	assert(pfn_vkCmdPushConstants);
	pfn_vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}

static PFN_vkCmdBeginRenderPass pfn_vkCmdBeginRenderPass;
VKAPI_ATTR void vkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo * pRenderPassBegin, VkSubpassContents contents)
{
	assert(pfn_vkCmdBeginRenderPass);
	pfn_vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}

static PFN_vkCmdNextSubpass pfn_vkCmdNextSubpass;
VKAPI_ATTR void vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents)
{
	assert(pfn_vkCmdNextSubpass);
	pfn_vkCmdNextSubpass(commandBuffer, contents);
}

static PFN_vkCmdEndRenderPass pfn_vkCmdEndRenderPass;
VKAPI_ATTR void vkCmdEndRenderPass(VkCommandBuffer commandBuffer)
{
	assert(pfn_vkCmdEndRenderPass);
	pfn_vkCmdEndRenderPass(commandBuffer);
}

static PFN_vkCmdExecuteCommands pfn_vkCmdExecuteCommands;
VKAPI_ATTR void vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer * pCommandBuffers)
{
	assert(pfn_vkCmdExecuteCommands);
	pfn_vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}

#endif // defined(VK_VERSION_1_0)

#if defined(VK_VERSION_1_1)

// Vulkan 1.1 core API interface definitions.

// Device Initialization

static PFN_vkEnumerateInstanceVersion pfn_vkEnumerateInstanceVersion;
VKAPI_ATTR VkResult vkEnumerateInstanceVersion(uint32_t * pApiVersion)
{
	assert(pfn_vkEnumerateInstanceVersion);
	return pfn_vkEnumerateInstanceVersion(pApiVersion);
}

// Promoted from VK_KHR_bind_memory2

static PFN_vkBindBufferMemory2 pfn_vkBindBufferMemory2;
VKAPI_ATTR VkResult vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo * pBindInfos)
{
	assert(pfn_vkBindBufferMemory2);
	return pfn_vkBindBufferMemory2(device, bindInfoCount, pBindInfos);
}

static PFN_vkBindImageMemory2 pfn_vkBindImageMemory2;
VKAPI_ATTR VkResult vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo * pBindInfos)
{
	assert(pfn_vkBindImageMemory2);
	return pfn_vkBindImageMemory2(device, bindInfoCount, pBindInfos);
}

// Promoted from VK_KHR_device_group

static PFN_vkGetDeviceGroupPeerMemoryFeatures pfn_vkGetDeviceGroupPeerMemoryFeatures;
VKAPI_ATTR void vkGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags * pPeerMemoryFeatures)
{
	assert(pfn_vkGetDeviceGroupPeerMemoryFeatures);
	pfn_vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

static PFN_vkCmdSetDeviceMask pfn_vkCmdSetDeviceMask;
VKAPI_ATTR void vkCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask)
{
	assert(pfn_vkCmdSetDeviceMask);
	pfn_vkCmdSetDeviceMask(commandBuffer, deviceMask);
}

static PFN_vkCmdDispatchBase pfn_vkCmdDispatchBase;
VKAPI_ATTR void vkCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
	assert(pfn_vkCmdDispatchBase);
	pfn_vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

// Promoted from VK_KHR_device_group_creation

static PFN_vkEnumeratePhysicalDeviceGroups pfn_vkEnumeratePhysicalDeviceGroups;
VKAPI_ATTR VkResult vkEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t * pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties * pPhysicalDeviceGroupProperties)
{
	assert(pfn_vkEnumeratePhysicalDeviceGroups);
	return pfn_vkEnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
}

// Promoted from VK_KHR_get_memory_requirements2

static PFN_vkGetImageMemoryRequirements2 pfn_vkGetImageMemoryRequirements2;
VKAPI_ATTR void vkGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2 * pInfo, VkMemoryRequirements2 * pMemoryRequirements)
{
	assert(pfn_vkGetImageMemoryRequirements2);
	pfn_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
}

static PFN_vkGetBufferMemoryRequirements2 pfn_vkGetBufferMemoryRequirements2;
VKAPI_ATTR void vkGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2 * pInfo, VkMemoryRequirements2 * pMemoryRequirements)
{
	assert(pfn_vkGetBufferMemoryRequirements2);
	pfn_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
}

static PFN_vkGetImageSparseMemoryRequirements2 pfn_vkGetImageSparseMemoryRequirements2;
VKAPI_ATTR void vkGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2 * pInfo, uint32_t * pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 * pSparseMemoryRequirements)
{
	assert(pfn_vkGetImageSparseMemoryRequirements2);
	pfn_vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

// Promoted from VK_KHR_get_physical_device_properties2

static PFN_vkGetPhysicalDeviceFeatures2 pfn_vkGetPhysicalDeviceFeatures2;
VKAPI_ATTR void vkGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2 * pFeatures)
{
	assert(pfn_vkGetPhysicalDeviceFeatures2);
	pfn_vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
}

static PFN_vkGetPhysicalDeviceProperties2 pfn_vkGetPhysicalDeviceProperties2;
VKAPI_ATTR void vkGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2 * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceProperties2);
	pfn_vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
}

static PFN_vkGetPhysicalDeviceFormatProperties2 pfn_vkGetPhysicalDeviceFormatProperties2;
VKAPI_ATTR void vkGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2 * pFormatProperties)
{
	assert(pfn_vkGetPhysicalDeviceFormatProperties2);
	pfn_vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
}

static PFN_vkGetPhysicalDeviceImageFormatProperties2 pfn_vkGetPhysicalDeviceImageFormatProperties2;
VKAPI_ATTR VkResult vkGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2 * pImageFormatInfo, VkImageFormatProperties2 * pImageFormatProperties)
{
	assert(pfn_vkGetPhysicalDeviceImageFormatProperties2);
	return pfn_vkGetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
}

static PFN_vkGetPhysicalDeviceQueueFamilyProperties2 pfn_vkGetPhysicalDeviceQueueFamilyProperties2;
VKAPI_ATTR void vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t * pQueueFamilyPropertyCount, VkQueueFamilyProperties2 * pQueueFamilyProperties)
{
	assert(pfn_vkGetPhysicalDeviceQueueFamilyProperties2);
	pfn_vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

static PFN_vkGetPhysicalDeviceMemoryProperties2 pfn_vkGetPhysicalDeviceMemoryProperties2;
VKAPI_ATTR void vkGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2 * pMemoryProperties)
{
	assert(pfn_vkGetPhysicalDeviceMemoryProperties2);
	pfn_vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
}

static PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 pfn_vkGetPhysicalDeviceSparseImageFormatProperties2;
VKAPI_ATTR void vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2 * pFormatInfo, uint32_t * pPropertyCount, VkSparseImageFormatProperties2 * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceSparseImageFormatProperties2);
	pfn_vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

// Promoted from VK_KHR_maintenance1

static PFN_vkTrimCommandPool pfn_vkTrimCommandPool;
VKAPI_ATTR void vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags)
{
	assert(pfn_vkTrimCommandPool);
	pfn_vkTrimCommandPool(device, commandPool, flags);
}

// Originally based on VK_KHR_protected_memory (extension 146), which was never published; thus the mystifying large value= numbers below. These are not aliased since they weren't actually promoted from an extension.

static PFN_vkGetDeviceQueue2 pfn_vkGetDeviceQueue2;
VKAPI_ATTR void vkGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2 * pQueueInfo, VkQueue * pQueue)
{
	assert(pfn_vkGetDeviceQueue2);
	pfn_vkGetDeviceQueue2(device, pQueueInfo, pQueue);
}

// Promoted from VK_KHR_sampler_ycbcr_conversion

static PFN_vkCreateSamplerYcbcrConversion pfn_vkCreateSamplerYcbcrConversion;
VKAPI_ATTR VkResult vkCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSamplerYcbcrConversion * pYcbcrConversion)
{
	assert(pfn_vkCreateSamplerYcbcrConversion);
	return pfn_vkCreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
}

static PFN_vkDestroySamplerYcbcrConversion pfn_vkDestroySamplerYcbcrConversion;
VKAPI_ATTR void vkDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroySamplerYcbcrConversion);
	pfn_vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
}

// Promoted from VK_KHR_descriptor_update_template

static PFN_vkCreateDescriptorUpdateTemplate pfn_vkCreateDescriptorUpdateTemplate;
VKAPI_ATTR VkResult vkCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDescriptorUpdateTemplate * pDescriptorUpdateTemplate)
{
	assert(pfn_vkCreateDescriptorUpdateTemplate);
	return pfn_vkCreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
}

static PFN_vkDestroyDescriptorUpdateTemplate pfn_vkDestroyDescriptorUpdateTemplate;
VKAPI_ATTR void vkDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyDescriptorUpdateTemplate);
	pfn_vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
}

static PFN_vkUpdateDescriptorSetWithTemplate pfn_vkUpdateDescriptorSetWithTemplate;
VKAPI_ATTR void vkUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void * pData)
{
	assert(pfn_vkUpdateDescriptorSetWithTemplate);
	pfn_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
}

// Promoted from VK_KHR_external_memory_capabilities

static PFN_vkGetPhysicalDeviceExternalBufferProperties pfn_vkGetPhysicalDeviceExternalBufferProperties;
VKAPI_ATTR void vkGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo * pExternalBufferInfo, VkExternalBufferProperties * pExternalBufferProperties)
{
	assert(pfn_vkGetPhysicalDeviceExternalBufferProperties);
	pfn_vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

// Promoted from VK_KHR_external_fence_capabilities

static PFN_vkGetPhysicalDeviceExternalFenceProperties pfn_vkGetPhysicalDeviceExternalFenceProperties;
VKAPI_ATTR void vkGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo * pExternalFenceInfo, VkExternalFenceProperties * pExternalFenceProperties)
{
	assert(pfn_vkGetPhysicalDeviceExternalFenceProperties);
	pfn_vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

// Promoted from VK_KHR_external_semaphore_capabilities

static PFN_vkGetPhysicalDeviceExternalSemaphoreProperties pfn_vkGetPhysicalDeviceExternalSemaphoreProperties;
VKAPI_ATTR void vkGetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo * pExternalSemaphoreInfo, VkExternalSemaphoreProperties * pExternalSemaphoreProperties)
{
	assert(pfn_vkGetPhysicalDeviceExternalSemaphoreProperties);
	pfn_vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

// Promoted from VK_KHR_maintenance3

static PFN_vkGetDescriptorSetLayoutSupport pfn_vkGetDescriptorSetLayoutSupport;
VKAPI_ATTR void vkGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo * pCreateInfo, VkDescriptorSetLayoutSupport * pSupport)
{
	assert(pfn_vkGetDescriptorSetLayoutSupport);
	pfn_vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
}

#endif // defined(VK_VERSION_1_1)

#if defined(VK_KHR_surface)

static PFN_vkDestroySurfaceKHR pfn_vkDestroySurfaceKHR;
VKAPI_ATTR void vkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroySurfaceKHR);
	pfn_vkDestroySurfaceKHR(instance, surface, pAllocator);
}

static PFN_vkGetPhysicalDeviceSurfaceSupportKHR pfn_vkGetPhysicalDeviceSurfaceSupportKHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32 * pSupported)
{
	assert(pfn_vkGetPhysicalDeviceSurfaceSupportKHR);
	return pfn_vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
}

static PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR pfn_vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR * pSurfaceCapabilities)
{
	assert(pfn_vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
	return pfn_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
}

static PFN_vkGetPhysicalDeviceSurfaceFormatsKHR pfn_vkGetPhysicalDeviceSurfaceFormatsKHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t * pSurfaceFormatCount, VkSurfaceFormatKHR * pSurfaceFormats)
{
	assert(pfn_vkGetPhysicalDeviceSurfaceFormatsKHR);
	return pfn_vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
}

static PFN_vkGetPhysicalDeviceSurfacePresentModesKHR pfn_vkGetPhysicalDeviceSurfacePresentModesKHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t * pPresentModeCount, VkPresentModeKHR * pPresentModes)
{
	assert(pfn_vkGetPhysicalDeviceSurfacePresentModesKHR);
	return pfn_vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
}

#endif // defined(VK_KHR_surface)

#if defined(VK_KHR_swapchain)

static PFN_vkCreateSwapchainKHR pfn_vkCreateSwapchainKHR;
VKAPI_ATTR VkResult vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSwapchainKHR * pSwapchain)
{
	assert(pfn_vkCreateSwapchainKHR);
	return pfn_vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
}

static PFN_vkDestroySwapchainKHR pfn_vkDestroySwapchainKHR;
VKAPI_ATTR void vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroySwapchainKHR);
	pfn_vkDestroySwapchainKHR(device, swapchain, pAllocator);
}

static PFN_vkGetSwapchainImagesKHR pfn_vkGetSwapchainImagesKHR;
VKAPI_ATTR VkResult vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t * pSwapchainImageCount, VkImage * pSwapchainImages)
{
	assert(pfn_vkGetSwapchainImagesKHR);
	return pfn_vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
}

static PFN_vkAcquireNextImageKHR pfn_vkAcquireNextImageKHR;
VKAPI_ATTR VkResult vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t * pImageIndex)
{
	assert(pfn_vkAcquireNextImageKHR);
	return pfn_vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
}

static PFN_vkQueuePresentKHR pfn_vkQueuePresentKHR;
VKAPI_ATTR VkResult vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR * pPresentInfo)
{
	assert(pfn_vkQueuePresentKHR);
	return pfn_vkQueuePresentKHR(queue, pPresentInfo);
}

#endif // defined(VK_KHR_swapchain)

#if defined(VK_KHR_display)

static PFN_vkGetPhysicalDeviceDisplayPropertiesKHR pfn_vkGetPhysicalDeviceDisplayPropertiesKHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkDisplayPropertiesKHR * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceDisplayPropertiesKHR);
	return pfn_vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
}

static PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR pfn_vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkDisplayPlanePropertiesKHR * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
	return pfn_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
}

static PFN_vkGetDisplayPlaneSupportedDisplaysKHR pfn_vkGetDisplayPlaneSupportedDisplaysKHR;
VKAPI_ATTR VkResult vkGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t * pDisplayCount, VkDisplayKHR * pDisplays)
{
	assert(pfn_vkGetDisplayPlaneSupportedDisplaysKHR);
	return pfn_vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
}

static PFN_vkGetDisplayModePropertiesKHR pfn_vkGetDisplayModePropertiesKHR;
VKAPI_ATTR VkResult vkGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t * pPropertyCount, VkDisplayModePropertiesKHR * pProperties)
{
	assert(pfn_vkGetDisplayModePropertiesKHR);
	return pfn_vkGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
}

static PFN_vkCreateDisplayModeKHR pfn_vkCreateDisplayModeKHR;
VKAPI_ATTR VkResult vkCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDisplayModeKHR * pMode)
{
	assert(pfn_vkCreateDisplayModeKHR);
	return pfn_vkCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
}

static PFN_vkGetDisplayPlaneCapabilitiesKHR pfn_vkGetDisplayPlaneCapabilitiesKHR;
VKAPI_ATTR VkResult vkGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR * pCapabilities)
{
	assert(pfn_vkGetDisplayPlaneCapabilitiesKHR);
	return pfn_vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
}

static PFN_vkCreateDisplayPlaneSurfaceKHR pfn_vkCreateDisplayPlaneSurfaceKHR;
VKAPI_ATTR VkResult vkCreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateDisplayPlaneSurfaceKHR);
	return pfn_vkCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

#endif // defined(VK_KHR_display)

#if defined(VK_KHR_display_swapchain)

static PFN_vkCreateSharedSwapchainsKHR pfn_vkCreateSharedSwapchainsKHR;
VKAPI_ATTR VkResult vkCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR * pCreateInfos, const VkAllocationCallbacks * pAllocator, VkSwapchainKHR * pSwapchains)
{
	assert(pfn_vkCreateSharedSwapchainsKHR);
	return pfn_vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
}

#endif // defined(VK_KHR_display_swapchain)

#if defined(VK_KHR_xlib_surface)

static PFN_vkCreateXlibSurfaceKHR pfn_vkCreateXlibSurfaceKHR;
VKAPI_ATTR VkResult vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateXlibSurfaceKHR);
	return pfn_vkCreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

static PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR pfn_vkGetPhysicalDeviceXlibPresentationSupportKHR;
VKAPI_ATTR VkBool32 vkGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display * dpy, VisualID visualID)
{
	assert(pfn_vkGetPhysicalDeviceXlibPresentationSupportKHR);
	return pfn_vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
}

#endif // defined(VK_KHR_xlib_surface)

#if defined(VK_KHR_xcb_surface)

static PFN_vkCreateXcbSurfaceKHR pfn_vkCreateXcbSurfaceKHR;
VKAPI_ATTR VkResult vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateXcbSurfaceKHR);
	return pfn_vkCreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

static PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR pfn_vkGetPhysicalDeviceXcbPresentationSupportKHR;
VKAPI_ATTR VkBool32 vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t * connection, xcb_visualid_t visual_id)
{
	assert(pfn_vkGetPhysicalDeviceXcbPresentationSupportKHR);
	return pfn_vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
}

#endif // defined(VK_KHR_xcb_surface)

#if defined(VK_KHR_wayland_surface)

static PFN_vkCreateWaylandSurfaceKHR pfn_vkCreateWaylandSurfaceKHR;
VKAPI_ATTR VkResult vkCreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateWaylandSurfaceKHR);
	return pfn_vkCreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

static PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR pfn_vkGetPhysicalDeviceWaylandPresentationSupportKHR;
VKAPI_ATTR VkBool32 vkGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display * display)
{
	assert(pfn_vkGetPhysicalDeviceWaylandPresentationSupportKHR);
	return pfn_vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
}

#endif // defined(VK_KHR_wayland_surface)

#if defined(VK_KHR_android_surface)

static PFN_vkCreateAndroidSurfaceKHR pfn_vkCreateAndroidSurfaceKHR;
VKAPI_ATTR VkResult vkCreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateAndroidSurfaceKHR);
	return pfn_vkCreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

#endif // defined(VK_KHR_android_surface)

#if defined(VK_KHR_win32_surface)

static PFN_vkCreateWin32SurfaceKHR pfn_vkCreateWin32SurfaceKHR;
VKAPI_ATTR VkResult vkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateWin32SurfaceKHR);
	return pfn_vkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
}

static PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR pfn_vkGetPhysicalDeviceWin32PresentationSupportKHR;
VKAPI_ATTR VkBool32 vkGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex)
{
	assert(pfn_vkGetPhysicalDeviceWin32PresentationSupportKHR);
	return pfn_vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
}

#endif // defined(VK_KHR_win32_surface)

#if defined(VK_ANDROID_native_buffer)

static PFN_vkGetSwapchainGrallocUsageANDROID pfn_vkGetSwapchainGrallocUsageANDROID;
VKAPI_ATTR VkResult vkGetSwapchainGrallocUsageANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, int * grallocUsage)
{
	assert(pfn_vkGetSwapchainGrallocUsageANDROID);
	return pfn_vkGetSwapchainGrallocUsageANDROID(device, format, imageUsage, grallocUsage);
}

static PFN_vkAcquireImageANDROID pfn_vkAcquireImageANDROID;
VKAPI_ATTR VkResult vkAcquireImageANDROID(VkDevice device, VkImage image, int nativeFenceFd, VkSemaphore semaphore, VkFence fence)
{
	assert(pfn_vkAcquireImageANDROID);
	return pfn_vkAcquireImageANDROID(device, image, nativeFenceFd, semaphore, fence);
}

static PFN_vkQueueSignalReleaseImageANDROID pfn_vkQueueSignalReleaseImageANDROID;
VKAPI_ATTR VkResult vkQueueSignalReleaseImageANDROID(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore * pWaitSemaphores, VkImage image, int * pNativeFenceFd)
{
	assert(pfn_vkQueueSignalReleaseImageANDROID);
	return pfn_vkQueueSignalReleaseImageANDROID(queue, waitSemaphoreCount, pWaitSemaphores, image, pNativeFenceFd);
}

static PFN_vkGetSwapchainGrallocUsage2ANDROID pfn_vkGetSwapchainGrallocUsage2ANDROID;
VKAPI_ATTR VkResult vkGetSwapchainGrallocUsage2ANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, VkSwapchainImageUsageFlagsANDROID swapchainImageUsage, uint64_t * grallocConsumerUsage, uint64_t * grallocProducerUsage)
{
	assert(pfn_vkGetSwapchainGrallocUsage2ANDROID);
	return pfn_vkGetSwapchainGrallocUsage2ANDROID(device, format, imageUsage, swapchainImageUsage, grallocConsumerUsage, grallocProducerUsage);
}

#endif // defined(VK_ANDROID_native_buffer)

#if defined(VK_EXT_debug_report)

static PFN_vkCreateDebugReportCallbackEXT pfn_vkCreateDebugReportCallbackEXT;
VKAPI_ATTR VkResult vkCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDebugReportCallbackEXT * pCallback)
{
	assert(pfn_vkCreateDebugReportCallbackEXT);
	return pfn_vkCreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
}

static PFN_vkDestroyDebugReportCallbackEXT pfn_vkDestroyDebugReportCallbackEXT;
VKAPI_ATTR void vkDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyDebugReportCallbackEXT);
	pfn_vkDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
}

static PFN_vkDebugReportMessageEXT pfn_vkDebugReportMessageEXT;
VKAPI_ATTR void vkDebugReportMessageEXT(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char * pLayerPrefix, const char * pMessage)
{
	assert(pfn_vkDebugReportMessageEXT);
	pfn_vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}

#endif // defined(VK_EXT_debug_report)

#if defined(VK_EXT_debug_marker)

static PFN_vkDebugMarkerSetObjectTagEXT pfn_vkDebugMarkerSetObjectTagEXT;
VKAPI_ATTR VkResult vkDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT * pTagInfo)
{
	assert(pfn_vkDebugMarkerSetObjectTagEXT);
	return pfn_vkDebugMarkerSetObjectTagEXT(device, pTagInfo);
}

static PFN_vkDebugMarkerSetObjectNameEXT pfn_vkDebugMarkerSetObjectNameEXT;
VKAPI_ATTR VkResult vkDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT * pNameInfo)
{
	assert(pfn_vkDebugMarkerSetObjectNameEXT);
	return pfn_vkDebugMarkerSetObjectNameEXT(device, pNameInfo);
}

static PFN_vkCmdDebugMarkerBeginEXT pfn_vkCmdDebugMarkerBeginEXT;
VKAPI_ATTR void vkCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT * pMarkerInfo)
{
	assert(pfn_vkCmdDebugMarkerBeginEXT);
	pfn_vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}

static PFN_vkCmdDebugMarkerEndEXT pfn_vkCmdDebugMarkerEndEXT;
VKAPI_ATTR void vkCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer)
{
	assert(pfn_vkCmdDebugMarkerEndEXT);
	pfn_vkCmdDebugMarkerEndEXT(commandBuffer);
}

static PFN_vkCmdDebugMarkerInsertEXT pfn_vkCmdDebugMarkerInsertEXT;
VKAPI_ATTR void vkCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT * pMarkerInfo)
{
	assert(pfn_vkCmdDebugMarkerInsertEXT);
	pfn_vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}

#endif // defined(VK_EXT_debug_marker)

#if defined(VK_EXT_transform_feedback)

static PFN_vkCmdBindTransformFeedbackBuffersEXT pfn_vkCmdBindTransformFeedbackBuffersEXT;
VKAPI_ATTR void vkCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer * pBuffers, const VkDeviceSize * pOffsets, const VkDeviceSize * pSizes)
{
	assert(pfn_vkCmdBindTransformFeedbackBuffersEXT);
	pfn_vkCmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}

static PFN_vkCmdBeginTransformFeedbackEXT pfn_vkCmdBeginTransformFeedbackEXT;
VKAPI_ATTR void vkCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer * pCounterBuffers, const VkDeviceSize * pCounterBufferOffsets)
{
	assert(pfn_vkCmdBeginTransformFeedbackEXT);
	pfn_vkCmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

static PFN_vkCmdEndTransformFeedbackEXT pfn_vkCmdEndTransformFeedbackEXT;
VKAPI_ATTR void vkCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer * pCounterBuffers, const VkDeviceSize * pCounterBufferOffsets)
{
	assert(pfn_vkCmdEndTransformFeedbackEXT);
	pfn_vkCmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

static PFN_vkCmdBeginQueryIndexedEXT pfn_vkCmdBeginQueryIndexedEXT;
VKAPI_ATTR void vkCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index)
{
	assert(pfn_vkCmdBeginQueryIndexedEXT);
	pfn_vkCmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}

static PFN_vkCmdEndQueryIndexedEXT pfn_vkCmdEndQueryIndexedEXT;
VKAPI_ATTR void vkCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index)
{
	assert(pfn_vkCmdEndQueryIndexedEXT);
	pfn_vkCmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}

static PFN_vkCmdDrawIndirectByteCountEXT pfn_vkCmdDrawIndirectByteCountEXT;
VKAPI_ATTR void vkCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride)
{
	assert(pfn_vkCmdDrawIndirectByteCountEXT);
	pfn_vkCmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

#endif // defined(VK_EXT_transform_feedback)

#if defined(VK_NVX_image_view_handle)

static PFN_vkGetImageViewHandleNVX pfn_vkGetImageViewHandleNVX;
VKAPI_ATTR uint32_t vkGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX * pInfo)
{
	assert(pfn_vkGetImageViewHandleNVX);
	return pfn_vkGetImageViewHandleNVX(device, pInfo);
}

#endif // defined(VK_NVX_image_view_handle)

#if defined(VK_AMD_draw_indirect_count)

static PFN_vkCmdDrawIndirectCountAMD pfn_vkCmdDrawIndirectCountAMD;
VKAPI_ATTR void vkCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
	assert(pfn_vkCmdDrawIndirectCountAMD);
	pfn_vkCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

static PFN_vkCmdDrawIndexedIndirectCountAMD pfn_vkCmdDrawIndexedIndirectCountAMD;
VKAPI_ATTR void vkCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
	assert(pfn_vkCmdDrawIndexedIndirectCountAMD);
	pfn_vkCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

#endif // defined(VK_AMD_draw_indirect_count)

#if defined(VK_AMD_shader_info)

static PFN_vkGetShaderInfoAMD pfn_vkGetShaderInfoAMD;
VKAPI_ATTR VkResult vkGetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t * pInfoSize, void * pInfo)
{
	assert(pfn_vkGetShaderInfoAMD);
	return pfn_vkGetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
}

#endif // defined(VK_AMD_shader_info)

#if defined(VK_GGP_stream_descriptor_surface)

static PFN_vkCreateStreamDescriptorSurfaceGGP pfn_vkCreateStreamDescriptorSurfaceGGP;
VKAPI_ATTR VkResult vkCreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateStreamDescriptorSurfaceGGP);
	return pfn_vkCreateStreamDescriptorSurfaceGGP(instance, pCreateInfo, pAllocator, pSurface);
}

#endif // defined(VK_GGP_stream_descriptor_surface)

#if defined(VK_NV_external_memory_capabilities)

static PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV pfn_vkGetPhysicalDeviceExternalImageFormatPropertiesNV;
VKAPI_ATTR VkResult vkGetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV * pExternalImageFormatProperties)
{
	assert(pfn_vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
	return pfn_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
}

#endif // defined(VK_NV_external_memory_capabilities)

#if defined(VK_NV_external_memory_win32)

static PFN_vkGetMemoryWin32HandleNV pfn_vkGetMemoryWin32HandleNV;
VKAPI_ATTR VkResult vkGetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE * pHandle)
{
	assert(pfn_vkGetMemoryWin32HandleNV);
	return pfn_vkGetMemoryWin32HandleNV(device, memory, handleType, pHandle);
}

#endif // defined(VK_NV_external_memory_win32)

#if defined(VK_KHR_get_physical_device_properties2)

static PFN_vkGetPhysicalDeviceFeatures2KHR pfn_vkGetPhysicalDeviceFeatures2KHR;
VKAPI_ATTR void vkGetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2 * pFeatures)
{
	assert(pfn_vkGetPhysicalDeviceFeatures2KHR);
	pfn_vkGetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
}

static PFN_vkGetPhysicalDeviceProperties2KHR pfn_vkGetPhysicalDeviceProperties2KHR;
VKAPI_ATTR void vkGetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2 * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceProperties2KHR);
	pfn_vkGetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
}

static PFN_vkGetPhysicalDeviceFormatProperties2KHR pfn_vkGetPhysicalDeviceFormatProperties2KHR;
VKAPI_ATTR void vkGetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2 * pFormatProperties)
{
	assert(pfn_vkGetPhysicalDeviceFormatProperties2KHR);
	pfn_vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);
}

static PFN_vkGetPhysicalDeviceImageFormatProperties2KHR pfn_vkGetPhysicalDeviceImageFormatProperties2KHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2 * pImageFormatInfo, VkImageFormatProperties2 * pImageFormatProperties)
{
	assert(pfn_vkGetPhysicalDeviceImageFormatProperties2KHR);
	return pfn_vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);
}

static PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR pfn_vkGetPhysicalDeviceQueueFamilyProperties2KHR;
VKAPI_ATTR void vkGetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t * pQueueFamilyPropertyCount, VkQueueFamilyProperties2 * pQueueFamilyProperties)
{
	assert(pfn_vkGetPhysicalDeviceQueueFamilyProperties2KHR);
	pfn_vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

static PFN_vkGetPhysicalDeviceMemoryProperties2KHR pfn_vkGetPhysicalDeviceMemoryProperties2KHR;
VKAPI_ATTR void vkGetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2 * pMemoryProperties)
{
	assert(pfn_vkGetPhysicalDeviceMemoryProperties2KHR);
	pfn_vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);
}

static PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR pfn_vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
VKAPI_ATTR void vkGetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2 * pFormatInfo, uint32_t * pPropertyCount, VkSparseImageFormatProperties2 * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
	pfn_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

#endif // defined(VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_device_group)

static PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR pfn_vkGetDeviceGroupPeerMemoryFeaturesKHR;
VKAPI_ATTR void vkGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags * pPeerMemoryFeatures)
{
	assert(pfn_vkGetDeviceGroupPeerMemoryFeaturesKHR);
	pfn_vkGetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

static PFN_vkCmdSetDeviceMaskKHR pfn_vkCmdSetDeviceMaskKHR;
VKAPI_ATTR void vkCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask)
{
	assert(pfn_vkCmdSetDeviceMaskKHR);
	pfn_vkCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}

static PFN_vkCmdDispatchBaseKHR pfn_vkCmdDispatchBaseKHR;
VKAPI_ATTR void vkCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
{
	assert(pfn_vkCmdDispatchBaseKHR);
	pfn_vkCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

#if defined(VK_KHR_surface)

static PFN_vkGetDeviceGroupPresentCapabilitiesKHR pfn_vkGetDeviceGroupPresentCapabilitiesKHR;
VKAPI_ATTR VkResult vkGetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR * pDeviceGroupPresentCapabilities)
{
	assert(pfn_vkGetDeviceGroupPresentCapabilitiesKHR);
	return pfn_vkGetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
}

static PFN_vkGetDeviceGroupSurfacePresentModesKHR pfn_vkGetDeviceGroupSurfacePresentModesKHR;
VKAPI_ATTR VkResult vkGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR * pModes)
{
	assert(pfn_vkGetDeviceGroupSurfacePresentModesKHR);
	return pfn_vkGetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
}

static PFN_vkGetPhysicalDevicePresentRectanglesKHR pfn_vkGetPhysicalDevicePresentRectanglesKHR;
VKAPI_ATTR VkResult vkGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t * pRectCount, VkRect2D * pRects)
{
	assert(pfn_vkGetPhysicalDevicePresentRectanglesKHR);
	return pfn_vkGetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
}

#endif // defined(VK_KHR_surface)

#if defined(VK_KHR_swapchain)

static PFN_vkAcquireNextImage2KHR pfn_vkAcquireNextImage2KHR;
VKAPI_ATTR VkResult vkAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR * pAcquireInfo, uint32_t * pImageIndex)
{
	assert(pfn_vkAcquireNextImage2KHR);
	return pfn_vkAcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
}

#endif // defined(VK_KHR_swapchain)

#endif // defined(VK_KHR_device_group)

#if defined(VK_NN_vi_surface)

static PFN_vkCreateViSurfaceNN pfn_vkCreateViSurfaceNN;
VKAPI_ATTR VkResult vkCreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateViSurfaceNN);
	return pfn_vkCreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);
}

#endif // defined(VK_NN_vi_surface)

#if defined(VK_KHR_maintenance1)

static PFN_vkTrimCommandPoolKHR pfn_vkTrimCommandPoolKHR;
VKAPI_ATTR void vkTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags)
{
	assert(pfn_vkTrimCommandPoolKHR);
	pfn_vkTrimCommandPoolKHR(device, commandPool, flags);
}

#endif // defined(VK_KHR_maintenance1)

#if defined(VK_KHR_device_group_creation)

static PFN_vkEnumeratePhysicalDeviceGroupsKHR pfn_vkEnumeratePhysicalDeviceGroupsKHR;
VKAPI_ATTR VkResult vkEnumeratePhysicalDeviceGroupsKHR(VkInstance instance, uint32_t * pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties * pPhysicalDeviceGroupProperties)
{
	assert(pfn_vkEnumeratePhysicalDeviceGroupsKHR);
	return pfn_vkEnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
}

#endif // defined(VK_KHR_device_group_creation)

#if defined(VK_KHR_external_memory_capabilities)

static PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR pfn_vkGetPhysicalDeviceExternalBufferPropertiesKHR;
VKAPI_ATTR void vkGetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo * pExternalBufferInfo, VkExternalBufferProperties * pExternalBufferProperties)
{
	assert(pfn_vkGetPhysicalDeviceExternalBufferPropertiesKHR);
	pfn_vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

#endif // defined(VK_KHR_external_memory_capabilities)

#if defined(VK_KHR_external_memory_win32)

static PFN_vkGetMemoryWin32HandleKHR pfn_vkGetMemoryWin32HandleKHR;
VKAPI_ATTR VkResult vkGetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR * pGetWin32HandleInfo, HANDLE * pHandle)
{
	assert(pfn_vkGetMemoryWin32HandleKHR);
	return pfn_vkGetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
}

static PFN_vkGetMemoryWin32HandlePropertiesKHR pfn_vkGetMemoryWin32HandlePropertiesKHR;
VKAPI_ATTR VkResult vkGetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR * pMemoryWin32HandleProperties)
{
	assert(pfn_vkGetMemoryWin32HandlePropertiesKHR);
	return pfn_vkGetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
}

#endif // defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_fd)

static PFN_vkGetMemoryFdKHR pfn_vkGetMemoryFdKHR;
VKAPI_ATTR VkResult vkGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR * pGetFdInfo, int * pFd)
{
	assert(pfn_vkGetMemoryFdKHR);
	return pfn_vkGetMemoryFdKHR(device, pGetFdInfo, pFd);
}

static PFN_vkGetMemoryFdPropertiesKHR pfn_vkGetMemoryFdPropertiesKHR;
VKAPI_ATTR VkResult vkGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR * pMemoryFdProperties)
{
	assert(pfn_vkGetMemoryFdPropertiesKHR);
	return pfn_vkGetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
}

#endif // defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_semaphore_capabilities)

static PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR pfn_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
VKAPI_ATTR void vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo * pExternalSemaphoreInfo, VkExternalSemaphoreProperties * pExternalSemaphoreProperties)
{
	assert(pfn_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
	pfn_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

#endif // defined(VK_KHR_external_semaphore_capabilities)

#if defined(VK_KHR_external_semaphore_win32)

static PFN_vkImportSemaphoreWin32HandleKHR pfn_vkImportSemaphoreWin32HandleKHR;
VKAPI_ATTR VkResult vkImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR * pImportSemaphoreWin32HandleInfo)
{
	assert(pfn_vkImportSemaphoreWin32HandleKHR);
	return pfn_vkImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
}

static PFN_vkGetSemaphoreWin32HandleKHR pfn_vkGetSemaphoreWin32HandleKHR;
VKAPI_ATTR VkResult vkGetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR * pGetWin32HandleInfo, HANDLE * pHandle)
{
	assert(pfn_vkGetSemaphoreWin32HandleKHR);
	return pfn_vkGetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
}

#endif // defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_fd)

static PFN_vkImportSemaphoreFdKHR pfn_vkImportSemaphoreFdKHR;
VKAPI_ATTR VkResult vkImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR * pImportSemaphoreFdInfo)
{
	assert(pfn_vkImportSemaphoreFdKHR);
	return pfn_vkImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
}

static PFN_vkGetSemaphoreFdKHR pfn_vkGetSemaphoreFdKHR;
VKAPI_ATTR VkResult vkGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR * pGetFdInfo, int * pFd)
{
	assert(pfn_vkGetSemaphoreFdKHR);
	return pfn_vkGetSemaphoreFdKHR(device, pGetFdInfo, pFd);
}

#endif // defined(VK_KHR_external_semaphore_fd)

#if defined(VK_KHR_push_descriptor)

static PFN_vkCmdPushDescriptorSetKHR pfn_vkCmdPushDescriptorSetKHR;
VKAPI_ATTR void vkCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet * pDescriptorWrites)
{
	assert(pfn_vkCmdPushDescriptorSetKHR);
	pfn_vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

#endif // defined(VK_KHR_push_descriptor)

#if defined(VK_EXT_conditional_rendering)

static PFN_vkCmdBeginConditionalRenderingEXT pfn_vkCmdBeginConditionalRenderingEXT;
VKAPI_ATTR void vkCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT * pConditionalRenderingBegin)
{
	assert(pfn_vkCmdBeginConditionalRenderingEXT);
	pfn_vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}

static PFN_vkCmdEndConditionalRenderingEXT pfn_vkCmdEndConditionalRenderingEXT;
VKAPI_ATTR void vkCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer)
{
	assert(pfn_vkCmdEndConditionalRenderingEXT);
	pfn_vkCmdEndConditionalRenderingEXT(commandBuffer);
}

#endif // defined(VK_EXT_conditional_rendering)

#if defined(VK_KHR_descriptor_update_template)

static PFN_vkCreateDescriptorUpdateTemplateKHR pfn_vkCreateDescriptorUpdateTemplateKHR;
VKAPI_ATTR VkResult vkCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDescriptorUpdateTemplate * pDescriptorUpdateTemplate)
{
	assert(pfn_vkCreateDescriptorUpdateTemplateKHR);
	return pfn_vkCreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
}

static PFN_vkDestroyDescriptorUpdateTemplateKHR pfn_vkDestroyDescriptorUpdateTemplateKHR;
VKAPI_ATTR void vkDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyDescriptorUpdateTemplateKHR);
	pfn_vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
}

static PFN_vkUpdateDescriptorSetWithTemplateKHR pfn_vkUpdateDescriptorSetWithTemplateKHR;
VKAPI_ATTR void vkUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void * pData)
{
	assert(pfn_vkUpdateDescriptorSetWithTemplateKHR);
	pfn_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
}

#if defined(VK_KHR_push_descriptor)

static PFN_vkCmdPushDescriptorSetWithTemplateKHR pfn_vkCmdPushDescriptorSetWithTemplateKHR;
VKAPI_ATTR void vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void * pData)
{
	assert(pfn_vkCmdPushDescriptorSetWithTemplateKHR);
	pfn_vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}

#endif // defined(VK_KHR_push_descriptor)

#endif // defined(VK_KHR_descriptor_update_template)

#if defined(VK_NVX_device_generated_commands)

static PFN_vkCmdProcessCommandsNVX pfn_vkCmdProcessCommandsNVX;
VKAPI_ATTR void vkCmdProcessCommandsNVX(VkCommandBuffer commandBuffer, const VkCmdProcessCommandsInfoNVX * pProcessCommandsInfo)
{
	assert(pfn_vkCmdProcessCommandsNVX);
	pfn_vkCmdProcessCommandsNVX(commandBuffer, pProcessCommandsInfo);
}

static PFN_vkCmdReserveSpaceForCommandsNVX pfn_vkCmdReserveSpaceForCommandsNVX;
VKAPI_ATTR void vkCmdReserveSpaceForCommandsNVX(VkCommandBuffer commandBuffer, const VkCmdReserveSpaceForCommandsInfoNVX * pReserveSpaceInfo)
{
	assert(pfn_vkCmdReserveSpaceForCommandsNVX);
	pfn_vkCmdReserveSpaceForCommandsNVX(commandBuffer, pReserveSpaceInfo);
}

static PFN_vkCreateIndirectCommandsLayoutNVX pfn_vkCreateIndirectCommandsLayoutNVX;
VKAPI_ATTR VkResult vkCreateIndirectCommandsLayoutNVX(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNVX * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkIndirectCommandsLayoutNVX * pIndirectCommandsLayout)
{
	assert(pfn_vkCreateIndirectCommandsLayoutNVX);
	return pfn_vkCreateIndirectCommandsLayoutNVX(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
}

static PFN_vkDestroyIndirectCommandsLayoutNVX pfn_vkDestroyIndirectCommandsLayoutNVX;
VKAPI_ATTR void vkDestroyIndirectCommandsLayoutNVX(VkDevice device, VkIndirectCommandsLayoutNVX indirectCommandsLayout, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyIndirectCommandsLayoutNVX);
	pfn_vkDestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, pAllocator);
}

static PFN_vkCreateObjectTableNVX pfn_vkCreateObjectTableNVX;
VKAPI_ATTR VkResult vkCreateObjectTableNVX(VkDevice device, const VkObjectTableCreateInfoNVX * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkObjectTableNVX * pObjectTable)
{
	assert(pfn_vkCreateObjectTableNVX);
	return pfn_vkCreateObjectTableNVX(device, pCreateInfo, pAllocator, pObjectTable);
}

static PFN_vkDestroyObjectTableNVX pfn_vkDestroyObjectTableNVX;
VKAPI_ATTR void vkDestroyObjectTableNVX(VkDevice device, VkObjectTableNVX objectTable, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyObjectTableNVX);
	pfn_vkDestroyObjectTableNVX(device, objectTable, pAllocator);
}

static PFN_vkRegisterObjectsNVX pfn_vkRegisterObjectsNVX;
VKAPI_ATTR VkResult vkRegisterObjectsNVX(VkDevice device, VkObjectTableNVX objectTable, uint32_t objectCount, const VkObjectTableEntryNVX * const* ppObjectTableEntries, const uint32_t * pObjectIndices)
{
	assert(pfn_vkRegisterObjectsNVX);
	return pfn_vkRegisterObjectsNVX(device, objectTable, objectCount, ppObjectTableEntries, pObjectIndices);
}

static PFN_vkUnregisterObjectsNVX pfn_vkUnregisterObjectsNVX;
VKAPI_ATTR VkResult vkUnregisterObjectsNVX(VkDevice device, VkObjectTableNVX objectTable, uint32_t objectCount, const VkObjectEntryTypeNVX * pObjectEntryTypes, const uint32_t * pObjectIndices)
{
	assert(pfn_vkUnregisterObjectsNVX);
	return pfn_vkUnregisterObjectsNVX(device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);
}

static PFN_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX pfn_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX;
VKAPI_ATTR void vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(VkPhysicalDevice physicalDevice, VkDeviceGeneratedCommandsFeaturesNVX * pFeatures, VkDeviceGeneratedCommandsLimitsNVX * pLimits)
{
	assert(pfn_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX);
	pfn_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, pFeatures, pLimits);
}

#endif // defined(VK_NVX_device_generated_commands)

#if defined(VK_NV_clip_space_w_scaling)

static PFN_vkCmdSetViewportWScalingNV pfn_vkCmdSetViewportWScalingNV;
VKAPI_ATTR void vkCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV * pViewportWScalings)
{
	assert(pfn_vkCmdSetViewportWScalingNV);
	pfn_vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

#endif // defined(VK_NV_clip_space_w_scaling)

#if defined(VK_EXT_direct_mode_display)

static PFN_vkReleaseDisplayEXT pfn_vkReleaseDisplayEXT;
VKAPI_ATTR VkResult vkReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display)
{
	assert(pfn_vkReleaseDisplayEXT);
	return pfn_vkReleaseDisplayEXT(physicalDevice, display);
}

#endif // defined(VK_EXT_direct_mode_display)

#if defined(VK_EXT_acquire_xlib_display)

static PFN_vkAcquireXlibDisplayEXT pfn_vkAcquireXlibDisplayEXT;
VKAPI_ATTR VkResult vkAcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display * dpy, VkDisplayKHR display)
{
	assert(pfn_vkAcquireXlibDisplayEXT);
	return pfn_vkAcquireXlibDisplayEXT(physicalDevice, dpy, display);
}

static PFN_vkGetRandROutputDisplayEXT pfn_vkGetRandROutputDisplayEXT;
VKAPI_ATTR VkResult vkGetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display * dpy, RROutput rrOutput, VkDisplayKHR * pDisplay)
{
	assert(pfn_vkGetRandROutputDisplayEXT);
	return pfn_vkGetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
}

#endif // defined(VK_EXT_acquire_xlib_display)

#if defined(VK_EXT_display_surface_counter)

static PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT pfn_vkGetPhysicalDeviceSurfaceCapabilities2EXT;
VKAPI_ATTR VkResult vkGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT * pSurfaceCapabilities)
{
	assert(pfn_vkGetPhysicalDeviceSurfaceCapabilities2EXT);
	return pfn_vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
}

#endif // defined(VK_EXT_display_surface_counter)

#if defined(VK_EXT_display_control)

static PFN_vkDisplayPowerControlEXT pfn_vkDisplayPowerControlEXT;
VKAPI_ATTR VkResult vkDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT * pDisplayPowerInfo)
{
	assert(pfn_vkDisplayPowerControlEXT);
	return pfn_vkDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
}

static PFN_vkRegisterDeviceEventEXT pfn_vkRegisterDeviceEventEXT;
VKAPI_ATTR VkResult vkRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT * pDeviceEventInfo, const VkAllocationCallbacks * pAllocator, VkFence * pFence)
{
	assert(pfn_vkRegisterDeviceEventEXT);
	return pfn_vkRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
}

static PFN_vkRegisterDisplayEventEXT pfn_vkRegisterDisplayEventEXT;
VKAPI_ATTR VkResult vkRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT * pDisplayEventInfo, const VkAllocationCallbacks * pAllocator, VkFence * pFence)
{
	assert(pfn_vkRegisterDisplayEventEXT);
	return pfn_vkRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
}

static PFN_vkGetSwapchainCounterEXT pfn_vkGetSwapchainCounterEXT;
VKAPI_ATTR VkResult vkGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t * pCounterValue)
{
	assert(pfn_vkGetSwapchainCounterEXT);
	return pfn_vkGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
}

#endif // defined(VK_EXT_display_control)

#if defined(VK_GOOGLE_display_timing)

static PFN_vkGetRefreshCycleDurationGOOGLE pfn_vkGetRefreshCycleDurationGOOGLE;
VKAPI_ATTR VkResult vkGetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE * pDisplayTimingProperties)
{
	assert(pfn_vkGetRefreshCycleDurationGOOGLE);
	return pfn_vkGetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
}

static PFN_vkGetPastPresentationTimingGOOGLE pfn_vkGetPastPresentationTimingGOOGLE;
VKAPI_ATTR VkResult vkGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t * pPresentationTimingCount, VkPastPresentationTimingGOOGLE * pPresentationTimings)
{
	assert(pfn_vkGetPastPresentationTimingGOOGLE);
	return pfn_vkGetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
}

#endif // defined(VK_GOOGLE_display_timing)

#if defined(VK_EXT_discard_rectangles)

static PFN_vkCmdSetDiscardRectangleEXT pfn_vkCmdSetDiscardRectangleEXT;
VKAPI_ATTR void vkCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D * pDiscardRectangles)
{
	assert(pfn_vkCmdSetDiscardRectangleEXT);
	pfn_vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

#endif // defined(VK_EXT_discard_rectangles)

#if defined(VK_EXT_hdr_metadata)

static PFN_vkSetHdrMetadataEXT pfn_vkSetHdrMetadataEXT;
VKAPI_ATTR void vkSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR * pSwapchains, const VkHdrMetadataEXT * pMetadata)
{
	assert(pfn_vkSetHdrMetadataEXT);
	pfn_vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
}

#endif // defined(VK_EXT_hdr_metadata)

#if defined(VK_KHR_create_renderpass2)

static PFN_vkCreateRenderPass2KHR pfn_vkCreateRenderPass2KHR;
VKAPI_ATTR VkResult vkCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2KHR * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkRenderPass * pRenderPass)
{
	assert(pfn_vkCreateRenderPass2KHR);
	return pfn_vkCreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);
}

static PFN_vkCmdBeginRenderPass2KHR pfn_vkCmdBeginRenderPass2KHR;
VKAPI_ATTR void vkCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo * pRenderPassBegin, const VkSubpassBeginInfoKHR * pSubpassBeginInfo)
{
	assert(pfn_vkCmdBeginRenderPass2KHR);
	pfn_vkCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

static PFN_vkCmdNextSubpass2KHR pfn_vkCmdNextSubpass2KHR;
VKAPI_ATTR void vkCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfoKHR * pSubpassBeginInfo, const VkSubpassEndInfoKHR * pSubpassEndInfo)
{
	assert(pfn_vkCmdNextSubpass2KHR);
	pfn_vkCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

static PFN_vkCmdEndRenderPass2KHR pfn_vkCmdEndRenderPass2KHR;
VKAPI_ATTR void vkCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfoKHR * pSubpassEndInfo)
{
	assert(pfn_vkCmdEndRenderPass2KHR);
	pfn_vkCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}

#endif // defined(VK_KHR_create_renderpass2)

#if defined(VK_KHR_shared_presentable_image)

static PFN_vkGetSwapchainStatusKHR pfn_vkGetSwapchainStatusKHR;
VKAPI_ATTR VkResult vkGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain)
{
	assert(pfn_vkGetSwapchainStatusKHR);
	return pfn_vkGetSwapchainStatusKHR(device, swapchain);
}

#endif // defined(VK_KHR_shared_presentable_image)

#if defined(VK_KHR_external_fence_capabilities)

static PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR pfn_vkGetPhysicalDeviceExternalFencePropertiesKHR;
VKAPI_ATTR void vkGetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo * pExternalFenceInfo, VkExternalFenceProperties * pExternalFenceProperties)
{
	assert(pfn_vkGetPhysicalDeviceExternalFencePropertiesKHR);
	pfn_vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

#endif // defined(VK_KHR_external_fence_capabilities)

#if defined(VK_KHR_external_fence_win32)

static PFN_vkImportFenceWin32HandleKHR pfn_vkImportFenceWin32HandleKHR;
VKAPI_ATTR VkResult vkImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR * pImportFenceWin32HandleInfo)
{
	assert(pfn_vkImportFenceWin32HandleKHR);
	return pfn_vkImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
}

static PFN_vkGetFenceWin32HandleKHR pfn_vkGetFenceWin32HandleKHR;
VKAPI_ATTR VkResult vkGetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR * pGetWin32HandleInfo, HANDLE * pHandle)
{
	assert(pfn_vkGetFenceWin32HandleKHR);
	return pfn_vkGetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
}

#endif // defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_fd)

static PFN_vkImportFenceFdKHR pfn_vkImportFenceFdKHR;
VKAPI_ATTR VkResult vkImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR * pImportFenceFdInfo)
{
	assert(pfn_vkImportFenceFdKHR);
	return pfn_vkImportFenceFdKHR(device, pImportFenceFdInfo);
}

static PFN_vkGetFenceFdKHR pfn_vkGetFenceFdKHR;
VKAPI_ATTR VkResult vkGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR * pGetFdInfo, int * pFd)
{
	assert(pfn_vkGetFenceFdKHR);
	return pfn_vkGetFenceFdKHR(device, pGetFdInfo, pFd);
}

#endif // defined(VK_KHR_external_fence_fd)

#if defined(VK_KHR_get_surface_capabilities2)

static PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR pfn_vkGetPhysicalDeviceSurfaceCapabilities2KHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, VkSurfaceCapabilities2KHR * pSurfaceCapabilities)
{
	assert(pfn_vkGetPhysicalDeviceSurfaceCapabilities2KHR);
	return pfn_vkGetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
}

static PFN_vkGetPhysicalDeviceSurfaceFormats2KHR pfn_vkGetPhysicalDeviceSurfaceFormats2KHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, uint32_t * pSurfaceFormatCount, VkSurfaceFormat2KHR * pSurfaceFormats)
{
	assert(pfn_vkGetPhysicalDeviceSurfaceFormats2KHR);
	return pfn_vkGetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
}

#endif // defined(VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_display_properties2)

static PFN_vkGetPhysicalDeviceDisplayProperties2KHR pfn_vkGetPhysicalDeviceDisplayProperties2KHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkDisplayProperties2KHR * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceDisplayProperties2KHR);
	return pfn_vkGetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
}

static PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR pfn_vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
VKAPI_ATTR VkResult vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkDisplayPlaneProperties2KHR * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
	return pfn_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
}

static PFN_vkGetDisplayModeProperties2KHR pfn_vkGetDisplayModeProperties2KHR;
VKAPI_ATTR VkResult vkGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t * pPropertyCount, VkDisplayModeProperties2KHR * pProperties)
{
	assert(pfn_vkGetDisplayModeProperties2KHR);
	return pfn_vkGetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
}

static PFN_vkGetDisplayPlaneCapabilities2KHR pfn_vkGetDisplayPlaneCapabilities2KHR;
VKAPI_ATTR VkResult vkGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR * pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR * pCapabilities)
{
	assert(pfn_vkGetDisplayPlaneCapabilities2KHR);
	return pfn_vkGetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
}

#endif // defined(VK_KHR_get_display_properties2)

#if defined(VK_MVK_ios_surface)

static PFN_vkCreateIOSSurfaceMVK pfn_vkCreateIOSSurfaceMVK;
VKAPI_ATTR VkResult vkCreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateIOSSurfaceMVK);
	return pfn_vkCreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
}

#endif // defined(VK_MVK_ios_surface)

#if defined(VK_MVK_macos_surface)

static PFN_vkCreateMacOSSurfaceMVK pfn_vkCreateMacOSSurfaceMVK;
VKAPI_ATTR VkResult vkCreateMacOSSurfaceMVK(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateMacOSSurfaceMVK);
	return pfn_vkCreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
}

#endif // defined(VK_MVK_macos_surface)

#if defined(VK_EXT_debug_utils)

static PFN_vkSetDebugUtilsObjectNameEXT pfn_vkSetDebugUtilsObjectNameEXT;
VKAPI_ATTR VkResult vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT * pNameInfo)
{
	assert(pfn_vkSetDebugUtilsObjectNameEXT);
	return pfn_vkSetDebugUtilsObjectNameEXT(device, pNameInfo);
}

static PFN_vkSetDebugUtilsObjectTagEXT pfn_vkSetDebugUtilsObjectTagEXT;
VKAPI_ATTR VkResult vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT * pTagInfo)
{
	assert(pfn_vkSetDebugUtilsObjectTagEXT);
	return pfn_vkSetDebugUtilsObjectTagEXT(device, pTagInfo);
}

static PFN_vkQueueBeginDebugUtilsLabelEXT pfn_vkQueueBeginDebugUtilsLabelEXT;
VKAPI_ATTR void vkQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT * pLabelInfo)
{
	assert(pfn_vkQueueBeginDebugUtilsLabelEXT);
	pfn_vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
}

static PFN_vkQueueEndDebugUtilsLabelEXT pfn_vkQueueEndDebugUtilsLabelEXT;
VKAPI_ATTR void vkQueueEndDebugUtilsLabelEXT(VkQueue queue)
{
	assert(pfn_vkQueueEndDebugUtilsLabelEXT);
	pfn_vkQueueEndDebugUtilsLabelEXT(queue);
}

static PFN_vkQueueInsertDebugUtilsLabelEXT pfn_vkQueueInsertDebugUtilsLabelEXT;
VKAPI_ATTR void vkQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT * pLabelInfo)
{
	assert(pfn_vkQueueInsertDebugUtilsLabelEXT);
	pfn_vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
}

static PFN_vkCmdBeginDebugUtilsLabelEXT pfn_vkCmdBeginDebugUtilsLabelEXT;
VKAPI_ATTR void vkCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT * pLabelInfo)
{
	assert(pfn_vkCmdBeginDebugUtilsLabelEXT);
	pfn_vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

static PFN_vkCmdEndDebugUtilsLabelEXT pfn_vkCmdEndDebugUtilsLabelEXT;
VKAPI_ATTR void vkCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer)
{
	assert(pfn_vkCmdEndDebugUtilsLabelEXT);
	pfn_vkCmdEndDebugUtilsLabelEXT(commandBuffer);
}

static PFN_vkCmdInsertDebugUtilsLabelEXT pfn_vkCmdInsertDebugUtilsLabelEXT;
VKAPI_ATTR void vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT * pLabelInfo)
{
	assert(pfn_vkCmdInsertDebugUtilsLabelEXT);
	pfn_vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}

static PFN_vkCreateDebugUtilsMessengerEXT pfn_vkCreateDebugUtilsMessengerEXT;
VKAPI_ATTR VkResult vkCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkDebugUtilsMessengerEXT * pMessenger)
{
	assert(pfn_vkCreateDebugUtilsMessengerEXT);
	return pfn_vkCreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
}

static PFN_vkDestroyDebugUtilsMessengerEXT pfn_vkDestroyDebugUtilsMessengerEXT;
VKAPI_ATTR void vkDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyDebugUtilsMessengerEXT);
	pfn_vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
}

static PFN_vkSubmitDebugUtilsMessageEXT pfn_vkSubmitDebugUtilsMessageEXT;
VKAPI_ATTR void vkSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT * pCallbackData)
{
	assert(pfn_vkSubmitDebugUtilsMessageEXT);
	pfn_vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
}

#endif // defined(VK_EXT_debug_utils)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)

static PFN_vkGetAndroidHardwareBufferPropertiesANDROID pfn_vkGetAndroidHardwareBufferPropertiesANDROID;
VKAPI_ATTR VkResult vkGetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer * buffer, VkAndroidHardwareBufferPropertiesANDROID * pProperties)
{
	assert(pfn_vkGetAndroidHardwareBufferPropertiesANDROID);
	return pfn_vkGetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
}

static PFN_vkGetMemoryAndroidHardwareBufferANDROID pfn_vkGetMemoryAndroidHardwareBufferANDROID;
VKAPI_ATTR VkResult vkGetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID * pInfo, struct AHardwareBuffer ** pBuffer)
{
	assert(pfn_vkGetMemoryAndroidHardwareBufferANDROID);
	return pfn_vkGetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
}

#endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_EXT_sample_locations)

static PFN_vkCmdSetSampleLocationsEXT pfn_vkCmdSetSampleLocationsEXT;
VKAPI_ATTR void vkCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT * pSampleLocationsInfo)
{
	assert(pfn_vkCmdSetSampleLocationsEXT);
	pfn_vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}

static PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT pfn_vkGetPhysicalDeviceMultisamplePropertiesEXT;
VKAPI_ATTR void vkGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT * pMultisampleProperties)
{
	assert(pfn_vkGetPhysicalDeviceMultisamplePropertiesEXT);
	pfn_vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
}

#endif // defined(VK_EXT_sample_locations)

#if defined(VK_KHR_get_memory_requirements2)

static PFN_vkGetImageMemoryRequirements2KHR pfn_vkGetImageMemoryRequirements2KHR;
VKAPI_ATTR void vkGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2 * pInfo, VkMemoryRequirements2 * pMemoryRequirements)
{
	assert(pfn_vkGetImageMemoryRequirements2KHR);
	pfn_vkGetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
}

static PFN_vkGetBufferMemoryRequirements2KHR pfn_vkGetBufferMemoryRequirements2KHR;
VKAPI_ATTR void vkGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2 * pInfo, VkMemoryRequirements2 * pMemoryRequirements)
{
	assert(pfn_vkGetBufferMemoryRequirements2KHR);
	pfn_vkGetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
}

static PFN_vkGetImageSparseMemoryRequirements2KHR pfn_vkGetImageSparseMemoryRequirements2KHR;
VKAPI_ATTR void vkGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2 * pInfo, uint32_t * pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 * pSparseMemoryRequirements)
{
	assert(pfn_vkGetImageSparseMemoryRequirements2KHR);
	pfn_vkGetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

#endif // defined(VK_KHR_get_memory_requirements2)

#if defined(VK_KHR_sampler_ycbcr_conversion)

static PFN_vkCreateSamplerYcbcrConversionKHR pfn_vkCreateSamplerYcbcrConversionKHR;
VKAPI_ATTR VkResult vkCreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSamplerYcbcrConversion * pYcbcrConversion)
{
	assert(pfn_vkCreateSamplerYcbcrConversionKHR);
	return pfn_vkCreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);
}

static PFN_vkDestroySamplerYcbcrConversionKHR pfn_vkDestroySamplerYcbcrConversionKHR;
VKAPI_ATTR void vkDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroySamplerYcbcrConversionKHR);
	pfn_vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
}

#endif // defined(VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_bind_memory2)

static PFN_vkBindBufferMemory2KHR pfn_vkBindBufferMemory2KHR;
VKAPI_ATTR VkResult vkBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo * pBindInfos)
{
	assert(pfn_vkBindBufferMemory2KHR);
	return pfn_vkBindBufferMemory2KHR(device, bindInfoCount, pBindInfos);
}

static PFN_vkBindImageMemory2KHR pfn_vkBindImageMemory2KHR;
VKAPI_ATTR VkResult vkBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo * pBindInfos)
{
	assert(pfn_vkBindImageMemory2KHR);
	return pfn_vkBindImageMemory2KHR(device, bindInfoCount, pBindInfos);
}

#endif // defined(VK_KHR_bind_memory2)

#if defined(VK_EXT_image_drm_format_modifier)

static PFN_vkGetImageDrmFormatModifierPropertiesEXT pfn_vkGetImageDrmFormatModifierPropertiesEXT;
VKAPI_ATTR VkResult vkGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT * pProperties)
{
	assert(pfn_vkGetImageDrmFormatModifierPropertiesEXT);
	return pfn_vkGetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
}

#endif // defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_validation_cache)

static PFN_vkCreateValidationCacheEXT pfn_vkCreateValidationCacheEXT;
VKAPI_ATTR VkResult vkCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkValidationCacheEXT * pValidationCache)
{
	assert(pfn_vkCreateValidationCacheEXT);
	return pfn_vkCreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
}

static PFN_vkDestroyValidationCacheEXT pfn_vkDestroyValidationCacheEXT;
VKAPI_ATTR void vkDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyValidationCacheEXT);
	pfn_vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
}

static PFN_vkMergeValidationCachesEXT pfn_vkMergeValidationCachesEXT;
VKAPI_ATTR VkResult vkMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT * pSrcCaches)
{
	assert(pfn_vkMergeValidationCachesEXT);
	return pfn_vkMergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
}

static PFN_vkGetValidationCacheDataEXT pfn_vkGetValidationCacheDataEXT;
VKAPI_ATTR VkResult vkGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t * pDataSize, void * pData)
{
	assert(pfn_vkGetValidationCacheDataEXT);
	return pfn_vkGetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
}

#endif // defined(VK_EXT_validation_cache)

#if defined(VK_NV_shading_rate_image)

static PFN_vkCmdBindShadingRateImageNV pfn_vkCmdBindShadingRateImageNV;
VKAPI_ATTR void vkCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout)
{
	assert(pfn_vkCmdBindShadingRateImageNV);
	pfn_vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}

static PFN_vkCmdSetViewportShadingRatePaletteNV pfn_vkCmdSetViewportShadingRatePaletteNV;
VKAPI_ATTR void vkCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV * pShadingRatePalettes)
{
	assert(pfn_vkCmdSetViewportShadingRatePaletteNV);
	pfn_vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

static PFN_vkCmdSetCoarseSampleOrderNV pfn_vkCmdSetCoarseSampleOrderNV;
VKAPI_ATTR void vkCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV * pCustomSampleOrders)
{
	assert(pfn_vkCmdSetCoarseSampleOrderNV);
	pfn_vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

#endif // defined(VK_NV_shading_rate_image)

#if defined(VK_NV_ray_tracing)

static PFN_vkCreateAccelerationStructureNV pfn_vkCreateAccelerationStructureNV;
VKAPI_ATTR VkResult vkCreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkAccelerationStructureNV * pAccelerationStructure)
{
	assert(pfn_vkCreateAccelerationStructureNV);
	return pfn_vkCreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
}

static PFN_vkDestroyAccelerationStructureNV pfn_vkDestroyAccelerationStructureNV;
VKAPI_ATTR void vkDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks * pAllocator)
{
	assert(pfn_vkDestroyAccelerationStructureNV);
	pfn_vkDestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
}

static PFN_vkGetAccelerationStructureMemoryRequirementsNV pfn_vkGetAccelerationStructureMemoryRequirementsNV;
VKAPI_ATTR void vkGetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV * pInfo, VkMemoryRequirements2KHR * pMemoryRequirements)
{
	assert(pfn_vkGetAccelerationStructureMemoryRequirementsNV);
	pfn_vkGetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
}

static PFN_vkBindAccelerationStructureMemoryNV pfn_vkBindAccelerationStructureMemoryNV;
VKAPI_ATTR VkResult vkBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV * pBindInfos)
{
	assert(pfn_vkBindAccelerationStructureMemoryNV);
	return pfn_vkBindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
}

static PFN_vkCmdBuildAccelerationStructureNV pfn_vkCmdBuildAccelerationStructureNV;
VKAPI_ATTR void vkCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV * pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset)
{
	assert(pfn_vkCmdBuildAccelerationStructureNV);
	pfn_vkCmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

static PFN_vkCmdCopyAccelerationStructureNV pfn_vkCmdCopyAccelerationStructureNV;
VKAPI_ATTR void vkCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeNV mode)
{
	assert(pfn_vkCmdCopyAccelerationStructureNV);
	pfn_vkCmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}

static PFN_vkCmdTraceRaysNV pfn_vkCmdTraceRaysNV;
VKAPI_ATTR void vkCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth)
{
	assert(pfn_vkCmdTraceRaysNV);
	pfn_vkCmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

static PFN_vkCreateRayTracingPipelinesNV pfn_vkCreateRayTracingPipelinesNV;
VKAPI_ATTR VkResult vkCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV * pCreateInfos, const VkAllocationCallbacks * pAllocator, VkPipeline * pPipelines)
{
	assert(pfn_vkCreateRayTracingPipelinesNV);
	return pfn_vkCreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}

static PFN_vkGetRayTracingShaderGroupHandlesNV pfn_vkGetRayTracingShaderGroupHandlesNV;
VKAPI_ATTR VkResult vkGetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void * pData)
{
	assert(pfn_vkGetRayTracingShaderGroupHandlesNV);
	return pfn_vkGetRayTracingShaderGroupHandlesNV(device, pipeline, firstGroup, groupCount, dataSize, pData);
}

static PFN_vkGetAccelerationStructureHandleNV pfn_vkGetAccelerationStructureHandleNV;
VKAPI_ATTR VkResult vkGetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void * pData)
{
	assert(pfn_vkGetAccelerationStructureHandleNV);
	return pfn_vkGetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
}

static PFN_vkCmdWriteAccelerationStructuresPropertiesNV pfn_vkCmdWriteAccelerationStructuresPropertiesNV;
VKAPI_ATTR void vkCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV * pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery)
{
	assert(pfn_vkCmdWriteAccelerationStructuresPropertiesNV);
	pfn_vkCmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

static PFN_vkCompileDeferredNV pfn_vkCompileDeferredNV;
VKAPI_ATTR VkResult vkCompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader)
{
	assert(pfn_vkCompileDeferredNV);
	return pfn_vkCompileDeferredNV(device, pipeline, shader);
}

#endif // defined(VK_NV_ray_tracing)

#if defined(VK_KHR_maintenance3)

static PFN_vkGetDescriptorSetLayoutSupportKHR pfn_vkGetDescriptorSetLayoutSupportKHR;
VKAPI_ATTR void vkGetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo * pCreateInfo, VkDescriptorSetLayoutSupport * pSupport)
{
	assert(pfn_vkGetDescriptorSetLayoutSupportKHR);
	pfn_vkGetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
}

#endif // defined(VK_KHR_maintenance3)

#if defined(VK_KHR_draw_indirect_count)

static PFN_vkCmdDrawIndirectCountKHR pfn_vkCmdDrawIndirectCountKHR;
VKAPI_ATTR void vkCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
	assert(pfn_vkCmdDrawIndirectCountKHR);
	pfn_vkCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

static PFN_vkCmdDrawIndexedIndirectCountKHR pfn_vkCmdDrawIndexedIndirectCountKHR;
VKAPI_ATTR void vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
	assert(pfn_vkCmdDrawIndexedIndirectCountKHR);
	pfn_vkCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

#endif // defined(VK_KHR_draw_indirect_count)

#if defined(VK_EXT_external_memory_host)

static PFN_vkGetMemoryHostPointerPropertiesEXT pfn_vkGetMemoryHostPointerPropertiesEXT;
VKAPI_ATTR VkResult vkGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void * pHostPointer, VkMemoryHostPointerPropertiesEXT * pMemoryHostPointerProperties)
{
	assert(pfn_vkGetMemoryHostPointerPropertiesEXT);
	return pfn_vkGetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
}

#endif // defined(VK_EXT_external_memory_host)

#if defined(VK_AMD_buffer_marker)

static PFN_vkCmdWriteBufferMarkerAMD pfn_vkCmdWriteBufferMarkerAMD;
VKAPI_ATTR void vkCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker)
{
	assert(pfn_vkCmdWriteBufferMarkerAMD);
	pfn_vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

#endif // defined(VK_AMD_buffer_marker)

#if defined(VK_EXT_calibrated_timestamps)

static PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT pfn_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
VKAPI_ATTR VkResult vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t * pTimeDomainCount, VkTimeDomainEXT * pTimeDomains)
{
	assert(pfn_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
	return pfn_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
}

static PFN_vkGetCalibratedTimestampsEXT pfn_vkGetCalibratedTimestampsEXT;
VKAPI_ATTR VkResult vkGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT * pTimestampInfos, uint64_t * pTimestamps, uint64_t * pMaxDeviation)
{
	assert(pfn_vkGetCalibratedTimestampsEXT);
	return pfn_vkGetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
}

#endif // defined(VK_EXT_calibrated_timestamps)

#if defined(VK_NV_mesh_shader)

static PFN_vkCmdDrawMeshTasksNV pfn_vkCmdDrawMeshTasksNV;
VKAPI_ATTR void vkCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask)
{
	assert(pfn_vkCmdDrawMeshTasksNV);
	pfn_vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}

static PFN_vkCmdDrawMeshTasksIndirectNV pfn_vkCmdDrawMeshTasksIndirectNV;
VKAPI_ATTR void vkCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
	assert(pfn_vkCmdDrawMeshTasksIndirectNV);
	pfn_vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}

static PFN_vkCmdDrawMeshTasksIndirectCountNV pfn_vkCmdDrawMeshTasksIndirectCountNV;
VKAPI_ATTR void vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride)
{
	assert(pfn_vkCmdDrawMeshTasksIndirectCountNV);
	pfn_vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

#endif // defined(VK_NV_mesh_shader)

#if defined(VK_NV_scissor_exclusive)

static PFN_vkCmdSetExclusiveScissorNV pfn_vkCmdSetExclusiveScissorNV;
VKAPI_ATTR void vkCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D * pExclusiveScissors)
{
	assert(pfn_vkCmdSetExclusiveScissorNV);
	pfn_vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

#endif // defined(VK_NV_scissor_exclusive)

#if defined(VK_NV_device_diagnostic_checkpoints)

static PFN_vkCmdSetCheckpointNV pfn_vkCmdSetCheckpointNV;
VKAPI_ATTR void vkCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void * pCheckpointMarker)
{
	assert(pfn_vkCmdSetCheckpointNV);
	pfn_vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}

static PFN_vkGetQueueCheckpointDataNV pfn_vkGetQueueCheckpointDataNV;
VKAPI_ATTR void vkGetQueueCheckpointDataNV(VkQueue queue, uint32_t * pCheckpointDataCount, VkCheckpointDataNV * pCheckpointData)
{
	assert(pfn_vkGetQueueCheckpointDataNV);
	pfn_vkGetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
}

#endif // defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_INTEL_performance_query)

static PFN_vkInitializePerformanceApiINTEL pfn_vkInitializePerformanceApiINTEL;
VKAPI_ATTR VkResult vkInitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL * pInitializeInfo)
{
	assert(pfn_vkInitializePerformanceApiINTEL);
	return pfn_vkInitializePerformanceApiINTEL(device, pInitializeInfo);
}

static PFN_vkUninitializePerformanceApiINTEL pfn_vkUninitializePerformanceApiINTEL;
VKAPI_ATTR void vkUninitializePerformanceApiINTEL(VkDevice device)
{
	assert(pfn_vkUninitializePerformanceApiINTEL);
	pfn_vkUninitializePerformanceApiINTEL(device);
}

static PFN_vkCmdSetPerformanceMarkerINTEL pfn_vkCmdSetPerformanceMarkerINTEL;
VKAPI_ATTR VkResult vkCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL * pMarkerInfo)
{
	assert(pfn_vkCmdSetPerformanceMarkerINTEL);
	return pfn_vkCmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
}

static PFN_vkCmdSetPerformanceStreamMarkerINTEL pfn_vkCmdSetPerformanceStreamMarkerINTEL;
VKAPI_ATTR VkResult vkCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL * pMarkerInfo)
{
	assert(pfn_vkCmdSetPerformanceStreamMarkerINTEL);
	return pfn_vkCmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
}

static PFN_vkCmdSetPerformanceOverrideINTEL pfn_vkCmdSetPerformanceOverrideINTEL;
VKAPI_ATTR VkResult vkCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL * pOverrideInfo)
{
	assert(pfn_vkCmdSetPerformanceOverrideINTEL);
	return pfn_vkCmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
}

static PFN_vkAcquirePerformanceConfigurationINTEL pfn_vkAcquirePerformanceConfigurationINTEL;
VKAPI_ATTR VkResult vkAcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL * pAcquireInfo, VkPerformanceConfigurationINTEL * pConfiguration)
{
	assert(pfn_vkAcquirePerformanceConfigurationINTEL);
	return pfn_vkAcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
}

static PFN_vkReleasePerformanceConfigurationINTEL pfn_vkReleasePerformanceConfigurationINTEL;
VKAPI_ATTR VkResult vkReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration)
{
	assert(pfn_vkReleasePerformanceConfigurationINTEL);
	return pfn_vkReleasePerformanceConfigurationINTEL(device, configuration);
}

static PFN_vkQueueSetPerformanceConfigurationINTEL pfn_vkQueueSetPerformanceConfigurationINTEL;
VKAPI_ATTR VkResult vkQueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration)
{
	assert(pfn_vkQueueSetPerformanceConfigurationINTEL);
	return pfn_vkQueueSetPerformanceConfigurationINTEL(queue, configuration);
}

static PFN_vkGetPerformanceParameterINTEL pfn_vkGetPerformanceParameterINTEL;
VKAPI_ATTR VkResult vkGetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL * pValue)
{
	assert(pfn_vkGetPerformanceParameterINTEL);
	return pfn_vkGetPerformanceParameterINTEL(device, parameter, pValue);
}

#endif // defined(VK_INTEL_performance_query)

#if defined(VK_AMD_display_native_hdr)

static PFN_vkSetLocalDimmingAMD pfn_vkSetLocalDimmingAMD;
VKAPI_ATTR void vkSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable)
{
	assert(pfn_vkSetLocalDimmingAMD);
	pfn_vkSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
}

#endif // defined(VK_AMD_display_native_hdr)

#if defined(VK_FUCHSIA_imagepipe_surface)

static PFN_vkCreateImagePipeSurfaceFUCHSIA pfn_vkCreateImagePipeSurfaceFUCHSIA;
VKAPI_ATTR VkResult vkCreateImagePipeSurfaceFUCHSIA(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateImagePipeSurfaceFUCHSIA);
	return pfn_vkCreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);
}

#endif // defined(VK_FUCHSIA_imagepipe_surface)

#if defined(VK_EXT_metal_surface)

static PFN_vkCreateMetalSurfaceEXT pfn_vkCreateMetalSurfaceEXT;
VKAPI_ATTR VkResult vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateMetalSurfaceEXT);
	return pfn_vkCreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
}

#endif // defined(VK_EXT_metal_surface)

#if defined(VK_EXT_buffer_device_address)

static PFN_vkGetBufferDeviceAddressEXT pfn_vkGetBufferDeviceAddressEXT;
VKAPI_ATTR VkDeviceAddress vkGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfoEXT * pInfo)
{
	assert(pfn_vkGetBufferDeviceAddressEXT);
	return pfn_vkGetBufferDeviceAddressEXT(device, pInfo);
}

#endif // defined(VK_EXT_buffer_device_address)

#if defined(VK_NV_cooperative_matrix)

static PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV pfn_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;
VKAPI_ATTR VkResult vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t * pPropertyCount, VkCooperativeMatrixPropertiesNV * pProperties)
{
	assert(pfn_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
	return pfn_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, pPropertyCount, pProperties);
}

#endif // defined(VK_NV_cooperative_matrix)

#if defined(VK_NV_coverage_reduction_mode)

static PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV pfn_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;
VKAPI_ATTR VkResult vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t * pCombinationCount, VkFramebufferMixedSamplesCombinationNV * pCombinations)
{
	assert(pfn_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
	return pfn_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, pCombinationCount, pCombinations);
}

#endif // defined(VK_NV_coverage_reduction_mode)

#if defined(VK_EXT_full_screen_exclusive)

static PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT pfn_vkGetPhysicalDeviceSurfacePresentModes2EXT;
VKAPI_ATTR VkResult vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, uint32_t * pPresentModeCount, VkPresentModeKHR * pPresentModes)
{
	assert(pfn_vkGetPhysicalDeviceSurfacePresentModes2EXT);
	return pfn_vkGetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
}

static PFN_vkAcquireFullScreenExclusiveModeEXT pfn_vkAcquireFullScreenExclusiveModeEXT;
VKAPI_ATTR VkResult vkAcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain)
{
	assert(pfn_vkAcquireFullScreenExclusiveModeEXT);
	return pfn_vkAcquireFullScreenExclusiveModeEXT(device, swapchain);
}

static PFN_vkReleaseFullScreenExclusiveModeEXT pfn_vkReleaseFullScreenExclusiveModeEXT;
VKAPI_ATTR VkResult vkReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain)
{
	assert(pfn_vkReleaseFullScreenExclusiveModeEXT);
	return pfn_vkReleaseFullScreenExclusiveModeEXT(device, swapchain);
}

#if defined(VK_KHR_device_group)

static PFN_vkGetDeviceGroupSurfacePresentModes2EXT pfn_vkGetDeviceGroupSurfacePresentModes2EXT;
VKAPI_ATTR VkResult vkGetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR * pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR * pModes)
{
	assert(pfn_vkGetDeviceGroupSurfacePresentModes2EXT);
	return pfn_vkGetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
}

#endif // defined(VK_KHR_device_group)

#endif // defined(VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_headless_surface)

static PFN_vkCreateHeadlessSurfaceEXT pfn_vkCreateHeadlessSurfaceEXT;
VKAPI_ATTR VkResult vkCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface)
{
	assert(pfn_vkCreateHeadlessSurfaceEXT);
	return pfn_vkCreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
}

#endif // defined(VK_EXT_headless_surface)

#if defined(VK_EXT_line_rasterization)

static PFN_vkCmdSetLineStippleEXT pfn_vkCmdSetLineStippleEXT;
VKAPI_ATTR void vkCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern)
{
	assert(pfn_vkCmdSetLineStippleEXT);
	pfn_vkCmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}

#endif // defined(VK_EXT_line_rasterization)

#if defined(VK_EXT_host_query_reset)

static PFN_vkResetQueryPoolEXT pfn_vkResetQueryPoolEXT;
VKAPI_ATTR void vkResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
	assert(pfn_vkResetQueryPoolEXT);
	pfn_vkResetQueryPoolEXT(device, queryPool, firstQuery, queryCount);
}

#endif // defined(VK_EXT_host_query_reset)

#if defined(VK_KHR_pipeline_executable_properties)

static PFN_vkGetPipelineExecutablePropertiesKHR pfn_vkGetPipelineExecutablePropertiesKHR;
VKAPI_ATTR VkResult vkGetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR * pPipelineInfo, uint32_t * pExecutableCount, VkPipelineExecutablePropertiesKHR * pProperties)
{
	assert(pfn_vkGetPipelineExecutablePropertiesKHR);
	return pfn_vkGetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
}

static PFN_vkGetPipelineExecutableStatisticsKHR pfn_vkGetPipelineExecutableStatisticsKHR;
VKAPI_ATTR VkResult vkGetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR * pExecutableInfo, uint32_t * pStatisticCount, VkPipelineExecutableStatisticKHR * pStatistics)
{
	assert(pfn_vkGetPipelineExecutableStatisticsKHR);
	return pfn_vkGetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
}

static PFN_vkGetPipelineExecutableInternalRepresentationsKHR pfn_vkGetPipelineExecutableInternalRepresentationsKHR;
VKAPI_ATTR VkResult vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR * pExecutableInfo, uint32_t * pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR * pInternalRepresentations)
{
	assert(pfn_vkGetPipelineExecutableInternalRepresentationsKHR);
	return pfn_vkGetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
}

#endif // defined(VK_KHR_pipeline_executable_properties)

void vulkan_loader_init(PFN_vkGetInstanceProcAddr get_address)
{
	pfn_vkGetInstanceProcAddr = get_address;
	pfn_vkCreateInstance = (PFN_vkCreateInstance)vkGetInstanceProcAddr(0, "vkCreateInstance");
	pfn_vkEnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties)vkGetInstanceProcAddr(0, "vkEnumerateInstanceExtensionProperties");
	pfn_vkEnumerateInstanceLayerProperties = (PFN_vkEnumerateInstanceLayerProperties)vkGetInstanceProcAddr(0, "vkEnumerateInstanceLayerProperties");
}

void vulkan_load_instance_procs(VkInstance vulkan)
{
	pfn_vkDestroyInstance = (PFN_vkDestroyInstance)vkGetInstanceProcAddr(vulkan, "vkDestroyInstance");
	pfn_vkEnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)vkGetInstanceProcAddr(vulkan, "vkEnumeratePhysicalDevices");
	pfn_vkGetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceFeatures");
	pfn_vkGetPhysicalDeviceFormatProperties = (PFN_vkGetPhysicalDeviceFormatProperties)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceFormatProperties");
	pfn_vkGetPhysicalDeviceImageFormatProperties = (PFN_vkGetPhysicalDeviceImageFormatProperties)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceImageFormatProperties");
	pfn_vkGetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceProperties");
	pfn_vkGetPhysicalDeviceQueueFamilyProperties = (PFN_vkGetPhysicalDeviceQueueFamilyProperties)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceQueueFamilyProperties");
	pfn_vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceMemoryProperties");
	pfn_vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)vkGetInstanceProcAddr(vulkan, "vkGetInstanceProcAddr");
	pfn_vkGetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)vkGetInstanceProcAddr(vulkan, "vkGetDeviceProcAddr");
	pfn_vkCreateDevice = (PFN_vkCreateDevice)vkGetInstanceProcAddr(vulkan, "vkCreateDevice");
	pfn_vkDestroyDevice = (PFN_vkDestroyDevice)vkGetInstanceProcAddr(vulkan, "vkDestroyDevice");
	pfn_vkEnumerateDeviceExtensionProperties = (PFN_vkEnumerateDeviceExtensionProperties)vkGetInstanceProcAddr(vulkan, "vkEnumerateDeviceExtensionProperties");
	pfn_vkEnumerateDeviceLayerProperties = (PFN_vkEnumerateDeviceLayerProperties)vkGetInstanceProcAddr(vulkan, "vkEnumerateDeviceLayerProperties");
	pfn_vkGetDeviceQueue = (PFN_vkGetDeviceQueue)vkGetInstanceProcAddr(vulkan, "vkGetDeviceQueue");
	pfn_vkQueueSubmit = (PFN_vkQueueSubmit)vkGetInstanceProcAddr(vulkan, "vkQueueSubmit");
	pfn_vkQueueWaitIdle = (PFN_vkQueueWaitIdle)vkGetInstanceProcAddr(vulkan, "vkQueueWaitIdle");
	pfn_vkDeviceWaitIdle = (PFN_vkDeviceWaitIdle)vkGetInstanceProcAddr(vulkan, "vkDeviceWaitIdle");
	pfn_vkAllocateMemory = (PFN_vkAllocateMemory)vkGetInstanceProcAddr(vulkan, "vkAllocateMemory");
	pfn_vkFreeMemory = (PFN_vkFreeMemory)vkGetInstanceProcAddr(vulkan, "vkFreeMemory");
	pfn_vkMapMemory = (PFN_vkMapMemory)vkGetInstanceProcAddr(vulkan, "vkMapMemory");
	pfn_vkUnmapMemory = (PFN_vkUnmapMemory)vkGetInstanceProcAddr(vulkan, "vkUnmapMemory");
	pfn_vkFlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)vkGetInstanceProcAddr(vulkan, "vkFlushMappedMemoryRanges");
	pfn_vkInvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)vkGetInstanceProcAddr(vulkan, "vkInvalidateMappedMemoryRanges");
	pfn_vkGetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)vkGetInstanceProcAddr(vulkan, "vkGetDeviceMemoryCommitment");
	pfn_vkBindBufferMemory = (PFN_vkBindBufferMemory)vkGetInstanceProcAddr(vulkan, "vkBindBufferMemory");
	pfn_vkBindImageMemory = (PFN_vkBindImageMemory)vkGetInstanceProcAddr(vulkan, "vkBindImageMemory");
	pfn_vkGetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)vkGetInstanceProcAddr(vulkan, "vkGetBufferMemoryRequirements");
	pfn_vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)vkGetInstanceProcAddr(vulkan, "vkGetImageMemoryRequirements");
	pfn_vkGetImageSparseMemoryRequirements = (PFN_vkGetImageSparseMemoryRequirements)vkGetInstanceProcAddr(vulkan, "vkGetImageSparseMemoryRequirements");
	pfn_vkGetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSparseImageFormatProperties");
	pfn_vkQueueBindSparse = (PFN_vkQueueBindSparse)vkGetInstanceProcAddr(vulkan, "vkQueueBindSparse");
	pfn_vkCreateFence = (PFN_vkCreateFence)vkGetInstanceProcAddr(vulkan, "vkCreateFence");
	pfn_vkDestroyFence = (PFN_vkDestroyFence)vkGetInstanceProcAddr(vulkan, "vkDestroyFence");
	pfn_vkResetFences = (PFN_vkResetFences)vkGetInstanceProcAddr(vulkan, "vkResetFences");
	pfn_vkGetFenceStatus = (PFN_vkGetFenceStatus)vkGetInstanceProcAddr(vulkan, "vkGetFenceStatus");
	pfn_vkWaitForFences = (PFN_vkWaitForFences)vkGetInstanceProcAddr(vulkan, "vkWaitForFences");
	pfn_vkCreateSemaphore = (PFN_vkCreateSemaphore)vkGetInstanceProcAddr(vulkan, "vkCreateSemaphore");
	pfn_vkDestroySemaphore = (PFN_vkDestroySemaphore)vkGetInstanceProcAddr(vulkan, "vkDestroySemaphore");
	pfn_vkCreateEvent = (PFN_vkCreateEvent)vkGetInstanceProcAddr(vulkan, "vkCreateEvent");
	pfn_vkDestroyEvent = (PFN_vkDestroyEvent)vkGetInstanceProcAddr(vulkan, "vkDestroyEvent");
	pfn_vkGetEventStatus = (PFN_vkGetEventStatus)vkGetInstanceProcAddr(vulkan, "vkGetEventStatus");
	pfn_vkSetEvent = (PFN_vkSetEvent)vkGetInstanceProcAddr(vulkan, "vkSetEvent");
	pfn_vkResetEvent = (PFN_vkResetEvent)vkGetInstanceProcAddr(vulkan, "vkResetEvent");
	pfn_vkCreateQueryPool = (PFN_vkCreateQueryPool)vkGetInstanceProcAddr(vulkan, "vkCreateQueryPool");
	pfn_vkDestroyQueryPool = (PFN_vkDestroyQueryPool)vkGetInstanceProcAddr(vulkan, "vkDestroyQueryPool");
	pfn_vkGetQueryPoolResults = (PFN_vkGetQueryPoolResults)vkGetInstanceProcAddr(vulkan, "vkGetQueryPoolResults");
	pfn_vkCreateBuffer = (PFN_vkCreateBuffer)vkGetInstanceProcAddr(vulkan, "vkCreateBuffer");
	pfn_vkDestroyBuffer = (PFN_vkDestroyBuffer)vkGetInstanceProcAddr(vulkan, "vkDestroyBuffer");
	pfn_vkCreateBufferView = (PFN_vkCreateBufferView)vkGetInstanceProcAddr(vulkan, "vkCreateBufferView");
	pfn_vkDestroyBufferView = (PFN_vkDestroyBufferView)vkGetInstanceProcAddr(vulkan, "vkDestroyBufferView");
	pfn_vkCreateImage = (PFN_vkCreateImage)vkGetInstanceProcAddr(vulkan, "vkCreateImage");
	pfn_vkDestroyImage = (PFN_vkDestroyImage)vkGetInstanceProcAddr(vulkan, "vkDestroyImage");
	pfn_vkGetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)vkGetInstanceProcAddr(vulkan, "vkGetImageSubresourceLayout");
	pfn_vkCreateImageView = (PFN_vkCreateImageView)vkGetInstanceProcAddr(vulkan, "vkCreateImageView");
	pfn_vkDestroyImageView = (PFN_vkDestroyImageView)vkGetInstanceProcAddr(vulkan, "vkDestroyImageView");
	pfn_vkCreateShaderModule = (PFN_vkCreateShaderModule)vkGetInstanceProcAddr(vulkan, "vkCreateShaderModule");
	pfn_vkDestroyShaderModule = (PFN_vkDestroyShaderModule)vkGetInstanceProcAddr(vulkan, "vkDestroyShaderModule");
	pfn_vkCreatePipelineCache = (PFN_vkCreatePipelineCache)vkGetInstanceProcAddr(vulkan, "vkCreatePipelineCache");
	pfn_vkDestroyPipelineCache = (PFN_vkDestroyPipelineCache)vkGetInstanceProcAddr(vulkan, "vkDestroyPipelineCache");
	pfn_vkGetPipelineCacheData = (PFN_vkGetPipelineCacheData)vkGetInstanceProcAddr(vulkan, "vkGetPipelineCacheData");
	pfn_vkMergePipelineCaches = (PFN_vkMergePipelineCaches)vkGetInstanceProcAddr(vulkan, "vkMergePipelineCaches");
	pfn_vkCreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)vkGetInstanceProcAddr(vulkan, "vkCreateGraphicsPipelines");
	pfn_vkCreateComputePipelines = (PFN_vkCreateComputePipelines)vkGetInstanceProcAddr(vulkan, "vkCreateComputePipelines");
	pfn_vkDestroyPipeline = (PFN_vkDestroyPipeline)vkGetInstanceProcAddr(vulkan, "vkDestroyPipeline");
	pfn_vkCreatePipelineLayout = (PFN_vkCreatePipelineLayout)vkGetInstanceProcAddr(vulkan, "vkCreatePipelineLayout");
	pfn_vkDestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)vkGetInstanceProcAddr(vulkan, "vkDestroyPipelineLayout");
	pfn_vkCreateSampler = (PFN_vkCreateSampler)vkGetInstanceProcAddr(vulkan, "vkCreateSampler");
	pfn_vkDestroySampler = (PFN_vkDestroySampler)vkGetInstanceProcAddr(vulkan, "vkDestroySampler");
	pfn_vkCreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)vkGetInstanceProcAddr(vulkan, "vkCreateDescriptorSetLayout");
	pfn_vkDestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)vkGetInstanceProcAddr(vulkan, "vkDestroyDescriptorSetLayout");
	pfn_vkCreateDescriptorPool = (PFN_vkCreateDescriptorPool)vkGetInstanceProcAddr(vulkan, "vkCreateDescriptorPool");
	pfn_vkDestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)vkGetInstanceProcAddr(vulkan, "vkDestroyDescriptorPool");
	pfn_vkResetDescriptorPool = (PFN_vkResetDescriptorPool)vkGetInstanceProcAddr(vulkan, "vkResetDescriptorPool");
	pfn_vkAllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)vkGetInstanceProcAddr(vulkan, "vkAllocateDescriptorSets");
	pfn_vkFreeDescriptorSets = (PFN_vkFreeDescriptorSets)vkGetInstanceProcAddr(vulkan, "vkFreeDescriptorSets");
	pfn_vkUpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)vkGetInstanceProcAddr(vulkan, "vkUpdateDescriptorSets");
	pfn_vkCreateFramebuffer = (PFN_vkCreateFramebuffer)vkGetInstanceProcAddr(vulkan, "vkCreateFramebuffer");
	pfn_vkDestroyFramebuffer = (PFN_vkDestroyFramebuffer)vkGetInstanceProcAddr(vulkan, "vkDestroyFramebuffer");
	pfn_vkCreateRenderPass = (PFN_vkCreateRenderPass)vkGetInstanceProcAddr(vulkan, "vkCreateRenderPass");
	pfn_vkDestroyRenderPass = (PFN_vkDestroyRenderPass)vkGetInstanceProcAddr(vulkan, "vkDestroyRenderPass");
	pfn_vkGetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)vkGetInstanceProcAddr(vulkan, "vkGetRenderAreaGranularity");
	pfn_vkCreateCommandPool = (PFN_vkCreateCommandPool)vkGetInstanceProcAddr(vulkan, "vkCreateCommandPool");
	pfn_vkDestroyCommandPool = (PFN_vkDestroyCommandPool)vkGetInstanceProcAddr(vulkan, "vkDestroyCommandPool");
	pfn_vkResetCommandPool = (PFN_vkResetCommandPool)vkGetInstanceProcAddr(vulkan, "vkResetCommandPool");
	pfn_vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)vkGetInstanceProcAddr(vulkan, "vkAllocateCommandBuffers");
	pfn_vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)vkGetInstanceProcAddr(vulkan, "vkFreeCommandBuffers");
	pfn_vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)vkGetInstanceProcAddr(vulkan, "vkBeginCommandBuffer");
	pfn_vkEndCommandBuffer = (PFN_vkEndCommandBuffer)vkGetInstanceProcAddr(vulkan, "vkEndCommandBuffer");
	pfn_vkResetCommandBuffer = (PFN_vkResetCommandBuffer)vkGetInstanceProcAddr(vulkan, "vkResetCommandBuffer");
	pfn_vkCmdBindPipeline = (PFN_vkCmdBindPipeline)vkGetInstanceProcAddr(vulkan, "vkCmdBindPipeline");
	pfn_vkCmdSetViewport = (PFN_vkCmdSetViewport)vkGetInstanceProcAddr(vulkan, "vkCmdSetViewport");
	pfn_vkCmdSetScissor = (PFN_vkCmdSetScissor)vkGetInstanceProcAddr(vulkan, "vkCmdSetScissor");
	pfn_vkCmdSetLineWidth = (PFN_vkCmdSetLineWidth)vkGetInstanceProcAddr(vulkan, "vkCmdSetLineWidth");
	pfn_vkCmdSetDepthBias = (PFN_vkCmdSetDepthBias)vkGetInstanceProcAddr(vulkan, "vkCmdSetDepthBias");
	pfn_vkCmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)vkGetInstanceProcAddr(vulkan, "vkCmdSetBlendConstants");
	pfn_vkCmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)vkGetInstanceProcAddr(vulkan, "vkCmdSetDepthBounds");
	pfn_vkCmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)vkGetInstanceProcAddr(vulkan, "vkCmdSetStencilCompareMask");
	pfn_vkCmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)vkGetInstanceProcAddr(vulkan, "vkCmdSetStencilWriteMask");
	pfn_vkCmdSetStencilReference = (PFN_vkCmdSetStencilReference)vkGetInstanceProcAddr(vulkan, "vkCmdSetStencilReference");
	pfn_vkCmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)vkGetInstanceProcAddr(vulkan, "vkCmdBindDescriptorSets");
	pfn_vkCmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)vkGetInstanceProcAddr(vulkan, "vkCmdBindIndexBuffer");
	pfn_vkCmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)vkGetInstanceProcAddr(vulkan, "vkCmdBindVertexBuffers");
	pfn_vkCmdDraw = (PFN_vkCmdDraw)vkGetInstanceProcAddr(vulkan, "vkCmdDraw");
	pfn_vkCmdDrawIndexed = (PFN_vkCmdDrawIndexed)vkGetInstanceProcAddr(vulkan, "vkCmdDrawIndexed");
	pfn_vkCmdDrawIndirect = (PFN_vkCmdDrawIndirect)vkGetInstanceProcAddr(vulkan, "vkCmdDrawIndirect");
	pfn_vkCmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)vkGetInstanceProcAddr(vulkan, "vkCmdDrawIndexedIndirect");
	pfn_vkCmdDispatch = (PFN_vkCmdDispatch)vkGetInstanceProcAddr(vulkan, "vkCmdDispatch");
	pfn_vkCmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)vkGetInstanceProcAddr(vulkan, "vkCmdDispatchIndirect");
	pfn_vkCmdCopyBuffer = (PFN_vkCmdCopyBuffer)vkGetInstanceProcAddr(vulkan, "vkCmdCopyBuffer");
	pfn_vkCmdCopyImage = (PFN_vkCmdCopyImage)vkGetInstanceProcAddr(vulkan, "vkCmdCopyImage");
	pfn_vkCmdBlitImage = (PFN_vkCmdBlitImage)vkGetInstanceProcAddr(vulkan, "vkCmdBlitImage");
	pfn_vkCmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)vkGetInstanceProcAddr(vulkan, "vkCmdCopyBufferToImage");
	pfn_vkCmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)vkGetInstanceProcAddr(vulkan, "vkCmdCopyImageToBuffer");
	pfn_vkCmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)vkGetInstanceProcAddr(vulkan, "vkCmdUpdateBuffer");
	pfn_vkCmdFillBuffer = (PFN_vkCmdFillBuffer)vkGetInstanceProcAddr(vulkan, "vkCmdFillBuffer");
	pfn_vkCmdClearColorImage = (PFN_vkCmdClearColorImage)vkGetInstanceProcAddr(vulkan, "vkCmdClearColorImage");
	pfn_vkCmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)vkGetInstanceProcAddr(vulkan, "vkCmdClearDepthStencilImage");
	pfn_vkCmdClearAttachments = (PFN_vkCmdClearAttachments)vkGetInstanceProcAddr(vulkan, "vkCmdClearAttachments");
	pfn_vkCmdResolveImage = (PFN_vkCmdResolveImage)vkGetInstanceProcAddr(vulkan, "vkCmdResolveImage");
	pfn_vkCmdSetEvent = (PFN_vkCmdSetEvent)vkGetInstanceProcAddr(vulkan, "vkCmdSetEvent");
	pfn_vkCmdResetEvent = (PFN_vkCmdResetEvent)vkGetInstanceProcAddr(vulkan, "vkCmdResetEvent");
	pfn_vkCmdWaitEvents = (PFN_vkCmdWaitEvents)vkGetInstanceProcAddr(vulkan, "vkCmdWaitEvents");
	pfn_vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)vkGetInstanceProcAddr(vulkan, "vkCmdPipelineBarrier");
	pfn_vkCmdBeginQuery = (PFN_vkCmdBeginQuery)vkGetInstanceProcAddr(vulkan, "vkCmdBeginQuery");
	pfn_vkCmdEndQuery = (PFN_vkCmdEndQuery)vkGetInstanceProcAddr(vulkan, "vkCmdEndQuery");
	pfn_vkCmdResetQueryPool = (PFN_vkCmdResetQueryPool)vkGetInstanceProcAddr(vulkan, "vkCmdResetQueryPool");
	pfn_vkCmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)vkGetInstanceProcAddr(vulkan, "vkCmdWriteTimestamp");
	pfn_vkCmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)vkGetInstanceProcAddr(vulkan, "vkCmdCopyQueryPoolResults");
	pfn_vkCmdPushConstants = (PFN_vkCmdPushConstants)vkGetInstanceProcAddr(vulkan, "vkCmdPushConstants");
	pfn_vkCmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)vkGetInstanceProcAddr(vulkan, "vkCmdBeginRenderPass");
	pfn_vkCmdNextSubpass = (PFN_vkCmdNextSubpass)vkGetInstanceProcAddr(vulkan, "vkCmdNextSubpass");
	pfn_vkCmdEndRenderPass = (PFN_vkCmdEndRenderPass)vkGetInstanceProcAddr(vulkan, "vkCmdEndRenderPass");
	pfn_vkCmdExecuteCommands = (PFN_vkCmdExecuteCommands)vkGetInstanceProcAddr(vulkan, "vkCmdExecuteCommands");
	pfn_vkEnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion)vkGetInstanceProcAddr(vulkan, "vkEnumerateInstanceVersion");
	pfn_vkBindBufferMemory2 = (PFN_vkBindBufferMemory2)vkGetInstanceProcAddr(vulkan, "vkBindBufferMemory2");
	pfn_vkBindImageMemory2 = (PFN_vkBindImageMemory2)vkGetInstanceProcAddr(vulkan, "vkBindImageMemory2");
	pfn_vkGetDeviceGroupPeerMemoryFeatures = (PFN_vkGetDeviceGroupPeerMemoryFeatures)vkGetInstanceProcAddr(vulkan, "vkGetDeviceGroupPeerMemoryFeatures");
	pfn_vkCmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)vkGetInstanceProcAddr(vulkan, "vkCmdSetDeviceMask");
	pfn_vkCmdDispatchBase = (PFN_vkCmdDispatchBase)vkGetInstanceProcAddr(vulkan, "vkCmdDispatchBase");
	pfn_vkEnumeratePhysicalDeviceGroups = (PFN_vkEnumeratePhysicalDeviceGroups)vkGetInstanceProcAddr(vulkan, "vkEnumeratePhysicalDeviceGroups");
	pfn_vkGetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)vkGetInstanceProcAddr(vulkan, "vkGetImageMemoryRequirements2");
	pfn_vkGetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)vkGetInstanceProcAddr(vulkan, "vkGetBufferMemoryRequirements2");
	pfn_vkGetImageSparseMemoryRequirements2 = (PFN_vkGetImageSparseMemoryRequirements2)vkGetInstanceProcAddr(vulkan, "vkGetImageSparseMemoryRequirements2");
	pfn_vkGetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceFeatures2");
	pfn_vkGetPhysicalDeviceProperties2 = (PFN_vkGetPhysicalDeviceProperties2)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceProperties2");
	pfn_vkGetPhysicalDeviceFormatProperties2 = (PFN_vkGetPhysicalDeviceFormatProperties2)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceFormatProperties2");
	pfn_vkGetPhysicalDeviceImageFormatProperties2 = (PFN_vkGetPhysicalDeviceImageFormatProperties2)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceImageFormatProperties2");
	pfn_vkGetPhysicalDeviceQueueFamilyProperties2 = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceQueueFamilyProperties2");
	pfn_vkGetPhysicalDeviceMemoryProperties2 = (PFN_vkGetPhysicalDeviceMemoryProperties2)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceMemoryProperties2");
	pfn_vkGetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSparseImageFormatProperties2");
	pfn_vkTrimCommandPool = (PFN_vkTrimCommandPool)vkGetInstanceProcAddr(vulkan, "vkTrimCommandPool");
	pfn_vkGetDeviceQueue2 = (PFN_vkGetDeviceQueue2)vkGetInstanceProcAddr(vulkan, "vkGetDeviceQueue2");
	pfn_vkCreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)vkGetInstanceProcAddr(vulkan, "vkCreateSamplerYcbcrConversion");
	pfn_vkDestroySamplerYcbcrConversion = (PFN_vkDestroySamplerYcbcrConversion)vkGetInstanceProcAddr(vulkan, "vkDestroySamplerYcbcrConversion");
	pfn_vkCreateDescriptorUpdateTemplate = (PFN_vkCreateDescriptorUpdateTemplate)vkGetInstanceProcAddr(vulkan, "vkCreateDescriptorUpdateTemplate");
	pfn_vkDestroyDescriptorUpdateTemplate = (PFN_vkDestroyDescriptorUpdateTemplate)vkGetInstanceProcAddr(vulkan, "vkDestroyDescriptorUpdateTemplate");
	pfn_vkUpdateDescriptorSetWithTemplate = (PFN_vkUpdateDescriptorSetWithTemplate)vkGetInstanceProcAddr(vulkan, "vkUpdateDescriptorSetWithTemplate");
	pfn_vkGetPhysicalDeviceExternalBufferProperties = (PFN_vkGetPhysicalDeviceExternalBufferProperties)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceExternalBufferProperties");
	pfn_vkGetPhysicalDeviceExternalFenceProperties = (PFN_vkGetPhysicalDeviceExternalFenceProperties)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceExternalFenceProperties");
	pfn_vkGetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceExternalSemaphoreProperties");
	pfn_vkGetDescriptorSetLayoutSupport = (PFN_vkGetDescriptorSetLayoutSupport)vkGetInstanceProcAddr(vulkan, "vkGetDescriptorSetLayoutSupport");

#if defined(VK_KHR_surface)
	pfn_vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)vkGetInstanceProcAddr(vulkan, "vkDestroySurfaceKHR");
	pfn_vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSurfaceSupportKHR");
	pfn_vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
	pfn_vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSurfaceFormatsKHR");
	pfn_vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSurfacePresentModesKHR");
#endif // defined(VK_KHR_surface)

#if defined(VK_KHR_swapchain)
	pfn_vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)vkGetInstanceProcAddr(vulkan, "vkCreateSwapchainKHR");
	pfn_vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)vkGetInstanceProcAddr(vulkan, "vkDestroySwapchainKHR");
	pfn_vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)vkGetInstanceProcAddr(vulkan, "vkGetSwapchainImagesKHR");
	pfn_vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)vkGetInstanceProcAddr(vulkan, "vkAcquireNextImageKHR");
	pfn_vkQueuePresentKHR = (PFN_vkQueuePresentKHR)vkGetInstanceProcAddr(vulkan, "vkQueuePresentKHR");
#endif // defined(VK_KHR_swapchain)

#if defined(VK_KHR_display)
	pfn_vkGetPhysicalDeviceDisplayPropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceDisplayPropertiesKHR");
	pfn_vkGetPhysicalDeviceDisplayPlanePropertiesKHR = (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
	pfn_vkGetDisplayPlaneSupportedDisplaysKHR = (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)vkGetInstanceProcAddr(vulkan, "vkGetDisplayPlaneSupportedDisplaysKHR");
	pfn_vkGetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetDisplayModePropertiesKHR");
	pfn_vkCreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)vkGetInstanceProcAddr(vulkan, "vkCreateDisplayModeKHR");
	pfn_vkGetDisplayPlaneCapabilitiesKHR = (PFN_vkGetDisplayPlaneCapabilitiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetDisplayPlaneCapabilitiesKHR");
	pfn_vkCreateDisplayPlaneSurfaceKHR = (PFN_vkCreateDisplayPlaneSurfaceKHR)vkGetInstanceProcAddr(vulkan, "vkCreateDisplayPlaneSurfaceKHR");
#endif // defined(VK_KHR_display)

#if defined(VK_KHR_display_swapchain)
	pfn_vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)vkGetInstanceProcAddr(vulkan, "vkCreateSharedSwapchainsKHR");
#endif // defined(VK_KHR_display_swapchain)

#if defined(VK_KHR_xlib_surface)
	pfn_vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)vkGetInstanceProcAddr(vulkan, "vkCreateXlibSurfaceKHR");
	pfn_vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
#endif // defined(VK_KHR_xlib_surface)

#if defined(VK_KHR_xcb_surface)
	pfn_vkCreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)vkGetInstanceProcAddr(vulkan, "vkCreateXcbSurfaceKHR");
	pfn_vkGetPhysicalDeviceXcbPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
#endif // defined(VK_KHR_xcb_surface)

#if defined(VK_KHR_wayland_surface)
	pfn_vkCreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)vkGetInstanceProcAddr(vulkan, "vkCreateWaylandSurfaceKHR");
	pfn_vkGetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
#endif // defined(VK_KHR_wayland_surface)

#if defined(VK_KHR_android_surface)
	pfn_vkCreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR)vkGetInstanceProcAddr(vulkan, "vkCreateAndroidSurfaceKHR");
#endif // defined(VK_KHR_android_surface)

#if defined(VK_KHR_win32_surface)
	pfn_vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)vkGetInstanceProcAddr(vulkan, "vkCreateWin32SurfaceKHR");
	pfn_vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
#endif // defined(VK_KHR_win32_surface)

#if defined(VK_ANDROID_native_buffer)
	pfn_vkGetSwapchainGrallocUsageANDROID = (PFN_vkGetSwapchainGrallocUsageANDROID)vkGetInstanceProcAddr(vulkan, "vkGetSwapchainGrallocUsageANDROID");
	pfn_vkAcquireImageANDROID = (PFN_vkAcquireImageANDROID)vkGetInstanceProcAddr(vulkan, "vkAcquireImageANDROID");
	pfn_vkQueueSignalReleaseImageANDROID = (PFN_vkQueueSignalReleaseImageANDROID)vkGetInstanceProcAddr(vulkan, "vkQueueSignalReleaseImageANDROID");
	pfn_vkGetSwapchainGrallocUsage2ANDROID = (PFN_vkGetSwapchainGrallocUsage2ANDROID)vkGetInstanceProcAddr(vulkan, "vkGetSwapchainGrallocUsage2ANDROID");
#endif // defined(VK_ANDROID_native_buffer)

#if defined(VK_EXT_debug_report)
	pfn_vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(vulkan, "vkCreateDebugReportCallbackEXT");
	pfn_vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(vulkan, "vkDestroyDebugReportCallbackEXT");
	pfn_vkDebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)vkGetInstanceProcAddr(vulkan, "vkDebugReportMessageEXT");
#endif // defined(VK_EXT_debug_report)

#if defined(VK_EXT_debug_marker)
	pfn_vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)vkGetInstanceProcAddr(vulkan, "vkDebugMarkerSetObjectTagEXT");
	pfn_vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)vkGetInstanceProcAddr(vulkan, "vkDebugMarkerSetObjectNameEXT");
	pfn_vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)vkGetInstanceProcAddr(vulkan, "vkCmdDebugMarkerBeginEXT");
	pfn_vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)vkGetInstanceProcAddr(vulkan, "vkCmdDebugMarkerEndEXT");
	pfn_vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)vkGetInstanceProcAddr(vulkan, "vkCmdDebugMarkerInsertEXT");
#endif // defined(VK_EXT_debug_marker)

#if defined(VK_EXT_transform_feedback)
	pfn_vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)vkGetInstanceProcAddr(vulkan, "vkCmdBindTransformFeedbackBuffersEXT");
	pfn_vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)vkGetInstanceProcAddr(vulkan, "vkCmdBeginTransformFeedbackEXT");
	pfn_vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)vkGetInstanceProcAddr(vulkan, "vkCmdEndTransformFeedbackEXT");
	pfn_vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)vkGetInstanceProcAddr(vulkan, "vkCmdBeginQueryIndexedEXT");
	pfn_vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)vkGetInstanceProcAddr(vulkan, "vkCmdEndQueryIndexedEXT");
	pfn_vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)vkGetInstanceProcAddr(vulkan, "vkCmdDrawIndirectByteCountEXT");
#endif // defined(VK_EXT_transform_feedback)

#if defined(VK_NVX_image_view_handle)
	pfn_vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)vkGetInstanceProcAddr(vulkan, "vkGetImageViewHandleNVX");
#endif // defined(VK_NVX_image_view_handle)

#if defined(VK_AMD_draw_indirect_count)
	pfn_vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)vkGetInstanceProcAddr(vulkan, "vkCmdDrawIndirectCountAMD");
	pfn_vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)vkGetInstanceProcAddr(vulkan, "vkCmdDrawIndexedIndirectCountAMD");
#endif // defined(VK_AMD_draw_indirect_count)

#if defined(VK_AMD_shader_info)
	pfn_vkGetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)vkGetInstanceProcAddr(vulkan, "vkGetShaderInfoAMD");
#endif // defined(VK_AMD_shader_info)

#if defined(VK_GGP_stream_descriptor_surface)
	pfn_vkCreateStreamDescriptorSurfaceGGP = (PFN_vkCreateStreamDescriptorSurfaceGGP)vkGetInstanceProcAddr(vulkan, "vkCreateStreamDescriptorSurfaceGGP");
#endif // defined(VK_GGP_stream_descriptor_surface)

#if defined(VK_NV_external_memory_capabilities)
	pfn_vkGetPhysicalDeviceExternalImageFormatPropertiesNV = (PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
#endif // defined(VK_NV_external_memory_capabilities)

#if defined(VK_NV_external_memory_win32)
	pfn_vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)vkGetInstanceProcAddr(vulkan, "vkGetMemoryWin32HandleNV");
#endif // defined(VK_NV_external_memory_win32)

#if defined(VK_KHR_get_physical_device_properties2)
	pfn_vkGetPhysicalDeviceFeatures2KHR = (PFN_vkGetPhysicalDeviceFeatures2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceFeatures2KHR");
	pfn_vkGetPhysicalDeviceProperties2KHR = (PFN_vkGetPhysicalDeviceProperties2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceProperties2KHR");
	pfn_vkGetPhysicalDeviceFormatProperties2KHR = (PFN_vkGetPhysicalDeviceFormatProperties2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceFormatProperties2KHR");
	pfn_vkGetPhysicalDeviceImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceImageFormatProperties2KHR");
	pfn_vkGetPhysicalDeviceQueueFamilyProperties2KHR = (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
	pfn_vkGetPhysicalDeviceMemoryProperties2KHR = (PFN_vkGetPhysicalDeviceMemoryProperties2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceMemoryProperties2KHR");
	pfn_vkGetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
#endif // defined(VK_KHR_get_physical_device_properties2)

#if defined(VK_KHR_device_group)
	pfn_vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)vkGetInstanceProcAddr(vulkan, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
	pfn_vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)vkGetInstanceProcAddr(vulkan, "vkCmdSetDeviceMaskKHR");
	pfn_vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)vkGetInstanceProcAddr(vulkan, "vkCmdDispatchBaseKHR");

#if defined(VK_KHR_surface)
	pfn_vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetDeviceGroupPresentCapabilitiesKHR");
	pfn_vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)vkGetInstanceProcAddr(vulkan, "vkGetDeviceGroupSurfacePresentModesKHR");
	pfn_vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDevicePresentRectanglesKHR");
#endif // defined(VK_KHR_surface)

#if defined(VK_KHR_swapchain)
	pfn_vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)vkGetInstanceProcAddr(vulkan, "vkAcquireNextImage2KHR");
#endif // defined(VK_KHR_swapchain)
#endif // defined(VK_KHR_device_group)

#if defined(VK_NN_vi_surface)
	pfn_vkCreateViSurfaceNN = (PFN_vkCreateViSurfaceNN)vkGetInstanceProcAddr(vulkan, "vkCreateViSurfaceNN");
#endif // defined(VK_NN_vi_surface)

#if defined(VK_KHR_maintenance1)
	pfn_vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)vkGetInstanceProcAddr(vulkan, "vkTrimCommandPoolKHR");
#endif // defined(VK_KHR_maintenance1)

#if defined(VK_KHR_device_group_creation)
	pfn_vkEnumeratePhysicalDeviceGroupsKHR = (PFN_vkEnumeratePhysicalDeviceGroupsKHR)vkGetInstanceProcAddr(vulkan, "vkEnumeratePhysicalDeviceGroupsKHR");
#endif // defined(VK_KHR_device_group_creation)

#if defined(VK_KHR_external_memory_capabilities)
	pfn_vkGetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
#endif // defined(VK_KHR_external_memory_capabilities)

#if defined(VK_KHR_external_memory_win32)
	pfn_vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)vkGetInstanceProcAddr(vulkan, "vkGetMemoryWin32HandleKHR");
	pfn_vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetMemoryWin32HandlePropertiesKHR");
#endif // defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_fd)
	pfn_vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)vkGetInstanceProcAddr(vulkan, "vkGetMemoryFdKHR");
	pfn_vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetMemoryFdPropertiesKHR");
#endif // defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_semaphore_capabilities)
	pfn_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
#endif // defined(VK_KHR_external_semaphore_capabilities)

#if defined(VK_KHR_external_semaphore_win32)
	pfn_vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)vkGetInstanceProcAddr(vulkan, "vkImportSemaphoreWin32HandleKHR");
	pfn_vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)vkGetInstanceProcAddr(vulkan, "vkGetSemaphoreWin32HandleKHR");
#endif // defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_fd)
	pfn_vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)vkGetInstanceProcAddr(vulkan, "vkImportSemaphoreFdKHR");
	pfn_vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)vkGetInstanceProcAddr(vulkan, "vkGetSemaphoreFdKHR");
#endif // defined(VK_KHR_external_semaphore_fd)

#if defined(VK_KHR_push_descriptor)
	pfn_vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)vkGetInstanceProcAddr(vulkan, "vkCmdPushDescriptorSetKHR");
#endif // defined(VK_KHR_push_descriptor)

#if defined(VK_EXT_conditional_rendering)
	pfn_vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)vkGetInstanceProcAddr(vulkan, "vkCmdBeginConditionalRenderingEXT");
	pfn_vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)vkGetInstanceProcAddr(vulkan, "vkCmdEndConditionalRenderingEXT");
#endif // defined(VK_EXT_conditional_rendering)

#if defined(VK_KHR_descriptor_update_template)
	pfn_vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)vkGetInstanceProcAddr(vulkan, "vkCreateDescriptorUpdateTemplateKHR");
	pfn_vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)vkGetInstanceProcAddr(vulkan, "vkDestroyDescriptorUpdateTemplateKHR");
	pfn_vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)vkGetInstanceProcAddr(vulkan, "vkUpdateDescriptorSetWithTemplateKHR");

#if defined(VK_KHR_push_descriptor)
	pfn_vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)vkGetInstanceProcAddr(vulkan, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif // defined(VK_KHR_push_descriptor)
#endif // defined(VK_KHR_descriptor_update_template)

#if defined(VK_NVX_device_generated_commands)
	pfn_vkCmdProcessCommandsNVX = (PFN_vkCmdProcessCommandsNVX)vkGetInstanceProcAddr(vulkan, "vkCmdProcessCommandsNVX");
	pfn_vkCmdReserveSpaceForCommandsNVX = (PFN_vkCmdReserveSpaceForCommandsNVX)vkGetInstanceProcAddr(vulkan, "vkCmdReserveSpaceForCommandsNVX");
	pfn_vkCreateIndirectCommandsLayoutNVX = (PFN_vkCreateIndirectCommandsLayoutNVX)vkGetInstanceProcAddr(vulkan, "vkCreateIndirectCommandsLayoutNVX");
	pfn_vkDestroyIndirectCommandsLayoutNVX = (PFN_vkDestroyIndirectCommandsLayoutNVX)vkGetInstanceProcAddr(vulkan, "vkDestroyIndirectCommandsLayoutNVX");
	pfn_vkCreateObjectTableNVX = (PFN_vkCreateObjectTableNVX)vkGetInstanceProcAddr(vulkan, "vkCreateObjectTableNVX");
	pfn_vkDestroyObjectTableNVX = (PFN_vkDestroyObjectTableNVX)vkGetInstanceProcAddr(vulkan, "vkDestroyObjectTableNVX");
	pfn_vkRegisterObjectsNVX = (PFN_vkRegisterObjectsNVX)vkGetInstanceProcAddr(vulkan, "vkRegisterObjectsNVX");
	pfn_vkUnregisterObjectsNVX = (PFN_vkUnregisterObjectsNVX)vkGetInstanceProcAddr(vulkan, "vkUnregisterObjectsNVX");
	pfn_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX = (PFN_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX");
#endif // defined(VK_NVX_device_generated_commands)

#if defined(VK_NV_clip_space_w_scaling)
	pfn_vkCmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)vkGetInstanceProcAddr(vulkan, "vkCmdSetViewportWScalingNV");
#endif // defined(VK_NV_clip_space_w_scaling)

#if defined(VK_EXT_direct_mode_display)
	pfn_vkReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT)vkGetInstanceProcAddr(vulkan, "vkReleaseDisplayEXT");
#endif // defined(VK_EXT_direct_mode_display)

#if defined(VK_EXT_acquire_xlib_display)
	pfn_vkAcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT)vkGetInstanceProcAddr(vulkan, "vkAcquireXlibDisplayEXT");
	pfn_vkGetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT)vkGetInstanceProcAddr(vulkan, "vkGetRandROutputDisplayEXT");
#endif // defined(VK_EXT_acquire_xlib_display)

#if defined(VK_EXT_display_surface_counter)
	pfn_vkGetPhysicalDeviceSurfaceCapabilities2EXT = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
#endif // defined(VK_EXT_display_surface_counter)

#if defined(VK_EXT_display_control)
	pfn_vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)vkGetInstanceProcAddr(vulkan, "vkDisplayPowerControlEXT");
	pfn_vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)vkGetInstanceProcAddr(vulkan, "vkRegisterDeviceEventEXT");
	pfn_vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)vkGetInstanceProcAddr(vulkan, "vkRegisterDisplayEventEXT");
	pfn_vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)vkGetInstanceProcAddr(vulkan, "vkGetSwapchainCounterEXT");
#endif // defined(VK_EXT_display_control)

#if defined(VK_GOOGLE_display_timing)
	pfn_vkGetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)vkGetInstanceProcAddr(vulkan, "vkGetRefreshCycleDurationGOOGLE");
	pfn_vkGetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)vkGetInstanceProcAddr(vulkan, "vkGetPastPresentationTimingGOOGLE");
#endif // defined(VK_GOOGLE_display_timing)

#if defined(VK_EXT_discard_rectangles)
	pfn_vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)vkGetInstanceProcAddr(vulkan, "vkCmdSetDiscardRectangleEXT");
#endif // defined(VK_EXT_discard_rectangles)

#if defined(VK_EXT_hdr_metadata)
	pfn_vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)vkGetInstanceProcAddr(vulkan, "vkSetHdrMetadataEXT");
#endif // defined(VK_EXT_hdr_metadata)

#if defined(VK_KHR_create_renderpass2)
	pfn_vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)vkGetInstanceProcAddr(vulkan, "vkCreateRenderPass2KHR");
	pfn_vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)vkGetInstanceProcAddr(vulkan, "vkCmdBeginRenderPass2KHR");
	pfn_vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)vkGetInstanceProcAddr(vulkan, "vkCmdNextSubpass2KHR");
	pfn_vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)vkGetInstanceProcAddr(vulkan, "vkCmdEndRenderPass2KHR");
#endif // defined(VK_KHR_create_renderpass2)

#if defined(VK_KHR_shared_presentable_image)
	pfn_vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)vkGetInstanceProcAddr(vulkan, "vkGetSwapchainStatusKHR");
#endif // defined(VK_KHR_shared_presentable_image)

#if defined(VK_KHR_external_fence_capabilities)
	pfn_vkGetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
#endif // defined(VK_KHR_external_fence_capabilities)

#if defined(VK_KHR_external_fence_win32)
	pfn_vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)vkGetInstanceProcAddr(vulkan, "vkImportFenceWin32HandleKHR");
	pfn_vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)vkGetInstanceProcAddr(vulkan, "vkGetFenceWin32HandleKHR");
#endif // defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_fd)
	pfn_vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR)vkGetInstanceProcAddr(vulkan, "vkImportFenceFdKHR");
	pfn_vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR)vkGetInstanceProcAddr(vulkan, "vkGetFenceFdKHR");
#endif // defined(VK_KHR_external_fence_fd)

#if defined(VK_KHR_get_surface_capabilities2)
	pfn_vkGetPhysicalDeviceSurfaceCapabilities2KHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
	pfn_vkGetPhysicalDeviceSurfaceFormats2KHR = (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSurfaceFormats2KHR");
#endif // defined(VK_KHR_get_surface_capabilities2)

#if defined(VK_KHR_get_display_properties2)
	pfn_vkGetPhysicalDeviceDisplayProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayProperties2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceDisplayProperties2KHR");
	pfn_vkGetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
	pfn_vkGetDisplayModeProperties2KHR = (PFN_vkGetDisplayModeProperties2KHR)vkGetInstanceProcAddr(vulkan, "vkGetDisplayModeProperties2KHR");
	pfn_vkGetDisplayPlaneCapabilities2KHR = (PFN_vkGetDisplayPlaneCapabilities2KHR)vkGetInstanceProcAddr(vulkan, "vkGetDisplayPlaneCapabilities2KHR");
#endif // defined(VK_KHR_get_display_properties2)

#if defined(VK_MVK_ios_surface)
	pfn_vkCreateIOSSurfaceMVK = (PFN_vkCreateIOSSurfaceMVK)vkGetInstanceProcAddr(vulkan, "vkCreateIOSSurfaceMVK");
#endif // defined(VK_MVK_ios_surface)

#if defined(VK_MVK_macos_surface)
	pfn_vkCreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK)vkGetInstanceProcAddr(vulkan, "vkCreateMacOSSurfaceMVK");
#endif // defined(VK_MVK_macos_surface)

#if defined(VK_EXT_debug_utils)
	pfn_vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)vkGetInstanceProcAddr(vulkan, "vkSetDebugUtilsObjectNameEXT");
	pfn_vkSetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)vkGetInstanceProcAddr(vulkan, "vkSetDebugUtilsObjectTagEXT");
	pfn_vkQueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)vkGetInstanceProcAddr(vulkan, "vkQueueBeginDebugUtilsLabelEXT");
	pfn_vkQueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)vkGetInstanceProcAddr(vulkan, "vkQueueEndDebugUtilsLabelEXT");
	pfn_vkQueueInsertDebugUtilsLabelEXT = (PFN_vkQueueInsertDebugUtilsLabelEXT)vkGetInstanceProcAddr(vulkan, "vkQueueInsertDebugUtilsLabelEXT");
	pfn_vkCmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)vkGetInstanceProcAddr(vulkan, "vkCmdBeginDebugUtilsLabelEXT");
	pfn_vkCmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)vkGetInstanceProcAddr(vulkan, "vkCmdEndDebugUtilsLabelEXT");
	pfn_vkCmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)vkGetInstanceProcAddr(vulkan, "vkCmdInsertDebugUtilsLabelEXT");
	pfn_vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(vulkan, "vkCreateDebugUtilsMessengerEXT");
	pfn_vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(vulkan, "vkDestroyDebugUtilsMessengerEXT");
	pfn_vkSubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT)vkGetInstanceProcAddr(vulkan, "vkSubmitDebugUtilsMessageEXT");
#endif // defined(VK_EXT_debug_utils)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
	pfn_vkGetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)vkGetInstanceProcAddr(vulkan, "vkGetAndroidHardwareBufferPropertiesANDROID");
	pfn_vkGetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)vkGetInstanceProcAddr(vulkan, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_EXT_sample_locations)
	pfn_vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)vkGetInstanceProcAddr(vulkan, "vkCmdSetSampleLocationsEXT");
	pfn_vkGetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
#endif // defined(VK_EXT_sample_locations)

#if defined(VK_KHR_get_memory_requirements2)
	pfn_vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)vkGetInstanceProcAddr(vulkan, "vkGetImageMemoryRequirements2KHR");
	pfn_vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)vkGetInstanceProcAddr(vulkan, "vkGetBufferMemoryRequirements2KHR");
	pfn_vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)vkGetInstanceProcAddr(vulkan, "vkGetImageSparseMemoryRequirements2KHR");
#endif // defined(VK_KHR_get_memory_requirements2)

#if defined(VK_KHR_sampler_ycbcr_conversion)
	pfn_vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)vkGetInstanceProcAddr(vulkan, "vkCreateSamplerYcbcrConversionKHR");
	pfn_vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)vkGetInstanceProcAddr(vulkan, "vkDestroySamplerYcbcrConversionKHR");
#endif // defined(VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_bind_memory2)
	pfn_vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)vkGetInstanceProcAddr(vulkan, "vkBindBufferMemory2KHR");
	pfn_vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)vkGetInstanceProcAddr(vulkan, "vkBindImageMemory2KHR");
#endif // defined(VK_KHR_bind_memory2)

#if defined(VK_EXT_image_drm_format_modifier)
	pfn_vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)vkGetInstanceProcAddr(vulkan, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif // defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_validation_cache)
	pfn_vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)vkGetInstanceProcAddr(vulkan, "vkCreateValidationCacheEXT");
	pfn_vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)vkGetInstanceProcAddr(vulkan, "vkDestroyValidationCacheEXT");
	pfn_vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)vkGetInstanceProcAddr(vulkan, "vkMergeValidationCachesEXT");
	pfn_vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)vkGetInstanceProcAddr(vulkan, "vkGetValidationCacheDataEXT");
#endif // defined(VK_EXT_validation_cache)

#if defined(VK_NV_shading_rate_image)
	pfn_vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)vkGetInstanceProcAddr(vulkan, "vkCmdBindShadingRateImageNV");
	pfn_vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)vkGetInstanceProcAddr(vulkan, "vkCmdSetViewportShadingRatePaletteNV");
	pfn_vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)vkGetInstanceProcAddr(vulkan, "vkCmdSetCoarseSampleOrderNV");
#endif // defined(VK_NV_shading_rate_image)

#if defined(VK_NV_ray_tracing)
	pfn_vkCreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)vkGetInstanceProcAddr(vulkan, "vkCreateAccelerationStructureNV");
	pfn_vkDestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)vkGetInstanceProcAddr(vulkan, "vkDestroyAccelerationStructureNV");
	pfn_vkGetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)vkGetInstanceProcAddr(vulkan, "vkGetAccelerationStructureMemoryRequirementsNV");
	pfn_vkBindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)vkGetInstanceProcAddr(vulkan, "vkBindAccelerationStructureMemoryNV");
	pfn_vkCmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)vkGetInstanceProcAddr(vulkan, "vkCmdBuildAccelerationStructureNV");
	pfn_vkCmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)vkGetInstanceProcAddr(vulkan, "vkCmdCopyAccelerationStructureNV");
	pfn_vkCmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)vkGetInstanceProcAddr(vulkan, "vkCmdTraceRaysNV");
	pfn_vkCreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)vkGetInstanceProcAddr(vulkan, "vkCreateRayTracingPipelinesNV");
	pfn_vkGetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)vkGetInstanceProcAddr(vulkan, "vkGetRayTracingShaderGroupHandlesNV");
	pfn_vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)vkGetInstanceProcAddr(vulkan, "vkGetAccelerationStructureHandleNV");
	pfn_vkCmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)vkGetInstanceProcAddr(vulkan, "vkCmdWriteAccelerationStructuresPropertiesNV");
	pfn_vkCompileDeferredNV = (PFN_vkCompileDeferredNV)vkGetInstanceProcAddr(vulkan, "vkCompileDeferredNV");
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_KHR_maintenance3)
	pfn_vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)vkGetInstanceProcAddr(vulkan, "vkGetDescriptorSetLayoutSupportKHR");
#endif // defined(VK_KHR_maintenance3)

#if defined(VK_KHR_draw_indirect_count)
	pfn_vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)vkGetInstanceProcAddr(vulkan, "vkCmdDrawIndirectCountKHR");
	pfn_vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR)vkGetInstanceProcAddr(vulkan, "vkCmdDrawIndexedIndirectCountKHR");
#endif // defined(VK_KHR_draw_indirect_count)

#if defined(VK_EXT_external_memory_host)
	pfn_vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)vkGetInstanceProcAddr(vulkan, "vkGetMemoryHostPointerPropertiesEXT");
#endif // defined(VK_EXT_external_memory_host)

#if defined(VK_AMD_buffer_marker)
	pfn_vkCmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)vkGetInstanceProcAddr(vulkan, "vkCmdWriteBufferMarkerAMD");
#endif // defined(VK_AMD_buffer_marker)

#if defined(VK_EXT_calibrated_timestamps)
	pfn_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
	pfn_vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)vkGetInstanceProcAddr(vulkan, "vkGetCalibratedTimestampsEXT");
#endif // defined(VK_EXT_calibrated_timestamps)

#if defined(VK_NV_mesh_shader)
	pfn_vkCmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)vkGetInstanceProcAddr(vulkan, "vkCmdDrawMeshTasksNV");
	pfn_vkCmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)vkGetInstanceProcAddr(vulkan, "vkCmdDrawMeshTasksIndirectNV");
	pfn_vkCmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)vkGetInstanceProcAddr(vulkan, "vkCmdDrawMeshTasksIndirectCountNV");
#endif // defined(VK_NV_mesh_shader)

#if defined(VK_NV_scissor_exclusive)
	pfn_vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)vkGetInstanceProcAddr(vulkan, "vkCmdSetExclusiveScissorNV");
#endif // defined(VK_NV_scissor_exclusive)

#if defined(VK_NV_device_diagnostic_checkpoints)
	pfn_vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)vkGetInstanceProcAddr(vulkan, "vkCmdSetCheckpointNV");
	pfn_vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)vkGetInstanceProcAddr(vulkan, "vkGetQueueCheckpointDataNV");
#endif // defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_INTEL_performance_query)
	pfn_vkInitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)vkGetInstanceProcAddr(vulkan, "vkInitializePerformanceApiINTEL");
	pfn_vkUninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)vkGetInstanceProcAddr(vulkan, "vkUninitializePerformanceApiINTEL");
	pfn_vkCmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)vkGetInstanceProcAddr(vulkan, "vkCmdSetPerformanceMarkerINTEL");
	pfn_vkCmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)vkGetInstanceProcAddr(vulkan, "vkCmdSetPerformanceStreamMarkerINTEL");
	pfn_vkCmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)vkGetInstanceProcAddr(vulkan, "vkCmdSetPerformanceOverrideINTEL");
	pfn_vkAcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)vkGetInstanceProcAddr(vulkan, "vkAcquirePerformanceConfigurationINTEL");
	pfn_vkReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)vkGetInstanceProcAddr(vulkan, "vkReleasePerformanceConfigurationINTEL");
	pfn_vkQueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)vkGetInstanceProcAddr(vulkan, "vkQueueSetPerformanceConfigurationINTEL");
	pfn_vkGetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)vkGetInstanceProcAddr(vulkan, "vkGetPerformanceParameterINTEL");
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_AMD_display_native_hdr)
	pfn_vkSetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)vkGetInstanceProcAddr(vulkan, "vkSetLocalDimmingAMD");
#endif // defined(VK_AMD_display_native_hdr)

#if defined(VK_FUCHSIA_imagepipe_surface)
	pfn_vkCreateImagePipeSurfaceFUCHSIA = (PFN_vkCreateImagePipeSurfaceFUCHSIA)vkGetInstanceProcAddr(vulkan, "vkCreateImagePipeSurfaceFUCHSIA");
#endif // defined(VK_FUCHSIA_imagepipe_surface)

#if defined(VK_EXT_metal_surface)
	pfn_vkCreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT)vkGetInstanceProcAddr(vulkan, "vkCreateMetalSurfaceEXT");
#endif // defined(VK_EXT_metal_surface)

#if defined(VK_EXT_buffer_device_address)
	pfn_vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)vkGetInstanceProcAddr(vulkan, "vkGetBufferDeviceAddressEXT");
#endif // defined(VK_EXT_buffer_device_address)

#if defined(VK_NV_cooperative_matrix)
	pfn_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
#endif // defined(VK_NV_cooperative_matrix)

#if defined(VK_NV_coverage_reduction_mode)
	pfn_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
#endif // defined(VK_NV_coverage_reduction_mode)

#if defined(VK_EXT_full_screen_exclusive)
	pfn_vkGetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)vkGetInstanceProcAddr(vulkan, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
	pfn_vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)vkGetInstanceProcAddr(vulkan, "vkAcquireFullScreenExclusiveModeEXT");
	pfn_vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)vkGetInstanceProcAddr(vulkan, "vkReleaseFullScreenExclusiveModeEXT");

#if defined(VK_KHR_device_group)
	pfn_vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)vkGetInstanceProcAddr(vulkan, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif // defined(VK_KHR_device_group)
#endif // defined(VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_headless_surface)
	pfn_vkCreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT)vkGetInstanceProcAddr(vulkan, "vkCreateHeadlessSurfaceEXT");
#endif // defined(VK_EXT_headless_surface)

#if defined(VK_EXT_line_rasterization)
	pfn_vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)vkGetInstanceProcAddr(vulkan, "vkCmdSetLineStippleEXT");
#endif // defined(VK_EXT_line_rasterization)

#if defined(VK_EXT_host_query_reset)
	pfn_vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)vkGetInstanceProcAddr(vulkan, "vkResetQueryPoolEXT");
#endif // defined(VK_EXT_host_query_reset)

#if defined(VK_KHR_pipeline_executable_properties)
	pfn_vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)vkGetInstanceProcAddr(vulkan, "vkGetPipelineExecutablePropertiesKHR");
	pfn_vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)vkGetInstanceProcAddr(vulkan, "vkGetPipelineExecutableStatisticsKHR");
	pfn_vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)vkGetInstanceProcAddr(vulkan, "vkGetPipelineExecutableInternalRepresentationsKHR");
#endif // defined(VK_KHR_pipeline_executable_properties)
}

void vulkan_load_device_procs(VkDevice device)
{

#if defined(VK_KHR_swapchain)
	pfn_vkCreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)vkGetDeviceProcAddr(device, "vkCreateSwapchainKHR");
	pfn_vkDestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)vkGetDeviceProcAddr(device, "vkDestroySwapchainKHR");
	pfn_vkGetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)vkGetDeviceProcAddr(device, "vkGetSwapchainImagesKHR");
	pfn_vkAcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)vkGetDeviceProcAddr(device, "vkAcquireNextImageKHR");
	pfn_vkQueuePresentKHR = (PFN_vkQueuePresentKHR)vkGetDeviceProcAddr(device, "vkQueuePresentKHR");
#endif // defined(VK_KHR_swapchain)

#if defined(VK_KHR_display_swapchain)
	pfn_vkCreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)vkGetDeviceProcAddr(device, "vkCreateSharedSwapchainsKHR");
#endif // defined(VK_KHR_display_swapchain)

#if defined(VK_ANDROID_native_buffer)
	pfn_vkGetSwapchainGrallocUsageANDROID = (PFN_vkGetSwapchainGrallocUsageANDROID)vkGetDeviceProcAddr(device, "vkGetSwapchainGrallocUsageANDROID");
	pfn_vkAcquireImageANDROID = (PFN_vkAcquireImageANDROID)vkGetDeviceProcAddr(device, "vkAcquireImageANDROID");
	pfn_vkQueueSignalReleaseImageANDROID = (PFN_vkQueueSignalReleaseImageANDROID)vkGetDeviceProcAddr(device, "vkQueueSignalReleaseImageANDROID");
	pfn_vkGetSwapchainGrallocUsage2ANDROID = (PFN_vkGetSwapchainGrallocUsage2ANDROID)vkGetDeviceProcAddr(device, "vkGetSwapchainGrallocUsage2ANDROID");
#endif // defined(VK_ANDROID_native_buffer)

#if defined(VK_EXT_debug_marker)
	pfn_vkDebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)vkGetDeviceProcAddr(device, "vkDebugMarkerSetObjectTagEXT");
	pfn_vkDebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)vkGetDeviceProcAddr(device, "vkDebugMarkerSetObjectNameEXT");
	pfn_vkCmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)vkGetDeviceProcAddr(device, "vkCmdDebugMarkerBeginEXT");
	pfn_vkCmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)vkGetDeviceProcAddr(device, "vkCmdDebugMarkerEndEXT");
	pfn_vkCmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)vkGetDeviceProcAddr(device, "vkCmdDebugMarkerInsertEXT");
#endif // defined(VK_EXT_debug_marker)

#if defined(VK_EXT_transform_feedback)
	pfn_vkCmdBindTransformFeedbackBuffersEXT = (PFN_vkCmdBindTransformFeedbackBuffersEXT)vkGetDeviceProcAddr(device, "vkCmdBindTransformFeedbackBuffersEXT");
	pfn_vkCmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)vkGetDeviceProcAddr(device, "vkCmdBeginTransformFeedbackEXT");
	pfn_vkCmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)vkGetDeviceProcAddr(device, "vkCmdEndTransformFeedbackEXT");
	pfn_vkCmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)vkGetDeviceProcAddr(device, "vkCmdBeginQueryIndexedEXT");
	pfn_vkCmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)vkGetDeviceProcAddr(device, "vkCmdEndQueryIndexedEXT");
	pfn_vkCmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)vkGetDeviceProcAddr(device, "vkCmdDrawIndirectByteCountEXT");
#endif // defined(VK_EXT_transform_feedback)

#if defined(VK_NVX_image_view_handle)
	pfn_vkGetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)vkGetDeviceProcAddr(device, "vkGetImageViewHandleNVX");
#endif // defined(VK_NVX_image_view_handle)

#if defined(VK_AMD_draw_indirect_count)
	pfn_vkCmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)vkGetDeviceProcAddr(device, "vkCmdDrawIndirectCountAMD");
	pfn_vkCmdDrawIndexedIndirectCountAMD = (PFN_vkCmdDrawIndexedIndirectCountAMD)vkGetDeviceProcAddr(device, "vkCmdDrawIndexedIndirectCountAMD");
#endif // defined(VK_AMD_draw_indirect_count)

#if defined(VK_AMD_shader_info)
	pfn_vkGetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)vkGetDeviceProcAddr(device, "vkGetShaderInfoAMD");
#endif // defined(VK_AMD_shader_info)

#if defined(VK_NV_external_memory_win32)
	pfn_vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)vkGetDeviceProcAddr(device, "vkGetMemoryWin32HandleNV");
#endif // defined(VK_NV_external_memory_win32)

#if defined(VK_KHR_device_group)
	pfn_vkGetDeviceGroupPeerMemoryFeaturesKHR = (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)vkGetDeviceProcAddr(device, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
	pfn_vkCmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)vkGetDeviceProcAddr(device, "vkCmdSetDeviceMaskKHR");
	pfn_vkCmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)vkGetDeviceProcAddr(device, "vkCmdDispatchBaseKHR");

#if defined(VK_KHR_surface)
	pfn_vkGetDeviceGroupPresentCapabilitiesKHR = (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)vkGetDeviceProcAddr(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
	pfn_vkGetDeviceGroupSurfacePresentModesKHR = (PFN_vkGetDeviceGroupSurfacePresentModesKHR)vkGetDeviceProcAddr(device, "vkGetDeviceGroupSurfacePresentModesKHR");
	pfn_vkGetPhysicalDevicePresentRectanglesKHR = (PFN_vkGetPhysicalDevicePresentRectanglesKHR)vkGetDeviceProcAddr(device, "vkGetPhysicalDevicePresentRectanglesKHR");
#endif // defined(VK_KHR_surface)

#if defined(VK_KHR_swapchain)
	pfn_vkAcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)vkGetDeviceProcAddr(device, "vkAcquireNextImage2KHR");
#endif // defined(VK_KHR_swapchain)
#endif // defined(VK_KHR_device_group)

#if defined(VK_KHR_maintenance1)
	pfn_vkTrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)vkGetDeviceProcAddr(device, "vkTrimCommandPoolKHR");
#endif // defined(VK_KHR_maintenance1)

#if defined(VK_KHR_external_memory_win32)
	pfn_vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)vkGetDeviceProcAddr(device, "vkGetMemoryWin32HandleKHR");
	pfn_vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)vkGetDeviceProcAddr(device, "vkGetMemoryWin32HandlePropertiesKHR");
#endif // defined(VK_KHR_external_memory_win32)

#if defined(VK_KHR_external_memory_fd)
	pfn_vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)vkGetDeviceProcAddr(device, "vkGetMemoryFdKHR");
	pfn_vkGetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)vkGetDeviceProcAddr(device, "vkGetMemoryFdPropertiesKHR");
#endif // defined(VK_KHR_external_memory_fd)

#if defined(VK_KHR_external_semaphore_win32)
	pfn_vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)vkGetDeviceProcAddr(device, "vkImportSemaphoreWin32HandleKHR");
	pfn_vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)vkGetDeviceProcAddr(device, "vkGetSemaphoreWin32HandleKHR");
#endif // defined(VK_KHR_external_semaphore_win32)

#if defined(VK_KHR_external_semaphore_fd)
	pfn_vkImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)vkGetDeviceProcAddr(device, "vkImportSemaphoreFdKHR");
	pfn_vkGetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)vkGetDeviceProcAddr(device, "vkGetSemaphoreFdKHR");
#endif // defined(VK_KHR_external_semaphore_fd)

#if defined(VK_KHR_push_descriptor)
	pfn_vkCmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)vkGetDeviceProcAddr(device, "vkCmdPushDescriptorSetKHR");
#endif // defined(VK_KHR_push_descriptor)

#if defined(VK_EXT_conditional_rendering)
	pfn_vkCmdBeginConditionalRenderingEXT = (PFN_vkCmdBeginConditionalRenderingEXT)vkGetDeviceProcAddr(device, "vkCmdBeginConditionalRenderingEXT");
	pfn_vkCmdEndConditionalRenderingEXT = (PFN_vkCmdEndConditionalRenderingEXT)vkGetDeviceProcAddr(device, "vkCmdEndConditionalRenderingEXT");
#endif // defined(VK_EXT_conditional_rendering)

#if defined(VK_KHR_descriptor_update_template)
	pfn_vkCreateDescriptorUpdateTemplateKHR = (PFN_vkCreateDescriptorUpdateTemplateKHR)vkGetDeviceProcAddr(device, "vkCreateDescriptorUpdateTemplateKHR");
	pfn_vkDestroyDescriptorUpdateTemplateKHR = (PFN_vkDestroyDescriptorUpdateTemplateKHR)vkGetDeviceProcAddr(device, "vkDestroyDescriptorUpdateTemplateKHR");
	pfn_vkUpdateDescriptorSetWithTemplateKHR = (PFN_vkUpdateDescriptorSetWithTemplateKHR)vkGetDeviceProcAddr(device, "vkUpdateDescriptorSetWithTemplateKHR");

#if defined(VK_KHR_push_descriptor)
	pfn_vkCmdPushDescriptorSetWithTemplateKHR = (PFN_vkCmdPushDescriptorSetWithTemplateKHR)vkGetDeviceProcAddr(device, "vkCmdPushDescriptorSetWithTemplateKHR");
#endif // defined(VK_KHR_push_descriptor)
#endif // defined(VK_KHR_descriptor_update_template)

#if defined(VK_NVX_device_generated_commands)
	pfn_vkCmdProcessCommandsNVX = (PFN_vkCmdProcessCommandsNVX)vkGetDeviceProcAddr(device, "vkCmdProcessCommandsNVX");
	pfn_vkCmdReserveSpaceForCommandsNVX = (PFN_vkCmdReserveSpaceForCommandsNVX)vkGetDeviceProcAddr(device, "vkCmdReserveSpaceForCommandsNVX");
	pfn_vkCreateIndirectCommandsLayoutNVX = (PFN_vkCreateIndirectCommandsLayoutNVX)vkGetDeviceProcAddr(device, "vkCreateIndirectCommandsLayoutNVX");
	pfn_vkDestroyIndirectCommandsLayoutNVX = (PFN_vkDestroyIndirectCommandsLayoutNVX)vkGetDeviceProcAddr(device, "vkDestroyIndirectCommandsLayoutNVX");
	pfn_vkCreateObjectTableNVX = (PFN_vkCreateObjectTableNVX)vkGetDeviceProcAddr(device, "vkCreateObjectTableNVX");
	pfn_vkDestroyObjectTableNVX = (PFN_vkDestroyObjectTableNVX)vkGetDeviceProcAddr(device, "vkDestroyObjectTableNVX");
	pfn_vkRegisterObjectsNVX = (PFN_vkRegisterObjectsNVX)vkGetDeviceProcAddr(device, "vkRegisterObjectsNVX");
	pfn_vkUnregisterObjectsNVX = (PFN_vkUnregisterObjectsNVX)vkGetDeviceProcAddr(device, "vkUnregisterObjectsNVX");
	pfn_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX = (PFN_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX)vkGetDeviceProcAddr(device, "vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX");
#endif // defined(VK_NVX_device_generated_commands)

#if defined(VK_NV_clip_space_w_scaling)
	pfn_vkCmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)vkGetDeviceProcAddr(device, "vkCmdSetViewportWScalingNV");
#endif // defined(VK_NV_clip_space_w_scaling)

#if defined(VK_EXT_display_control)
	pfn_vkDisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)vkGetDeviceProcAddr(device, "vkDisplayPowerControlEXT");
	pfn_vkRegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)vkGetDeviceProcAddr(device, "vkRegisterDeviceEventEXT");
	pfn_vkRegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)vkGetDeviceProcAddr(device, "vkRegisterDisplayEventEXT");
	pfn_vkGetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)vkGetDeviceProcAddr(device, "vkGetSwapchainCounterEXT");
#endif // defined(VK_EXT_display_control)

#if defined(VK_GOOGLE_display_timing)
	pfn_vkGetRefreshCycleDurationGOOGLE = (PFN_vkGetRefreshCycleDurationGOOGLE)vkGetDeviceProcAddr(device, "vkGetRefreshCycleDurationGOOGLE");
	pfn_vkGetPastPresentationTimingGOOGLE = (PFN_vkGetPastPresentationTimingGOOGLE)vkGetDeviceProcAddr(device, "vkGetPastPresentationTimingGOOGLE");
#endif // defined(VK_GOOGLE_display_timing)

#if defined(VK_EXT_discard_rectangles)
	pfn_vkCmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)vkGetDeviceProcAddr(device, "vkCmdSetDiscardRectangleEXT");
#endif // defined(VK_EXT_discard_rectangles)

#if defined(VK_EXT_hdr_metadata)
	pfn_vkSetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)vkGetDeviceProcAddr(device, "vkSetHdrMetadataEXT");
#endif // defined(VK_EXT_hdr_metadata)

#if defined(VK_KHR_create_renderpass2)
	pfn_vkCreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)vkGetDeviceProcAddr(device, "vkCreateRenderPass2KHR");
	pfn_vkCmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)vkGetDeviceProcAddr(device, "vkCmdBeginRenderPass2KHR");
	pfn_vkCmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)vkGetDeviceProcAddr(device, "vkCmdNextSubpass2KHR");
	pfn_vkCmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)vkGetDeviceProcAddr(device, "vkCmdEndRenderPass2KHR");
#endif // defined(VK_KHR_create_renderpass2)

#if defined(VK_KHR_shared_presentable_image)
	pfn_vkGetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)vkGetDeviceProcAddr(device, "vkGetSwapchainStatusKHR");
#endif // defined(VK_KHR_shared_presentable_image)

#if defined(VK_KHR_external_fence_win32)
	pfn_vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)vkGetDeviceProcAddr(device, "vkImportFenceWin32HandleKHR");
	pfn_vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)vkGetDeviceProcAddr(device, "vkGetFenceWin32HandleKHR");
#endif // defined(VK_KHR_external_fence_win32)

#if defined(VK_KHR_external_fence_fd)
	pfn_vkImportFenceFdKHR = (PFN_vkImportFenceFdKHR)vkGetDeviceProcAddr(device, "vkImportFenceFdKHR");
	pfn_vkGetFenceFdKHR = (PFN_vkGetFenceFdKHR)vkGetDeviceProcAddr(device, "vkGetFenceFdKHR");
#endif // defined(VK_KHR_external_fence_fd)

#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
	pfn_vkGetAndroidHardwareBufferPropertiesANDROID = (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)vkGetDeviceProcAddr(device, "vkGetAndroidHardwareBufferPropertiesANDROID");
	pfn_vkGetMemoryAndroidHardwareBufferANDROID = (PFN_vkGetMemoryAndroidHardwareBufferANDROID)vkGetDeviceProcAddr(device, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)

#if defined(VK_EXT_sample_locations)
	pfn_vkCmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)vkGetDeviceProcAddr(device, "vkCmdSetSampleLocationsEXT");
	pfn_vkGetPhysicalDeviceMultisamplePropertiesEXT = (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT)vkGetDeviceProcAddr(device, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
#endif // defined(VK_EXT_sample_locations)

#if defined(VK_KHR_get_memory_requirements2)
	pfn_vkGetImageMemoryRequirements2KHR = (PFN_vkGetImageMemoryRequirements2KHR)vkGetDeviceProcAddr(device, "vkGetImageMemoryRequirements2KHR");
	pfn_vkGetBufferMemoryRequirements2KHR = (PFN_vkGetBufferMemoryRequirements2KHR)vkGetDeviceProcAddr(device, "vkGetBufferMemoryRequirements2KHR");
	pfn_vkGetImageSparseMemoryRequirements2KHR = (PFN_vkGetImageSparseMemoryRequirements2KHR)vkGetDeviceProcAddr(device, "vkGetImageSparseMemoryRequirements2KHR");
#endif // defined(VK_KHR_get_memory_requirements2)

#if defined(VK_KHR_sampler_ycbcr_conversion)
	pfn_vkCreateSamplerYcbcrConversionKHR = (PFN_vkCreateSamplerYcbcrConversionKHR)vkGetDeviceProcAddr(device, "vkCreateSamplerYcbcrConversionKHR");
	pfn_vkDestroySamplerYcbcrConversionKHR = (PFN_vkDestroySamplerYcbcrConversionKHR)vkGetDeviceProcAddr(device, "vkDestroySamplerYcbcrConversionKHR");
#endif // defined(VK_KHR_sampler_ycbcr_conversion)

#if defined(VK_KHR_bind_memory2)
	pfn_vkBindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)vkGetDeviceProcAddr(device, "vkBindBufferMemory2KHR");
	pfn_vkBindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)vkGetDeviceProcAddr(device, "vkBindImageMemory2KHR");
#endif // defined(VK_KHR_bind_memory2)

#if defined(VK_EXT_image_drm_format_modifier)
	pfn_vkGetImageDrmFormatModifierPropertiesEXT = (PFN_vkGetImageDrmFormatModifierPropertiesEXT)vkGetDeviceProcAddr(device, "vkGetImageDrmFormatModifierPropertiesEXT");
#endif // defined(VK_EXT_image_drm_format_modifier)

#if defined(VK_EXT_validation_cache)
	pfn_vkCreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)vkGetDeviceProcAddr(device, "vkCreateValidationCacheEXT");
	pfn_vkDestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)vkGetDeviceProcAddr(device, "vkDestroyValidationCacheEXT");
	pfn_vkMergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)vkGetDeviceProcAddr(device, "vkMergeValidationCachesEXT");
	pfn_vkGetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)vkGetDeviceProcAddr(device, "vkGetValidationCacheDataEXT");
#endif // defined(VK_EXT_validation_cache)

#if defined(VK_NV_shading_rate_image)
	pfn_vkCmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)vkGetDeviceProcAddr(device, "vkCmdBindShadingRateImageNV");
	pfn_vkCmdSetViewportShadingRatePaletteNV = (PFN_vkCmdSetViewportShadingRatePaletteNV)vkGetDeviceProcAddr(device, "vkCmdSetViewportShadingRatePaletteNV");
	pfn_vkCmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)vkGetDeviceProcAddr(device, "vkCmdSetCoarseSampleOrderNV");
#endif // defined(VK_NV_shading_rate_image)

#if defined(VK_NV_ray_tracing)
	pfn_vkCreateAccelerationStructureNV = (PFN_vkCreateAccelerationStructureNV)vkGetDeviceProcAddr(device, "vkCreateAccelerationStructureNV");
	pfn_vkDestroyAccelerationStructureNV = (PFN_vkDestroyAccelerationStructureNV)vkGetDeviceProcAddr(device, "vkDestroyAccelerationStructureNV");
	pfn_vkGetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)vkGetDeviceProcAddr(device, "vkGetAccelerationStructureMemoryRequirementsNV");
	pfn_vkBindAccelerationStructureMemoryNV = (PFN_vkBindAccelerationStructureMemoryNV)vkGetDeviceProcAddr(device, "vkBindAccelerationStructureMemoryNV");
	pfn_vkCmdBuildAccelerationStructureNV = (PFN_vkCmdBuildAccelerationStructureNV)vkGetDeviceProcAddr(device, "vkCmdBuildAccelerationStructureNV");
	pfn_vkCmdCopyAccelerationStructureNV = (PFN_vkCmdCopyAccelerationStructureNV)vkGetDeviceProcAddr(device, "vkCmdCopyAccelerationStructureNV");
	pfn_vkCmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)vkGetDeviceProcAddr(device, "vkCmdTraceRaysNV");
	pfn_vkCreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)vkGetDeviceProcAddr(device, "vkCreateRayTracingPipelinesNV");
	pfn_vkGetRayTracingShaderGroupHandlesNV = (PFN_vkGetRayTracingShaderGroupHandlesNV)vkGetDeviceProcAddr(device, "vkGetRayTracingShaderGroupHandlesNV");
	pfn_vkGetAccelerationStructureHandleNV = (PFN_vkGetAccelerationStructureHandleNV)vkGetDeviceProcAddr(device, "vkGetAccelerationStructureHandleNV");
	pfn_vkCmdWriteAccelerationStructuresPropertiesNV = (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)vkGetDeviceProcAddr(device, "vkCmdWriteAccelerationStructuresPropertiesNV");
	pfn_vkCompileDeferredNV = (PFN_vkCompileDeferredNV)vkGetDeviceProcAddr(device, "vkCompileDeferredNV");
#endif // defined(VK_NV_ray_tracing)

#if defined(VK_KHR_maintenance3)
	pfn_vkGetDescriptorSetLayoutSupportKHR = (PFN_vkGetDescriptorSetLayoutSupportKHR)vkGetDeviceProcAddr(device, "vkGetDescriptorSetLayoutSupportKHR");
#endif // defined(VK_KHR_maintenance3)

#if defined(VK_KHR_draw_indirect_count)
	pfn_vkCmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)vkGetDeviceProcAddr(device, "vkCmdDrawIndirectCountKHR");
	pfn_vkCmdDrawIndexedIndirectCountKHR = (PFN_vkCmdDrawIndexedIndirectCountKHR)vkGetDeviceProcAddr(device, "vkCmdDrawIndexedIndirectCountKHR");
#endif // defined(VK_KHR_draw_indirect_count)

#if defined(VK_EXT_external_memory_host)
	pfn_vkGetMemoryHostPointerPropertiesEXT = (PFN_vkGetMemoryHostPointerPropertiesEXT)vkGetDeviceProcAddr(device, "vkGetMemoryHostPointerPropertiesEXT");
#endif // defined(VK_EXT_external_memory_host)

#if defined(VK_AMD_buffer_marker)
	pfn_vkCmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)vkGetDeviceProcAddr(device, "vkCmdWriteBufferMarkerAMD");
#endif // defined(VK_AMD_buffer_marker)

#if defined(VK_EXT_calibrated_timestamps)
	pfn_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT)vkGetDeviceProcAddr(device, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
	pfn_vkGetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)vkGetDeviceProcAddr(device, "vkGetCalibratedTimestampsEXT");
#endif // defined(VK_EXT_calibrated_timestamps)

#if defined(VK_NV_mesh_shader)
	pfn_vkCmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)vkGetDeviceProcAddr(device, "vkCmdDrawMeshTasksNV");
	pfn_vkCmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)vkGetDeviceProcAddr(device, "vkCmdDrawMeshTasksIndirectNV");
	pfn_vkCmdDrawMeshTasksIndirectCountNV = (PFN_vkCmdDrawMeshTasksIndirectCountNV)vkGetDeviceProcAddr(device, "vkCmdDrawMeshTasksIndirectCountNV");
#endif // defined(VK_NV_mesh_shader)

#if defined(VK_NV_scissor_exclusive)
	pfn_vkCmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)vkGetDeviceProcAddr(device, "vkCmdSetExclusiveScissorNV");
#endif // defined(VK_NV_scissor_exclusive)

#if defined(VK_NV_device_diagnostic_checkpoints)
	pfn_vkCmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)vkGetDeviceProcAddr(device, "vkCmdSetCheckpointNV");
	pfn_vkGetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)vkGetDeviceProcAddr(device, "vkGetQueueCheckpointDataNV");
#endif // defined(VK_NV_device_diagnostic_checkpoints)

#if defined(VK_INTEL_performance_query)
	pfn_vkInitializePerformanceApiINTEL = (PFN_vkInitializePerformanceApiINTEL)vkGetDeviceProcAddr(device, "vkInitializePerformanceApiINTEL");
	pfn_vkUninitializePerformanceApiINTEL = (PFN_vkUninitializePerformanceApiINTEL)vkGetDeviceProcAddr(device, "vkUninitializePerformanceApiINTEL");
	pfn_vkCmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)vkGetDeviceProcAddr(device, "vkCmdSetPerformanceMarkerINTEL");
	pfn_vkCmdSetPerformanceStreamMarkerINTEL = (PFN_vkCmdSetPerformanceStreamMarkerINTEL)vkGetDeviceProcAddr(device, "vkCmdSetPerformanceStreamMarkerINTEL");
	pfn_vkCmdSetPerformanceOverrideINTEL = (PFN_vkCmdSetPerformanceOverrideINTEL)vkGetDeviceProcAddr(device, "vkCmdSetPerformanceOverrideINTEL");
	pfn_vkAcquirePerformanceConfigurationINTEL = (PFN_vkAcquirePerformanceConfigurationINTEL)vkGetDeviceProcAddr(device, "vkAcquirePerformanceConfigurationINTEL");
	pfn_vkReleasePerformanceConfigurationINTEL = (PFN_vkReleasePerformanceConfigurationINTEL)vkGetDeviceProcAddr(device, "vkReleasePerformanceConfigurationINTEL");
	pfn_vkQueueSetPerformanceConfigurationINTEL = (PFN_vkQueueSetPerformanceConfigurationINTEL)vkGetDeviceProcAddr(device, "vkQueueSetPerformanceConfigurationINTEL");
	pfn_vkGetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)vkGetDeviceProcAddr(device, "vkGetPerformanceParameterINTEL");
#endif // defined(VK_INTEL_performance_query)

#if defined(VK_AMD_display_native_hdr)
	pfn_vkSetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)vkGetDeviceProcAddr(device, "vkSetLocalDimmingAMD");
#endif // defined(VK_AMD_display_native_hdr)

#if defined(VK_EXT_buffer_device_address)
	pfn_vkGetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)vkGetDeviceProcAddr(device, "vkGetBufferDeviceAddressEXT");
#endif // defined(VK_EXT_buffer_device_address)

#if defined(VK_NV_cooperative_matrix)
	pfn_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV)vkGetDeviceProcAddr(device, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
#endif // defined(VK_NV_cooperative_matrix)

#if defined(VK_NV_coverage_reduction_mode)
	pfn_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV)vkGetDeviceProcAddr(device, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
#endif // defined(VK_NV_coverage_reduction_mode)

#if defined(VK_EXT_full_screen_exclusive)
	pfn_vkGetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)vkGetDeviceProcAddr(device, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
	pfn_vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)vkGetDeviceProcAddr(device, "vkAcquireFullScreenExclusiveModeEXT");
	pfn_vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)vkGetDeviceProcAddr(device, "vkReleaseFullScreenExclusiveModeEXT");

#if defined(VK_KHR_device_group)
	pfn_vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)vkGetDeviceProcAddr(device, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif // defined(VK_KHR_device_group)
#endif // defined(VK_EXT_full_screen_exclusive)

#if defined(VK_EXT_line_rasterization)
	pfn_vkCmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)vkGetDeviceProcAddr(device, "vkCmdSetLineStippleEXT");
#endif // defined(VK_EXT_line_rasterization)

#if defined(VK_EXT_host_query_reset)
	pfn_vkResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)vkGetDeviceProcAddr(device, "vkResetQueryPoolEXT");
#endif // defined(VK_EXT_host_query_reset)

#if defined(VK_KHR_pipeline_executable_properties)
	pfn_vkGetPipelineExecutablePropertiesKHR = (PFN_vkGetPipelineExecutablePropertiesKHR)vkGetDeviceProcAddr(device, "vkGetPipelineExecutablePropertiesKHR");
	pfn_vkGetPipelineExecutableStatisticsKHR = (PFN_vkGetPipelineExecutableStatisticsKHR)vkGetDeviceProcAddr(device, "vkGetPipelineExecutableStatisticsKHR");
	pfn_vkGetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)vkGetDeviceProcAddr(device, "vkGetPipelineExecutableInternalRepresentationsKHR");
#endif // defined(VK_KHR_pipeline_executable_properties)
}


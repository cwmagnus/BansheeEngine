//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Marko Pintera (marko.pintera@gmail.com). All rights reserved. **********************//
#pragma once

#include "BsVulkanPrerequisites.h"
#include "BsHardwareBufferManager.h"

namespace bs { namespace ct
{
	/** @addtogroup Vulkan
	 *  @{
	 */

	/**	Handles creation of Vulkan hardware buffers. */
	class VulkanHardwareBufferManager : public HardwareBufferManager
	{
	public:
		VulkanHardwareBufferManager();
		~VulkanHardwareBufferManager();

		/** Returns a buffer view that can be used for buffer read operations when no other buffer is bound. */
		VkBufferView getDummyReadBufferView(UINT32 deviceIdx) const;

		/** Returns a buffer view that can be used for buffer storage operations when no other buffer is bound. */
		VkBufferView getDummyStorageBufferView(UINT32 deviceIdx) const;

		/** Returns a buffer that can be used for uniform storage when no other buffer is bound. */
		VkBuffer getDummyUniformBuffer(UINT32 deviceIdx) const;

	protected:     
		/** @copydoc HardwareBufferManager::createVertexBufferInternal */
		SPtr<VertexBuffer> createVertexBufferInternal(const VERTEX_BUFFER_DESC& desc, 
			GpuDeviceFlags deviceMask = GDF_DEFAULT) override;

		/** @copydoc HardwareBufferManager::createIndexBufferInternal */
		SPtr<IndexBuffer> createIndexBufferInternal(const INDEX_BUFFER_DESC& desc, 
			GpuDeviceFlags deviceMask = GDF_DEFAULT) override;

		/** @copydoc HardwareBufferManager::createGpuParamBlockBufferInternal  */
		SPtr<GpuParamBlockBuffer> createGpuParamBlockBufferInternal(UINT32 size, 
			GpuParamBlockUsage usage = GPBU_DYNAMIC, GpuDeviceFlags deviceMask = GDF_DEFAULT) override;

		/** @copydoc HardwareBufferManager::createGpuBufferInternal */
		SPtr<GpuBuffer> createGpuBufferInternal(const GPU_BUFFER_DESC& desc,
			GpuDeviceFlags deviceMask = GDF_DEFAULT) override;

		/** @copydoc HardwareBufferManager::createGpuParamsInternal */
		SPtr<GpuParams> createGpuParamsInternal(const SPtr<GpuPipelineParamInfo>& paramInfo,
													GpuDeviceFlags deviceMask = GDF_DEFAULT) override;

		VulkanHardwareBuffer* mDummyReadBuffer;
		VulkanHardwareBuffer* mDummyStorageBuffer;
		VulkanHardwareBuffer* mDummyUniformBuffer;
	};

	/** @} */
}}
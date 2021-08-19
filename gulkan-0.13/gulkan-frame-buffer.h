/*
 * gulkan
 * Copyright 2018 Collabora Ltd.
 * Author: Lubosz Sarnecki <lubosz.sarnecki@collabora.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XRD_FRAME_BUFFER_H_
#define XRD_FRAME_BUFFER_H_

#if !defined (GULKAN_INSIDE) && !defined (GULKAN_COMPILATION)
#error "Only <gulkan.h> can be included directly."
#endif

#define VK_USE_PLATFORM_XLIB_KHR
#include <vulkan/vulkan.h>

#include <gulkan-device.h>
#include <gulkan-texture.h>

#include <glib-object.h>

G_BEGIN_DECLS

#define GULKAN_TYPE_FRAME_BUFFER gulkan_frame_buffer_get_type()
G_DECLARE_FINAL_TYPE (GulkanFrameBuffer, gulkan_frame_buffer,
                      GULKAN, FRAME_BUFFER, GObject)

GulkanFrameBuffer *gulkan_frame_buffer_new (void);

bool
gulkan_frame_buffer_initialize (GulkanFrameBuffer    *self,
                                GulkanDevice         *device,
                                uint32_t              width,
                                uint32_t              height,
                                VkSampleCountFlagBits sample_count,
                                VkFormat              color_format);

bool
gulkan_frame_buffer_initialize_from_image (GulkanFrameBuffer    *self,
                                           GulkanDevice         *device,
                                           VkImage               color_image,
                                           uint32_t              width,
                                           uint32_t              height,
                                           VkSampleCountFlagBits sample_count,
                                           VkFormat              color_format);

void
gulkan_frame_buffer_begin_pass (GulkanFrameBuffer *self,
                                VkCommandBuffer    cmd_buffer);


VkImage
gulkan_frame_buffer_get_color_image (GulkanFrameBuffer *self);

VkRenderPass
gulkan_frame_buffer_get_render_pass (GulkanFrameBuffer *self);

G_END_DECLS

#endif /* XRD_FRAME_BUFFER_H_ */

/*
 * gulkan
 * Copyright 2018 Collabora Ltd.
 * Author: Lubosz Sarnecki <lubosz.sarnecki@collabora.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef GULKAN_CLIENT_H_
#define GULKAN_CLIENT_H_

#if !defined (GULKAN_INSIDE) && !defined (GULKAN_COMPILATION)
#error "Only <gulkan.h> can be included directly."
#endif

#include <glib-object.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <cairo.h>

#define VK_USE_PLATFORM_XLIB_KHR
#include <vulkan/vulkan.h>

#include "gulkan-instance.h"
#include "gulkan-device.h"
#include "gulkan-texture.h"

G_BEGIN_DECLS

#define GULKAN_TYPE_CLIENT gulkan_client_get_type()
G_DECLARE_DERIVABLE_TYPE (GulkanClient, gulkan_client, GULKAN, CLIENT, GObject)

/**
 * GulkanCommandBuffer:
 * @handle: The #VkCommandBuffer handle of the buffer.
 * @fence: A #VkFence used with the buffer.
 *
 * Structure that contains a command buffer handle and a fence.
 **/
typedef struct {
  VkCommandBuffer handle;
  VkFence fence;
} GulkanCommandBuffer;

struct _GulkanClientClass
{
  GObjectClass parent_class;
};

GulkanClient * gulkan_client_new (void);

bool
gulkan_client_begin_cmd_buffer (GulkanClient        *self,
                                GulkanCommandBuffer *buffer);

bool
gulkan_client_submit_cmd_buffer (GulkanClient        *self,
                                 GulkanCommandBuffer *buffer);

bool
gulkan_client_upload_pixels (GulkanClient   *self,
                             GulkanTexture  *texture,
                             guchar         *pixels,
                             gsize           size,
                             VkImageLayout   layout);

GulkanTexture *
gulkan_client_texture_new_from_cairo_surface (GulkanClient    *self,
                                              cairo_surface_t *surface,
                                              VkFormat         format,
                                              VkImageLayout    layout);

GulkanTexture *
gulkan_client_texture_new_from_pixbuf (GulkanClient *self,
                                       GdkPixbuf    *pixbuf,
                                       VkFormat      format,
                                       VkImageLayout layout,
                                       bool          create_mipmaps);

bool
gulkan_client_upload_pixbuf (GulkanClient  *self,
                             GulkanTexture *texture,
                             GdkPixbuf     *pixbuf,
                             VkImageLayout  layout);

bool
gulkan_client_upload_cairo_surface (GulkanClient    *self,
                                    GulkanTexture   *texture,
                                    cairo_surface_t *surface,
                                    VkImageLayout    layout);

bool
gulkan_client_init_vulkan (GulkanClient *self,
                           GSList       *instance_extensions,
                           GSList       *device_extensions);

bool
gulkan_client_init_vulkan_full (GulkanClient    *self,
                                GSList          *instance_extensions,
                                GSList          *device_extensions,
                                VkPhysicalDevice physical_device);

bool
gulkan_client_transfer_layout_full (GulkanClient        *self,
                                    GulkanTexture       *texture,
                                    VkAccessFlags        src_access_mask,
                                    VkAccessFlags        dst_access_mask,
                                    VkImageLayout        src_layout,
                                    VkImageLayout        dst_layout,
                                    VkPipelineStageFlags src_stage_mask,
                                    VkPipelineStageFlags dst_stage_mask);

bool
gulkan_client_transfer_layout (GulkanClient  *self,
                               GulkanTexture *texture,
                               VkImageLayout  src_layout,
                               VkImageLayout  dst_layout);

bool
gulkan_client_init_command_pool (GulkanClient *self);

VkPhysicalDevice
gulkan_client_get_physical_device_handle (GulkanClient *self);

VkDevice
gulkan_client_get_device_handle (GulkanClient *self);

GulkanDevice *
gulkan_client_get_device (GulkanClient *self);

VkInstance
gulkan_client_get_instance_handle (GulkanClient *self);

GulkanInstance *
gulkan_client_get_instance (GulkanClient *self);

VkCommandPool
gulkan_client_get_command_pool (GulkanClient *self);

bool
gulkan_cmd_buffer_begin (GulkanCommandBuffer *buffer,
                         GulkanDevice        *device,
                         VkCommandPool        command_pool);

bool
gulkan_cmd_buffer_submit (GulkanCommandBuffer *buffer,
                          GulkanDevice        *device,
                          VkCommandPool        command_pool);

G_END_DECLS

#endif /* GULKAN_CLIENT_H_ */

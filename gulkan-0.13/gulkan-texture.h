/*
 * gulkan
 * Copyright 2018 Collabora Ltd.
 * Author: Lubosz Sarnecki <lubosz.sarnecki@collabora.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef GULKAN_TEXTURE_H_
#define GULKAN_TEXTURE_H_

#if !defined (GULKAN_INSIDE) && !defined (GULKAN_COMPILATION)
#error "Only <gulkan.h> can be included directly."
#endif

#include <glib-object.h>
#include <vulkan/vulkan.h>
#include <cairo.h>
#include <stdbool.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#include "gulkan-device.h"

G_BEGIN_DECLS

#define GULKAN_TYPE_TEXTURE gulkan_texture_get_type()
G_DECLARE_FINAL_TYPE (GulkanTexture, gulkan_texture,
                      GULKAN, TEXTURE, GObject)

GulkanTexture *
gulkan_texture_new_mip_levels (GulkanDevice *device,
                               guint         width,
                               guint         height,
                               guint         mip_levels,
                               gsize         size,
                               VkFormat      format);

GulkanTexture *
gulkan_texture_new (GulkanDevice *device,
                    guint         width,
                    guint         height,
                    gsize         size,
                    VkFormat      format);

GulkanTexture *
gulkan_texture_new_from_pixbuf (GulkanDevice   *device,
                                VkCommandBuffer cmd_buffer,
                                GdkPixbuf      *pixbuf,
                                VkFormat        format,
                                VkImageLayout   layout,
                                bool            create_mipmaps);

GulkanTexture *
gulkan_texture_new_from_cairo_surface (GulkanDevice    *device,
                                       VkCommandBuffer  cmd_buffer,
                                       cairo_surface_t *surface,
                                       VkFormat         format,
                                       VkImageLayout    layout);

GulkanTexture *
gulkan_texture_new_from_dmabuf (GulkanDevice *device,
                                int           fd,
                                guint         width,
                                guint         height,
                                VkFormat      format);

GulkanTexture *
gulkan_texture_new_export_fd (GulkanDevice *device,
                              guint         width,
                              guint         height,
                              VkFormat      format,
                              gsize        *size,
                              int          *fd);

void
gulkan_texture_transfer_layout (GulkanTexture       *self,
                                GulkanDevice        *device,
                                VkCommandBuffer      cmd_buffer,
                                VkImageLayout        src_layout,
                                VkImageLayout        layout);

void
gulkan_texture_transfer_layout_full (GulkanTexture       *self,
                                     GulkanDevice        *device,
                                     VkCommandBuffer      cmd_buffer,
                                     VkAccessFlags        src_access_mask,
                                     VkAccessFlags        dst_access_mask,
                                     VkImageLayout        src_layout,
                                     VkImageLayout        dst_layout,
                                     VkPipelineStageFlags src_stage_mask,
                                     VkPipelineStageFlags dst_stage_mask);

bool
gulkan_texture_upload_pixels (GulkanTexture  *self,
                              VkCommandBuffer cmd_buffer,
                              guchar         *pixels,
                              gsize           size,
                              VkImageLayout   layout);

void
gulkan_texture_free_staging_memory (GulkanTexture *self);

VkImageView
gulkan_texture_get_image_view (GulkanTexture *self);

VkImage
gulkan_texture_get_image (GulkanTexture *self);

guint
gulkan_texture_get_width (GulkanTexture *self);

guint
gulkan_texture_get_height (GulkanTexture *self);

VkFormat
gulkan_texture_get_format (GulkanTexture *self);

guint
gulkan_texture_get_mip_levels (GulkanTexture *self);

G_END_DECLS

#endif /* GULKAN_TEXTURE_H_ */

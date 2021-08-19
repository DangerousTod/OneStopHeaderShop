/*
 * gulkan
 * Copyright 2018 Collabora Ltd.
 * Author: Lubosz Sarnecki <lubosz.sarnecki@collabora.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XRD_VERTEX_BUFFER_H_
#define XRD_VERTEX_BUFFER_H_

#if !defined (GULKAN_INSIDE) && !defined (GULKAN_COMPILATION)
#error "Only <gulkan.h> can be included directly."
#endif

#include <glib-object.h>

#define VK_USE_PLATFORM_XLIB_KHR
#include <vulkan/vulkan.h>

#include <graphene.h>
#include <gulkan-device.h>

G_BEGIN_DECLS

#define GULKAN_TYPE_VERTEX_BUFFER gulkan_vertex_buffer_get_type()
G_DECLARE_FINAL_TYPE (GulkanVertexBuffer, gulkan_vertex_buffer,
                      GULKAN, VERTEX_BUFFER, GObject)

GulkanVertexBuffer *gulkan_vertex_buffer_new (void);

void
gulkan_vertex_buffer_draw (GulkanVertexBuffer *self,
                           VkCommandBuffer cmd_buffer);

void
gulkan_vertex_buffer_draw_indexed (GulkanVertexBuffer *self,
                                   VkCommandBuffer cmd_buffer);

void
gulkan_vertex_buffer_reset (GulkanVertexBuffer *self);

void
gulkan_vertex_buffer_map_array (GulkanVertexBuffer *self);

bool
gulkan_vertex_buffer_alloc_empty (GulkanVertexBuffer *self,
                                  GulkanDevice       *device,
                                  uint32_t            multiplier);

bool
gulkan_vertex_buffer_alloc_array (GulkanVertexBuffer *self,
                                  GulkanDevice       *device);

bool
gulkan_vertex_buffer_alloc_data (GulkanVertexBuffer *self,
                                 GulkanDevice       *device,
                                 const void         *data,
                                 VkDeviceSize        size);

bool
gulkan_vertex_buffer_alloc_index_data (GulkanVertexBuffer *self,
                                       GulkanDevice       *device,
                                       const void         *data,
                                       VkDeviceSize        element_size,
                                       guint               element_count);

void
gulkan_vertex_buffer_append_position_uv (GulkanVertexBuffer *self,
                                         graphene_vec4_t *vec,
                                         float u, float v);

void
gulkan_vertex_buffer_append_with_color (GulkanVertexBuffer *self,
                                        graphene_vec4_t *vec,
                                        graphene_vec3_t *color);

gboolean
gulkan_vertex_buffer_is_initialized (GulkanVertexBuffer *self);

G_END_DECLS

#endif /* XRD_VERTEX_BUFFER_H_ */

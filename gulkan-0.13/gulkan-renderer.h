/*
 * gulkan
 * Copyright 2018 Collabora Ltd.
 * Author: Lubosz Sarnecki <lubosz.sarnecki@collabora.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef GULKAN_RENDERER_H_
#define GULKAN_RENDERER_H_

#if !defined (GULKAN_INSIDE) && !defined (GULKAN_COMPILATION)
#error "Only <gulkan.h> can be included directly."
#endif

#include <stdint.h>
#include <glib-object.h>

#include "gulkan-client.h"
#include "gulkan-texture.h"

G_BEGIN_DECLS

#define GULKAN_TYPE_RENDERER gulkan_renderer_get_type()
G_DECLARE_FINAL_TYPE (GulkanRenderer, gulkan_renderer,
                      GULKAN, RENDERER, GulkanClient)

struct _GulkanRendererClass
{
  GulkanClientClass parent_class;
};

GulkanRenderer *gulkan_renderer_new (void);


bool
gulkan_renderer_init_rendering (GulkanRenderer *self,
                                VkSurfaceKHR surface,
                                GulkanTexture *texture);

bool
gulkan_renderer_update_texture (GulkanRenderer *self,
                                GulkanTexture  *texture);

bool
gulkan_renderer_draw (GulkanRenderer *self);

bool
gulkan_renderer_create_shader_module (VkDevice device,
                                      const gchar* resource_name,
                                      VkShaderModule *module);

G_END_DECLS

#endif /* GULKAN_RENDERER_H_ */

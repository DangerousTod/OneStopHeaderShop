/*
 * gulkan
 * Copyright 2018 Collabora Ltd.
 * Author: Lubosz Sarnecki <lubosz.sarnecki@collabora.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef XRD_DESCRIPTOR_SET_H_
#define XRD_DESCRIPTOR_SET_H_

#if !defined (GULKAN_INSIDE) && !defined (GULKAN_COMPILATION)
#error "Only <gulkan.h> can be included directly."
#endif

#include "gulkan-device.h"

#define GULKAN_INIT_DECRIPTOR_POOL(a, b, c, d) \
  gulkan_init_descriptor_pool (a, b, G_N_ELEMENTS (b), c, d)

gboolean
gulkan_init_descriptor_pool (GulkanDevice               *device,
                             const VkDescriptorPoolSize *pool_sizes,
                             uint32_t                    pool_size_count,
                             uint32_t                    set_count,
                             VkDescriptorPool           *pool);

gboolean
gulkan_allocate_descritpor_set (GulkanDevice          *device,
                                VkDescriptorPool       pool,
                                VkDescriptorSetLayout *layout,
                                uint32_t               count,
                                VkDescriptorSet       *set);

#endif /* XRD_DESCRIPTOR_SET_H_ */

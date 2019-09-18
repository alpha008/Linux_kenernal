// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2002-3 Patrick Mochel
 * Copyright (c) 2002-3 Open Source Development Labs
 */

#include <linux/device.h>
#include <linux/init.h>
#include <linux/memory.h>
#include <linux/of.h>

#include "base.h"

/**
 * driver_init - initialize driver model.
 *
 * Call the driver model init functions to initialize their
 * subsystems. Called early from init/main.c.
 */
void __init driver_init(void)
{
	/* These are the core pieces */
	devtmpfs_init();
                    //创建devtmpfs文件系统
	devices_init();
                    //在/sys/目录下创建devices子目录             devices_kset
                    //在/sys/目录下创建dev子目录                 dev_kobj
                    //在/sys/dev/目录下创建block子目录           sysfs_dev_block_kobj
                    //在/sys/dev/目录下创建char子目录            sysfs_dev_char_kobj
	buses_init();
                    //在/sys/目录下创建bus子目录                   bus_kset
	classes_init();
                    //在/sys/目录下创建class子目录                 class_kset
	firmware_init();
                    //在/sys/目录下创建firmware子目录              firmware_kset
	hypervisor_init();
                    //在/sys/目录下创建hypervisor子目录            hypervisor_kset
	/* These are also core pieces, but must come after the
	 * core core pieces.
	 */
	of_core_init();
	platform_bus_init();
                    //device_register(&platform_bus)
                    //bus_register(&platform_bus_type)
	cpu_dev_init();
	memory_dev_init();
	container_dev_init();
}

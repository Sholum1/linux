# SPDX-License-Identifier: GPL-2.0

netfs-y := \
	buffered_read.o \
	buffered_write.o \
	direct_read.o \
	direct_write.o \
	iterator.o \
	locking.o \
	main.o \
	misc.o \
	objects.o \
	read_collect.o \
	read_pgpriv2.o \
	read_retry.o \
	read_single.o \
	rolling_buffer.o \
	write_collect.o \
	write_issue.o \
	write_retry.o

netfs-$(CONFIG_NETFS_STATS) += stats.o

netfs-$(CONFIG_FSCACHE) += \
	fscache_cache.o \
	fscache_cookie.o \
	fscache_io.o \
	fscache_main.o \
	fscache_volume.o

ifeq ($(CONFIG_PROC_FS),y)
netfs-$(CONFIG_FSCACHE) += fscache_proc.o
endif
netfs-$(CONFIG_FSCACHE_STATS) += fscache_stats.o

obj-$(CONFIG_NETFS_SUPPORT) += netfs.o

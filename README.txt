Bringup and Diagnostic Kit
--------------------------

This directory contains the "Bringup and Diagnostic Kit" (BDK).  These
files support chip bringup, board bringup, and the creation of
diagnostics. The basic layout is as follows:

csr-tool/
	Python scripts for updating CSR files.

docs/
	BDK documentation.

libbdk/
	This is a combined library and single header file for using all of
	the BDK features. Normally, this contains the only C header
	and library that applications should ever reference. Make sure bdk.h
	is the very first line in C files to make sure the precompiled header
	works properly.

libbdk-arch/
	Library and C files related to Octeon II architecture. This
	contains the minimal code needed to write any code for Octeon II
	with the minimal amount of abstractions as possible. This contains
	CSR and assembly defines and access functions . Higher level APIs
	are not part of this library.

libbdk-dram/
	Library and C files related to Octeon II DRAM initialization. These
	files are meant to be shared by all loaders and early diagnostics
	that need to setup DRAM.

libbdk-hal/
	Library and C files providing a API for interfacing with Octeon II
	hardware. This is similar to the "executive" in the Octeon SDK.

libbdk-os/
	Glue logic for the C library and operating system style operations.
	This contains the init code, threading, and filesystem operations.

libc/
	Port of newlib for use with the BDK.

liblua/
	The Lua scripting language as a library.

lua/
	The main BDK scripting application.

rom/
	All file in this directory are included inside BDK applications.
	These files can be read using the "/rom/" directory.

traffic-gen/
	Port of traffic-gen using the BDK libraries.


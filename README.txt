Bringup and Diagnostic Kit
--------------------------

This directory contains the "Bringup and Diagnostic Kit" (BDK).  These
files support chip bringup, board bringup, and the creation of
diagnostics. The basic layout is as follows:

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

libbdk.a, bdk.h, bdk.pch
	This is a combined library and single header file for using all of
	the libbdk-* features. Normally, this contains the only C header
	and library that applications should ever reference. Make sure bdk.h
	is the very first line in C files to make sure the precompiled header
	works properly.

eLua/
	This is a nearly boot environment based on the Lua scripting
	language.

